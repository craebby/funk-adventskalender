// Tag 20: Die Weihnachtsfernbedienung (Empfaenger)
// Laeuft auf dem Nano im Steckbrett. Empfaenger an Pin 2, Kerzen-LEDs an Pin 5, 6 und 7,
// passiver Summer an Pin 9. Bibliothek "rc-switch" (von sui77).
// Fernbedienung: Uno mit Sketch tag18_fernbedienung, jetzt an der Powerbank.
// Taste 1 (Code 2412) schaltet die Kerzen an und aus, Taste 2 laesst nach dem Gruss die Glocke klingen.

#include <RCSwitch.h>

RCSwitch funk;
const int KERZE1 = 5, KERZE2 = 6, KERZE3 = 7;
const int SUMMER = 9;
bool kerzenAn = false;
unsigned long zuletztGeschaltet = 0;   // der Sender wiederholt jeden Code, Doppelte ignorieren
unsigned long zuletztGeklingelt = 0;

void setup() {
  Serial.begin(115200);
  pinMode(KERZE1, OUTPUT);
  pinMode(KERZE2, OUTPUT);
  pinMode(KERZE3, OUTPUT);
  funk.enableReceive(0);
  Serial.println("Warte auf die Fernbedienung ...");
}

void glocke() {
  int toene[] = {784, 659, 784, 523};
  for (int i = 0; i < 4; i++) {
    tone(SUMMER, toene[i], 250);
    delay(300);
  }
}

void loop() {
  if (funk.available()) {
    unsigned long code = funk.getReceivedValue();
    funk.resetAvailable();
    if (code == 2412 && millis() - zuletztGeschaltet > 1000) {
      kerzenAn = !kerzenAn;
      zuletztGeschaltet = millis();
      Serial.println(kerzenAn ? "Taste 1: Kerzen an" : "Taste 1: Kerzen aus");
    } else if (code == 2512 && millis() - zuletztGeklingelt > 2000) {
      zuletztGeklingelt = millis();
      Serial.println("Taste 2: Glocke!");
      glocke();
    } else if (code >= 100000UL) {
      // Taste 2 funkt vorher einen Gruss, Buchstabe fuer Buchstabe. Den lesen wir morgen (Tag 21).
      Serial.print(".");
    }
  }
  if (kerzenAn) {
    analogWrite(KERZE1, random(80, 256));
    analogWrite(KERZE2, random(80, 256));
    digitalWrite(KERZE3, random(0, 4) > 0);
    delay(random(40, 120));
  } else {
    analogWrite(KERZE1, 0);
    analogWrite(KERZE2, 0);
    digitalWrite(KERZE3, LOW);
  }
}
