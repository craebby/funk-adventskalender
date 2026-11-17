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
| 1 | LED leuchtet ohne Programm | rote LED an | ✅ 17.11. 220 Ω aus Fritzing-Kiste, LED eher schwach. Brett: links + außen, rechts + innen → Farbhinweis ergänzt |
| 2 | Blink-Sketch, `delay(20)` | Blinken, ab ca. 20 ms Dauerleuchten | ✅ 17.11. |
| 3 | drei Kerzen | rot/gelb flackern weich, grün springt an/aus | ✅ 17.11. |
| 4 | Taster schaltet um | Druck = an, Druck = aus | |
| 5 | Jingle Bells, dann aktiver Summer | Melodie, aktiver schnarrt nur. **Summer quer (i25/Minus-Schiene) passt?** | ✅ 17.11. Aktiver Summer spielt die Melodie auch, nur kratzig. Piezo-Scheibe als Ersatz für den passiven klappt prima → Text angepasst |
| 6 | Licht-Theremin | Ton folgt der Hand | |
| 7 | Nachtlicht, Wert `DUNKEL` | Kerzen gehen bei Dunkelheit an. Optional: `uebrigens_lampenflackern` zeigt 100 Hz? **(prüfen)** | |
| 8 | offener Eingang im Plotter | Welle + Staerke | ⚠️ 17.11. Mit 1 m Draht übersteuert (Ruhe 800–1000). Mit kurzer Steckbrücke: Ruhe ~170, seitlich nähern 200–250, Isolierung 350, Spitze antippen 700+. Sketch auf Welle/Staerke umgebaut, Text angepasst |
| 9 | Brumm-Melder am Schreibtisch | Hand nähern piept, Verlängerungskabel eingesteckt piept, ausgesteckt still | ✅ 17.11. Wandsuche unpraktisch → zum Brumm-Melder am Schreibtisch umgebaut, klappt |
| 10 | Knacks-Detektor am Schreibtisch | Schalter neben dem Draht → Knacks | ⚠️ 17.11. Mit kurzer Steckbrücke nichts. Mit 50 cm Draht und Poti fast bis kein Auslösen in Ruhe: Aktenvernichter und Schalter der Schreibtischlampe knacken → Text angepasst |
| 11 | Ultraschall-Theremin | Ton folgt dem Abstand 2–40 cm | ✅ 17.11. Erst an A4 statt Pin 4 gesteckt → Warnkasten ergänzt |
| 12 | Morse-Übersetzer (neu 17.11.) | Taster piept, Monitor zeigt `... = S`. **(prüfen: Tempo LANG 250 ms passt?)** | |
| 13 | Radar-Wächter (neu 17.11.) | Freie Strecke wird gemessen, Durchlaufen zählt als Besuch. **(prüfen: Reichweite, Fehlalarme)** | |
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
