// Tag 4: Licht per Knopfdruck
// Taster zwischen Pin 3 und GND. Kein Widerstand noetig, der Arduino hat einen eingebaut.
// LED mit 220 Ohm an Pin 5.

const int TASTER = 3;
const int LED = 5;
bool an = false;

void setup() {
  pinMode(TASTER, INPUT_PULLUP);  // ungedrueckt = HIGH, gedrueckt = LOW
  pinMode(LED, OUTPUT);
}

void loop() {
  if (digitalRead(TASTER) == LOW) {
    an = !an;                     // umschalten
    digitalWrite(LED, an);
    delay(250);                   // warten, bis der Finger wieder oben ist
    while (digitalRead(TASTER) == LOW) {}
  }
}
