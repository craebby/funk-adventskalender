# 23. Dezember: Die Atomuhr hören

**Heute neu:** nichts. Für Ambitionierte: ein DCF77-Modul (optional)

## Für alle: Die Atomuhr im Browser

1. **websdr.ewi.utwente.nl:8901** öffnen. Das ist ein echter Funkempfänger an der Universität Twente in den
   Niederlanden, den jeder übers Internet bedienen darf.
2. In der Stationsliste **„D DCF77 Mainflingen“** wählen, oder als Frequenz **77.5** eintippen und **CW** wählen.
3. Lautstärke hoch, eventuell einmal auf die Seite klicken, damit der Ton startet.

Du hörst einen Pfeifton, der jede Sekunde kurz leiser wird. Kurz (0,1 s) oder lang (0,2 s). In der 59. Sekunde
fehlt die Lücke: Dann beginnt eine neue Minute.

Das ist DCF77, der Sender bei Frankfurt, nach dem sich alle Funkuhren in Deutschland richten. In den kurzen und
langen Lücken steckt die Uhrzeit, als Nullen und Einsen.

## Für Ambitionierte: Selbst empfangen

Mit einem DCF77-Modul empfängt der Arduino die Atomuhr selbst und zeigt nach einer Minute die Uhrzeit:
[`tag23_atomuhr_modul.ino`](../sketches/tag23_atomuhr_modul/tag23_atomuhr_modul.ino). Anschluss steht im Sketch.
Achtung: Die meisten Module vertragen nur **3,3 V**, nicht 5 V. **(prüfen: Modul und Pegel)**

## Übrigens

Gestern ist dein Arduino um Sekunden falsch gegangen. Die Atomuhren der Physikalisch-Technischen Bundesanstalt in
Braunschweig gehen in Millionen Jahren nicht eine Sekunde falsch. Über DCF77 bekommt jede Funkuhr diese
Genauigkeit geschenkt.

> 📻 **Funkamateur-Ecke:** Den WebSDR hat ein Funkamateur erfunden: Pieter-Tjerk de Boer, Rufzeichen PA3FWM, an der Uni Twente. Inzwischen gibt es weltweit Hunderte WebSDRs, viele davon betrieben von Funkamateuren, die ihren Empfänger einfach für alle öffnen. Probier gern andere Frequenzen aus, du kannst nichts kaputt machen.
