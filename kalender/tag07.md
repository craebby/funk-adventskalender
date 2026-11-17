# 7. Dezember: Das Nachtlicht

**Heute neu:** nichts

## Aufbau

Alles bleibt. Den Summer darfst du drinlassen, er bleibt heute still.

## Programm

[`tag07_nachtlicht.ino`](../sketches/tag07_nachtlicht/tag07_nachtlicht.ino)

## Was passiert

Hand über den Fotowiderstand oder Licht aus: Die Kerzen flackern los. Licht an: Sie gehen aus. Im Seriellen
Monitor (115200 Baud) siehst du die Helligkeit als Zahl.

## Probier mal

Im Programm steht `DUNKEL = 300`. Schau im Monitor, welche Zahl bei Zimmerlicht kommt und welche, wenn du die Hand
drüberhältst. Stell `DUNKEL` genau dazwischen. Das brauchst du an Heiligabend wieder.

## Übrigens für Neugierige

Viele LED-Lampen flackern, 100-mal pro Sekunde, viel zu schnell für das Auge (erinnerst du dich an Tag 2?). Mit
[`uebrigens_lampenflackern.ino`](../sketches/uebrigens_lampenflackern/uebrigens_lampenflackern.ino) und dem
Seriellen Plotter kannst du versuchen, das sichtbar zu machen. Ob der Fotowiderstand dafür schnell genug ist,
hängt von der Lampe ab. **(prüfen)**
