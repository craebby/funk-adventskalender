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
Seriellen Plotter siehst du, wie oft der Empfänger pro Zehntelsekunde zwischen 0 und 1 springt.

## Übrigens

So ein Empfänger ist eitel: Wenn keiner sendet, dreht er seine Verstärkung so lange hoch, bis er wenigstens das
Rauschen hört. Sobald ein richtiges Signal kommt, wird er still und gibt es sauber wieder. Das Rauschen entsteht
zum größten Teil im Empfänger selbst: Jedes warme Bauteil zappelt ein bisschen elektrisch.

## Klappt nicht?

Steht auf dem kleinen silbernen Bauteil des Empfängers **433**? Es gibt baugleiche Module für 315 MHz.
