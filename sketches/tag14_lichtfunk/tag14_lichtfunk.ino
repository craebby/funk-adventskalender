// Tag 14: Zahlen per Licht schicken
// Sender: weisse oder rote LED mit 220 Ohm an Pin 5.
// Empfaenger: Fotowiderstand an A1 wie an Tag 6, direkt gegenueber der LED (1-2 cm).
// Taster an Pin 3: Jeder Druck schickt eine zufaellige Zahl von 1 bis 9 als Lichtblitze.
// Der Empfaenger zaehlt die Blitze und zeigt das Ergebnis im Seriellen Monitor.
// So funktionieren auch Fernbedienungen und die 433-MHz-Module ab Tag 15: an, aus, an, aus.

const int LED = 5;
const int LICHT = A1;
const int TASTER = 3;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(TASTER, INPUT_PULLUP);
  Serial.begin(115200);
  randomSeed(analogRead(A0));
  Serial.println("Taster druecken zum Senden.");
}

int schwelle() {
  // Mitte zwischen LED aus und LED an messen
  digitalWrite(LED, LOW);  delay(50); int aus = analogRead(LICHT);
  digitalWrite(LED, HIGH); delay(50); int an  = analogRead(LICHT);
  digitalWrite(LED, LOW);  delay(50);
  return (aus + an) / 2;
}

void loop() {
  if (digitalRead(TASTER) == HIGH) return;
  int s = schwelle();
  int zahl = random(1, 10);
  Serial.print("Gesendet: ");
  Serial.println(zahl);

  int gezaehlt = 0;
  for (int i = 0; i < zahl; i++) {
    digitalWrite(LED, HIGH);
    delay(150);                              // der Fotowiderstand ist etwas traege
    if (analogRead(LICHT) > s) gezaehlt++;   // Empfaenger schaut, ob es hell ist
    digitalWrite(LED, LOW);
    delay(250);
  }
  Serial.print("Empfangen: ");
  Serial.println(gezaehlt);
  Serial.println(gezaehlt == zahl ? "Stimmt!" : "Uebertragungsfehler - LED und Fotowiderstand naeher zusammen?");
  delay(500);
}
