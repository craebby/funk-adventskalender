// Tag 20: Die Weihnachtsfernbedienung (Empfaenger)
// Laeuft auf dem Nano im Steckbrett. Empfaenger an Pin 2, Kerzen-LEDs an Pin 5 und 6,
// passiver Summer an Pin 9.
// Fernbedienung: Uno mit Sketch tag18_fernbedienung, jetzt an der Powerbank.
// Taste 1 (Code 2412) schaltet die Kerzen an und aus, Taste 2 laesst die Glocke klingen.

#include <RCSwitch.h>

RCSwitch funk;
const int KERZE1 = 5, KERZE2 = 6;
const int SUMMER = 9;
bool kerzenAn = false;

void setup() {
  Serial.begin(115200);
  pinMode(KERZE1, OUTPUT);
  pinMode(KERZE2, OUTPUT);
  funk.enableReceive(0);
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
    Serial.println(code);
    if (code == 2412) {
      kerzenAn = !kerzenAn;
      delay(400);              // der Sender wiederholt den Code, Doppelte ignorieren
    }
    if (code == 2512) glocke();
    funk.resetAvailable();
  }
  if (kerzenAn) {
    analogWrite(KERZE1, random(80, 256));
    analogWrite(KERZE2, random(80, 256));
    delay(random(40, 120));
  } else {
    analogWrite(KERZE1, 0);
    analogWrite(KERZE2, 0);
  }
}
