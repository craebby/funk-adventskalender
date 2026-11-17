// Tag 12: Der Morse-Uebersetzer
// Taster an Pin 3 (gegen GND) wie an Tag 4, rote LED an Pin 5, passiver Summer an Pin 9.
// Kurz druecken = Punkt, lang druecken = Strich. Kurze Pause = Buchstabe fertig.
// Der Arduino uebersetzt, was du tippst, im Seriellen Monitor (115200 Baud).
// Du musst Morse nicht koennen: Die Tabelle steht auf der Tagesseite.

const int TASTE = 3;
const int LED = 5;
const int SUMMER = 9;

const int LANG = 250;          // ab so vielen Millisekunden ist es ein Strich
const int BUCHSTABE_ENDE = 700; // so lange Pause, dann ist der Buchstabe fertig
const int WORT_ENDE = 1800;    // so lange Pause, dann kommt ein Leerzeichen

const char* CODES[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
  "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};
const char ZEICHEN[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

char zeichen[8];
int laenge = 0;
bool gedrueckt = false;
bool wortLuecke = true;
unsigned long seit = 0;

void buchstabeFertig() {
  zeichen[laenge] = 0;
  char erkannt = '?';
  for (int i = 0; i < 36; i++) {
    if (strcmp(zeichen, CODES[i]) == 0) erkannt = ZEICHEN[i];
  }
  Serial.print(erkannt);
  laenge = 0;
}

void setup() {
  pinMode(TASTE, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Morse-Uebersetzer bereit. Tipp los!");
}

void loop() {
  bool jetzt = digitalRead(TASTE) == LOW;
  unsigned long dauer = millis() - seit;

  if (jetzt && !gedrueckt) {                 // Taste geht runter
    gedrueckt = true;
    seit = millis();
    digitalWrite(LED, HIGH);
    tone(SUMMER, 700);
    wortLuecke = false;
  } else if (!jetzt && gedrueckt) {          // Taste geht hoch
    gedrueckt = false;
    digitalWrite(LED, LOW);
    noTone(SUMMER);
    if (dauer > 20 && laenge < 7) {          // kuerzer als 20 ms ist nur Prellen
      zeichen[laenge++] = (dauer < LANG) ? '.' : '-';
      Serial.print(zeichen[laenge - 1]);     // Punkt oder Strich gleich anzeigen
    }
    seit = millis();
  } else if (!gedrueckt) {
    if (laenge > 0 && dauer > BUCHSTABE_ENDE) {
      Serial.print(" = ");
      buchstabeFertig();
      Serial.println();
    }
    if (!wortLuecke && dauer > WORT_ENDE) {
      Serial.println("--- Pause ---");
      wortLuecke = true;
    }
  }
  delay(5);
}
