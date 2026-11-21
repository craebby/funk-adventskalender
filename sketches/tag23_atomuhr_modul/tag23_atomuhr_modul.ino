// Tag 23 (optional, mit DCF77-Modul): Die Atomuhr aus Mainflingen
// DCF77-Modul (z. B. mit den Anschluessen VCC, GND, PON, TCO):
//   VCC an 3,3V (nicht 5V!), GND an GND, PON ebenfalls an GND (sonst schlaeft das Modul),
//   TCO (Ausgang) an Pin 12 und ueber 10 kOhm an 3,3V.
//   Ein Kondensator (10-100 uF, langes Bein an VCC) direkt am Modul beruhigt die Versorgung.
// Modul mindestens 1-2 m weg von PC, Monitor, Netzteilen und LED-Lampen, am besten ans Fenster.
// LED mit 220 Ohm an Pin 5 blinkt mit dem Signal.
// Serieller Monitor auf 115200 Baud. Nach 3 bis 5 Minuten steht dort die Uhrzeit.
//
// Wie es funktioniert: Jede Sekunde kommt eine Marke, 100 ms lang fuer eine 0, 200 ms fuer eine 1.
// Bei schwachem Empfang fehlen Marken oder sind zerfasert. Darum legt das Programm mehrere Minuten
// uebereinander, wie eine echte Funkuhr: Stunde und Datum bleiben gleich, die Minute zaehlt hoch.
// Ob dein Modul die Marke als HIGH oder LOW schickt, erkennt das Programm selbst.

const int DCF = 12;
const int LED = 5;
const int GEDAECHTNIS = 4;    // so viele Minuten vergleicht das Programm fuer die Minutenanzeige

byte ring[125];               // die letzte Sekunde, ein Bit pro Millisekunde
unsigned int bins[100];       // in welchen 10 ms einer Sekunde ist das Signal meistens aktiv?
int phase = 0;                // wo in der Sekunde die Marke beginnt (ms)
long anteilHigh = 32768;      // wie oft der Eingang HIGH ist, langsamer Mittelwert
unsigned long sek = 0;        // gezaehlte Sekunden
int luecke[60];               // pro Sekunde im Minutenraster: wie viel Signal am Anfang (klein = Minutenluecke)
int einsen[60];               // pro Sekunde im Minutenraster: wie oft eine 1
signed char weich[60];        // die letzte Messung pro Sekunde: >0 eher 1, <0 eher 0, 0 unbekannt
int summe[59];                // Bits der Minute, ueber mehrere Minuten gemittelt
signed char zeitBits[GEDAECHTNIS][15]; // Minuten- und Stunden-Bits (21..35) der letzten Minuten
int gesammelt = 0;
int typischNull = 10, typischEins = 60;   // lernt mit: wie viel Signal im zweiten Zehntel bei 0 und bei 1
unsigned long letzteMs = 0;

const byte GEWICHT[] = {1, 2, 4, 8, 10, 20, 40, 80};

void setup() {
  pinMode(DCF, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println(F("Lausche auf DCF77 ... Nach 3 bis 5 Minuten kommt die Uhrzeit."));
  letzteMs = millis();
}

bool ringBit(unsigned long t) { unsigned int i = t % 1000; return ring[i >> 3] & (1 << (i & 7)); }

void ringSetzen(unsigned long t, bool aktiv) {
  unsigned int i = t % 1000;
  if (aktiv) ring[i >> 3] |= (1 << (i & 7)); else ring[i >> 3] &= ~(1 << (i & 7));
}

// Wo beginnt die Marke? Die 100 ms mit dem meisten Signal.
void phaseSuchen() {
  long s = 0, best = -1;
  for (int k = 0; k < 10; k++) s += bins[k];
  for (int i = 0; i < 100; i++) {
    if (s > best) { best = s; phase = i * 10; }
    s += (long)bins[(i + 10) % 100] - bins[i];
  }
  for (int i = 0; i < 100; i++) bins[i] = bins[i] * 7 / 8;   // Altes langsam vergessen
}

// Wie gut passt Sekunde m als Minutenluecke? Dort fehlt die Marke, 21 s spaeter kommt immer eine 1,
// und von den Bits 17 und 18 (Winter-/Sommerzeit) ist genau eines 1.
long passtAlsLuecke(int m) {
  return (long)einsen[(m + 21) % 60] + abs(einsen[(m + 19) % 60] - einsen[(m + 18) % 60]) - 2L * luecke[m];
}

int wert(const bool b[], int von, int bis) {
  int s = 0;
  for (int i = von; i <= bis; i++) if (b[i]) s += GEWICHT[i - von];
  return s;
}

bool geradeEinsen(const bool b[], int von, int bis) {
  int n = 0;
  for (int i = von; i <= bis; i++) n += b[i];
  return n % 2 == 0;
}

// Zahl als BCD wie bei DCF77: Einer in Bit 0-3, Zehner ab Bit 4
byte bcd(int v) { return (v % 10) | ((v / 10) << 4); }

// Wie gut passen die gemessenen Bits zu einem erwarteten Wert (n Bits plus Pruefbit)?
long passt(const signed char gemessen[], int ab, byte erwartet, int n) {
  long p = 0;
  byte anzahl = 0;
  for (int j = 0; j < n; j++) {
    bool e = (erwartet >> j) & 1;
    anzahl += e;
    p += e ? gemessen[ab + j] : -gemessen[ab + j];
  }
  p += (anzahl & 1) ? gemessen[ab + n] : -gemessen[ab + n];   // Pruefbit
  return p;
}

void minuteAuswerten(int ml) {
  // die neue Minute in die Mittelwerte aufnehmen
  for (int i = 0; i < 59; i++) summe[i] = summe[i] * 3 / 4 + weich[(ml + 1 + i) % 60];
  for (int k = GEDAECHTNIS - 1; k > 0; k--) for (int j = 0; j < 15; j++) zeitBits[k][j] = zeitBits[k - 1][j];
  for (int j = 0; j < 15; j++) zeitBits[0][j] = weich[(ml + 22 + j) % 60];
  if (gesammelt < GEDAECHTNIS) gesammelt++;

  bool b[59];
  for (int i = 0; i < 59; i++) b[i] = summe[i] > 0;

  // Stunde und Minute: Welches Paar passt am besten zu den letzten Minuten?
  // (Eine Minute frueher war es eine Minute weniger, und bei Minute 0 auch eine Stunde weniger.)
  int besteMinute = 0, besteStunde = 0; long bestePunkte = -32000, zweite = -32000;
  for (int h = 0; h < 24; h++) {
    for (int m = 0; m < 60; m++) {
      long p = 0;
      for (int k = 0; k < gesammelt; k++) {
        int mk = m - k, hk = h;
        if (mk < 0) { mk += 60; hk = (h + 23) % 24; }
        p += passt(zeitBits[k], 0, bcd(mk), 7) + passt(zeitBits[k], 8, bcd(hk), 6);
      }
      if (p > bestePunkte) { zweite = bestePunkte; bestePunkte = p; besteMinute = m; besteStunde = h; }
      else if (p > zweite) zweite = p;
    }
  }
  int beste = besteMinute;

  int stunde = besteStunde, tag = wert(b, 36, 41), monat = wert(b, 45, 49), jahr = wert(b, 50, 57);
  bool sicher = geradeEinsen(b, 36, 58) && tag >= 1 && tag <= 31
                && monat >= 1 && monat <= 12 && bestePunkte - zweite >= 20 && gesammelt >= 3;

  // Gegenprobe: Passt das Ergebnis zur Minute davor (eine Minute weiter, gleiches Datum)?
  static int vorher[5] = {-1, -1, -1, -1, -1};
  bool bestaetigt = sicher && vorher[0] >= 0 && (vorher[0] * 60 + vorher[1] + 1) % 1440 == stunde * 60 + beste
                    && vorher[2] == tag && vorher[3] == monat && vorher[4] == jahr;
  if (sicher) { vorher[0] = stunde; vorher[1] = beste; vorher[2] = tag; vorher[3] = monat; vorher[4] = jahr; }
  else vorher[0] = -1;

  Serial.println();
  Serial.print(bestaetigt ? F("Funkzeit: ") : (sicher ? F("Kandidat (wird naechste Minute geprueft): ") : F("Noch unsicher, sammle weiter ")));
  if (!sicher) { Serial.println(F("...")); return; }
  Serial.print(stunde); Serial.print(":");
  if (beste < 10) Serial.print("0");
  Serial.print(beste);
  Serial.print(F(" Uhr am "));
  Serial.print(tag); Serial.print("."); Serial.print(monat); Serial.print(".20"); Serial.println(jahr);
}

// Einmal pro Sekunde, 250 ms nach Beginn der Marke: Was war los?
void sekundeAuswerten(unsigned long t) {
  static unsigned long letzte = 0;
  if (letzte > 0 && t - letzte < 500) return;                   // Takt hat sich verschoben: nicht doppelt zaehlen
  if (letzte > 0 && t - letzte > 1500) sek += (t - letzte + 500) / 1000 - 1;   // ausgelassene Sekunden mitzaehlen
  letzte = t;
  unsigned long start = t - 250;
  int a = 0, b = 0;
  for (int k = 0; k < 100; k++) a += ringBit(start + k);
  for (int k = 120; k < 200; k++) b += ringBit(start + k);   // zweites Zehntel, mit etwas Abstand

  int slot = sek % 60;
  sek++;
  luecke[slot] = luecke[slot] * 3 / 4 + a;
  einsen[slot] = einsen[slot] * 3 / 4 + b;
  if (a + b < 20) weich[slot] = 0;                         // Marke fehlt
  else {
    int mitte = (typischNull + typischEins) / 2;           // Grenze zwischen 0 und 1, passt sich dem Modul an
    if (b < mitte) typischNull += (b - typischNull) / 8;
    else typischEins += (b - typischEins) / 8;
    weich[slot] = constrain(b - mitte, -30, 30);
  }
  Serial.print(weich[slot] == 0 ? '?' : (weich[slot] > 0 ? '1' : '0'));

  if (sek < 60) return;
  int ml = 0, zweitbeste = -1;
  for (int m = 1; m < 60; m++) if (passtAlsLuecke(m) > passtAlsLuecke(ml)) ml = m;
  for (int m = 0; m < 60; m++) if (m != ml && (zweitbeste < 0 || passtAlsLuecke(m) > passtAlsLuecke(zweitbeste))) zweitbeste = m;
  if (slot == ml && passtAlsLuecke(ml) - passtAlsLuecke(zweitbeste) >= 30) minuteAuswerten(ml);
}

void loop() {
  unsigned long jetzt = millis();
  while (letzteMs != jetzt) {             // jede Millisekunde genau einmal bearbeiten
    letzteMs++;
    int roh = digitalRead(DCF);
    anteilHigh += ((roh == HIGH ? 65535L : 0L) - anteilHigh) / 2048;
    bool aktiv = roh != (anteilHigh > 32768 ? HIGH : LOW);
    digitalWrite(LED, aktiv);
    ringSetzen(letzteMs, aktiv);
    if (aktiv) bins[(letzteMs % 1000) / 10]++;
    if (letzteMs % 1000 == 999) phaseSuchen();
    if (letzteMs >= 3000 && (letzteMs + 1000 - phase) % 1000 == 250) sekundeAuswerten(letzteMs);
  }
}
