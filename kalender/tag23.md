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

Mit einem DCF77-Modul empfängt der Arduino die Atomuhr selbst. Getestet mit einem Modul mit den Anschlüssen
**VCC, GND, PON, TCO** (so beschriftet sind viele, zum Beispiel das Pollin DCF1). Die meisten Module vertragen
nur **3,3 V**, nicht 5 V.

**Aufbau** (zwei freie Reihen, hier 40 und 42; mit dem Nano im Brett wie seit Tag 18):

- Steckbrücke vom **3V3**-Pin des Nano (Loch a2) nach **a42**. Reihe 42 ist jetzt die 3,3-V-Reihe.
- **VCC** vom Modul nach **b42**.
- **GND** und **PON** vom Modul beide in die **−**-Schiene. PON an GND schaltet das Modul ein.
- **TCO** vom Modul nach **a40**, Steckbrücke von **b40** nach **j1** (das ist **D12** am Nano).
- Widerstand 10 kΩ (braun-schwarz-orange) von **c40** nach **c42**. Er zieht TCO auf 3,3 V, das Modul zieht
  ihn im Takt nach unten.
- Ein Kondensator direkt am Modul beruhigt die Versorgung: Elko 10–100 µF zwischen Reihe 42 und der
  **−**-Schiene, das **lange Bein in Reihe 42**, der Streifen (kurzes Bein) an **−**. Gern zusätzlich einen kleinen
  Keramik-Kondensator „104“ daneben.

Programm: [`tag23_atomuhr_modul.ino`](../sketches/tag23_atomuhr_modul/tag23_atomuhr_modul.ino), Serieller Monitor
auf **115200**. Die Kerze an D5 blinkt mit dem Signal. Jede Sekunde erscheint eine 0 oder 1, ein `?`, wenn die Marke
gestört war. Nach 3 bis 5 Minuten steht da zum Beispiel:

```
Funkzeit: 7:18 Uhr am 21.11.2026
```

Das Programm arbeitet wie eine echte Funkuhr: Es legt mehrere Minuten übereinander, weil bei schwachem Empfang
immer mal eine Sekunde fehlt. Eine Uhrzeit zeigt es erst, wenn zwei Minuten hintereinander zusammenpassen.

**Stolperfallen:**

- **PON und TCO verwechselt?** Dann schläft das Modul, und es kommt gar nichts. Die Beschriftung genau lesen.
- **Störungen** sind der größte Feind: Monitor, PC-Netzteil, Ladegeräte, LED-Lampen und Funkgeräte überdecken die
  schwachen 77,5 kHz. Beim Testen ging am Schreibtisch neben dem PC nichts, mit dem Modul zwei, drei Meter weiter
  am Fenster klappte es sofort. Ein langes USB-Kabel hilft. Den Ferritstab quer zur Richtung Frankfurt legen.
- **Nichts los?** Mit [`tag23_dcf_test.ino`](../sketches/tag23_dcf_test/tag23_dcf_test.ino) siehst du, was am
  Pin ankommt. Gut ist: jede Sekunde **2 Wechsel**, eine Phase davon 100 bis 250 ms lang. Immer HIGH und
  0 Wechsel heißt: Das Modul schläft oder hat noch keinen Empfang. Viele Wechsel heißt: zu viele Störungen.
- Gleich nach dem Einschalten braucht das Modul oft ein, zwei Minuten, bis es sauber tickt.

## Übrigens

Gestern ist dein Arduino um Sekunden falsch gegangen. Die Atomuhren der Physikalisch-Technischen Bundesanstalt in
Braunschweig gehen in Millionen Jahren nicht eine Sekunde falsch. Über DCF77 bekommt jede Funkuhr diese
Genauigkeit geschenkt.

> 📻 **Funkamateur-Ecke:** Den WebSDR hat ein Funkamateur erfunden: Pieter-Tjerk de Boer, Rufzeichen PA3FWM, an der Uni Twente. Inzwischen gibt es weltweit Hunderte WebSDRs, viele davon betrieben von Funkamateuren, die ihren Empfänger einfach für alle öffnen. Probier gern andere Frequenzen aus, du kannst nichts kaputt machen.
