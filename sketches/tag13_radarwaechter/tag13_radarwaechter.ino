// Tag 13: Der Radar-Waechter
// Ultraschall-Sensor wie an Tag 11: Trig an Pin 4, Echo an Pin 8. Rote LED an Pin 5, passiver Summer an Pin 9.
// Beim Start misst der Sensor, wie weit die Wand oder Tuer gegenueber ist. Laeuft jemand dazwischen,
// piept es und der Arduino zaehlt mit. Seriellen Monitor oeffnen (115200 Baud).

const int TRIG = 4;
const int ECHO = 8;
const int LED = 5;
const int SUMMER = 9;

int frei;               // Abstand, wenn niemand da ist
int besuche = 0;
bool jemandDa = false;

int messen() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long echo = pulseIn(ECHO, HIGH, 30000);
  if (echo == 0) return 500;           // kein Echo: sehr weit weg
  return echo / 58;
}

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Bitte aus dem Weg gehen, ich messe den Raum ...");
  delay(2000);
  long summe = 0;
  for (int i = 0; i < 10; i++) { summe += messen(); delay(60); }
  frei = summe / 10;
  Serial.print("Freie Strecke: ");
  Serial.print(frei);
  Serial.println(" cm. Wache aktiv!");
  tone(SUMMER, 1000, 100);
}

void loop() {
  int cm = messen();
  bool jetztDa = cm < frei - 20;       // 20 cm naeher als die Wand = da ist jemand

  if (jetztDa && !jemandDa) {
    besuche++;
    Serial.print("Besuch Nr. ");
    Serial.print(besuche);
    Serial.print(" in ");
    Serial.print(cm);
    Serial.print(" cm Entfernung, nach ");
    Serial.print(millis() / 1000);
    Serial.println(" Sekunden");
    digitalWrite(LED, HIGH);
    tone(SUMMER, 1500, 150);
  }
  if (!jetztDa && jemandDa) digitalWrite(LED, LOW);
  jemandDa = jetztDa;
  delay(60);
}
