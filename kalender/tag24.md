# 24. Dezember: Der funkgesteuerte Weihnachtsbaum

**Heute neu:** ein Stück Schoki. Du hast es dir verdient. Und der Fotowiderstand von Tag 6 kommt zurück.

## Aufbau

Der Fotowiderstand zieht wieder ein, damit der Baum merkt, wann es dunkel wird:

- Fotowiderstand mit den Beinen in **c28** und **c29**.
- Steckbrücke von der linken **+**-Schiene nach **a28**.
- Widerstand 10 kΩ (braun-schwarz-orange) von **b29** schräg in die linke **−**-Schiene (Reihe 28, denn in
  Reihe 29 steckt schon die Brücke nach rechts).
- Steckbrücke vom Nano-Anschluss **A1** (Loch a5) nach **a29**. Am besten links außen am Brett vorbei, wie im
  Steckbild.

## Programm

- **Nano:** [`tag24_finale.ino`](../sketches/tag24_finale/tag24_finale.ino)
- **Uno:** bleibt bei `tag18_fernbedienung`, an der Powerbank. Schreib vorher noch deinen eigenen Gruß hinein
  (siehe Tag 21).

Das Steckbrett mit dem Nano darf in den Weihnachtsbaum oder daneben. Strom bekommt es über ein USB-Ladegerät.

## Was passiert

- **Taste 1:** Die drei Kerzen gehen an oder aus.
- **Taste 2:** Dein Weihnachtsgruß fliegt per Funk durch das Zimmer (im Seriellen Monitor zu lesen, wenn der Nano
  am PC hängt), und dann spielt Jingle Bells, während die Kerzen flackern.
- **Wird es dunkel**, gehen die Kerzen von selbst an. Den Wert für „dunkel“ kennst du von Tag 7.

## Bonus mit SDR-Stick

Wer einen SDR-Stick hat (einen Funkempfänger für den USB-Anschluss): auf 433,92 MHz einstellen und Taste 1 tippen.
Im Wasserfall-Bild erscheint dein eigener Sender als Strich. Mit etwas Glück sieht man daneben die
Funkthermometer der Nachbarn.

## Wie es weitergehen kann

In 24 Tagen hast du gesehen, dass die Luft voller Wellen ist: 50 Hz aus der Steckdose, Funken aus dem
Lichtschalter, Ultraschall, 433 MHz und eine Atomuhr auf 77,5 kHz.

Wenn dir das Spaß gemacht hat: Funkamateure dürfen mit selbst gebauten Geräten richtig senden, auf der ganzen
Welt. Den Einstieg bildet die Lizenzklasse N, seit 2024, mit einer Prüfung bei der Bundesnetzagentur.

So kommst du hin:

1. **[50ohm.de](https://50ohm.de)**: die kostenlose Lernplattform des DARC. Dort gibt es einen Online-Kurs für
   Klasse N und eine Prüfungssimulation. Einfach mal reinklicken und schauen, wie viel du nach diesem Kalender
   schon weißt.
2. **Ortsverband**: Frag beim nächsten DARC-Ortsverband nach. Viele bieten Kurse an, und fast alle freuen sich
   über Besuch beim OV-Abend.
3. **Zuhören geht sofort**: Mit dem WebSDR von Tag 23 kannst du schon heute Abend Funkamateuren aus ganz Europa
   lauschen.

**Frohe Weihnachten!** Und schau morgen und übermorgen noch einmal vorbei: Es gibt zwei Bonus-Türchen zum
Zuhören, ganz ohne Steckbrett.
