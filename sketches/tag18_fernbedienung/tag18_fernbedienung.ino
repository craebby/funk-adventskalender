// Tag 18 bis 24: Die Weihnachtsfernbedienung (Sender)
// Laeuft auf dem grossen Arduino Uno, ganz ohne Steckbrett.
// Bibliothek "rc-switch" (von sui77) ueber den Bibliotheksverwalter installieren.
// 433-MHz-Sender mit drei Buchse-Stecker-Kabeln direkt an den Uno:
//   VCC an 5V, GND an GND, DATA an Pin 10. Antenne 17,3 cm durch das Loch ANT.
// Zwei Drahttaster: je eine Steckbruecke in Pin 3 und Pin 4, eine dritte in GND.
//   Das Ende von Pin 3 kurz an das GND-Kabel tippen = Taste 1, Pin 4 an GND = Taste 2.
// Strom: per USB vom PC, ab Tag 20 von einer Powerbank oder einem Handy-Ladegeraet.
//
// Taste 1: Code 2412 (Kerzen an/aus)
// Taste 2: funkt einen Weihnachtsgruss Buchstabe fuer Buchstabe, danach Code 2512 (Musik)

#include <RCSwitch.h>

RCSwitch funk;
const int TASTER1 = 3;
const int TASTER2 = 4;
const char GRUSS[] = "FROHE WEIHNACHTEN!";   // hier darf ein eigener Gruss stehen (ohne Umlaute)

void setup() {
  pinMode(TASTER1, INPUT_PULLUP);
  pinMode(TASTER2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  funk.enableTransmit(10);
  funk.setRepeatTransmit(6);
}

void sende(unsigned long code) {
  digitalWrite(LED_BUILTIN, HIGH);   // die kleine LED "L" auf dem Uno zeigt: Ich funke
  funk.send(code, 24);
  digitalWrite(LED_BUILTIN, LOW);
}

void sendeGruss() {
  // Jeder Buchstabe bekommt seine Nummer dazu, damit der Empfaenger Wiederholungen erkennt:
  // Code = 100000 + Position * 256 + Buchstabe
  for (unsigned int i = 0; i < strlen(GRUSS); i++) {
    sende(100000UL + i * 256UL + (unsigned char)GRUSS[i]);
    delay(80);
  }
  sende(2512);
}

void loop() {
  if (digitalRead(TASTER1) == LOW) { sende(2412); delay(300); }
  if (digitalRead(TASTER2) == LOW) { sendeGruss(); delay(300); }
}
