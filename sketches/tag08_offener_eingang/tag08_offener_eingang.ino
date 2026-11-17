// Tag 8: Die Luft ist voller Strom
// Ein Draht (ca. 30 cm) an A0, das andere Ende frei. Sonst nichts.
// Serieller Plotter (115200 Baud). Hand naehern, Draht anfassen, an ein Netzkabel halten:
// Die Welle, die du siehst, ist das Stromnetz mit 50 Hz.

const int ANTENNE = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int werte[200];
  for (int i = 0; i < 200; i++) {
    werte[i] = analogRead(ANTENNE);
    delayMicroseconds(400);   // 200 Messungen = etwa 0,1 s = 5 Schwingungen bei 50 Hz
  }
  for (int i = 0; i < 200; i++) Serial.println(werte[i]);
  delay(300);
}
