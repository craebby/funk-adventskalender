# 2. Dezember: Die erste LED blinkt

**Heute neu:** nichts, nur die Arduino-IDE (siehe [Vorbereitung](00_vorbereitung.md))

Gestern hat der Uno einfach Strom geliefert. Heute sagt ihm ein Programm, wann.

## Aufbau

Nur eine Änderung: Die Steckbrücke, die von **+** nach **a10** geht, steckst du am Uno-Ende jetzt in **Pin 5**
statt in die +-Schiene.

## Programm

[`tag02_blinken.ino`](../sketches/tag02_blinken/tag02_blinken.ino) kopieren und hochladen.

## Was passiert

Die LED blinkt: eine halbe Sekunde an, eine halbe Sekunde aus. `digitalWrite(LED, HIGH)` schaltet Pin 5 auf
5 Volt, `LOW` auf 0 Volt. `delay(500)` wartet 500 Millisekunden.

## Probier mal

- Ändere beide `500` in `100`. Schneller!
- Und in `20`? Ab etwa 50 Mal pro Sekunde sieht dein Auge kein Blinken mehr, nur noch Leuchten. Merk dir das,
  am 7. Dezember braucht man es.
- Morse ein SOS: kurz-kurz-kurz, lang-lang-lang, kurz-kurz-kurz.

## Übrigens

Ein Programm für den Arduino heißt „Sketch“, also Skizze. `setup()` läuft einmal beim Start, `loop()` immer
wieder, solange Strom da ist.

## Klappt nicht?

Steht unten „Hochladen abgeschlossen“? Wenn nicht: Port unter Werkzeuge prüfen. Wenn ja, aber nichts blinkt:
Steckt die Brücke wirklich in Pin 5 (nicht in 5V)?
