# 4. Dezember: Licht per Knopf

**Heute neu:** ein Taster

## Aufbau

1. Den Taster über den Graben setzen, die vier Beine in **e20, e22, f20, f22**. Ist dein Taster breiter, sitzen
   die Beine eben in **d20, d22, g20, g22**. Das ist egal, denn a bis e einer Reihe sind ohnehin verbunden.
2. Eine Steckbrücke von **Pin 3** am Uno nach **a20**.
3. Eine kurze Steckbrücke von **a22** in die linke blaue **−**-Schiene. Ohne sie passiert beim Drücken nichts!

Der Stromweg: Pin 3 → Reihe 20 → durch den gedrückten Taster → Reihe 22 → Minus.

## So funktioniert der Taster

Der Taster hat vier Beine, aber eigentlich nur zwei Anschlüsse:

- **Die zwei weit auseinanderliegenden Beine** (links und rechts, über den Graben hinweg) sind **immer
  verbunden**, auch ohne Drücken. Im Steckbild zeigt das die graue Linie.
- **Die zwei nah beieinanderliegenden Beine** (oben und unten, Reihe 20 und Reihe 22) werden erst **beim
  Drücken** verbunden. Im Steckbild ist das die gestrichelte Linie.

Darum gehört der Taster so aufs Brett, dass die weiten Beine über dem Graben stehen. Meist passt er ohnehin nur in
dieser Richtung bequem. Dreh ihn nicht um 90 Grad, sonst ist Reihe 20 dauernd mit Reihe 22 verbunden, und
der Arduino denkt, du drückst die ganze Zeit.

**Unsicher?** Schau unter den Taster: Oft sieht man, welche Beine innen zusammenhängen. Oder steck ihn testweise
zwischen LED und Widerstand von Tag 1. Leuchtet die LED nur beim Drücken, sitzt er richtig.

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

Leuchtet die Kerze dauernd oder reagiert gar nicht, den Taster um 90 Grad drehen (siehe „So funktioniert der
Taster“). Und prüfen, ob die kurze Brücke von a22 wirklich in der blauen **−**-Schiene steckt.
