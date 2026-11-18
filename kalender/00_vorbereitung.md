# Bevor es losgeht

Schön, dass du dabei bist! In den nächsten 24 Tagen machst du Dinge hör- und sichtbar, die sonst unsichtbar um
dich herum passieren: den Strom in der Luft, Funken beim Lichtschalten, Ultraschall und echte Funksignale. Am
Heiligabend steuerst du deinen eigenen Weihnachtsbaum per Funk.

Du brauchst kein Vorwissen. Jeder Tag dauert 15 bis 30 Minuten. Die Programme (Sketches) bekommst du fertig, du
musst sie nur kopieren und hochladen.

## Einmal einrichten (ca. 15 Minuten)

1. **Arduino-IDE installieren.** Kostenlos auf arduino.cc unter „Software“. Für Windows, Mac und Linux.
2. **Uno anstecken.** USB-Kabel aus dem Kit in den Uno und in den Computer. Die grüne LED „ON“ leuchtet.
3. **Board auswählen.** In der IDE oben im Auswahlfeld „Arduino Uno“ und den angebotenen Anschluss wählen
   (Windows: COM3 oder ähnlich, Mac/Linux: etwas mit „usb“ oder „ttyACM“).
4. **Testen.** Datei → Beispiele → 01.Basics → Blink öffnen und auf den Pfeil (Hochladen) klicken. Die kleine
   LED „L“ auf dem Uno blinkt. Geschafft.

## Wie du jeden Tag arbeitest

- **Aufbauen** nach der Anleitung des Tages. Immer erst den USB-Stecker ziehen, dann umstecken, dann wieder
  einstecken.
- **Sketch öffnen:** Den Code des Tages kopieren, in der IDE Datei → Neu, alles markieren und ersetzen.
- **Hochladen:** auf den Pfeil klicken. Unten steht „Hochladen abgeschlossen“.
- **Serieller Monitor** (Lupe oben rechts): Hier schreibt der Arduino Text. Unten rechts **115200 Baud**
  einstellen, sonst siehst du nur Zeichensalat.
- **Serieller Plotter** (Werkzeuge → Serieller Plotter): Zeigt Zahlen als Kurve. Ab Tag 8 dein Oszilloskop.
- **Bibliotheken** (ab Tag 17): Werkzeuge → Bibliotheken verwalten, den Namen eintippen, „Installieren“.

## Unterwegs ohne PC

Ein hochgeladener Sketch bleibt im Arduino gespeichert. Für die Tage, an denen du durchs Haus gehst (ab Tag 9),
steckst du das USB-Kabel nach dem Hochladen einfach an eine Powerbank oder ein Handy-Ladegerät. Nur den Seriellen
Monitor und Plotter gibt es dann nicht, LEDs und Summer funktionieren weiter.

## Sicherheit

Auf deinem Steckbrett gibt es nur die 5 Volt aus dem USB-Kabel. Das ist völlig ungefährlich. Mit 230 Volt aus
der Steckdose arbeitest du nie. An ein paar Tagen hältst du einen Draht **in die Nähe** von Kabeln und Wänden,
aber nie hinein. Nichts aufschrauben, nicht in Steckdosen fassen, keine kaputten Kabel.

## Das Steckbrett

Schau dir einmal den [Steckplan](steckplan.md) an. Dort steht, wo jedes Teil im ganzen Monat seinen Platz hat.
Kurz gesagt: In einer Reihe sind die fünf Löcher a–e verbunden, und die fünf Löcher f–j. Dazwischen ist ein
Graben. Die langen Schienen am Rand sind Plus (rot) und Minus (blau).

## Wenn etwas nicht klappt

- **LED bleibt dunkel:** umdrehen. Das lange Bein muss zur Seite mit dem Strom, das kurze zum Minus.
- **„Port nicht gefunden“ oder Hochladen schlägt fehl:** anderes USB-Kabel probieren (manche können nur laden)
  und unter Werkzeuge → Port den richtigen auswählen.
- **Zeichensalat im Monitor:** 115200 Baud einstellen.
- **Irgendwas riecht oder wird heiß:** sofort USB abziehen und die Verkabelung prüfen. Meist stecken 5V und GND
  direkt zusammen.
