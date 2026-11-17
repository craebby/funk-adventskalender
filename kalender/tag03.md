# 3. Dezember: Drei flackernde Kerzen

**Heute neu:** gelbe und grüne LED, zwei Widerstände 220 Ω

## Aufbau

Genau wie die rote Kerze, nur zwei Reihen weiter unten:

- **Kerze 2 (gelb):** 220 Ω von e13 nach f13, LED langes Bein j13, kurzes in die rechte −. Pin 6 → a13.
- **Kerze 3 (grün):** 220 Ω von e16 nach f16, LED langes Bein j16, kurzes in die rechte −. Pin 7 → a16.

## Programm

[`tag03_kerzen.ino`](../sketches/tag03_kerzen/tag03_kerzen.ino)

## Was passiert

Die drei LEDs flackern unruhig wie Kerzenflammen. `analogWrite` kann eine LED nicht nur an und aus, sondern auch
halb hell machen, und `random` würfelt jedes Mal eine neue Helligkeit.

## Probier mal

- Schau genau hin: Die grüne Kerze flackert anders, sie springt nur zwischen an und aus. Pin 7 kann nicht dimmen.
  Auf dem Uno haben nur die Pins mit einer Welle (~) neben der Zahl diese Fähigkeit.
- Ändere `random(80, 256)` in `random(200, 256)`: ruhigere Flammen.

## Übrigens

Das „halb hell“ ist ein Trick. Der Pin schaltet hunderte Male pro Sekunde an und aus, unterschiedlich lange.
Dein Auge mittelt das zu einem Helligkeitswert. Das heißt Pulsweitenmodulation.
