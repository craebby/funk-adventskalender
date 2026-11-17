// Tag 9: Der Kabelsucher
// Draht an A0 wie gestern. LED mit 220 Ohm an Pin 5, passiver Summer an Pin 9.
// Potentiometer: aeussere Beine an 5V und GND, mittleres Bein an A2. Damit stellst du die Empfindlichkeit ein.
// Den Draht an der Wand entlangfuehren: Wo eine Stromleitung liegt, piept es.
// Nur von aussen suchen! Nie in Steckdosen oder an offene Leitungen fassen.

const int ANTENNE = A0;
const int POTI = A2;
const int LED = 5;
const int SUMMER = 9;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // 40 ms lang messen (zwei volle Netzschwingungen) und Groesst- und Kleinstwert merken
  int hoch = 0, tief = 1023;
  unsigned long start = millis();
  while (millis() - start < 40) {
    int w = analogRead(ANTENNE);
    if (w > hoch) hoch = w;
    if (w < tief) tief = w;
  }
  int staerke = hoch - tief;                           // wie stark der 50-Hz-Brumm ist
  int schwelle = map(analogRead(POTI), 0, 1023, 10, 600);  // Poti nach links = empfindlicher
  Serial.print(staerke);
  Serial.print("  Schwelle ");
  Serial.println(schwelle);

  if (staerke > schwelle) {
    digitalWrite(LED, HIGH);
    tone(SUMMER, 400 + staerke);   // je staerker, desto hoeher
  } else {
    digitalWrite(LED, LOW);
    noTone(SUMMER);
  }
}
