# 9. Dezember: Der Brumm-Melder

**Heute neu:** Potentiometer (Drehknopf). Aus dem Haushalt: ein Verlängerungskabel oder eine Schreibtischlampe.

Gestern hast du gesehen, wie viel Strom in der Luft liegt. Heute baust du daraus einen Melder, der piept, sobald
Strom in der Nähe ist. Wie ein Geigerzähler, nur für Stromkabel.

## Aufbau

Das Potentiometer mit den drei Beinen in **c2, c3, c4** (passen sie nicht, dann in 2, 4 und 6). a2 → linke +,
a4 → linke −, das mittlere Bein a3 → **A2**. Die kurze Steckbrücke von gestern bleibt in A0.

## Programm

[`tag09_kabelsucher.ino`](../sketches/tag09_kabelsucher/tag09_kabelsucher.ino), dann den **Seriellen Monitor**
öffnen (115200 Baud). Dort stehen zwei Zahlen: die Stärke und die Schwelle, ab der es piept.

## Einstellen

Hände weg von der Steckbrücke. Dreh den Knopf so, dass es gerade **nicht** piept. Die Schwelle steht dann etwas
über der Stärke in Ruhe.

## Was passiert

Das Steckbrett bleibt liegen. Heute kommen die Dinge zur Antenne, nicht umgekehrt.

1. **Hand nähern**, ohne zu berühren: Ab einem bestimmten Abstand leuchtet die rote Kerze und der Summer piept.
   Je näher, desto höher der Ton.
2. **Verlängerungskabel**: Steck es in die Steckdose (sonst nichts daran) und bring das Kabel langsam an die
   Steckbrücke heran. Schon mit etwas Abstand piept es, direkt daneben geht die Stärke bis zum Anschlag.
3. **Stecker ziehen**: Das gleiche Kabel, aber nicht eingesteckt. Stille! Das Kabel ist dasselbe, nur der Strom
   fehlt.

## Probier mal

- Schreibtischlampe: Kabel an die Steckbrücke legen und die Lampe am Schalter an- und ausmachen. Ändert sich etwas?
- Handy-Ladegerät, Laptop-Netzteil, Steckdosenleiste: Wer brummt am lautesten?
- Dreh den Knopf ganz nach links: Jetzt ist der Melder so empfindlich, dass er schon auf dich reagiert, wenn du
  dich vorbeugst.

## Für Mutige: Kabel in der Wand suchen

Der Sketch bleibt im Uno gespeichert, auch ohne PC. Mit einer **Powerbank** statt des PCs kannst du das
Steckbrett zur Wand tragen und die Leitung vom Lichtschalter zur Deckenlampe suchen. Ehrlich gesagt klappt das nur
mäßig: Deine Hand am Steckbrett stört mehr als die Leitung hinter dem Putz. Halt das Steckbrett möglichst weit vorn
an der Kante und dreh den Knopf nach, bis es in der Luft still ist. Profi-Leitungssucher haben genau dafür eine
Abschirmung eingebaut.

## Sicherheit

**Nur von außen.** Nichts aufschrauben, nicht in Steckdosen stecken, nicht an kaputte Kabel. Das
Verlängerungskabel bleibt heil und ganz normal eingesteckt.

## Übrigens

Das Potentiometer ist ein Widerstand mit Schleifer. Es teilt die 5 Volt auf, je nachdem, wie weit du drehst. Der
Arduino liest das an A2 als Zahl und macht daraus die Schwelle, ab der es piept.

Und warum piept das ausgesteckte Kabel nicht? Das elektrische Feld entsteht durch die Spannung im Kabel, die
50-mal pro Sekunde hin- und herschwingt. Ohne Stecker keine Spannung, kein Feld. Dafür muss nicht einmal ein Gerät
eingeschaltet sein.
