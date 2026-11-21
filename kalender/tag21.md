# 21. Dezember: Die Funk-Postkarte

**Heute neu:** nichts

## Programm

- **Nano:** [`tag21_funkpostkarte.ino`](../sketches/tag21_funkpostkarte/tag21_funkpostkarte.ino), Seriellen
  Monitor des Nano öffnen.
- **Uno:** bleibt bei `tag18_fernbedienung`.

## Was passiert

Taste 2 (Pin 4 an GND): Beim Nano erscheint Buchstabe für Buchstabe **FROHE WEIHNACHTEN!**. Ein „?“ heißt: Da ist
ein Buchstabe unterwegs verloren gegangen.

## Probier mal: Dein eigener Gruß

Öffne `tag18_fernbedienung.ino` und ändere die Zeile

```
const char GRUSS[] = "FROHE WEIHNACHTEN!";
```

in deinen eigenen Text, ohne ä, ö, ü und ß. Neu auf den Uno laden und abschicken.

## Übrigens

Jeder Buchstabe wird zu einer Zahl (A ist 65, B ist 66 …), dazu kommt seine Position im Text. So weiß der
Empfänger, welcher Buchstabe an welche Stelle gehört, auch wenn einer doppelt ankommt. Nach diesem Prinzip reisen
alle Nachrichten per Funk, von der SMS bis zum WLAN: als lauter kleine nummerierte Zahlenpakete.

## Bonus: Daten per Funk hören

Wie klingen Daten, wenn man sie hören kann? Öffne den WebSDR **websdr.ewi.utwente.nl:8901**, tipp **7074** ein
und wähle **USB**. Das gleichmäßige Zwitschern, das alle 15 Sekunden neu einsetzt, sind Funkamateure aus ganz
Europa, deren Computer sich Rufzeichen und Empfangsberichte schicken, auch das in kleinen Paketen. Im Wasserfall
ist jeder kleine Strich eine Station. Mehr dazu gibt es am zweiten Weihnachtstag.
