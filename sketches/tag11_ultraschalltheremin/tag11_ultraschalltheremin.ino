// Tag 11: Das Ultraschall-Theremin
// Ultraschall-Sensor HC-SR04: VCC an 5V, GND an GND, Trig an Pin 4, Echo an Pin 8.
// Passiver Summer an Pin 9.
// Der Sensor ruft unhoerbar hohe Toene (40 kHz) und lauscht auf das Echo, wie eine Fledermaus.
// Die Hand ueber dem Sensor auf und ab bewegen: Je naeher, desto hoeher der Ton.

const int TRIG = 4;
const int ECHO = 8;
const int SUMMER = 9;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(TRIG, HIGH);                  // kurzer Ruf
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long echo = pulseIn(ECHO, HIGH, 30000);    // wie lange bis das Echo zurueck ist (Mikrosekunden)
  int cm = echo / 58;                        // Schall braucht 58 us fuer 1 cm hin und zurueck
  Serial.println(cm);

  if (cm > 2 && cm < 40) {
    tone(SUMMER, map(cm, 2, 40, 1500, 150));
  } else {
    noTone(SUMMER);                          // Hand weg: Ruhe
  }
  delay(30);
}
