// Tag 10: Der Knacks-Detektor
// Draht ca. 50 cm an A0, LED mit 220 Ohm an Pin 5, passiver Summer an Pin 9, Poti an A2 wie gestern.
// Schreibtischlampe oder Steckdosenleiste mit Schalter neben dem Draht schalten:
// Jeder Funke im Schalter sendet einen kurzen Funkimpuls. Der Arduino hoert ihn als Knacks.
// Genauso orten Blitzdetektoren Gewitter, nur mit viel groesseren Funken.
// Erst das Poti so weit nach rechts drehen, dass es in Ruhe fast nie knackt.

const int ANTENNE = A0;
const int POTI = A2;
const int LED = 5;
const int SUMMER = 9;

int vorher;
int zaehler = 0;
int sprung = 100;
unsigned long zuletztPoti = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  vorher = analogRead(ANTENNE);
}

void loop() {
  // Poti nur alle 100 ms lesen. Danach haengt seine Spannung im Arduino noch nach,
  // darum die naechsten Antennen-Messungen verwerfen.
  if (millis() - zuletztPoti > 100) {
    sprung = map(analogRead(POTI), 0, 1023, 20, 600);   // so gross muss ein Sprung sein
    for (int i = 0; i < 5; i++) vorher = analogRead(ANTENNE);
    zuletztPoti = millis();
  }
  int jetzt = analogRead(ANTENNE);
  if (abs(jetzt - vorher) > sprung) {
    zaehler++;
    Serial.print("Knacks Nr. ");
    Serial.println(zaehler);
    digitalWrite(LED, HIGH);
    tone(SUMMER, 2000, 30);
    delay(80);
    digitalWrite(LED, LOW);
    jetzt = analogRead(ANTENNE);
  }
  vorher = jetzt;
}
