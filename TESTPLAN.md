# Testplan mit den eigenen Teilen

Ziel: jeden Tag einmal echt aufbauen, bevor der Kalender beworben wird. Ergebnis in die Spalte eintragen
(✅ klappt, ⚠️ klappt mit Änderung, ❌ klappt nicht) und Auffälligkeiten als Issue oder direkt in den Tagestext.

## Teile aus dem eigenen Bestand

| Kalender braucht | Aus dem Bestand |
|---|---|
| Uno | Arduino Uno R3 (einzeln) |
| Nano | einer der vorhandenen Nanos. Bei Mini-USB das passende Kabel nehmen, in der IDE ggf. „ATmega328P (Old Bootloader)“ wählen |
| Steckbrett, LEDs, Widerstände, Taster, Poti, Summer, Fotowiderstand, HC-SR04 | Elegoo UNO R3 Most Complete Starter Kit, LED-Kit |
| 433-MHz-Sender und -Empfänger | 2 × FS1000A, 3 × Empfänger. **Vorher Aufdruck auf dem Metallbauteil prüfen: 433?** |
| Steckbrett 400 Kontakte | Falls nur ein 830er da ist: geht auch, die Reihen 1–30 einfach von oben zählen |

## Tage

| Tag | Was prüfen | Erwartet | Ergebnis |
|---|---|---|---|
| 1 | LED leuchtet ohne Programm | rote LED an | |
| 2 | Blink-Sketch, `delay(20)` | Blinken, ab ca. 20 ms Dauerleuchten | |
| 3 | drei Kerzen | rot/gelb flackern weich, grün springt an/aus | |
| 4 | Taster schaltet um | Druck = an, Druck = aus | |
| 5 | Jingle Bells, dann aktiver Summer | Melodie, aktiver schnarrt nur. **Summer quer (i25/Minus-Schiene) passt?** | |
| 6 | Licht-Theremin | Ton folgt der Hand | |
| 7 | Nachtlicht, Wert `DUNKEL` | Kerzen gehen bei Dunkelheit an. Optional: `uebrigens_lampenflackern` zeigt 100 Hz? **(prüfen)** | |
| 8 | offener Eingang im Plotter | 50-Hz-Welle am Monitorkabel | |
| 9 | Kabelsucher mit Powerbank | Piepen an der Wandleitung, Poti stellt ein | |
| 10 | Knacks-Detektor | Lichtschalter löst Knacks aus **(prüfen: Schwelle)** | |
| 11 | Ultraschall-Theremin | Ton folgt dem Abstand 2–40 cm | |
| 12 | Körper-Antenne | Welle wird beim Anfassen größer | |
| 13 | Störungsjagd am Schreibtisch | Netzteile unterscheiden sich | |
| 14 | Zahlen per Licht | „Stimmt!“ **(prüfen: Tempo, LDR-Trägheit)** | |
| 15 | Rauschen des Empfängers | Summer rauscht, Plotter zappelt | |
| 16 | rc-switch lauscht | eigene Fernbedienung/Klingel zeigt Code, sonst nichts | |
| 17 | Antennen 17,3 cm | Rauschen ändert sich | |
| 18 | Umbau, Nano empfängt 2412 | **Platzprobe Nano auf dem Steckbrett, Pinbelegung wie im Steckplan?** | |
| 19 | Alufolie, Keksdose | Keksdose = Funkstille | |
| 20 | Fernbedienung mit Powerbank | Kerzen an/aus aus dem Nebenzimmer, Glocke | |
| 21 | Funk-Postkarte | alle Buchstaben kommen an? **(prüfen)** | |
| 22 | Arduino-Uhr | nach 1 h einige Sekunden Abweichung | |
| 23 | WebSDR DCF77 | Ticken hörbar. Mit Modul: Uhrzeit im Monitor **(prüfen: Pegel)** | |
| 24 | Finale | Taste 1 Kerzen, Taste 2 Gruß + Jingle Bells, Dunkel = Kerzen an | |

## Nach dem Test

- Was nicht passt, im Tagestext unter `kalender/` ändern. Bei geändertem Aufbau zusätzlich `tools/steckbilder.py`
  anpassen, `python3 tools/steckbilder.py` und `python3 tools/pruefe_steckbilder.py` laufen lassen und in
  `assets/app.js` die `BILD_VERSION` um eins erhöhen.
- Fotos nach `bilder/fotos/` legen, Claude baut sie in die Tagesseiten ein.
