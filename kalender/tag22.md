# 22. Dezember: Wie falsch geht der Arduino?

**Heute neu:** nichts

## Programm

[`tag22_arduinouhr.ino`](../sketches/tag22_arduinouhr/tag22_arduinouhr.ino) auf den Nano oder den Uno, Seriellen
Monitor öffnen.

## Experiment

1. Im Browser **time.is** öffnen. Das ist die genaue Zeit.
2. Genau beim Sprung auf eine volle Minute den Reset-Knopf am Arduino drücken. Er fängt bei 0:00:00 an zu zählen.
3. Arduino am Strom lassen, Monitor offen lassen.
4. Nach einer Stunde, besser morgen früh: Wie viele Minuten sind laut time.is vergangen, und was sagt der
   Arduino?

Schreib auf: Nach ___ Stunden lag der Arduino ___ Sekunden daneben.

## Übrigens

Der Arduino hat keine richtige Uhr, er zählt die Schwingungen eines kleinen Bauteils auf der Platine. Das ist bei
billigen Boards nicht sehr genau. Beim Testen lag ein Nano nach gut 5 Stunden 15 Sekunden daneben, also etwa
3 Sekunden pro Stunde. Aufs Jahr gerechnet wären das über 7 Stunden! Eine Armbanduhr mit Quarz schafft
ein paar Sekunden im Monat. Und noch genauer? Darum geht es morgen.
