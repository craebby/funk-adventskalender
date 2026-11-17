// Tag 21: Die Funk-Postkarte (Empfaenger)
// Nano mit 433-MHz-Empfaenger an Pin 2, per USB am PC. Serieller Monitor auf 115200 Baud.
// Am Uno (Fernbedienung) Taste 2 tippen: Der Gruss kommt Buchstabe fuer Buchstabe an.
// Genau so reisen auch SMS und WLAN-Daten: als lauter kleine Zahlen.

#include <RCSwitch.h>

RCSwitch funk;
int letztePosition = -1;

void setup() {
  Serial.begin(115200);
  funk.enableReceive(0);   // Pin 2
  Serial.println("Warte auf Post ...");
}

void loop() {
  if (!funk.available()) return;
  unsigned long code = funk.getReceivedValue();
  funk.resetAvailable();

  if (code >= 100000UL) {
    int position = (code - 100000UL) / 256;
    char buchstabe = (code - 100000UL) % 256;
    if (position == letztePosition) return;     // Wiederholung, schon gezeigt
    if (position == 0) Serial.print("\nPost: ");
    if (position > letztePosition + 1 && letztePosition >= 0) Serial.print("?");  // etwas verloren
    Serial.print(buchstabe);
    letztePosition = position;
  } else if (code == 2512) {
    Serial.println("   (Ende der Nachricht)");
    letztePosition = -1;
  }
}
