# 11. Dezember: Das Ultraschall-Theremin

**Heute neu:** Ultraschall-Sensor HC-SR04 (der mit den zwei silbernen „Augen“)

## Aufbau

Die vier Stifte des Sensors in **i2, i3, i4, i5**, die Augen zeigen nach außen. Achte auf die Beschriftung:
VCC, Trig, Echo, GND.
- f2 (VCC) → rechte +
- f3 (Trig) → Pin 4
- f4 (Echo) → Pin 8
- f5 (GND) → rechte −

## Programm

[`tag11_ultraschalltheremin.ino`](../sketches/tag11_ultraschalltheremin/tag11_ultraschalltheremin.ino)

## Was passiert

Halt die Hand über den Sensor und beweg sie auf und ab. Nah: hoher Ton. Weiter weg: tiefer. Hand weg: Ruhe. Im
Seriellen Monitor siehst du den Abstand in Zentimetern.

## Probier mal

Miss, wie weit die Wand weg ist. Oder die Zimmerdecke. Stimmt das mit dem Zollstock?

## Übrigens

Das eine Auge ruft, das andere hört. Der Ruf ist ein Ton mit 40.000 Hz, viel zu hoch für Menschen, aber nicht für
Fledermäuse und Hunde. Der Arduino misst, wie lange das Echo braucht. Schall schafft etwa 343 Meter pro Sekunde,
daraus wird die Entfernung. Radar macht dasselbe mit Funkwellen, nur eine Million Mal schneller.
