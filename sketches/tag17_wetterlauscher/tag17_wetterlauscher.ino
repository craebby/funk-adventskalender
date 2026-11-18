// Tag 17: Wer funkt denn hier?
// 433-MHz-Empfaenger: VCC an 5V, GND an GND, DATA an Pin 2. Antenne (17,3 cm) ans Loch ANT. Keine Bibliothek noetig.
// Der Arduino lauscht auf Funk-Thermometer in der Nachbarschaft. Die meisten billigen Sensoren
// funken so: kurzer Puls, dann eine kurze Pause (= 0) oder eine lange Pause (= 1), am Ende eine sehr lange Pause.
// Der Sketch sammelt diese Nullen und Einsen und versucht, Temperatur und Feuchte herauszulesen.
// Seriellen Monitor oeffnen (115200 Baud) und Geduld haben: Thermometer funken nur etwa jede Minute.

const int DATEN = 2;
const bool ALLES_ZEIGEN = false;   // true: jedes Telegramm roh zeigen, auch halbe (zur Fehlersuche)

// --- Lauschen im Hintergrund (Interrupt) ---
const byte MAX_LUECKEN = 80;
volatile unsigned int luecken[MAX_LUECKEN];   // Pausen zwischen den Pulsen in Mikrosekunden
volatile byte anzahl = 0;
volatile unsigned int kurz = 0;               // typische kurze Pause dieses Telegramms (Mittelwert)
// Fertige Telegramme kommen in einen zweiten Speicher. So hoert der Arduino schon das naechste
// Telegramm, waehrend er das vorige auswertet. Die Wiederholungen kommen naemlich direkt hintereinander.
volatile unsigned int fertigeLuecken[MAX_LUECKEN];
volatile byte fertigeAnzahl = 0;
volatile bool fertig = false;
volatile unsigned long anstieg = 0;           // wann der letzte Puls begann
volatile unsigned long pauseStart = 0;        // wann der letzte gueltige Puls endete

void neuAnfangen() {
  anzahl = 0;
  kurz = 0;
}

void weiterreichen() {                          // fertiges Telegramm an loop() geben
  if (anzahl >= 24 && !fertig) {
    for (byte i = 0; i < anzahl; i++) fertigeLuecken[i] = luecken[i];
    fertigeAnzahl = anzahl;
    fertig = true;
  }
  neuAnfangen();
}

void flanke() {
  unsigned long jetzt = micros();
  if (digitalRead(DATEN) == HIGH) {             // ein Puls beginnt: nur merken
    anstieg = jetzt;
    return;
  }
  // Ein Puls ist zu Ende
  unsigned long puls = jetzt - anstieg;
  if (puls < 250) return;                       // winziger Stoerpuls: ignorieren, die Pause laeuft weiter
  if (puls > 1100) {                            // viel zu lang: Rauschen oder etwas anderes
    weiterreichen();
    pauseStart = jetzt;
    return;
  }
  // Gueltiger Puls. Jetzt die Pause davor auswerten.
  unsigned long pause = anstieg - pauseStart;
  pauseStart = jetzt;
  if (pause < 600) { weiterreichen(); return; } // zu kurz: Rauschen

  // Sehr lange Pause (mehr als dreimal die kurze) = das Telegramm davor ist zu Ende
  if ((kurz > 0 && pause > 3UL * kurz) || pause > 12000) {
    weiterreichen();
    return;
  }
  if (anzahl >= MAX_LUECKEN) { neuAnfangen(); return; }
  luecken[anzahl++] = pause;

  // Die kurze Pause merken: Ist diese Pause deutlich kuerzer als bisher, ist sie die neue kurze.
  // Ist sie aehnlich lang, fliesst sie in den Mittelwert ein. Lange Pausen (Einsen) zaehlen nicht.
  if (kurz == 0 || pause * 3UL < kurz * 2UL) kurz = pause;
  else if (pause * 2UL < kurz * 3UL) kurz = (kurz * 3UL + pause) / 4;
}

// --- Auswerten ---
byte bits[MAX_LUECKEN];
byte zahlBits = 0;
// Thermometer senden jedes Telegramm mehrmals. Gezeigt wird nur, was zweimal gleich ankam.
const byte MERKEN = 4;
String gehoert[MERKEN];
unsigned long gehoertZeit[MERKEN];
byte merkPos = 0;
String letztes = "";
unsigned long letztesMal = 0;
int telegramme = 0;

long holeBits(byte von, byte wieviele) {
  long wert = 0;
  for (byte i = 0; i < wieviele; i++) wert = (wert << 1) | bits[von + i];
  return wert;
}

// Ergebnis der Auswertung
String ergebnis;       // was wir anzeigen
String kennung;        // woran wir Wiederholungen erkennen

bool nexusAb(byte a) {
  // 36 Bits ab Stelle a: ID (8), Batterie, 0, Kanal (2), Temperatur (12), 1111, Feuchte (8)
  if (holeBits(a + 24, 4) != 0b1111 || bits[a + 9] != 0) return false;
  int roh = holeBits(a + 12, 12);
  if (roh & 0x800) roh -= 4096;
  if (roh < -400 || roh > 700) return false;
  int feuchte = holeBits(a + 28, 8);
  if (feuchte > 100) return false;
  ergebnis = F("Thermometer (Nexus-Format): ID ");
  ergebnis += holeBits(a, 8);
  ergebnis += F(", Kanal ");
  ergebnis += holeBits(a + 10, 2) + 1;
  ergebnis += F(", ");
  ergebnis += String(roh / 10.0, 1);
  ergebnis += F(" Grad");
  if (feuchte > 0) { ergebnis += F(", Feuchte "); ergebnis += feuchte; ergebnis += F(" %"); }
  kennung = "N";
  for (byte i = a; i < a + 36; i++) kennung += bits[i] ? '1' : '0';
  return true;
}

bool alsNexus() {
  // Am Anfang oder Ende koennen ein paar Bits zu viel sein (Rauschen). Wir suchen die passende Stelle,
  // von hinten nach vorn.
  if (zahlBits < 36) return false;
  for (int a = zahlBits - 36; a >= 0; a--) {
    if (nexusAb(a)) return true;
  }
  return false;
}

// Pruefsumme des inFactory-Sensors (CRC-4, wie im Programm rtl_433). Stimmt sie, ist kein Bit falsch.
bool inFactoryPruefsummeOk(byte a) {
  byte b[5];
  for (byte i = 0; i < 5; i++) b[i] = holeBits(a + i * 8, 8);
  byte soll = b[1] >> 4;
  b[1] = (b[1] & 0x0F) | ((b[4] & 0x0F) << 4);   // der Kanal steht bei der Rechnung an der Stelle der Pruefsumme
  byte rest = 0;
  for (byte i = 0; i < 4; i++) {
    rest ^= b[i];
    for (byte k = 0; k < 8; k++) rest = (rest & 0x80) ? (rest << 1) ^ 0x30 : (rest << 1);
  }
  return (((rest >> 4) ^ (b[4] >> 4)) & 0x0F) == soll;
}

bool inFactoryAb(byte a) {
  // 40 Bits ab Stelle a: ID (8), Pruefsumme (4), Status (4), Temperatur in Fahrenheit + 90 (12), Feuchte (2 Ziffern), Kanal (4)
  if (!inFactoryPruefsummeOk(a)) return false;
  long roh = holeBits(a + 16, 12);
  float grad = (roh / 10.0 - 90.0 - 32.0) * 5.0 / 9.0;
  int zehner = holeBits(a + 28, 4), einer = holeBits(a + 32, 4);
  if (grad < -40 || grad > 70 || zehner > 9 || einer > 9) return false;
  ergebnis = F("Thermometer (inFactory-Format): ID ");
  ergebnis += holeBits(a, 8);
  ergebnis += F(", ");
  ergebnis += String(grad, 1);
  ergebnis += F(" Grad, Feuchte ");
  ergebnis += zehner * 10 + einer;
  ergebnis += F(" %");
  kennung = "I";
  for (byte i = a; i < a + 40; i++) kennung += bits[i] ? '1' : '0';
  return true;
}

bool alsInFactory() {
  if (zahlBits < 40) return false;
  for (int a = zahlBits - 40; a >= 0; a--) {
    if (inFactoryAb(a)) return true;
  }
  return false;
}

void setup() {
  pinMode(DATEN, INPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(DATEN), flanke, CHANGE);
  Serial.println(F("Ich lausche auf 433 MHz ... (Thermometer funken etwa jede Minute)"));
  Serial.println(F("Jeder Punkt ist ein empfangenes Telegramm."));
}

void loop() {
  // Kommt nach einem Telegramm lange nichts mehr, ist es auch fertig
  noInterrupts();
  if (anzahl >= 24 && micros() - pauseStart > 20000) weiterreichen();
  interrupts();
  if (!fertig) return;

  // Pausen in kurz (0) und lang (1) einteilen: alles ueber der Mitte ist lang
  zahlBits = fertigeAnzahl;
  unsigned int klein = 65535, gross = 0;
  for (byte i = 0; i < zahlBits; i++) {
    if (fertigeLuecken[i] < klein) klein = fertigeLuecken[i];
    if (fertigeLuecken[i] > gross) gross = fertigeLuecken[i];
  }
  unsigned int mitte = (klein + gross) / 2;
  for (byte i = 0; i < zahlBits; i++) bits[i] = fertigeLuecken[i] > mitte;
  fertig = false;                               // Platz fuer das naechste Telegramm

  String text = "";
  for (byte i = 0; i < zahlBits; i++) text += bits[i] ? '1' : '0';
  if (ALLES_ZEIGEN) {
    Serial.print(F("roh: "));
    Serial.print(zahlBits);
    Serial.print(F(" Bits, Pausen "));
    Serial.print(klein);
    Serial.print('/');
    Serial.print(gross);
    Serial.print(F(" us  "));
    Serial.println(text);
  }
  if (gross < klein * 3UL / 2) return;          // keine zwei verschiedenen Pausen: kein Telegramm
  Serial.print('.');

  // Bekannte Thermometer probieren, sonst unbekannt
  if (!alsInFactory() && !alsNexus()) {     // inFactory zuerst: hat eine Pruefsumme, ist also sicherer
    ergebnis = F("unbekanntes Geraet (Pausen ca. ");
    ergebnis += klein;
    ergebnis += F(" und ");
    ergebnis += gross;
    ergebnis += F(" Mikrosekunden)");
    kennung = "U" + text;
    // Nur das hintere Stueck eines gerade gezeigten Telegramms? Dann nicht noch einmal melden.
    if (millis() - letztesMal < 5000 && letztes.endsWith(text)) return;
  }

  // Nur glauben, was zweimal gleich ankam, und nicht dauernd dasselbe zeigen
  if (kennung == letztes && millis() - letztesMal < 5000) return;
  bool zweimal = kennung[0] == 'I';             // inFactory hat eine Pruefsumme: einmal reicht
  for (byte i = 0; i < MERKEN; i++) {
    if (gehoert[i] == kennung && millis() - gehoertZeit[i] < 5000) zweimal = true;
  }
  gehoert[merkPos] = kennung;
  gehoertZeit[merkPos] = millis();
  merkPos = (merkPos + 1) % MERKEN;
  if (!zweimal) return;
  letztes = kennung;
  letztesMal = millis();
  telegramme++;

  Serial.println();
  Serial.print(F("Telegramm Nr. "));
  Serial.print(telegramme);
  Serial.print(F(" nach "));
  Serial.print(millis() / 1000);
  Serial.print(F(" s: "));
  Serial.print(kennung.length() - 1);
  Serial.print(F(" Bits  "));
  Serial.println(kennung.substring(1));
  Serial.print(F("  -> "));
  Serial.println(ergebnis);
}
