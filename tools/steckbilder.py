#!/usr/bin/env python3
"""Erzeugt fuer jeden Kalendertag ein einfaches Steckbild als SVG (bilder/tagNN.svg).

Grundlage ist kalender/steckplan.md. Teile, die an diesem Tag neu dazukommen, werden gelb umrandet.
Aufruf: python3 tools/steckbilder.py
"""
from pathlib import Path

P = 16                      # Lochabstand in Pixeln
X0, Y0 = 250, 60            # linke obere Ecke des Steckbretts (erstes Loch)
SPALTEN = {"L+": 0, "L-": 1, "a": 3, "b": 4, "c": 5, "d": 6, "e": 7,
           "f": 9, "g": 10, "h": 11, "i": 12, "j": 13, "R-": 15, "R+": 16}
REIHEN = 30
BREITE, HOEHE = 860, Y0 + REIHEN * P + 50

FARBE = {"rot": "#e53935", "gelb": "#fdd835", "gruen": "#43a047", "plus": "#e53935",
         "minus": "#1e88e5", "draht": "#8e24aa", "signal": "#fb8c00", "analog": "#00897b"}


def x(spalte):
    return X0 + SPALTEN[spalte] * P


def y(reihe):
    return Y0 + (reihe - 1) * P


def loch(name):
    """'a10' -> (x, y), 'L+17' -> Schiene"""
    for s in ("L+", "L-", "R+", "R-"):
        if name.startswith(s):
            return x(s), y(int(name[len(s):]))
    return x(name[0]), y(int(name[1:]))


class Bild:
    def __init__(self, titel):
        self.teile = []
        self.titel = titel

    def add(self, svg, neu=False):
        if neu:
            svg = f'<g class="neu" filter="url(#glow)">{svg}</g>'
        self.teile.append(svg)

    def svg(self):
        kopf = (f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {BREITE} {HOEHE}" '
                f'font-family="sans-serif" font-size="11">'
                '<defs><filter id="glow" x="-50%" y="-50%" width="200%" height="200%">'
                '<feDropShadow dx="0" dy="0" stdDeviation="2.5" flood-color="#ffd400" flood-opacity="1"/>'
                '</filter></defs>'
                f'<rect width="{BREITE}" height="{HOEHE}" fill="#fafafa"/>'
                f'<text x="16" y="26" font-size="16" font-weight="bold">{self.titel}</text>'
                f'<text x="{BREITE - 16}" y="26" text-anchor="end" fill="#b8860b">gelb leuchtend = heute neu</text>')
        return kopf + steckbrett() + "".join(self.teile) + "</svg>"


def steckbrett():
    teile = [f'<rect x="{x("L+") - 12}" y="{Y0 - 22}" width="{x("R+") - x("L+") + 24}" '
             f'height="{REIHEN * P + 30}" rx="8" fill="#ffffff" stroke="#bbb"/>',
             f'<rect x="{x("e") + 5}" y="{Y0 - 10}" width="{x("f") - x("e") - 10}" height="{REIHEN * P}" fill="#e8e8e8"/>']
    for s in ("L+", "R+"):
        teile.append(f'<line x1="{x(s)}" y1="{Y0 - 14}" x2="{x(s)}" y2="{y(REIHEN) + 10}" stroke="{FARBE["plus"]}" stroke-width="1"/>')
    for s in ("L-", "R-"):
        teile.append(f'<line x1="{x(s)}" y1="{Y0 - 14}" x2="{x(s)}" y2="{y(REIHEN) + 10}" stroke="{FARBE["minus"]}" stroke-width="1"/>')
    for s in SPALTEN:
        label = {"L+": "+", "R+": "+", "L-": "−", "R-": "−"}.get(s, s)
        teile.append(f'<text x="{x(s)}" y="{Y0 - 26}" text-anchor="middle" fill="#666">{label}</text>')
        for r in range(1, REIHEN + 1):
            teile.append(f'<rect x="{x(s) - 2.5}" y="{y(r) - 2.5}" width="5" height="5" fill="#555"/>')
    for r in range(1, REIHEN + 1):
        if r == 1 or r % 5 == 0:
            teile.append(f'<text x="{x("a") - 10}" y="{y(r) + 4}" text-anchor="end" fill="#999" font-size="9">{r}</text>')
            teile.append(f'<text x="{x("j") + 10}" y="{y(r) + 4}" fill="#999" font-size="9">{r}</text>')
    return "".join(teile)


def draht(p1, p2, farbe, breite=3):
    (x1, y1), (x2, y2) = p1, p2
    mx = (x1 + x2) / 2
    return (f'<path d="M{x1},{y1} C{mx},{y1} {mx},{y2} {x2},{y2}" fill="none" stroke="{farbe}" '
            f'stroke-width="{breite}" stroke-linecap="round" opacity="0.9"/>')


def widerstand(h1, h2, label):
    (x1, y1), (x2, y2) = loch(h1), loch(h2)
    mx, my = (x1 + x2) / 2, (y1 + y2) / 2
    return (f'<line x1="{x1}" y1="{y1}" x2="{x2}" y2="{y2}" stroke="#777" stroke-width="2"/>'
            f'<rect x="{mx - 11}" y="{my - 5}" width="22" height="10" rx="4" fill="#d7b98e" stroke="#8d6e63"/>'
            f'<text x="{mx}" y="{my - 8}" text-anchor="middle" font-size="9">{label}</text>')


def led(anode, kathode, farbe):
    (x1, y1), (x2, y2) = loch(anode), loch(kathode)
    bx, by = (x1 + x2) / 2, min(y1, y2) - 9
    return (f'<line x1="{x1}" y1="{y1}" x2="{bx - 3}" y2="{by + 5}" stroke="#777" stroke-width="2"/>'
            f'<line x1="{x2}" y1="{y2}" x2="{bx + 3}" y2="{by + 5}" stroke="#777" stroke-width="2"/>'
            f'<circle cx="{bx}" cy="{by}" r="7" fill="{farbe}" stroke="#333"/>'
            f'<text x="{bx + 10}" y="{by - 6}" font-size="8" fill="#555">lang</text>')


def taster(r1, r2):
    x1, y1 = loch(f"e{r1}")
    x2, y2 = loch(f"f{r2}")
    return (f'<rect x="{x1 - 5}" y="{y1 - 5}" width="{x2 - x1 + 10}" height="{y2 - y1 + 10}" rx="3" fill="#333"/>'
            f'<circle cx="{(x1 + x2) / 2}" cy="{(y1 + y2) / 2}" r="9" fill="#555" stroke="#111"/>'
            f'<text x="{x2 + 10}" y="{(y1 + y2) / 2 + 4}" font-size="9">Taster</text>')


def summer(plus, minus):
    (x1, y1), (x2, y2) = loch(plus), loch(minus)
    return (f'<circle cx="{x1 + 18}" cy="{(y1 + y2) / 2}" r="{(y2 - y1) / 2 + 2}" fill="#222" stroke="#000"/>'
            f'<circle cx="{x1 + 18}" cy="{(y1 + y2) / 2}" r="3" fill="#666"/>'
            f'<text x="{x1 + 18}" y="{y1 - 10}" text-anchor="middle" font-size="9">Summer (passiv) +</text>'
            f'<line x1="{x1}" y1="{y1}" x2="{x1 + 10}" y2="{y1 + 4}" stroke="#777" stroke-width="2"/>'
            f'<line x1="{x2}" y1="{y2}" x2="{x2 + 10}" y2="{y2 - 4}" stroke="#777" stroke-width="2"/>')


def fotowiderstand(h1, h2):
    (x1, y1), (x2, y2) = loch(h1), loch(h2)
    return (f'<ellipse cx="{x1 + 2}" cy="{(y1 + y2) / 2}" rx="7" ry="{(y2 - y1) / 2 + 5}" fill="#ffb74d" stroke="#e65100"/>'
            f'<path d="M{x1 - 3},{y1 + 2} l6,3 l-6,3 l6,3" stroke="#bf360c" fill="none"/>'
            f'<text x="{x1 - 12}" y="{y1 - 6}" text-anchor="end" font-size="9">Fotowiderstand</text>')


def poti(reihen):
    xs, ys = loch(f"c{reihen[0]}")
    _, ye = loch(f"c{reihen[-1]}")
    return (f'<rect x="{xs - 10}" y="{ys - 7}" width="20" height="{ye - ys + 14}" rx="3" fill="#1565c0"/>'
            f'<circle cx="{xs}" cy="{(ys + ye) / 2}" r="6" fill="#fff" stroke="#0d47a1"/>'
            f'<text x="{xs - 14}" y="{(ys + ye) / 2 + 4}" text-anchor="end" font-size="9">Poti</text>')


def ultraschall():
    x1, y1 = loch("i2")
    _, y2 = loch("i5")
    bx = x1 + 6
    return (f'<rect x="{bx}" y="{y1 - 10}" width="60" height="{y2 - y1 + 20}" rx="3" fill="#1976d2" stroke="#0d47a1"/>'
            f'<circle cx="{bx + 22}" cy="{y1 + 4}" r="9" fill="#cfd8dc" stroke="#607d8b"/>'
            f'<circle cx="{bx + 22}" cy="{y2 - 4}" r="9" fill="#cfd8dc" stroke="#607d8b"/>'
            f'<text x="{bx + 64}" y="{y1 + 4}" font-size="9">HC-SR04</text>'
            f'<text x="{bx + 64}" y="{y1 + 16}" font-size="8" fill="#555">VCC, Trig, Echo, GND</text>'
            + "".join(f'<rect x="{x1 - 2.5}" y="{loch(f"i{r}")[1] - 2.5}" width="5" height="5" fill="#ffd54f"/>' for r in range(2, 6)))


def empfaenger(r0, antenne=False):
    x1, y1 = loch(f"c{r0}")
    _, y2 = loch(f"c{r0 + 3}")
    s = (f'<rect x="{x1 - 8}" y="{y1 - 8}" width="16" height="{y2 - y1 + 16}" rx="2" fill="#2e7d32" stroke="#1b5e20"/>'
         f'<text x="{x1 - 12}" y="{y1 + 4}" text-anchor="end" font-size="9">433-MHz-</text>'
         f'<text x="{x1 - 12}" y="{y1 + 15}" text-anchor="end" font-size="9">Empfänger</text>'
         f'<text x="{x1 - 12}" y="{y1 + 26}" text-anchor="end" font-size="8" fill="#555">VCC/DATA/DATA/GND</text>')
    if antenne:
        s += (f'<path d="M{x1},{y2 + 8} q-30,20 -40,60" stroke="#795548" stroke-width="2" fill="none"/>'
              f'<text x="{x1 - 44}" y="{y2 + 80}" font-size="9">Antenne 17,3 cm</text>')
    return s


def nano():
    x1, y1 = loch("d1")
    x2, y2 = loch("h15")
    links = ["D13", "3V3", "AREF", "A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "5V", "RST", "GND", "VIN"]
    rechts = ["D12", "D11", "D10", "D9", "D8", "D7", "D6", "D5", "D4", "D3", "D2", "GND", "RST", "RX0", "TX1"]
    s = (f'<rect x="{x1 - 8}" y="{y1 - 14}" width="{x2 - x1 + 16}" height="{y2 - y1 + 22}" rx="3" fill="#0d47a1" opacity="0.92"/>'
         f'<rect x="{(x1 + x2) / 2 - 12}" y="{y1 - 22}" width="24" height="12" rx="3" fill="#bdbdbd"/>'
         f'<text x="{(x1 + x2) / 2}" y="{(y1 + y2) / 2}" text-anchor="middle" fill="#fff" font-size="12" font-weight="bold">Nano</text>'
         f'<text x="{(x1 + x2) / 2}" y="{y1 - 26}" text-anchor="middle" font-size="9">USB-C</text>')
    for i, (l, r) in enumerate(zip(links, rechts)):
        yy = y(i + 1)
        s += (f'<text x="{x1 + 6}" y="{yy + 3}" fill="#fff" font-size="8">{l}</text>'
              f'<text x="{x2 - 6}" y="{yy + 3}" fill="#fff" font-size="8" text-anchor="end">{r}</text>'
              f'<rect x="{x1 - 2.5}" y="{yy - 2.5}" width="5" height="5" fill="#ffd54f"/>'
              f'<rect x="{x2 - 2.5}" y="{yy - 2.5}" width="5" height="5" fill="#ffd54f"/>')
    return s


# --- Der Uno links neben dem Steckbrett (Woche 1 bis 3) ---
UNO_PINS = ["5V", "GND", "A0", "A1", "A2", "Pin 2", "Pin 3", "Pin 4", "Pin 5", "Pin 6", "Pin 7", "Pin 8", "Pin 9", "Pin 10"]


def uno_pin(name):
    return 150, 70 + UNO_PINS.index(name) * 26


def uno():
    s = (f'<rect x="20" y="50" width="130" height="{len(UNO_PINS) * 26 + 20}" rx="8" fill="#00838f"/>'
         f'<text x="30" y="{50 + len(UNO_PINS) * 26 + 6}" fill="#fff" font-size="14" font-weight="bold">Uno</text>')
    for p in UNO_PINS:
        px, py = uno_pin(p)
        s += (f'<text x="{px - 10}" y="{py + 4}" text-anchor="end" fill="#fff">{p}</text>'
              f'<rect x="{px - 6}" y="{py - 5}" width="10" height="10" fill="#222"/>')
    return s


PIN_FARBE = {"Pin 2": "#6d4c41", "Pin 3": "#00acc1", "Pin 4": "#7cb342", "Pin 5": "#fb8c00", "Pin 6": "#f9a825",
             "Pin 7": "#2e7d32", "Pin 8": "#5e35b1", "Pin 9": "#d81b60", "Pin 10": "#3949ab", "A0": "#795548",
             "A1": "#00897b", "A2": "#26a69a", "D2": "#6d4c41", "D5": "#fb8c00", "D6": "#f9a825", "D7": "#2e7d32",
             "D9": "#d81b60"}


def uno_draht(pin, ziel, farbe):
    return draht(uno_pin(pin), loch(ziel), PIN_FARBE.get(pin, farbe))


def tag_bild(t):
    b = Bild(f"Steckbild Tag {t}")
    neu = lambda von: von == t  # noqa: E731

    if t <= 17:
        b.add(uno())
        b.add(uno_draht("5V", "L+3", FARBE["plus"]), neu(1))
        b.add(uno_draht("GND", "L-4", FARBE["minus"]), neu(1))
        b.add(draht(loch("L+30"), loch("R+30"), FARBE["plus"], 2), neu(1))
        b.add(draht(loch("L-29"), loch("R-29"), FARBE["minus"], 2), neu(1))
        # Kerze 1
        b.add(widerstand("e10", "f10", "220 Ω"), neu(1))
        b.add(led("j10", "R-10", FARBE["rot"]), neu(1))
        if t == 1:
            b.add(draht(loch("L+10"), loch("a10"), FARBE["plus"]), True)
        else:
            b.add(uno_draht("Pin 5", "a10", FARBE["signal"]), neu(2))
        if t >= 3:
            for r, pin, f in ((13, "Pin 6", "gelb"), (16, "Pin 7", "gruen")):
                b.add(widerstand(f"e{r}", f"f{r}", "220 Ω"), neu(3))
                b.add(led(f"j{r}", f"R-{r}", FARBE[f]), neu(3))
                b.add(uno_draht(pin, f"a{r}", FARBE["signal"]), neu(3))
        if t >= 4:
            b.add(taster(20, 22), neu(4))
            b.add(uno_draht("Pin 3", "a20", FARBE["signal"]), neu(4))
            b.add(draht(loch("a22"), loch("L-22"), FARBE["minus"], 2), neu(4))
        if t >= 5:
            b.add(summer("f25", "f28"), neu(5))
            b.add(uno_draht("Pin 9", "j25", FARBE["signal"]), neu(5))
            b.add(draht(loch("j28"), loch("R-28"), FARBE["minus"], 2), neu(5))
        if t >= 6:
            b.add(fotowiderstand("c17", "c18"), neu(6))
            b.add(draht(loch("L+17"), loch("a17"), FARBE["plus"], 2), neu(6))
            b.add(uno_draht("A1", "a18", FARBE["analog"]), neu(6))
            b.add(widerstand("b18", "L-18", "10 kΩ"), neu(6))
        if 8 <= t <= 13:
            ax, ay = uno_pin("A0")
            b.add(f'<path d="M{ax},{ay} C 200,{ay + 40} 60,{ay + 300} 180,{ay + 420}" stroke="#795548" '
                  f'stroke-width="3" fill="none"/><text x="160" y="{ay + 440}" font-size="10">'
                  f'Antennendraht ca. 1 m, Ende frei</text>', neu(8))
        if t >= 9:
            b.add(poti([2, 3, 4]), neu(9))
            b.add(draht(loch("L+2"), loch("a2"), FARBE["plus"], 2), neu(9))
            b.add(draht(loch("a4"), loch("L-4"), FARBE["minus"], 2), neu(9))
            b.add(uno_draht("A2", "a3", FARBE["analog"]), neu(9))
        if t >= 11:
            b.add(ultraschall(), neu(11))
            b.add(draht(loch("f2"), loch("R+2"), FARBE["plus"], 2), neu(11))
            b.add(uno_draht("Pin 4", "f3", FARBE["signal"]), neu(11))
            b.add(uno_draht("Pin 8", "f4", FARBE["signal"]), neu(11))
            b.add(draht(loch("f5"), loch("R-5"), FARBE["minus"], 2), neu(11))
        if t >= 15:
            b.add(empfaenger(24, antenne=t >= 17), neu(15) or neu(17))
            b.add(draht(loch("L+24"), loch("a24"), FARBE["plus"], 2), neu(15))
            b.add(uno_draht("Pin 2", "a25", FARBE["signal"]), neu(15))
            b.add(draht(loch("a27"), loch("L-27"), FARBE["minus"], 2), neu(15))
        if t == 14:
            b.add('<text x="16" y="44" fill="#b8860b">Heute: grüne LED (Reihe 16) zum Fotowiderstand biegen</text>')
        return b.svg()

    # --- Ab Tag 18: Nano im Steckbrett, Uno als Fernbedienung ---
    n18 = neu(18)
    b.add(nano(), n18)
    b.add(draht(loch("a12"), loch("L+12"), FARBE["plus"]), n18)      # 5V
    b.add(draht(loch("a14"), loch("L-14"), FARBE["minus"]), n18)     # GND
    b.add(draht(loch("L+30"), loch("R+30"), FARBE["plus"], 2), n18)
    b.add(draht(loch("L-29"), loch("R-29"), FARBE["minus"], 2), n18)
    for r, nano_loch, f, pin in ((17, "i8", "rot", "D5"), (19, "i7", "gelb", "D6"), (21, "i6", "gruen", "D7")):
        b.add(widerstand(f"e{r}", f"f{r}", "220 Ω"), n18)
        b.add(led(f"j{r}", f"R-{r}", FARBE[f]), n18)
        b.add(draht(loch(nano_loch), loch(f"a{r}"), PIN_FARBE[pin]), n18)
    b.add(empfaenger(23, antenne=True), n18)
    b.add(draht(loch("L+23"), loch("a23"), FARBE["plus"], 2), n18)
    b.add(draht(loch("i11"), loch("a24"), PIN_FARBE["D2"]), n18)     # D2
    b.add(draht(loch("a26"), loch("L-26"), FARBE["minus"], 2), n18)
    b.add(summer("f24", "f27"), n18)
    b.add(draht(loch("i4"), loch("j24"), PIN_FARBE["D9"]), n18)      # D9
    b.add(draht(loch("j27"), loch("R-27"), FARBE["minus"], 2), n18)
    b.add(fotowiderstand("c28", "c29"), n18)
    b.add(draht(loch("L+28"), loch("a28"), FARBE["plus"], 2), n18)
    b.add(draht(loch("a5"), loch("a29"), PIN_FARBE["A1"]), n18)      # A1
    b.add(widerstand("b29", "L-29", "10 kΩ"), n18)
    # Fernbedienung
    fx, fy = 540, 120
    fb = (f'<rect x="{fx}" y="{fy}" width="150" height="190" rx="8" fill="#00838f"/>'
          f'<text x="{fx + 10}" y="{fy + 20}" fill="#fff" font-size="13" font-weight="bold">Uno = Fernbedienung</text>'
          f'<text x="{fx + 10}" y="{fy + 36}" fill="#fff" font-size="9">an Powerbank, kein Steckbrett</text>')
    pins = {"5V": fy + 60, "GND": fy + 85, "Pin 10": fy + 110, "Pin 3": fy + 140, "Pin 4": fy + 160, "GND ": fy + 180}
    for p, py in pins.items():
        fb += (f'<text x="{fx + 140}" y="{py + 4}" fill="#fff" text-anchor="end">{p.strip()}</text>'
               f'<rect x="{fx + 146}" y="{py - 5}" width="10" height="10" fill="#222"/>')
    tx, ty = fx + 200, fy + 70
    fb += (f'<rect x="{tx}" y="{ty}" width="40" height="40" rx="3" fill="#2e7d32"/>'
           f'<text x="{tx + 20}" y="{ty - 6}" text-anchor="middle" font-size="9">433-MHz-Sender</text>'
           f'<path d="M{tx + 40},{ty + 5} q30,-10 20,-60" stroke="#795548" stroke-width="2" fill="none"/>'
           f'<text x="{tx + 20}" y="{ty - 64}" font-size="9">Antenne 17,3 cm</text>')
    for p, ziel, farbe in (("5V", ty + 10, FARBE["plus"]), ("GND", ty + 20, FARBE["minus"]), ("Pin 10", ty + 30, FARBE["signal"])):
        fb += draht((fx + 156, pins[p]), (tx, ziel), farbe, 2)
    for p, farbe in (("Pin 3", FARBE["signal"]), ("Pin 4", FARBE["signal"]), ("GND ", FARBE["minus"])):
        py = pins[p]
        fb += (f'<path d="M{fx + 156},{py} l40,8 l12,0" stroke="{farbe}" stroke-width="3" fill="none"/>'
               f'<circle cx="{fx + 208}" cy="{py + 8}" r="3" fill="#bbb"/>')
    fb += (f'<text x="{fx + 214}" y="{fy + 152}" font-size="9">Taste 1: Pin 3 an GND tippen</text>'
           f'<text x="{fx + 214}" y="{fy + 172}" font-size="9">Taste 2: Pin 4 an GND tippen</text>')
    b.add(fb, n18)
    return b.svg()


def main():
    ziel = Path(__file__).resolve().parent.parent / "bilder"
    ziel.mkdir(exist_ok=True)
    for t in range(1, 25):
        (ziel / f"tag{t:02d}.svg").write_text(tag_bild(t), encoding="utf-8")
    print(f"24 Steckbilder in {ziel}")


if __name__ == "__main__":
    main()
