# 12. Dezember: Der Morse-Übersetzer

**Heute neu:** nichts. Taster, Summer und rote Kerze stecken schon.

Heute funkst du wie auf der Titanic, und der Arduino übersetzt für dich. Morse lernen musst du dafür nicht.

## Aufbau

Alles bleibt, wie es ist. Den Draht aus A0 darfst du rausziehen. Der Taster von Tag 4 (Pin 3) ist ab jetzt deine
**Morsetaste**, der Summer an Pin 9 dein Lautsprecher.

## Programm

[`tag12_morseuebersetzer.ino`](../sketches/tag12_morseuebersetzer/tag12_morseuebersetzer.ino), dann den
**Seriellen Monitor** öffnen (115200 Baud).

## Was passiert

Drück den Taster: Der Summer piept und die rote Kerze leuchtet.

- **Kurz drücken** = Punkt `.`
- **Lang drücken** (etwa eine halbe Sekunde) = Strich `-`
- **Kurz warten**: Der Buchstabe ist fertig, und der Arduino schreibt ihn in den Monitor.

Fang mit SOS an: dreimal kurz, Pause, dreimal lang, Pause, dreimal kurz. Im Monitor steht dann:

```
... = S
--- = O
... = S
```

## Spickzettel

| A `.-` | B `-...` | C `-.-.` | D `-..` | E `.` | F `..-.` | G `--.` |
|---|---|---|---|---|---|---|
| **H** `....` | **I** `..` | **J** `.---` | **K** `-.-` | **L** `.-..` | **M** `--` | **N** `-.` |
| **O** `---` | **P** `.--.` | **Q** `--.-` | **R** `.-.` | **S** `...` | **T** `-` | **U** `..-` |
| **V** `...-` | **W** `.--` | **X** `-..-` | **Y** `-.--` | **Z** `--..` | | |

## Probier mal

- Tipp deinen Namen. Versteht der Arduino dich?
- Ein Fragezeichen heißt: Diesen Code gibt es nicht. Meist war ein Strich zu kurz oder die Pause zu lang.
- Zu zweit: Eine Person tippt, die andere schaut nicht auf den Monitor und versucht, nur nach Gehör mitzuschreiben.
- Zu schnell oder zu langsam? Im Sketch stehen oben `LANG`, `BUCHSTABE_ENDE` und `WORT_ENDE`. Mit größeren Zahlen
  hat man mehr Zeit.

## Bonus: echte Morsezeichen hören

Öffne den WebSDR von **websdr.ewi.utwente.nl:8901**, tipp als Frequenz **7020** ein und wähle **CW**. Am besten
abends. Das Piepen, das du hörst, sind Funkamateure aus ganz Europa, die gerade miteinander morsen. Viel zu schnell
zum Mitschreiben, aber jetzt weißt du, was da passiert.

## Übrigens

Morsezeichen sind die älteste Art, Nachrichten per Funk zu schicken. 1912 funkte die sinkende Titanic damit um
Hilfe. Bis 1999 hörten Schiffe auf der ganzen Welt rund um die Uhr nach SOS.

> 📻 **Funkamateur-Ecke:** Funkamateure morsen bis heute, und das hat einen Grund: Ein Piepton kommt auch dann
> noch durch, wenn Sprache längst im Rauschen untergeht. Mit Morse und wenigen Watt erreicht man andere Kontinente.
> Für die Lizenz musst du Morse übrigens nicht mehr können. Wer es mag, lernt es freiwillig.
