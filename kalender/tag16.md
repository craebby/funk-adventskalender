# 16. Dezember: Wer funkt denn hier?

**Heute neu:** nichts. Steck aber schon die Antenne (17,3 cm Draht) ins Loch **ANT** des Empfängers, das hilft
heute sehr. Mehr dazu morgen.

## Programm

[`tag16_wetterlauscher.ino`](../sketches/tag16_wetterlauscher/tag16_wetterlauscher.ino), Seriellen Monitor auf
(115200 Baud). Keine Bibliothek nötig.

## Was passiert

Der Arduino lauscht auf Funk-Thermometer in der Nachbarschaft. Die meisten funken nach demselben Muster: kurzer
Puls, dann eine kurze Pause (= 0) oder eine lange Pause (= 1). Der Sketch sammelt diese Nullen und Einsen und
versucht, Temperatur und Feuchte herauszulesen.

Geduld: Thermometer funken nur alle 30 bis 60 Sekunden. Lass ihn ein paar Minuten laufen. So sah es beim Testen
aus, mit dem Thermometer auf dem Dachboden und dem auf dem Balkon:

```
Telegramm Nr. 2 nach 149 s: 36 Bits  010001101000000001101100111100000000
  -> Thermometer (Nexus-Format): ID 70, Kanal 1, 10.8 Grad
Telegramm Nr. 3 nach 221 s: 40 Bits  0011100011010000010101110100100001000001
  -> Thermometer (inFactory-Format): ID 56, 9.8 Grad, Feuchte 84 %
```

Die Temperatur steckt direkt in den Bits. Beim Nexus-Thermometer sind es die Bits 13 bis 24:
`000001101100` ist 108, also 10,8 Grad.

**Kommt nichts?** Ohne Antenne hört der Empfänger nur ein paar Meter weit. Mit dem 17,3-cm-Draht am Loch ANT
klappt es durch Wände und aus der Nachbarschaft. „Unbekanntes Gerät“ heißt: Da funkt etwas in einem Format, das der
Sketch nicht kennt, zum Beispiel eine Wetterstation einer anderen Marke.

**Welche Thermometer kennt der Sketch?** Das Nexus-Format benutzen viele günstige Funkthermometer, auch unter
anderen Namen (zum Beispiel Sencor, Digoo, Rubicson). Dazu kommt inFactory (oft von Pearl). Manche
Wetterstationen, etwa viele von Bresser, TFA oder La Crosse, funken in einem anderen Verfahren (FSK) oder auf
868 MHz. Die kann dieser einfache Empfänger gar nicht hören, egal mit welchem Programm.

## Bonus: Fernbedienungen mitlesen

Hast du eine Funksteckdosen-Fernbedienung, eine Funkklingel oder einen Garagentoröffner? Die funken in einem
anderen Format. Dafür gibt es eine fertige Bibliothek:

1. In der IDE: Werkzeuge → Bibliotheken verwalten → **rc-switch** (mit Bindestrich) suchen → die von **sui77**
   installieren (Version 2.6.4). Findest du sie nicht, such nach **sui77**. Nicht „RcSwitchReceiver“ oder
   „RcSwitchTransmitter“ nehmen, das sind andere Bibliotheken.
2. [`tag16_funklauscher.ino`](../sketches/tag16_funklauscher/tag16_funklauscher.ino) hochladen, Monitor auf, auf
   die Fernbedienung drücken: Im Monitor erscheint der Code, den das Gerät funkt.

Die Bibliothek brauchst du ab Tag 18 sowieso.

## Übrigens

433 MHz heißt: Die Welle schwingt 433 Millionen Mal pro Sekunde. Erinnerst du dich an die 50 Hz aus der
Steckdose? Hier ist es fast zehn Millionen Mal schneller. Das Band ist für Geräte mit wenig Leistung frei, ohne
Anmeldung. Deshalb funken dort Klingeln, Garagentore und Wetterstationen.

Beim Bauen dieses Türchens hat der Empfänger gezeigt, wie Funk im echten Leben ist: Nach jeder langen Pause
dreht er die Verstärkung hoch und rauscht, dabei gehen gern die ersten Bits verloren. Winzige Störpulse
zerhacken die Pausen. Deshalb senden die Thermometer jeden Messwert sechs- bis zehnmal hintereinander, und deshalb
rechnet der Balkon-Sensor eine **Prüfsumme** mit: Stimmt sie, ist kein Bit falsch. Dein Handy, WLAN und das
Digitalradio machen es genauso, nur viel schneller.

Bitte nur auf eigene Geräte drücken und fremde Codes nicht nachsenden.
