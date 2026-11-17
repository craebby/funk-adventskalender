# 16. Dezember: Wer funkt denn hier?

**Heute neu:** die Bibliothek „rc-switch“

## Vorbereitung

In der IDE: Werkzeuge → Bibliotheken verwalten → „rc-switch“ suchen → die von **sui77** installieren.

## Programm

[`tag16_funklauscher.ino`](../sketches/tag16_funklauscher/tag16_funklauscher.ino), Seriellen Monitor auf.

## Was passiert

Der Arduino lauscht auf 433 MHz und übersetzt, was er hört. Hast du eine Funk-Türklingel, ein Funkthermometer,
eine alte Funksteckdosen-Fernbedienung? Drück drauf. Im Monitor erscheint eine Zahl: der Code, den das Gerät funkt.

Wenn nichts kommt: auch gut. Viele Geräte im Haus funken heute anders, und manche Wettersensoren benutzen ein
Format, das rc-switch nicht kennt. Übermorgen funkst du selbst, dann kommt garantiert etwas.

## Übrigens

433 MHz heißt: Die Welle schwingt 433 Millionen Mal pro Sekunde. Erinnerst du dich an die 50 Hz aus der
Steckdose? Hier ist es fast zehn Millionen Mal schneller. Das Band ist für Geräte mit wenig Leistung frei, ohne
Anmeldung. Deshalb funken dort Klingeln, Garagentore und Wetterstationen.

Bitte nur auf eigene Geräte drücken und fremde Codes nicht nachsenden.
