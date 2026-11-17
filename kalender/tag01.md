# 1. Dezember: Hallo Steckbrett

**Heute neu:** Uno, USB-Kabel, Steckbrett, Steckbrücken, rote LED, Widerstand 220 Ω (rot-rot-braun)

Heute leuchtet etwas, ganz ohne Programm. Der Uno ist erst mal nur eine Steckdose mit 5 Volt.

## Aufbau

1. Steckbrücke vom Uno-Anschluss **5V** ganz oben (Reihe 1) in die linke rote **+**-Schiene, eine zweite von
   **GND** ganz oben in die linke blaue **−**-Schiene.
2. Die Schienen ganz unten auf die rechte Seite verlängern: linke + mit rechter + (Reihe 30), linke − mit
   rechter − (Reihe 29). Das bleibt den
   ganzen Monat so.
3. Widerstand 220 Ω von **e10** nach **f10**, über den Graben.
4. Rote LED: **langes Bein in j10**, kurzes Bein direkt daneben in die rechte **−**-Schiene.
5. Steckbrücke von der **+**-Schiene nach **a10**.
6. USB einstecken.

> **Achtung, Farben zählen:** Auf manchen Steckbrettern liegt die rote **+**-Schiene außen, auf anderen innen,
> manchmal sogar auf beiden Seiten verschieden. Geh immer nach der Farbe der Linie (rot = +, blau = −), nicht danach,
> wie es auf dem Bild aussieht.

## Was passiert

Die LED leuchtet. Der Strom fließt von 5V über die Brücke in Reihe 10, durch den Widerstand, durch die LED und
zurück zu GND. Ein Kreis, darum heißt es Stromkreis.

## Probier mal

- Zieh den Widerstand heraus: Die LED geht aus. Der Kreis ist offen.
- Dreh die LED um: Sie bleibt dunkel. LEDs lassen Strom nur in eine Richtung durch.

## Übrigens

Der Widerstand bremst den Strom. Ohne ihn würde die LED nach ein paar Sekunden durchbrennen. Die Farbringe sagen
seinen Wert: Rot (2), Rot (2), Braun (eine Null) = 220 Ohm.

## Klappt nicht?

LED umdrehen. Prüfen, ob die Schienen wirklich auf beiden Seiten verbunden sind, viele Steckbretter haben dort
eine Lücke.
