# 6. Dezember: Nikolaus spielt Licht-Theremin

**Heute neu:** Fotowiderstand, Widerstand 10 kΩ (braun-schwarz-orange)

## Aufbau

Fotowiderstand mit den Beinen in **c17** und **c18**. a17 → linke +, a18 → **A1**. Den 10-kΩ-Widerstand von
**b18** in die linke −.

## Programm

[`tag06_lichttheremin.ino`](../sketches/tag06_lichttheremin/tag06_lichttheremin.ino)

## Was passiert

Ein Ton, der sich mit dem Licht ändert. Halt die Hand darüber: tiefer. Leuchte mit der Handy-Taschenlampe drauf:
hoch. Wedel mit der Hand, und du spielst ein Instrument aus Licht.

## Probier mal

- Finger langsam über den Fotowiderstand ziehen und eine Melodie versuchen.
- Ändere die `150, 1500` in `map(...)`: anderer Tonbereich.

## Übrigens

Der Fotowiderstand leitet umso besser, je mehr Licht auf ihn fällt. Zusammen mit dem 10-kΩ-Widerstand teilt er
die 5 Volt auf. Am Eingang A1 kommt mal mehr, mal weniger an. Der Arduino misst das als Zahl von 0 bis 1023.
