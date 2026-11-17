// Tag 15: So klingt Funkstille
// 433-MHz-Empfaenger (XY-MK-5V): VCC an 5V, GND an GND, DATA an Pin 2.
// Passiver Summer an Pin 9.
// Der Empfaenger regelt sich so empfindlich, dass er ohne Sender das Rauschen hoert.
// Der Summer gibt es direkt wieder. Serieller Plotter zeigt es als Zappeln.

const int DATEN = 2;
const int SUMMER = 9;

void setup() {
  pinMode(DATEN, INPUT);
  pinMode(SUMMER, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long start = millis();
  int wechsel = 0;
  int vorher = digitalRead(DATEN);
  while (millis() - start < 100) {
    int jetzt = digitalRead(DATEN);
    digitalWrite(SUMMER, jetzt);      // jeden Pegel direkt auf den Summer geben
    if (jetzt != vorher) wechsel++;
    vorher = jetzt;
  }
  Serial.println(wechsel);            // Wechsel pro 0,1 s: viel = Rauschen
}
