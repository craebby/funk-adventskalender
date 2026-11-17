# 5. Dezember: Jingle Bells

**Heute neu:** passiver und aktiver Summer

Im Kit liegen zwei Summer, die fast gleich aussehen. Dreh sie um: Beim **passiven** siehst du unten eine grüne
Platine, der **aktive** ist unten schwarz vergossen und hat oft einen Aufkleber.

## Aufbau

Den **passiven** Summer quer stecken: das längere Bein (+) in **i25**, das kürzere direkt in die rechte blaue
**−**-Schiene in derselben Reihe. Das Gehäuse liegt dann über dem Rand des Steckbretts und verdeckt nichts. Dazu eine
Steckbrücke von **Pin 9** nach **f25**.

## Programm

[`tag05_melodie.ino`](../sketches/tag05_melodie/tag05_melodie.ino)

## Was passiert

Jingle Bells, einmal. Für eine Zugabe den Reset-Knopf auf dem Uno drücken.

## Probier mal

Steck jetzt den **aktiven** Summer an dieselbe Stelle und drück Reset. Er schnarrt nur in einer Tonhöhe. Der aktive
hat einen eigenen Tongeber eingebaut und piept, sobald Strom fließt. Der passive ist nur eine Membran, die genau so
schnell schwingt, wie der Arduino sie anschubst. Danach wieder den passiven einstecken, den brauchst du noch oft.

## Übrigens

`tone(SUMMER, 659)` lässt Pin 9 659-mal pro Sekunde an- und ausgehen. Das ist der Ton E. 659 Schwingungen pro
Sekunde heißen 659 Hertz (Hz). Diese Einheit begegnet dir im Kalender noch oft, auch bei Funk.
