# 20. Dezember: Die Weihnachtsfernbedienung

**Heute neu:** nichts aus dem Kit. Du brauchst eine Powerbank oder ein Handy-Ladegerät.

## Aufbau

- **Nano:** [`tag20_fernbedienung_empfaenger.ino`](../sketches/tag20_fernbedienung_empfaenger/tag20_fernbedienung_empfaenger.ino)
  hochladen, er bleibt am PC.
- **Uno:** Hier musst du nichts neu hochladen, `tag18_fernbedienung` bleibt drauf. Steck ihn jetzt an eine
  **Powerbank** oder ein Handy-Ladegerät. Jetzt ist er frei beweglich.

## Was passiert

- **Taste 1** (Pin 3 kurz an GND tippen): Alle drei Kerzen am Nano gehen an und flackern. Noch mal tippen:
  aus. Im Monitor steht „Taste 1: Kerzen an“.
- **Taste 2** (Pin 4 kurz an GND tippen): Erst funkt der Uno ein paar Sekunden lang einen Weihnachtsgruß,
  Buchstabe für Buchstabe. Im Monitor erscheint dafür eine Reihe Punkte. Lesen kannst du ihn morgen. Danach
  läutet die Glocke.

Tipp: Nur kurz antippen, nicht festhalten.

## Probier mal: Wie weit reicht es?

Nimm den Uno und geh durch die Wohnung. Tipp alle paar Meter auf Taste 1. Wo kommt es noch an?

- Im Nebenzimmer?
- Durch zwei Wände?
- Ein Stockwerk tiefer?
- Im Garten?

Mal eine Karte deiner Wohnung und trag ein, wo es klappt.

## Übrigens

Die Sendeleistung ist winzig, ein paar Tausendstel Watt. Ein Handy sendet bis zu hundertmal stärker. Trotzdem
schaffst du durch mehrere Wände. Funkamateure bauen mit wenigen Watt Verbindungen um die halbe Welt.

> 📻 **Funkamateur-Ecke:** Auf der Internationalen Raumstation ISS steht eine Amateurfunkstation. Astronauten sprechen darüber regelmäßig mit Schulklassen auf der Erde, mit einer Funkleistung, die kaum größer ist als die eines Handfunkgeräts. Wer eine Lizenz hat, kann die ISS sogar selbst anfunken.

## Klappt nicht?

- **Glocke still, aber im Monitor steht „Taste 2: Glocke!“?** Dann kommt der Funk an, und es liegt am Summer.
  Sitzt er wirklich in **i24** und das Kabel von **D9** in **f24**? Seit dem Umzug an Tag 18 ist alles eine Reihe
  anders als vorher, da verrutscht man leicht.
- **Im Monitor nur Zahlen statt „Taste 1: …“?** Dann läuft auf dem Nano noch das Programm von gestern.
- **Nichts kommt an?** Hat der Uno noch `tag18_fernbedienung` drauf, und steckt die Antenne am Sender?
