// Tag 23, Pruef-Sketch fuer das DCF77-Modul: Was kommt an Pin 12 an?
// Verkabelung wie bei tag23_atomuhr_modul. Die LED an Pin 5 zeigt den Pegel direkt an.
// Im Seriellen Monitor (115200 Baud) steht jede Sekunde eine Zeile:
//   Pegel jetzt, wie oft er in dieser Sekunde gewechselt hat, und wie lange er LOW war.
// So sieht es aus, wenn alles stimmt: 2 Wechsel pro Sekunde, LOW etwa 100 oder 200 ms
// (oder HIGH 100/200 ms, dann ist das Modul "andersherum").

const int DCF = 12;
const int LED = 5;

void setup() {
  pinMode(DCF, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println(F("DCF77-Test: Pegel, Wechsel pro Sekunde, Zeit auf LOW in ms"));
}

void loop() {
  static unsigned long sekunde = millis();
  static unsigned long lowZeit = 0, letzte = millis();
  static int wechsel = 0;
  static int alt = digitalRead(DCF);

  int jetzt = digitalRead(DCF);
  digitalWrite(LED, jetzt == LOW);
  unsigned long t = millis();
  if (alt == LOW) lowZeit += t - letzte;
  letzte = t;
  if (jetzt != alt) { wechsel++; alt = jetzt; }

  if (t - sekunde >= 1000) {
    sekunde = t;
    Serial.print(F("Pegel "));
    Serial.print(jetzt == HIGH ? F("HIGH") : F("LOW "));
    Serial.print(F("  Wechsel "));
    Serial.print(wechsel);
    Serial.print(F("  LOW "));
    Serial.print(lowZeit);
    Serial.println(F(" ms"));
    wechsel = 0;
    lowZeit = 0;
  }
}
