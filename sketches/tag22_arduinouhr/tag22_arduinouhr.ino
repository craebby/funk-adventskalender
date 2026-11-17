// Tag 22: Wie falsch geht der Arduino?
// Keine neuen Teile. Serieller Monitor auf 115200 Baud.
// Auf time.is die genaue Zeit aufrufen. Genau zur vollen Minute den Reset-Knopf druecken.
// Der Arduino zaehlt ab dann mit. Nach einer Stunde (oder morgen frueh) vergleichen:
// Wie viele Sekunden liegt er daneben? Darum gibt es Funkuhren.

void setup() {
  Serial.begin(115200);
  Serial.println("Uhr gestartet. Zeit seit dem Reset:");
}

void loop() {
  static unsigned long letzte = 0;
  unsigned long sek = millis() / 1000;
  if (sek != letzte) {
    letzte = sek;
    unsigned long h = sek / 3600, m = (sek / 60) % 60, s = sek % 60;
    Serial.print(h);
    Serial.print(m < 10 ? ":0" : ":");
    Serial.print(m);
    Serial.print(s < 10 ? ":0" : ":");
    Serial.println(s);
  }
}
