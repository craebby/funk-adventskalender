// Tag 3: Drei flackernde Kerzen
// LEDs mit je 220 Ohm an Pin 5, 6 und 11 (diese Pins koennen "dimmen").

const int KERZEN[] = {5, 6, 11};

void setup() {
  for (int i = 0; i < 3; i++) pinMode(KERZEN[i], OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    // Zufaellige Helligkeit zwischen 80 und 255 sieht aus wie eine Flamme
    analogWrite(KERZEN[i], random(80, 256));
  }
  delay(random(40, 120));
}
