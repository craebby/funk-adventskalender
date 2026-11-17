// Tag 3: Drei flackernde Kerzen
// LEDs mit je 220 Ohm an Pin 5, 6 und 7 (siehe Steckplan).
// Pin 5 und 6 koennen dimmen (Welle ~ neben der Zahl auf dem Uno), Pin 7 nur an und aus.

const int KERZE1 = 5, KERZE2 = 6, KERZE3 = 7;

void setup() {
  pinMode(KERZE1, OUTPUT);
  pinMode(KERZE2, OUTPUT);
  pinMode(KERZE3, OUTPUT);
}

void loop() {
  // Zufaellige Helligkeit zwischen 80 und 255 sieht aus wie eine Flamme
  analogWrite(KERZE1, random(80, 256));
  analogWrite(KERZE2, random(80, 256));
  // Pin 7 kann nicht dimmen, also flackert diese Kerze an und aus (meistens an)
  digitalWrite(KERZE3, random(0, 4) > 0);
  delay(random(40, 120));
}
