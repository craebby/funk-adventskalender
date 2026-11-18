# 14. Dezember: Zahlen per Licht

**Heute neu:** nichts.

## Aufbau

Die grüne Kerze (Reihe 16) vorsichtig umbiegen, bis ihr Kopf direkt auf den Fotowiderstand (Reihe 17/18) zeigt.
Ein kleines Röhrchen aus Papier über beide hält das Zimmerlicht ab.

## Programm

[`tag14_lichtfunk.ino`](../sketches/tag14_lichtfunk/tag14_lichtfunk.ino), Seriellen Monitor öffnen.

## Was passiert

Taster drücken: Der Arduino denkt sich eine Zahl von 1 bis 9 aus und blitzt sie mit der grünen LED. Der
Fotowiderstand zählt die Blitze mit. Im Monitor steht „Gesendet: 7, Empfangen: 7, Stimmt!“.

## Probier mal

- Röhrchen weg, Zimmerlicht an: Gibt es Fehler?
- Im Programm `delay(150)` und `delay(250)` kleiner machen. Wie schnell geht es, bevor Fehler kommen?

## Übrigens

An, aus, an, aus: Genau so funken ab morgen die 433-MHz-Module. Statt Licht schicken sie Funkwellen, aber das
Prinzip heißt in beiden Fällen „Ein-Aus-Tastung“. Fernbedienungen für den Fernseher machen es mit unsichtbarem
Infrarotlicht.
