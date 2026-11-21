# Kurzvorstellung für das Elektronik-Labor (für den 30.11.)

Zugesagt an Burkhard Kainka bis Sonntag, 22.11. Als Mail mit drei Bildern im Anhang:
`werbung/bilder/aufbau_nano.jpg`, `werbung/bilder/plotter_anfassen.png` und `werbung/bilder/dcf_modul.jpg`
(optional als viertes `werbung/bilder/dcf_funkzeit.png`).

---

**Betreff:** Kurzvorstellung Funk-Adventskalender für das Elektronik-Labor

Hallo Herr Kainka,

wie versprochen hier die Kurzvorstellung. Kürzen oder umstellen Sie gern, wie es für das Elektronik-Labor passt.
Drei Bilder hängen an.

Viele Grüße
Stefan Kaufmann

---

## Der Funk-Adventskalender: Das Unsichtbare hören

**https://craebby.github.io/funk-adventskalender/**

Die Luft um uns herum ist voller Signale: das 50-Hz-Feld der Hausleitungen, die Funken im Lichtschalter, die
Funk-Thermometer der Nachbarn, die Atomuhr aus Mainflingen. Der Funk-Adventskalender macht sie in 24 kleinen
Experimenten hörbar und sichtbar, jeden Tag ein Türchen mit 15 bis 30 Minuten Bastelzeit.

Gebaut wird auf dem Steckbrett, ohne Löten, mit einem Arduino Uno und ab der dritten Woche einem Nano dazu. Die
Programme gibt es fertig zum Kopieren, Steckbilder zeigen jede Verbindung Loch für Loch. Die Teile liegen bei vielen
ohnehin in der Bastelkiste: ein paar LEDs und Widerstände, Taster, Fotowiderstand, Poti, passiver Summer, ein
Ultraschall-Sensor und ein einfaches 433-MHz-Sender-Empfänger-Paar. Eine Materialliste liegt bei. Wer nichts
hat, kommt mit fertigen Sets auf rund 40 €, und alle Teile bleiben danach heil.

**Was hinter den Türchen steckt, nur angedeutet:**

- **Woche 1:** Licht, Klang und das erste eigene Instrument.
- **Woche 2:** Ein offener Analogeingang zeigt im Seriellen Plotter das Netzbrummen, sobald man die Hand nähert.
  Danach wird es hörbar, und der Arduino meldet jeden Funken, den ein Schalter im Haus erzeugt. Ultraschall und
  ein Morse-Übersetzer kommen dazu.
- **Woche 3:** Echter Funk auf 433 MHz mit selbst gebauter Viertelwellen-Antenne. Der Arduino liest ohne
  Bibliothek die Funk-Thermometer der Nachbarschaft mit und wird dann selbst zum Sender.
- **Woche 4:** Wie falsch geht eigentlich die Arduino-Uhr? Danach die Atomuhr DCF77, über einen WebSDR im Browser
  oder mit eigenem Modul, und an Heiligabend ein Weihnachtsbaum mit Funkfernbedienung.

Zwischendurch gibt es eine kleine „Funkamateur-Ecke“. Wer Feuer gefangen hat, findet am Ende den Weg zur
Einsteigerlizenz N über 50ohm.de und den nächsten Ortsverband.

**Wie er entstanden ist:** Inspiriert haben mich die Elektronik-Adventskalender, die viele aus dem
Elektronik-Labor kennen, und besonders der FriFle-Advent von 2023. Entwickelt habe ich den Kalender zusammen
mit einer KI: Konzept, Programme, Texte und Steckbilder. Anschließend habe ich jeden Tag selbst auf dem
Steckbrett nachgebaut, und dabei kam einiges ans Licht. Der Decoder für die Funk-Thermometer brauchte mehrere
Anläufe am echten Empfänger. Ein geplanter „Kabelsucher“ wurde zum „Brumm-Melder“, weil der offene Eingang
schlicht übersteuerte. Und Stolperfallen wie Pin 4 statt A4 oder „Nano Every“ statt „Nano“ in der IDE stehen
jetzt als Hinweise im Text. Eine KI schreibt schnell Programme, aber erst das echte Steckbrett zeigt, ob sie
funktionieren. Zuletzt gilt das für die Atomuhr: Neben PC und Funkgerät ging im Rauschen jede dritte
Sekundenmarke verloren. Erst ein Programm, das wie eine echte Funkuhr mehrere Minuten übereinanderlegt, und ein
Platz zwei, drei Meter weiter am Fenster brachten die Uhrzeit, dann aber Minute für Minute zuverlässig.

Alles ist kostenlos und offen unter MIT-Lizenz, Quellcode auf GitHub:
https://github.com/craebby/funk-adventskalender. Über Rückmeldungen und Fotos von Aufbauten freue ich mich sehr.

*Bild 1: Mein Testaufbau mit dem Nano auf dem Steckbrett.*
*Bild 2: Der Serielle Plotter beim Anfassen der Steckbrücke an A0: das Netzbrummen, so stark, dass der Eingang
voll ausschlägt.*
*Bild 3: Ein DCF77-Modul mit Ferritantenne auf dem Steckbrett, daneben die Kerzen-LEDs.*
*(Optional Bild 4: Der Serielle Monitor zeigt Minute für Minute die Funkzeit.)*
