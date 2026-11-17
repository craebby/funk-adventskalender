// Tag 6: Licht-Theremin
// Fotowiderstand von 5V nach A1, 10 kOhm von A1 nach GND.
// Passiver Summer an Pin 9.
// Hand ueber den Fotowiderstand halten: Je dunkler, desto tiefer der Ton.

const int LICHT = A1;
const int SUMMER = 9;

void setup() {}

void loop() {
  int hell = analogRead(LICHT);                  // 0 (dunkel) bis 1023 (hell)
  int frequenz = map(hell, 0, 1023, 150, 1500);  // in einen Ton umrechnen
  tone(SUMMER, frequenz);
  delay(10);
}
