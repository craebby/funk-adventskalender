# Der Steckplan für den ganzen Monat

Alles steckt auf einem Steckbrett mit 400 Kontakten: 30 Reihen (1–30), links die Spalten a–e, rechts f–j,
außen je eine rote Plus- und eine blaue Minus-Schiene. Teile bleiben stecken, bis der Text sagt, dass sie
raus dürfen. So muss man nicht jeden Tag neu anfangen.

**Stand:** Am Schreibtisch geplant, noch nicht mit dem Miuzei-Steckbrett geprüft. **(prüfen)**

## So ist ein Steckbrett verbunden

- In einer Reihe sind a, b, c, d und e miteinander verbunden. Genauso f, g, h, i und j.
- Zwischen e und f ist ein Graben. Links und rechts davon sind **nicht** verbunden.
- Die Schienen am Rand laufen der Länge nach durch. Rot = Plus (+), Blau = Minus (−).

## Woche 1 bis 3: Der Uno steuert

| Was | Wo | Kabel zum Uno |
|---|---|---|
| Schienen | linke + mit rechter + verbinden, linke − mit rechter − | 5V → linke +, GND → linke − |
| Kerze 1 (rot) | Widerstand 220 Ω von e10 nach f10, LED: langes Bein j10, kurzes Bein direkt daneben in die rechte − | Pin 5 → a10 (an Tag 1: 5V → a10) |
| Kerze 2 (gelb) | 220 Ω e13–f13, LED langes Bein j13, kurzes in rechte − | Pin 6 → a13 |
| Kerze 3 (grün) | 220 Ω e16–f16, LED langes Bein j16, kurzes in rechte − | Pin 7 → a16 |
| Fotowiderstand | Beine in c17 und c18. 10 kΩ von b18 in die linke − | a17 → linke +, a18 → A1 |
| Taster | über den Graben: Beine in e20, e22, f20, f22 | Pin 3 → a20, a22 → linke − |
| Passiver Summer | Beine in f25 (+, das längere) und f28 (−), je nach Beinabstand | Pin 9 → j25, j28 → rechte − |
| Potentiometer | Beine in c2, c3, c4 (je nach Abstand auch 2/4/6) | a2 → linke +, a4 → linke −, a3 → A2 |
| Ultraschall HC-SR04 | Stifte in i2 (VCC), i3 (Trig), i4 (Echo), i5 (GND), Augen nach außen | f2 → rechte +, f3 → Pin 4, f4 → Pin 8, f5 → rechte − |
| 433-MHz-Empfänger | Stifte in c24 bis c27 (Aufdruck beachten: VCC, DATA, DATA, GND) | a24 → linke +, a25 → Pin 2, a27 → linke − |
| Antennendraht (Woche 2) | nicht im Steckbrett, direkt in die Buchse A0 am Uno | – |

## Ab Tag 18: Der Nano empfängt, der Uno funkt

Das Steckbrett wird einmal umgebaut. Der Nano kommt hinein, der Uno wird die Fernbedienung.

**Nano:** in die Reihen 1 bis 15, quer über den Graben, USB-Buchse nach oben (Reihe 1). Die Stiftreihen stecken
in Spalte d und h. Links bleiben a–c frei, rechts i–j. **(prüfen: je nach Nano auch c und g)**

| Was | Wo | Kabel zum Nano (Pin steht auf dem Nano) |
|---|---|---|
| Schienen | wie vorher verbunden | Reihe mit „5V“ → +, Reihe mit „GND“ → − |
| Kerze 1, 2, 3 | 220 Ω e17–f17, e19–f19, e21–f21, LEDs langes Bein j17/j19/j21, kurzes in rechte − | D5 → a17, D6 → a19, D7 → a21 |
| 433-MHz-Empfänger | c23 bis c26 | a23 → linke +, a24 → D2, a26 → linke − |
| Fotowiderstand | c28 und c29, 10 kΩ von b29 in die linke − | a28 → linke +, a29 → A1 |
| Passiver Summer | f24 (+) und f27 (−) | D9 → j24, j27 → rechte − |

**Uno als Fernbedienung (ohne Steckbrett):**

| Was | Kabel |
|---|---|
| 433-MHz-Sender | drei Buchse-Stecker-Kabel: VCC → 5V, GND → GND, DATA → Pin 10 |
| Taste 1 | Steckbrücke in Pin 3, freies Ende |
| Taste 2 | Steckbrücke in Pin 4, freies Ende |
| GND-Draht | Steckbrücke in GND, freies Ende. Taste „drücken“ = Ende von Pin 3 oder 4 an dieses Ende tippen |
