// Tag 8: Die Luft ist voller Strom
// Eine kurze Steckbruecke (10-20 cm) an A0, das andere Ende frei. Ein langer Draht uebersteuert!
// Serieller Plotter (115200 Baud). Zwei Linien:
//   Welle   = was der Draht gerade auffaengt (bei 50 Hz: 8 Punkte pro Berg)
//   Staerke = wie gross die Welle ist. Je hoeher, desto mehr Strom in der Luft.
// Finger von der Seite naehern, Isolierung beruehren, Spitze antippen: auf Staerke achten.

const int ANTENNE = A0;
const int ANZAHL = 20;          // Staerke ueber die letzten 20 Messungen (50 ms)

int werte[ANZAHL];
int pos = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long start = micros();

  werte[pos] = analogRead(ANTENNE);
  pos = (pos + 1) % ANZAHL;

  int klein = 1023, gross = 0;
  for (int i = 0; i < ANZAHL; i++) {
    if (werte[i] < klein) klein = werte[i];
    if (werte[i] > gross) gross = werte[i];
  }

  Serial.print("Welle:");
  Serial.print(werte[(pos + ANZAHL - 1) % ANZAHL]);
  Serial.print(",Staerke:");
  Serial.println(gross - klein);

  while (micros() - start < 2500) { }   // 400 Messungen pro Sekunde
}
