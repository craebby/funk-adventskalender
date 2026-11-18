# 18. Dezember: Der eigene Sender

**Heute neu:** Arduino Nano mit USB-C-Kabel, 433-MHz-Sender, drei Buchse-Stecker-Kabel

Heute ist Umzugstag. Der kleine Nano zieht ins Steckbrett und wird Empfänger. Der große Uno wird zum Sender.
Nimm dir etwas mehr Zeit als sonst.

## Umbau Steckbrett (Nano = Empfänger)

1. Uno abziehen. Alle Kabel zum Uno, Taster, Drehknopf und Ultraschall-Sensor herausnehmen. Kerzen, Summer,
   Fotowiderstand und Empfänger dürfen raus, wir stecken sie gleich neu.
2. Den Nano in die **Reihen 1 bis 15**, quer über den Graben, USB-Buchse oben. Links sollen noch drei Löcher
   (a–c), rechts zwei (i–j) frei sein. **(prüfen)**
3. Neu stecken nach dem [Steckplan](steckplan.md#ab-tag-18-der-nano-empfängt-der-uno-funkt): Schienen an 5V und
   GND des Nano, Empfänger in Reihe 23–26 mit DATA an **D2**, Kerzen in Reihe 17/19/21 an D5/D6/D7, Summer an D9,
   Fotowiderstand an A1.
4. Nano mit dem USB-C-Kabel an den PC. In der IDE als Board „Arduino Nano“ wählen, Prozessor „ATmega328P“.
5. [`tag17_funklauscher.ino`](../sketches/tag17_funklauscher/tag17_funklauscher.ino) auf den **Nano** laden.

## Umbau Uno (Uno = Sender)

1. Den Sender an drei Buchse-Stecker-Kabel stecken: **VCC → 5V**, **GND → GND**, **DATA → Pin 10** am Uno.
2. Drei Steckbrücken in den Uno: eine in **Pin 3**, eine in **Pin 4**, eine in **GND**. Die freien Enden sind
   deine Tasten: Pin 3 an GND tippen = Taste 1, Pin 4 an GND = Taste 2.
3. Uno an den PC, Board wieder „Arduino Uno“, Port des Uno wählen,
   [`tag18_fernbedienung.ino`](../sketches/tag18_fernbedienung/tag18_fernbedienung.ino) hochladen.

## Was passiert

Öffne den Seriellen Monitor **des Nano** (Port des Nano auswählen). Tipp am Uno Pin 3 an GND: Die kleine LED „L“
auf dem Uno blitzt, und beim Nano steht **Empfangen: Code 2412**. Dein erster eigener Funkspruch!

## Übrigens

Der Sender schickt den Code nicht einmal, sondern mehrmals hintereinander. Funk ist unzuverlässig, Wiederholen
ist der einfachste Schutz gegen Aussetzer.
