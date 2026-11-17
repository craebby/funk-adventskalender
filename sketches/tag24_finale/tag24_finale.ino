// Tag 24: Finale - der funkgesteuerte Weihnachtsbaum
// Nano im Steckbrett mit Empfaenger an Pin 2, drei Kerzen-LEDs an Pin 5, 6 und 7,
// passiver Summer an Pin 9, Fotowiderstand an A1 wie an Tag 6.
// Die Fernbedienung (Uno, Sketch tag18_fernbedienung) schaltet mit Taste 1 die Kerzen.
// Taste 2 schickt den Weihnachtsgruss (Serieller Monitor) und startet Jingle Bells.
// Wird es im Zimmer dunkel, gehen die Kerzen von selbst an.

#include <RCSwitch.h>

RCSwitch funk;
const int KERZE1 = 5, KERZE2 = 6, KERZE3 = 7;
const int SUMMER = 9;
const int LICHT = A1;
const int DUNKEL = 300;    // unter diesem Wert gilt der Raum als dunkel (Tag 6 hilft beim Einstellen)

bool perFunkAn = false;

const int C5 = 523, D5 = 587, E5 = 659, F5 = 698, G5 = 784;
const int melodie[] = {E5, E5, E5,  E5, E5, E5,  E5, G5, C5, D5, E5,
                       F5, F5, F5, F5,  F5, E5, E5, E5, E5,  E5, D5, D5, E5, D5, G5};
const int dauer[]   = {1, 1, 2,  1, 1, 2,  1, 1, 1, 1, 4,
                       1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 2, 2};

void kerzen(bool an) {
  if (an) {
    analogWrite(KERZE1, random(80, 256));
    analogWrite(KERZE2, random(80, 256));
    digitalWrite(KERZE3, random(0, 4) > 0);   // Pin 7 kann nicht dimmen, also flackert er an und aus
  } else {
    analogWrite(KERZE1, 0);
    analogWrite(KERZE2, 0);
    digitalWrite(KERZE3, LOW);
  }
}

void jingleBells() {
  for (unsigned int i = 0; i < sizeof(melodie) / sizeof(melodie[0]); i++) {
    int ms = dauer[i] * 200;
    tone(SUMMER, melodie[i], ms * 0.9);
    kerzen(true);
    delay(ms);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(KERZE1, OUTPUT);
  pinMode(KERZE2, OUTPUT);
  pinMode(KERZE3, OUTPUT);
  funk.enableReceive(0);
  Serial.println("Frohe Weihnachten! Warte auf die Fernbedienung ...");
}

void loop() {
  if (funk.available()) {
    unsigned long code = funk.getReceivedValue();
    funk.resetAvailable();
    if (code == 2412) { perFunkAn = !perFunkAn; delay(400); }
    if (code >= 100000UL) {                       // ein Buchstabe der Funk-Postkarte (Tag 21)
      static int letzte = -1;
      int position = (code - 100000UL) / 256;
      if (position != letzte) {
        if (position == 0) Serial.print("\nPost: ");
        Serial.print((char)((code - 100000UL) % 256));
        letzte = position;
      }
    }
    if (code == 2512) { Serial.println(); jingleBells(); }
  }
  bool dunkel = analogRead(LICHT) < DUNKEL;
  kerzen(perFunkAn || dunkel);
  delay(random(40, 120));
}
