# 8. Dezember: Die Luft ist voller Strom

**Heute neu:** ein Stück Draht, ca. 1 m (Klingeldraht, Litze oder mehrere Steckbrücken hintereinander)

Heute baust du deine erste Antenne. Sie besteht aus genau einem Draht.

## Aufbau

Ein Ende des Drahts in die Buchse **A0** am Uno stecken. Das andere Ende bleibt frei. Sonst nichts. Alles andere
auf dem Steckbrett darf stecken bleiben.

## Programm

[`tag08_offener_eingang.ino`](../sketches/tag08_offener_eingang/tag08_offener_eingang.ino), dann
**Werkzeuge → Serieller Plotter** öffnen (115200 Baud).

## Was passiert

Im Plotter tanzt eine Kurve. Halt das freie Ende in die Nähe eines Netzkabels, einer Lampe oder einer
Steckdosenleiste (nicht hinein!): Die Kurve wird zu einer schönen Welle. Zähl die Berge. Das Programm misst
genau eine Zehntelsekunde, also siehst du fünf Berge: 50 pro Sekunde.

## Probier mal

- Fass den Draht mit der Hand an. Was passiert?
- Halt ihn an den Fernseher, den Kühlschrank, das Handy-Ladegerät.

## Übrigens

Durch jedes Kabel im Haus fließt Wechselstrom, der 50-mal pro Sekunde die Richtung wechselt. Um das Kabel herum
entsteht ein elektrisches Feld, das genauso schwingt. Dein Draht fängt einen winzigen Teil davon auf. Genau das
macht jede Antenne: Sie fängt Schwingungen aus der Luft ein. Bei Radio und Handy sind es nur viel, viel schnellere.
