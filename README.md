# Funk-Adventskalender: Das Unsichtbare hören

> ⚠️ **Spoiler-Warnung:** Hier im Repository liegen alle 24 Tage offen. Wer sich überraschen lassen will, öffnet
> lieber den Kalender unter **https://craebby.github.io/funk-adventskalender/** und schaut hier erst nach
> Heiligabend rein.
>
> 🐞 Wer trotzdem schon alles durchgerattert hat und dabei einen Fehler findet: bitte als
> [Issue](https://github.com/craebby/funk-adventskalender/issues) melden. Alles ist nach bestem Wissen und Gewissen gemacht, aber Fehler können sich einschleichen.
>
> 💛 Gefällt dir der Kalender? Über [GitHub Sponsors](https://github.com/sponsors/craebby) kannst du einen
> Kaffee spendieren.

Konzept, Stand 17.11.2026.

24 kleine Experimente auf dem Steckbrett, jeden Tag 15 bis 30 Minuten. Man braucht kein Vorwissen und keinen
Lötkolben: aufbauen, Sketch kopieren, hochladen, staunen. Am ersten Tag leuchtet eine LED, am Ende schaltet eine
selbst gebaute Funkfernbedienung den Weihnachtsbaum aus dem Nebenzimmer und schickt einen Weihnachtsgruß.

Der rote Faden: Um uns herum ist ständig etwas unterwegs, das man nicht sieht. Der Brumm aus der Steckdose, Funken
beim Lichtschalten, Ultraschall, Funksignale, die Atomuhr. Der Kalender macht das hör- und sichtbar.

**Stand der Prüfung:** Alle Sketches kompilieren für Uno und Nano. Vom 17. bis 18.11.2026 wurde der Kalender mit
eigenen Teilen komplett nachgebaut (Uno R3, Nano-Nachbau mit CH340, großes Steckbrett) und dabei an vielen Stellen
verbessert. Details und Messwerte stehen in [TESTPLAN.md](TESTPLAN.md). Am 21.11. kam das optionale
DCF77-Modul (Tag 23) dazu. Noch nicht mit Hardware geprüft: die Keksdose (Tag 19).

## Die Webseite

`index.html` ist der Kalender mit 24 Türchen. Jedes geht erst am jeweiligen Dezembertag auf (deutsche Zeit),
mit dem Spoiler-Knopf auch früher. Im November läuft ein Countdown, nach Weihnachten ist alles offen.
`tag.html` zeigt einen Tag mit Steckbild, Text und Sketch zum Kopieren. Die Texte kommen direkt aus `kalender/`,
die Steckbilder aus `bilder/`.

- **Veröffentlichen:** Repo öffentlich stellen, dann Settings → Pages → „Deploy from a branch“, Branch `main`,
  Ordner `/ (root)`. Adresse: `https://craebby.github.io/funk-adventskalender/`
- **Lokal ansehen:** `python3 -m http.server 8642` im Repo, dann http://localhost:8642
- **Steckbilder neu erzeugen** (nach Änderungen am Steckplan): `python3 tools/steckbilder.py`
- **Steckbilder prüfen** (doppelt belegte oder verdeckte Löcher): `python3 tools/pruefe_steckbilder.py`,
  alle Bilder auf einen Blick: `tools/uebersicht.html` im lokalen Server
- **Bilder zum Teilen:** [werbung/bilder/](werbung/bilder/)

## Der Kalender zum Lesen

- [Bevor es losgeht](kalender/00_vorbereitung.md): Arduino-IDE, Hochladen, Monitor und Plotter, Sicherheit
- [Steckplan](kalender/steckplan.md): wo jedes Teil den ganzen Monat steckt
- Die Türchen: [1](kalender/tag01.md) · [2](kalender/tag02.md) · [3](kalender/tag03.md) · [4](kalender/tag04.md) ·
  [5](kalender/tag05.md) · [6](kalender/tag06.md) · [7](kalender/tag07.md) · [8](kalender/tag08.md) ·
  [9](kalender/tag09.md) · [10](kalender/tag10.md) · [11](kalender/tag11.md) · [12](kalender/tag12.md) ·
  [13](kalender/tag13.md) · [14](kalender/tag14.md) · [15](kalender/tag15.md) · [16](kalender/tag16.md) ·
  [17](kalender/tag17.md) · [18](kalender/tag18.md) · [19](kalender/tag19.md) · [20](kalender/tag20.md) ·
  [21](kalender/tag21.md) · [22](kalender/tag22.md) · [23](kalender/tag23.md) · [24](kalender/tag24.md)

Jeder Tag hat dieselben Abschnitte: Heute neu, Aufbau, Programm, Was passiert, Probier mal, Übrigens.
Fotos fehlen noch, sie entstehen mit den bestellten Kits.

## Einkaufsliste

Drei Dinge, zusammen etwa **43 €**. Kein Löten, keine Spezialteile.

| Was | Preis | Wofür |
|---|---|---|
| **Miuzei Elektronik Starter Kit für Arduino R3, 203 Teile, Variante „Basic Starter Kit“** (Amazon) | 25,99 € | alles für Woche 1 und 2, der Uno wird später die Fernbedienung |
| **dixfedy Nano-V3 mit USB-C, 2 Stück, Pins verlötet** (Amazon) | 9,99 € | der Empfänger ab Tag 18. Der zweite ist Reserve. |
| **ARCELI 5 Stück 433 MHz RF Sender und Empfänger Link Kit** (Amazon, B07MY39VF8): 5 Paare aus Sender MX-FS-03V und Empfänger MX-05V, 433,92 MHz | 7,09 € | Woche 3 und 4. Ein Paar wird gebraucht, der Rest ist Reserve. Die Module sind baugleich zu FS1000A/XY-MK-5V. |

Aus dem Haushalt: Alufolie, eine Keksdose, etwa 1,5 m Draht (Klingeldraht, Lautsprecherkabel oder einige
Steckbrücken hintereinander), ein USB-C-Kabel vom Handy, eine Powerbank oder ein Handy-Ladegerät.

Was aus dem Miuzei-Kit gebraucht wird (laut Produktbild): Uno mit USB-Kabel, Steckbrett (400 Kontakte),
Steckbrücken und Buchse-Stecker-Kabel, LEDs, Widerstände 220 Ω und 10 kΩ, Taster, Fotowiderstand, Potentiometer,
passiver und aktiver Summer, Ultraschall-Sensor HC-SR04. Übrig bleiben unter anderem Temperatur-Sensoren,
Neigungsschalter, RGB-LED und 7-Segment-Anzeige, gut für eigene Ideen nach Weihnachten.

**Beim Kauf achten auf:**
- Auf dem 433-MHz-Empfänger muss auf dem kleinen Metallbauteil **433** stehen (es gibt gleich aussehende mit 315 MHz).
- Der Nano hat einen CH340-Chip. Windows 10/11 und Linux erkennen ihn meist von selbst, sonst den CH340-Treiber
  installieren. In der Arduino-IDE als „Arduino Nano“ auswählen, Prozessor „ATmega328P“.

Preise vom 17.11.2026, sie schwanken.

### Sparen

- **Zu zweit bestellen:** Im Nano-Doppelpack stecken zwei Nanos, im ARCELI-Set fünf Funkpaare. Teilen sich zwei
  Leute beides, kostet es pro Person etwa 25,99 + 5,00 + 3,55 = **ca. 35 €**. Bei fünf Leuten wird das Funkset noch
  günstiger.
- **Ein einzelnes 433-MHz-Paar** statt fünf gibt es ab etwa 3–4 € (eBay), das spart ca. 3 €.
- **Einzelteile statt Kit** (Steckbrett ca. 2 €, Poti ca. 1 €, LEDs, Widerstände, Summer, Fotowiderstand, Ultraschall
  ab ca. 2 €, z. B. bei Berrybase) kommt mit zwei Nanos auf etwa 25–30 €, aber mit vielen Einzelbestellungen und
  Versandkosten. Für Einsteiger nicht empfohlen.
- **Mit eigener Bastelkiste:** meist nur das Funkset, also 4–7 €.

### Minimale Materialliste (für alle, die schon eine Bastelkiste haben)

Das hier wird wirklich gebraucht, egal aus welchem Kit es stammt:

| Anzahl | Teil | Ab Tag | Hinweis |
|---|---|---|---|
| 1 | Arduino Uno mit USB-Kabel | 1 | Jedes 5-V-Board mit ATmega328 geht, auch ein Nano |
| 1 | Arduino Nano mit Pins und USB-Kabel | 18 | Oder ein zweiter Uno. Hauptsache zwei Boards: eines sendet, eines empfängt |
| 1 | Steckbrett, mindestens 400 Kontakte | 1 | |
| ca. 15 | Steckbrücken Stecker–Stecker | 1 | |
| 3 | Steckbrücken Buchse–Stecker | 18 | Für den Sender direkt am Uno |
| 3 | LEDs, Farbe egal | 1 | |
| 3 | Widerstände 220 Ω | 1 | 150 bis 470 Ω gehen auch |
| 1 | Widerstand 10 kΩ | 6 | Für den Fotowiderstand |
| 1 | Fotowiderstand (LDR) | 6 | |
| 1 | Taster | 4 | |
| 1 | Potentiometer 10 kΩ | 9 | Andere Werte von 1 bis 100 kΩ gehen auch |
| 1 | **Passiver** Summer | 5 | Ein aktiver spielt Melodien nur schräg. Eine Piezo-Scheibe oder ein kleiner Lautsprecher mit 100 Ω in Reihe gehen auch |
| 1 | Ultraschall-Sensor HC-SR04 | 11 | |
| 1 | 433-MHz-Sender + Empfänger (FS1000A/MX-FS-03V + XY-MK-5V/MX-05V) | 15 | Auf dem Empfänger muss 433 stehen, nicht 315 |
| ca. 1,5 m | Draht, beliebig | 10 | 50 cm Antenne für den Knacks-Detektor, 1 m zum Vergleich an Tag 8, 2 × 17,3 cm für 433 MHz |

Nicht zwingend nötig: ein aktiver Summer (Tag 5, zum Vergleich hören), eine Powerbank (Tag 20, ein langes
USB-Kabel tut es auch), Alufolie und Keksdose (Tag 19).

### Nur für Ambitionierte (optional)

| Teil | Preis ca. | Für |
|---|---|---|
| DCF77-Empfangsmodul, möglichst mit Pins | ca. 6–10 € | Tag 23: die Atomuhr selbst empfangen. Ohne Modul hört man sie über den WebSDR. |
| SDR-Stick (z. B. RTL-SDR Blog V4) | 35–60 € | Bonus am 24.: den eigenen Sender auf dem Bildschirm sehen |

## Wer macht was

- **Tag 1 bis 17:** Der **Uno** sitzt neben dem Steckbrett und steuert alles.
- **Ab Tag 18:** Der **Nano** zieht ins Steckbrett und wird der Empfänger mit Kerzen, Summer und Lichtsensor. Er
  bleibt per USB am PC. Der **Uno** wird die Fernbedienung: Der Sender hängt an drei Buchse-Stecker-Kabeln direkt am
  Uno, die Tasten sind Steckbrücken, die man an GND tippt. So braucht die Fernbedienung kein eigenes Steckbrett
  und läuft an jeder Powerbank.

Feste Pins, beim Uno und beim Nano gleich:

| Pin | Was |
|---|---|
| 5, 6, 7 | LEDs (Kerzen), je mit 220 Ω |
| 3 | Taster gegen GND |
| 9 | Passiver Summer |
| A0 | Antennendraht (offener Eingang) |
| A1 | Fotowiderstand (mit 10 kΩ nach GND) |
| A2 | Potentiometer (Empfindlichkeit) |
| 4 und 8 | Ultraschall-Sensor (Trig und Echo) |
| 2 | 433-MHz-Empfänger DATA |
| 10 | 433-MHz-Sender DATA (am Uno, ab Tag 18) |

## Die 24 Tage

### Woche 1: Licht und Töne. Ankommen.

| Tag | Experiment | Was passiert | Sketch |
|---|---|---|---|
| 1 | **Hallo Steckbrett** | 5V vom Uno über 220 Ω an eine LED: Sie leuchtet. Noch kein Programm, nur verstehen, wie das Steckbrett verbunden ist. | – |
| 2 | **Die erste LED blinkt** | Erstes eigenes Programm. Mit `delay` spielen: schneller, langsamer. | `tag02_blinken` |
| 3 | **Drei flackernde Kerzen** | Zufällige Helligkeit sieht aus wie Kerzenflammen. | `tag03_kerzen` |
| 4 | **Licht per Knopf** | Der Taster schaltet die Kerze an und aus. | `tag04_taster` |
| 5 | **Jingle Bells** | Der passive Summer spielt die Melodie. Dann den aktiven Summer einstecken: Er schnarrt oder spielt schräg, weil er seinen eigenen Tongeber hat. So lernt man den Unterschied. | `tag05_melodie` |
| 6 | **Nikolaus: Das Licht-Theremin** | Hand über den Fotowiderstand: Je dunkler, desto tiefer der Ton. Mit der Handy-Taschenlampe spielen. | `tag06_lichttheremin` |
| 7 | **Das Nachtlicht** | Wird es dunkel, gehen die Kerzen von selbst an. Das braucht das Finale wieder. Übrigens für Neugierige: Mit `uebrigens_lampenflackern` im Seriellen Plotter nachsehen, ob die LED-Lampen im Haus flackern. | `tag07_nachtlicht` |

### Woche 2: Unsichtbare Felder

| Tag | Experiment | Was passiert | Sketch |
|---|---|---|---|
| 8 | **Die Luft ist voller Strom** | Eine kurze Steckbrücke an A0, sonst nichts. Im Seriellen Plotter laufen Welle und Stärke. Nähert man den Finger von der Seite, steigt die Stärke von ca. 170 auf 350, beim Antippen auf über 700 (getestet 17.11.). Das ist das Stromnetz mit 50 Hz, ganz ohne Kontakt. Die erste Antenne des Kalenders. | `tag08_offener_eingang` |
| 9 | **Der Brumm-Melder** | Am Schreibtisch: Mit dem Drehknopf eine Schwelle einstellen. Hand nähern oder ein eingestecktes Verlängerungskabel an die Steckbrücke halten: Kerze und Summer melden den Strom, je näher, desto höher. Stecker ziehen: Stille. Wandsuche mit Powerbank nur als Bonus. **Nur von außen, nie in Steckdosen fassen.** | `tag09_kabelsucher` |
| 10 | **Der Knacks-Detektor** | 50 cm Draht an A0, Knopf so einstellen, dass es in Ruhe fast nie knackt. Schreibtischlampe, Aktenvernichter, Föhn: Jeder Funke im Schalter ist ein winziger Funksender. Der Arduino knackt und zählt mit. Genau so orten Blitzdetektoren Gewitter. Übrigens: Auf blitzortung.org sieht man das Netz der Hobby-Blitzdetektoren live. (getestet 17.11.) | `tag10_knacksdetektor` |
| 11 | **Das Ultraschall-Theremin** | Der Ultraschall-Sensor ruft Töne, die zu hoch für unsere Ohren sind, und lauscht auf das Echo, wie eine Fledermaus. Die Hand darüber auf und ab bewegen: Der Summer spielt dazu. | `tag11_ultraschalltheremin` |
| 12 | **Der Morse-Übersetzer** | Der Taster wird zur Morsetaste, der Summer piept, und der Arduino übersetzt live in Buchstaben im Seriellen Monitor. Kein Morse-Lernen, ein Spickzettel genügt: SOS, den eigenen Namen tippen. Bonus: echte Morsezeichen von Funkamateuren auf dem WebSDR (7020 kHz, CW). | `tag12_morseuebersetzer` |
| 13 | **Der Radar-Wächter** | Der Ultraschall-Sensor misst die freie Strecke durchs Zimmer und meldet jeden, der durch den Strahl läuft, mit Abstand und Zeit. Radar macht dasselbe mit Funkwellen, Funkamateure sogar mit dem Mond als Spiegel. | `tag13_radarwaechter` |
| 14 | **Zahlen per Licht** | Die LED blitzt eine Zahl, der Fotowiderstand zählt mit. An, aus, an, aus: So funktioniert ab morgen auch der Funk. | `tag14_lichtfunk` |

### Woche 3: Echter Funk auf 433 MHz

| Tag | Experiment | Was passiert | Sketch |
|---|---|---|---|
| 15 | **So klingt Funkstille** | Den 433-MHz-Empfänger einstecken und auf den Summer schalten: Er rauscht. Der Empfänger dreht so lange auf, bis er das Rauschen hört. | `tag15_rauschen` |
| 16 | **Eine Antenne bauen** | Zwei Drähte, je 17,3 cm: ein Viertel der Wellenlänge bei 433 MHz. Durch das Loch „ANT“ an Sender und Empfänger stecken und verdrillen. Mit dem Sketch von Tag 15 hören: Mit Antenne ändert sich das Rauschen, und ein telefonierendes Handy daneben knattert hinein. | `tag15_rauschen` |
| 17 | **Wer funkt denn hier?** | Der Arduino lauscht ohne Bibliothek auf Funk-Thermometer in der Nachbarschaft und liest Temperatur und Feuchte aus den Bits (Nexus- und inFactory-Format, getestet 18.11. mit Abgleich gegen rtl_433). Bonus: Fernbedienungen mit der Bibliothek rc-switch mitlesen. | `tag17_wetterlauscher` |
| 18 | **Der eigene Sender** | Umzug: Der Nano zieht ins Steckbrett und übernimmt den Empfänger. Der Uno bekommt den Sender an drei Kabeln und zwei Drahttasten. Pin-3-Draht an GND tippen: Auf dem Bildschirm des Nano steht 2412. Der erste eigene Funkspruch. | Uno: `tag18_fernbedienung`, Nano: `tag17_funklauscher` |
| 19 | **Die Keksdose als Funkbunker** | Wie gestern. Den Uno samt Sender in Alufolie wickeln oder in eine Keksdose legen: Funkstille. Ein Faradayscher Käfig, wie im Auto oder im Aufzug. Und Holz, Wasser, die Hand? Und ohne Antenne? | wie Tag 18 |
| 20 | **Die Weihnachtsfernbedienung** | Der Uno hängt jetzt an der Powerbank und ist frei beweglich. Der Nano schaltet die Kerzen und läutet die Glocke. Durch die Wohnung gehen: Wo reicht es noch? | Nano: `tag20_fernbedienung_empfaenger` |
| 21 | **Die Funk-Postkarte** | Taste 2 schickt „FROHE WEIHNACHTEN!“ Buchstabe für Buchstabe, der Nano zeigt den Text. Einen eigenen Gruß in den Sketch schreiben. So reisen auch SMS und WLAN-Daten: als lauter kleine Zahlen. | Nano: `tag21_funkpostkarte` |

### Woche 4: Zeit und Finale

| Tag | Experiment | Was passiert | Sketch |
|---|---|---|---|
| 22 | **Wie falsch geht der Arduino?** | Der Arduino zählt die Zeit seit dem Start. Zur vollen Minute starten, nach ein paar Stunden mit time.is vergleichen: Er geht falsch, oft um mehrere Sekunden pro Stunde. Genau dafür gibt es Funkuhren. | `tag22_arduinouhr` |
| 23 | **Die Atomuhr hören** | Für alle: Im Browser den WebSDR der Uni Twente öffnen (websdr.ewi.utwente.nl:8901), DCF77 aus der Stationsliste wählen. Man hört die Sekunden ticken, kurz und lang, aus Mainflingen bei Frankfurt. Am 16.11. getestet, das Ticken ist deutlich. Für Ambitionierte mit DCF77-Modul: Der Arduino empfängt selbst und zeigt nach 3 bis 5 Minuten die Uhrzeit (am 21.11. mit Modul getestet). | optional `tag23_atomuhr_modul`, Prüfhilfe `tag23_dcf_test` |
| 24 | **Finale: Der funkgesteuerte Weihnachtsbaum** | Taste 1 schaltet die Kerzen, Taste 2 schickt den Gruß und spielt Jingle Bells, und bei Dunkelheit gehen die Kerzen von selbst an. Bonus mit SDR-Stick: den eigenen Sender als Strich im Wasserfall sehen. | Nano: `tag24_finale` |

### Amateurfunk als roter Faden

Kein Lizenz-Vortrag, sondern kleine Häppchen: Die Tage 6, 10, 12, 13, 17, 20 und 23 haben am Ende eine
**📻 Funkamateur-Ecke** mit einer Geschichte aus dem Amateurfunk (Theremin, Gewitter auf Kurzwelle, Morse, Mond-Echo,
70-cm-Band, ISS, WebSDR). Am 24. folgt der Ausblick auf die Klasse N mit drei Schritten:
[50ohm.de](https://50ohm.de) (kostenlose Lernplattform des DARC), Ortsverband, WebSDR zum Zuhören.

## Hinter den Türchen

Wer den Kalender verschenken will und die Teile verteilen möchte:

| Tag | Neues Teil |
|---|---|
| 1 | Uno, USB-Kabel, Steckbrett, Steckbrücken, rote LED, 220 Ω |
| 3 | zwei weitere LEDs, zwei 220 Ω |
| 4 | Taster |
| 5 | passiver und aktiver Summer |
| 6 | Fotowiderstand, 10 kΩ |
| 8 | kurze Steckbrücke |
| 9 | Potentiometer |
| 10 | 50 cm Draht |
| 11 | Ultraschall-Sensor |
| 15 | 433-MHz-Empfänger |
| 16 | 2 × 17,3 cm Draht |
| 18 | Nano mit USB-C-Kabel, 433-MHz-Sender, drei Buchse-Stecker-Kabel |
| 19 | eine Keksdose, gern gefüllt |
| 20 | (Powerbank aus dem Haushalt) |
| 24 | ein Stück Schoki |

An den übrigen Tagen wird nur umgebaut.

## Rechtliches und Sicherheit

- **Strom:** Auf dem Steckbrett gibt es nur 5 V vom USB, das ist ungefährlich. Mit 230 V wird nie gearbeitet.
  Brumm-Melder und Knacks-Detektor halten den Draht nur in die Nähe von Wänden und geschlossenen Kabeln. Nichts
  aufschrauben, nicht in Steckdosen fassen, keine beschädigten Kabel.
- **433 MHz:** Der Bereich 433,05–434,79 MHz ist für Funkanwendungen geringer Reichweite allgemein zugeteilt, laut
  [mikrocontroller.net](https://www.mikrocontroller.net/articles/Allgemeinzuteilung) mit 10 mW ERP (Vfg 30/2014).
  Die aktuelle Fassung vor der Veröffentlichung bei der Bundesnetzagentur nachlesen. Im Text: Sender mit 5 V
  betreiben, nur auf Tastendruck senden, keine fremden Geräte anfunken.

## Offene Punkte

1. Platzprobe des Nano im 400er-Steckbrett des Miuzei-Kits (getestet wurde mit einem großen Brett und einem per
   Kabel angeschlossenen Nano).
2. Fotos der Aufbauten für die Tagesseiten.
