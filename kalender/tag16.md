# 16. Dezember: Eine Antenne bauen

**Heute neu:** zwei Drähte, je **17,3 cm**

## Aufbau

Zwei Stücke Draht genau 17,3 cm lang abschneiden. An beiden Enden 5 mm abisolieren (vorsichtig die Plastikhülle
einritzen und abziehen).

- **Empfänger:** Ein Draht durch das kleine Loch mit der Aufschrift **ANT**, ein paar Mal um sich selbst
  verdrillen, damit er hält.
- **Sender** (die kleinere, quadratische Platine, die du übermorgen brauchst): den zweiten Draht genauso durch sein
  ANT-Loch.

Kein Löten nötig. Gelötet hält es besser, aber verdrillt reicht.

## Programm

Wieder [`tag15_rauschen.ino`](../sketches/tag15_rauschen/tag15_rauschen.ino).

## Was passiert

Hör auf das Rauschen und schau in den Plotter, einmal ohne und einmal mit Antenne. Leg dein Handy daneben und ruf
jemanden an oder starte ein Video: Mit Antenne knattert das Handy deutlich ins Rauschen hinein.

Die Antenne bleibt ab jetzt dran. Morgen merkst du, wie viel sie bringt: Ohne sie hört der Empfänger nur ein
paar Meter weit, mit ihr die Funk-Thermometer der ganzen Nachbarschaft.

## Übrigens

Warum 17,3 cm? Eine Funkwelle bei 433 MHz ist von Berg zu Berg 69,2 cm lang. Antennen funktionieren besonders gut,
wenn sie ein Viertel davon lang sind. Funkamateure rechnen das ständig, für jedes Band eine andere Länge.

> 📻 **Funkamateur-Ecke:** 433 MHz liegt mitten im **70-cm-Band** der Funkamateure (430 bis 440 MHz). Dein Sender darf dort mit 10 Tausendstel Watt funken. Mit der Einsteigerlizenz **N** dürften Funkamateure auf demselben Band mit bis zu 10 Watt senden, tausendmal mehr, und mit Menschen sprechen statt nur Zahlen zu schicken.
