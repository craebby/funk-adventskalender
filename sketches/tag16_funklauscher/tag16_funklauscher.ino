// Tag 16: Wer funkt denn hier?
// Bibliothek "rc-switch" (von sui77) ueber den Bibliotheksverwalter installieren.
// Empfaenger wie gestern an Pin 2. Serieller Monitor auf 115200 Baud.
// Laeuft auf dem Uno (Tag 16) und ab Tag 18 genauso auf dem Nano, gleiche Pins.
// Druecke die Fernbedienung einer Funksteckdose oder eine Funk-Tuerklingel:
// Der Arduino zeigt den Code, den sie sendet.
// Manche Wettersensoren und Garagentore funken in einem Format, das rc-switch nicht kennt.
// Die tauchen dann nicht auf, das ist normal.

#include <RCSwitch.h>

RCSwitch funk;

void setup() {
  Serial.begin(115200);
  funk.enableReceive(0);   // 0 heisst: Pin 2 beim Uno und Nano
  Serial.println("Ich lausche auf 433 MHz ...");
}

void loop() {
  if (funk.available()) {
    Serial.print("Empfangen: Code ");
    Serial.print(funk.getReceivedValue());
    Serial.print("  (");
    Serial.print(funk.getReceivedBitlength());
    Serial.print(" Bit, Protokoll ");
    Serial.print(funk.getReceivedProtocol());
    Serial.println(")");
    funk.resetAvailable();
  }
}
