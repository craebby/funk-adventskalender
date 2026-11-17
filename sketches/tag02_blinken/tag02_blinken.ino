// Tag 2: Die erste LED blinkt
// Rote LED mit 220 Ohm an Pin 5, kurzes Bein an GND.

const int LED = 5;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);  // an
  delay(500);               // eine halbe Sekunde warten
  digitalWrite(LED, LOW);   // aus
  delay(500);
}
