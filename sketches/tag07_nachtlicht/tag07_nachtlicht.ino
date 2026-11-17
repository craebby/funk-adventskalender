// Tag 7: Das Nachtlicht
// Fotowiderstand wie an Tag 6 (5V -> Fotowiderstand -> A1 -> 10 kOhm -> GND).
// Kerzen-LEDs mit je 220 Ohm an Pin 5 und 6.
// Wird es dunkel (Hand drueber, Licht aus), gehen die Kerzen an.
// Im Seriellen Monitor siehst du die Helligkeit. Damit stellst du DUNKEL passend ein.

const int LICHT = A1;
const int KERZE1 = 5, KERZE2 = 6;
const int DUNKEL = 300;   // unter diesem Wert ist es "dunkel"

void setup() {
  Serial.begin(115200);
}

void loop() {
  int hell = analogRead(LICHT);
  Serial.println(hell);
  if (hell < DUNKEL) {
    analogWrite(KERZE1, random(80, 256));
    analogWrite(KERZE2, random(80, 256));
  } else {
    analogWrite(KERZE1, 0);
    analogWrite(KERZE2, 0);
  }
  delay(random(40, 120));
}
