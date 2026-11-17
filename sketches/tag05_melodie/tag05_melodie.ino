// Tag 5: Jingle Bells
// Passiver Summer: Plus an Pin 9, Minus an GND.
// (Ein aktiver Summer piept nur in einer Tonhoehe. Fuer Melodien braucht es den passiven.)

const int SUMMER = 9;

// Toene in Hertz
const int C5 = 523, D5 = 587, E5 = 659, F5 = 698, G5 = 784;

const int melodie[] = {E5, E5, E5,  E5, E5, E5,  E5, G5, C5, D5, E5,
                       F5, F5, F5, F5,  F5, E5, E5, E5, E5,  E5, D5, D5, E5, D5, G5};
const int dauer[]   = {1, 1, 2,  1, 1, 2,  1, 1, 1, 1, 4,
                       1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 2, 2};
const int ANZAHL = sizeof(melodie) / sizeof(melodie[0]);

void setup() {
  for (int i = 0; i < ANZAHL; i++) {
    int ms = dauer[i] * 200;
    tone(SUMMER, melodie[i], ms * 0.9);
    delay(ms);
  }
}

void loop() {
  // einmal reicht. Reset-Knopf druecken fuer eine Zugabe.
}
