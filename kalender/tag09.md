# 9. Dezember: Der Kabelsucher

**Heute neu:** Potentiometer (Drehknopf)

## Aufbau

Das Potentiometer mit den drei Beinen in **c2, c3, c4** (passen sie nicht, dann in 2, 4 und 6). a2 → linke +,
a4 → linke −, das mittlere Bein a3 → **A2**. Der Antennendraht von gestern bleibt in A0.

## Programm

[`tag09_kabelsucher.ino`](../sketches/tag09_kabelsucher/tag09_kabelsucher.ino)

## Was passiert

Führ den Draht langsam an der Wand entlang. Wo eine Stromleitung liegt, leuchtet die rote Kerze und der Summer
piept, je näher, desto höher. Mit dem Drehknopf stellst du ein, wie empfindlich er ist. Dreh ihn so, dass er in
der Luft gerade still ist.

## Probier mal

Such die Leitung vom Lichtschalter zur Deckenlampe. Läuft sie senkrecht nach oben? Profi-Leitungssucher machen
das genauso.

## Sicherheit

**Nur von außen suchen.** Nichts aufschrauben, nicht in Steckdosen stecken, nicht an kaputte Kabel.

## Übrigens

Das Potentiometer ist ein Widerstand mit Schleifer. Wie gestern teilt es die 5 Volt auf, je nachdem, wie weit du
drehst. Der Arduino liest das an A2 als Zahl und macht daraus die Schwelle, ab der es piept.
