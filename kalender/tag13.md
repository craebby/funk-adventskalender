# 13. Dezember: Der Radar-Wächter

**Heute neu:** nichts. Der Ultraschall-Sensor von Tag 11 bekommt einen neuen Job.

An Tag 11 hast du mit dem Echo Musik gemacht. Heute bewacht es dein Zimmer.

## Aufbau

Alles bleibt, wie es ist. Leg das Steckbrett so auf den Tisch, dass die beiden „Augen“ des Sensors quer durchs
Zimmer zeigen, am besten auf eine Wand oder einen Schrank, 1 bis 3 Meter entfernt. Oder auf die Zimmertür.

## Programm

[`tag13_radarwaechter.ino`](../sketches/tag13_radarwaechter/tag13_radarwaechter.ino), dann den **Seriellen
Monitor** öffnen (115200 Baud).

## Was passiert

1. Nach dem Start bittet der Arduino dich, aus dem Weg zu gehen. Zwei Sekunden später misst er die freie Strecke,
   zum Beispiel „Freie Strecke: 214 cm. Wache aktiv!“ und piept einmal.
2. Jetzt geh durch den Strahl. Piep! Die rote Kerze leuchtet, und im Monitor steht:
   „Besuch Nr. 1 in 120 cm Entfernung, nach 14 Sekunden“.

Der Wächter merkt sich jeden Besuch, mit Abstand und Zeit.

## Probier mal

- Wie schnell kannst du durchhuschen, ohne dass er dich bemerkt?
- Lass ihn eine Weile an der Tür wachen, während du weg bist. Wer war im Zimmer? Die Katze, die Geschwister?
- Halt ein Kissen in den Strahl, dann ein Blatt Papier schräg. Weiches und schräges Zeug schluckt das Echo oder
  lenkt es ab. Genau so funktionieren Tarnkappen-Flugzeuge.
- Klappt die Erkennung nicht? Wenn die Wand weiter als etwa 3 Meter weg ist, kommt kein Echo mehr zurück. Dann
  näher an ein Möbelstück zielen und den Uno neu starten (Reset-Knopf).

## Übrigens

Radar macht genau dasselbe, nur mit Funkwellen statt Schall: rufen, auf das Echo warten, aus der Zeit die
Entfernung ausrechnen. Damit sehen Fluglotsen jedes Flugzeug, Schiffe finden im Nebel den Hafen, und der
Wetterdienst sieht Regenwolken, bevor es nass wird.

> 📻 **Funkamateur-Ecke:** Funkamateure benutzen den **Mond** als Spiegel. Sie senden mit großen Antennen zum
> Mond und hören ihr eigenes Echo etwa 2,5 Sekunden später wieder, nach fast 770.000 Kilometern Reise. So können
> zwei Funkamateure auf verschiedenen Kontinenten über den Mond miteinander funken. Das heißt
> Erde-Mond-Erde-Verbindung.
