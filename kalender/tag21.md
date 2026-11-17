# 21. Dezember: Die Funk-Postkarte

**Heute neu:** nichts

## Programm

- **Nano:** [`tag21_funkpostkarte.ino`](../sketches/tag21_funkpostkarte/tag21_funkpostkarte.ino), Seriellen
  Monitor des Nano öffnen.
- **Uno:** bleibt bei `tag18_fernbedienung`.

## Was passiert

Taste 2 (Pin 4 an GND): Beim Nano erscheint Buchstabe für Buchstabe **FROHE WEIHNACHTEN!**. Ein „?“ heißt: Da ist
ein Buchstabe unterwegs verloren gegangen. **(prüfen: ob alle ankommen)**

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
