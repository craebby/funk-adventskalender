// Uebrigens zu Tag 7: Das unsichtbare Flackern (Fotowiderstand evtl. zu traege, ausprobieren!)
// Aufbau wie Tag 6 (Fotowiderstand an A1), Summer abziehen.
// Werkzeuge -> Serieller Plotter oeffnen (115200 Baud).
// Den Fotowiderstand unter eine Lampe halten: Viele LED-Lampen flackern 100-mal pro Sekunde.

const int LICHT = A1;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // 200 Messungen sehr schnell hintereinander, dann ausgeben
  int werte[200];
  for (int i = 0; i < 200; i++) {
    werte[i] = analogRead(LICHT);
    delayMicroseconds(400);   // ungefaehr 2000 Messungen pro Sekunde
  }
  for (int i = 0; i < 200; i++) Serial.println(werte[i]);
  delay(300);
}
