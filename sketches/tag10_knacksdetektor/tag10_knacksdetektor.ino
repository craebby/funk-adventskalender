// Tag 10: Der Knacks-Detektor
// Draht an A0, LED mit 220 Ohm an Pin 5, passiver Summer an Pin 9, Poti an A2 wie gestern.
// Licht an- und ausschalten, Wasserkocher ausschalten, Staubsauger einschalten:
// Jeder Funke im Schalter sendet einen kurzen Funkimpuls. Der Arduino hoert ihn als Knacks.
// Genauso orten Blitzdetektoren Gewitter, nur mit viel groesseren Funken.
// Knackt es dauernd, das Poti nach rechts drehen. Knackt es nie, nach links.

const int ANTENNE = A0;
const int POTI = A2;
const int LED = 5;
const int SUMMER = 9;

int vorher;
int zaehler = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  vorher = analogRead(ANTENNE);
}

void loop() {
  int sprung = map(analogRead(POTI), 0, 1023, 20, 600);   // so gross muss ein Sprung sein
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
