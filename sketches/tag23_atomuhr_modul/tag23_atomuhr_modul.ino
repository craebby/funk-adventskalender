// Tag 23 (optional, mit DCF77-Modul): Die Atomuhr aus Mainflingen
// DCF77-Modul (z. B. Pollin DCF1): VDD an 3,3V (nicht 5V!), GND an GND,
// Ausgang an Pin 12 und ueber 10 kOhm an 3,3V. Antenne quer zu Frankfurt ausrichten,
// weg von Monitor, Netzteil und LED-Lampen.
// LED mit 220 Ohm an Pin 5 blinkt mit jeder Sekunde.
// Nach einer vollen Minute steht die Uhrzeit im Seriellen Monitor.

const int DCF = 12;
const int LED = 5;
const int PULS = LOW;   // Pegel waehrend der Sekundenmarke. Blinkt die LED "falsch herum", HIGH eintragen.

int bits[60];
int nr = -1;            // welches Bit gerade dran ist, -1 = Minutenanfang noch nicht gefunden
unsigned long pulsStart = 0, letzterStart = 0;
bool imPuls = false;

void setup() {
  pinMode(DCF, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Warte auf DCF77 ... (die erste volle Minute dauert bis zu 2 Minuten)");
}

int wert(int von, int bis, const int gewicht[]) {
  int summe = 0;
  for (int i = von; i <= bis; i++) if (bits[i]) summe += gewicht[i - von];
  return summe;
}

void auswerten() {
  const int g[] = {1, 2, 4, 8, 10, 20, 40};
  int minute = wert(21, 27, g);
  int stunde = wert(29, 34, g);
  int tag    = wert(36, 41, g);
  int monat  = wert(45, 49, g);
  if (bits[20] != 1 || minute > 59 || stunde > 23) {
    Serial.println("Empfang gestoert, naechste Minute ...");
    return;
  }
  Serial.print("Funkzeit: ");
  Serial.print(stunde); Serial.print(":");
  if (minute < 10) Serial.print("0");
  Serial.print(minute);
  Serial.print(" Uhr am ");
  Serial.print(tag); Serial.print("."); Serial.print(monat); Serial.println(".");
}

void loop() {
  bool puls = digitalRead(DCF) == PULS;
  unsigned long jetzt = millis();

  if (puls && !imPuls) {                  // Sekundenmarke beginnt
    if (jetzt - pulsStart < 700) return;  // Stoerung, zu kurz nach der letzten
    imPuls = true;
    pulsStart = jetzt;
    digitalWrite(LED, HIGH);
    if (letzterStart > 0 && jetzt - letzterStart > 1500) {  // Sekunde 59 fehlt: neue Minute
      if (nr == 59) auswerten();
      nr = 0;
      Serial.println();
    }
    letzterStart = jetzt;
  }

  if (!puls && imPuls) {                  // Sekundenmarke endet
    imPuls = false;
    digitalWrite(LED, LOW);
    unsigned long laenge = jetzt - pulsStart;
    if (laenge < 40) return;              // Stoerung
    int bit = laenge > 150 ? 1 : 0;       // 100 ms = 0, 200 ms = 1
    Serial.print(bit);
    if (nr >= 0 && nr < 60) bits[nr++] = bit;
  }
}
