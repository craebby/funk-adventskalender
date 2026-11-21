# 15. Dezember: So klingt Funkstille

**Heute neu:** 433-MHz-Empfänger (die längere der beiden kleinen Platinen)

Willkommen in der Funkwoche!

## Aufbau

Den Empfänger mit seinen vier Stiften in **c24, c25, c26, c27**. Lies die Beschriftung: meist VCC, DATA, DATA, GND.
- a24 (VCC) → linke +
- a25 (DATA) → **Pin 2**
- a27 (GND) → linke −

Die Kerze von gestern darfst du wieder geradebiegen.

## Programm

[`tag15_rauschen.ino`](../sketches/tag15_rauschen/tag15_rauschen.ino)

## Was passiert

Es rauscht. Der Summer gibt direkt wieder, was der Empfänger hört, und das ist: nichts, nur Rauschen. Im
Seriellen Plotter siehst du, wie oft der Empfänger pro Zehntelsekunde zwischen 0 und 1 springt. Bei reinem
Rauschen sind das ein paar Hundert Mal, die Zahl zappelt etwa zwischen 250 und 450.

## Übrigens

So ein Empfänger ist eitel: Wenn keiner sendet, dreht er seine Verstärkung so lange hoch, bis er wenigstens das
Rauschen hört. Sobald ein richtiges Signal kommt, wird er still und gibt es sauber wieder. Das Rauschen entsteht
zum größten Teil im Empfänger selbst: Jedes warme Bauteil zappelt ein bisschen elektrisch.

## Bonus: Rauschen in einem großen Empfänger

Auch ein richtiger Funkempfänger rauscht. Öffne **websdr.ewi.utwente.nl:8901**, das ist ein Empfänger an der
Universität Twente in den Niederlanden, den jeder übers Internet bedienen darf. Wähle **AM** und klick im
**Wasserfall** (dem bunten Bild oben) auf eine dunkle Stelle zwischen zwei hellen Streifen. Dort sendet niemand,
und du hörst dasselbe Rauschen wie bei deinem Empfänger. Im Wasserfall sieht es aus wie graues Gekrissel.
Klickst du auf einen hellen Streifen, wird es still, und ein Sender ist da. Genau wie bei dir.

## Klappt nicht?

Steht auf dem kleinen silbernen Bauteil des Empfängers **433**? Es gibt baugleiche Module für 315 MHz.
