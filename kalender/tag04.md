# 4. Dezember: Licht per Knopf

**Heute neu:** ein Taster

## Aufbau

1. Den Taster über den Graben setzen, die vier Beine in **e20, e22, f20, f22**.
2. Eine Steckbrücke von **Pin 3** am Uno nach **a20**.
3. Eine kurze Steckbrücke von **a22** in die linke blaue **−**-Schiene. Ohne sie passiert beim Drücken nichts!

Der Stromweg: Pin 3 → Reihe 20 → durch den gedrückten Taster → Reihe 22 → Minus.

## Programm

[`tag04_taster.ino`](../sketches/tag04_taster/tag04_taster.ino)

## Was passiert

Ein Druck: Die rote Kerze geht an. Noch ein Druck: aus. Der Arduino merkt sich in `an`, wie der Stand ist.

## Probier mal

Ändere das Programm so, dass die Kerze nur leuchtet, **solange** du drückst. (Tipp: Die Zeile
`digitalWrite(LED, digitalRead(TASTER) == LOW);` in `loop()` reicht.)

## Übrigens

`INPUT_PULLUP` schaltet im Arduino einen Widerstand zu, der den Pin auf 5V zieht. Drückst du, verbindet der Taster
den Pin mit GND und er fällt auf 0. Deshalb heißt „gedrückt“ im Programm `LOW`.

## Klappt nicht?

Leuchtet die Kerze dauernd oder reagiert gar nicht, den Taster um 90 Grad drehen. Bei diesen Tastern sind immer
zwei Beine fest verbunden, und es ist nicht immer klar, welche.
