# 18. Dezember: Der eigene Sender

**Heute neu:** Arduino Nano mit USB-C-Kabel, 433-MHz-Sender, drei Buchse-Stecker-Kabel

Heute ist Umzugstag. Der kleine Nano zieht ins Steckbrett und wird Empfänger. Der große Uno wird zum Sender.
Nimm dir etwas mehr Zeit als sonst.

**Ab heute gibt es zwei Arduinos und damit zwei Programme**, eins für jeden:

| Arduino | Aufgabe | Programm |
|---|---|---|
| **Nano** (im Steckbrett) | Empfänger: hört zu | `tag17_funklauscher` (kennst du schon von gestern, Bonus) |
| **Uno** (an der Powerbank) | Sender: deine Fernbedienung | `tag18_fernbedienung` (neu) |

Beim Hochladen also immer darauf achten, welcher Arduino gerade am PC hängt und welches Board in der IDE
eingestellt ist.

## Umbau Steckbrett (Nano = Empfänger)

1. Uno abziehen. Alle Kabel zum Uno, Taster, Drehknopf, Ultraschall-Sensor und den **Fotowiderstand** mit
   seinem 10-kΩ-Widerstand herausnehmen. Den Fotowiderstand leg beiseite, er kommt erst an Heiligabend wieder.
   Kerzen, Summer und Empfänger dürfen raus, wir stecken sie gleich neu.
2. Den Nano in die **Reihen 1 bis 15**, quer über den Graben, USB-Buchse oben. Links sollen noch drei Löcher
   (a–c), rechts zwei (i–j) frei sein. Passt er nicht, leg ihn neben das Brett und verbinde seine Stifte mit
   Kabeln (siehe Steckplan).
3. Neu stecken nach dem [Steckplan](steckplan.md#ab-tag-18-der-nano-empfängt-der-uno-funkt): Schienen an 5V und
   GND des Nano, Empfänger in Reihe 23–26 mit DATA an **D2**, Kerzen in Reihe 17/19/21 an D5/D6/D7, Summer an
   D9.
4. Nano mit dem USB-Kabel an den PC. Jetzt kommt der kniffligste Moment des ganzen Kalenders, die Auswahl in
   der IDE. Schritt für Schritt:

   > **Den Nano in der IDE auswählen**
   >
   > 1. Oben in der Menüleiste: **Werkzeuge → Board → Arduino AVR Boards → Arduino Nano**.
   >    Achtung, es gibt mehrere Nanos! **Nicht** „Arduino Nano Every“ (steht unter „megaAVR Boards“),
   >    **nicht** „Nano ESP32“ oder „Nano 33“. Nur das schlichte **„Arduino Nano“**.
   > 2. **Werkzeuge → Port:** den Anschluss des Nano wählen. Nachbauten heißen dort oft nicht „Nano“, sondern
   >    nur `COM4` (Windows) oder `/dev/ttyUSB0` (Linux). Unsicher? Nano abziehen, Liste anschauen, wieder
   >    anstecken: Der neue Eintrag ist der Nano.
   > 3. **Werkzeuge → Prozessor:** „ATmega328P“. Die Zeile erscheint erst, wenn in Schritt 1 das richtige Board
   >    gewählt ist.
   > 4. Hochladen. Bricht es mit Fehlern ab (zum Beispiel „not in sync“), unter Prozessor
   >    **„ATmega328P (Old Bootloader)“** wählen und noch einmal hochladen. Das brauchen viele günstige Nanos.
   >
   > Rote Zeilen mit „jtagmkII“ heißen fast immer: Es ist der „Nano Every“ ausgewählt. Zurück zu Schritt 1.

5. **Programm für den Nano:** [`tag17_funklauscher.ino`](../sketches/tag17_funklauscher/tag17_funklauscher.ino)
   hochladen. Er braucht die Bibliothek rc-switch (siehe Tag 17, Bonus). Hast du sie gestern nicht installiert,
   jetzt nachholen.

## Umbau Uno (Uno = Sender)

1. Den Sender an drei Buchse-Stecker-Kabel stecken: **VCC → 5V**, **GND → GND**, **DATA → Pin 10** am Uno.
2. Drei Steckbrücken in den Uno: eine in **Pin 3**, eine in **Pin 4**, eine in **GND**. Die freien Enden sind
   deine Tasten: Pin 3 an GND tippen = Taste 1, Pin 4 an GND = Taste 2.
3. **Programm für den Uno:** Uno an den PC, Board wieder „Arduino Uno“, Port des Uno wählen,
   [`tag18_fernbedienung.ino`](../sketches/tag18_fernbedienung/tag18_fernbedienung.ino) hochladen.

## Was passiert

Öffne den Seriellen Monitor **des Nano** (Port des Nano auswählen). Tipp am Uno Pin 3 an GND: Die kleine LED „L“
auf dem Uno blitzt, und beim Nano steht **Empfangen: Code 2412**. Dein erster eigener Funkspruch!

## Übrigens

Der Sender schickt den Code nicht einmal, sondern mehrmals hintereinander. Funk ist unzuverlässig, Wiederholen
ist der einfachste Schutz gegen Aussetzer.
