# Einkaufsliste

Bestell rechtzeitig, damit am 1. Dezember alles da ist. Gelötet wird nichts.

## Der einfachste Weg: drei Pakete, zusammen etwa 43 €

| Was | Preis ca. | Wofür |
|---|---|---|
| **Miuzei Elektronik Starter Kit für Arduino R3, 203 Teile**, Variante „Basic Starter Kit“ (Amazon) | 26 € | Uno, Steckbrett, LEDs, Widerstände, Taster, beide Summer, Fotowiderstand, Drehknopf, Ultraschall-Sensor |
| **Nano V3 mit USB-C, Pins verlötet, 2 Stück** (Amazon, z. B. dixfedy) | 10 € | der Empfänger ab Türchen 18, der zweite ist Reserve |
| **433-MHz-Sender und -Empfänger**, z. B. ARCELI 5 Stück Link-Kit (Amazon) | 7 € | Funk ab Türchen 15. Ein Paar reicht, der Rest ist Reserve |

Aus dem Haushalt: Alufolie, eine Keksdose, etwa 1,5 m Draht (Klingeldraht, Lautsprecherkabel oder mehrere
Steckbrücken hintereinander), ein USB-C-Kabel vom Handy, eine Powerbank oder ein Handy-Ladegerät.

**Spartipp:** Zu zweit bestellen. Im Nano-Doppelpack stecken zwei Nanos, im Funkset fünf Paare. Dann kostet es
pro Person etwa 35 €.

Preise vom November 2026, sie schwanken.

## Du hast schon eine Bastelkiste?

Das hier wird wirklich gebraucht, egal aus welchem Kit:

| Anzahl | Teil | Ab Türchen | Hinweis |
|---|---|---|---|
| 1 | Arduino Uno mit USB-Kabel | 1 | Jedes 5-V-Board mit ATmega328 geht |
| 1 | Arduino Nano oder ein zweiter Uno | 18 | Zwei Boards: eines sendet, eines empfängt |
| 1 | Steckbrett, mindestens 400 Kontakte | 1 | |
| ca. 15 | Steckbrücken Stecker–Stecker | 1 | |
| 3 | Steckbrücken Buchse–Stecker | 18 | für den Sender am Uno |
| 3 | LEDs, Farbe egal | 1 | |
| 3 | Widerstände 220 Ω | 1 | 150 bis 470 Ω gehen auch |
| 1 | Widerstand 10 kΩ | 6 | |
| 1 | Fotowiderstand | 6 | |
| 1 | Taster | 4 | |
| 1 | Potentiometer 10 kΩ | 9 | 1 bis 100 kΩ gehen auch |
| 1 | **passiver** Summer | 5 | ein aktiver kann keine Melodien |
| 1 | Ultraschall-Sensor HC-SR04 | 11 | |
| 1 | 433-MHz-Sender + Empfänger (FS1000A/MX-FS-03V + XY-MK-5V/MX-05V) | 15 | auf dem Empfänger muss 433 stehen |

Wer eine typische Arduino-Kiste hat, braucht meist nur das Funkset für ein paar Euro.

## Beim Kauf achten auf

- **433 MHz:** Auf dem kleinen Metallbauteil des Empfängers muss **433** stehen. Es gibt gleich aussehende mit 315 MHz.
- **Nano:** „mit verlöteten Pins“ und am besten mit **USB-C**. Er hat meist einen CH340-Chip. Windows und Linux
  erkennen ihn fast immer von selbst, sonst den CH340-Treiber installieren.
- **Summer:** Im Miuzei-Kit sind beide. Bei anderen Kits auf „passiver Summer“ oder „passive buzzer“ achten.

## Nur für Ambitionierte (optional)

| Teil | Preis ca. | Für |
|---|---|---|
| DCF77-Empfangsmodul, möglichst mit Pins | 6–10 € | Türchen 23: die Atomuhr selbst empfangen. Ohne Modul hört man sie im Browser. |
| SDR-Stick (z. B. RTL-SDR Blog V4) | 35–60 € | Bonus an Heiligabend: den eigenen Sender auf dem Bildschirm sehen |
