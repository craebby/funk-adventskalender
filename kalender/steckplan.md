# Der Steckplan für den ganzen Monat

Alles steckt auf einem Steckbrett mit 400 Kontakten: 30 Reihen (1–30), links die Spalten a–e, rechts f–j,
außen je eine rote Plus- und eine blaue Minus-Schiene. Teile bleiben stecken, bis der Text sagt, dass sie
raus dürfen. **Jedes Loch wird nur einmal benutzt**, auch auf den Schienen. So muss man nicht jeden Tag neu anfangen.

**Stand:** Am Schreibtisch geplant, noch nicht mit dem Miuzei-Steckbrett geprüft. **(prüfen)**

## So ist ein Steckbrett verbunden

- In einer Reihe sind a, b, c, d und e miteinander verbunden. Genauso f, g, h, i und j.
- Zwischen e und f ist ein Graben. Links und rechts davon sind **nicht** verbunden.
- Die Schienen am Rand laufen der Länge nach durch. Rot = Plus (+), Blau = Minus (−).

## Woche 1 bis 3: Der Uno steuert

| Was | Wo | Kabel zum Uno |
|---|---|---|
| Schienen | unten verbinden: linke + mit rechter + (Reihe 30), linke − mit rechter − (Reihe 29) | 5V → linke + (Reihe 1), GND → linke − (Reihe 1) |
| Kerze 1 (rot) | Widerstand 220 Ω von e10 nach f10, LED: langes Bein j10, kurzes Bein direkt daneben in die rechte − | Pin 5 → a10 (an Tag 1: 5V → a10) |
| Kerze 2 (gelb) | 220 Ω e13–f13, LED langes Bein j13, kurzes in rechte − | Pin 6 → a13 |
| Kerze 3 (grün) | 220 Ω e16–f16, LED langes Bein j16, kurzes in rechte − | Pin 7 → a16 |
| Fotowiderstand | Beine in c17 und c18. 10 kΩ von b18 in die linke − | a17 → linke +, a18 → A1 |
| Taster | über den Graben: Beine in e20, e22, f20, f22 (breiter Taster: d/g). Die weiten Beine über dem Graben sind fest verbunden, Reihe 20 und 22 erst beim Drücken | Pin 3 → a20, a22 → linke − |
| Passiver Summer | Beine waagerecht: + (das längere) in i25, − direkt in die rechte − (Reihe 25). Das Gehäuse liegt über j und der Schiene | Pin 9 → f25 |
| Potentiometer | Beine in c2, c3, c4 (je nach Abstand auch 2/4/6) | a2 → linke +, a4 → linke −, a3 → A2 |
| Ultraschall HC-SR04 | Stifte in i2 (VCC), i3 (Trig), i4 (Echo), i5 (GND), Augen nach außen | f2 → rechte +, f3 → Pin 4, f4 → Pin 8, f5 → rechte − |
| 433-MHz-Empfänger | Stifte in c24 bis c27 (Aufdruck beachten: VCC, DATA, DATA, GND) | a24 → linke +, a25 → Pin 2, a27 → linke − |
| Antennendraht (Woche 2) | nicht im Steckbrett, direkt in die Buchse A0 am Uno | – |

## Ab Tag 18: Der Nano empfängt, der Uno funkt

Das Steckbrett wird einmal umgebaut. Der Nano kommt hinein, der Uno wird die Fernbedienung.

**Nano:** in die Reihen 1 bis 15, quer über den Graben, USB-Buchse nach oben (Reihe 1). Die Stiftreihen stecken
in Spalte d und h. Links bleiben a–c frei, rechts i–j. **(prüfen: je nach Nano auch c und g)**

Dann liegen die Pins so (der Aufdruck auf dem Nano gilt, falls deiner anders ist):

| Reihe | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| links (d) | D13 | 3V3 | AREF | A0 | **A1** | A2 | A3 | A4 | A5 | A6 | A7 | **5V** | RST | **GND** | VIN |
| rechts (h) | D12 | D11 | D10 | **D9** | D8 | **D7** | **D6** | **D5** | D4 | D3 | **D2** | GND | RST | RX0 | TX1 |

| Was | Wo | Kabel |
|---|---|---|
| Schienen | wie vorher verbunden | a12 (5V) → linke +, a14 (GND) → linke − |
| Kerze 1, 2, 3 | 220 Ω e17–f17, e19–f19, e21–f21, LEDs langes Bein j17/j19/j21, kurzes in rechte − | i8 (D5) → a17, i7 (D6) → a19, i6 (D7) → a21 |
| 433-MHz-Empfänger | c23 bis c26, Antenne bleibt dran | a23 → linke +, i11 (D2) → a24, a26 → linke − |
| Fotowiderstand | c28 und c29, 10 kΩ von b29 schräg in die linke − (Reihe 28, Reihe 29 ist schon belegt) | a28 → linke +, a5 (A1) → a29 |
| Passiver Summer | + in i24, − direkt in die rechte − (Reihe 24) | i4 (D9) → f24 |

**Uno als Fernbedienung (ohne Steckbrett):**

| Was | Kabel |
|---|---|
| 433-MHz-Sender | drei Buchse-Stecker-Kabel: VCC → 5V, GND → GND, DATA → Pin 10 |
| Taste 1 | Steckbrücke in Pin 3, freies Ende |
| Taste 2 | Steckbrücke in Pin 4, freies Ende |
| GND-Draht | Steckbrücke in GND, freies Ende. Taste „drücken“ = Ende von Pin 3 oder 4 an dieses Ende tippen |
