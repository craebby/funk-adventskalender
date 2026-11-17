#!/usr/bin/env python3
"""Prueft alle Steckbilder: Wird ein Loch doppelt benutzt? Liegt ein Kabelende unter einem Bauteil?

Aufruf: python3 tools/pruefe_steckbilder.py   (Exitcode 1, wenn etwas auffaellt)
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import steckbilder as sb  # noqa: E402

LOECHER = {}
for spalte in sb.SPALTEN:
    for reihe in range(1, sb.REIHEN + 1):
        LOECHER[(sb.x(spalte), sb.y(reihe))] = f"{spalte}{reihe}"


def loch_bei(px, py):
    for (lx, ly), name in LOECHER.items():
        if abs(lx - px) < 1.5 and abs(ly - py) < 1.5:
            return name
    return None


def zahlen(s):
    return [float(v) for v in re.findall(r"-?\d+(?:\.\d+)?", s)]


def pruefe(t):
    svg = sb.tag_bild(t)
    benutzt = []           # (loch, teil)
    deckel = []            # (art, geometrie, eigene_loecher)

    for d, rest in re.findall(r'<path d="(M[^"]+)"([^>]*)>', svg):
        if "dasharray" in rest or "q" in d or "l" in d:
            continue       # Antennen, Fernbedienungs-Tasten, Pfeile
        z = zahlen(d)
        for px, py in ((z[0], z[1]), (z[-2], z[-1])):
            name = loch_bei(px, py)
            if name:
                benutzt.append((name, f"Kabel {d[:22]}"))
    for x1, y1 in re.findall(r'<line x1="([\d.]+)" y1="([\d.]+)"[^>]*stroke="#777"', svg):
        name = loch_bei(float(x1), float(y1))
        if name:
            benutzt.append((name, "Bein/Widerstand"))
    for x2, y2 in re.findall(r'<line x1="[\d.]+" y1="[\d.]+" x2="([\d.]+)" y2="([\d.]+)" stroke="#777" stroke-width="2"/><rect', svg):
        name = loch_bei(float(x2), float(y2))
        if name:
            benutzt.append((name, "Widerstand Ende"))
    for cx, cy in re.findall(r'<circle cx="([\d.]+)" cy="([\d.]+)" r="3" fill="#ffd54f"', svg):
        benutzt.append((loch_bei(float(cx), float(cy)), "Summer-Bein"))
    for cx, cy in re.findall(r'<circle cx="([\d.]+)" cy="([\d.]+)" r="30"', svg):
        deckel.append(("Summer", (float(cx), float(cy), 30)))
    for rx, ry, w, h in re.findall(r'<rect x="([\d.]+)" y="([\d.]+)" width="([\d.]+)" height="([\d.]+)" rx="3" fill="#333"', svg):
        x0, y0 = float(rx) + 5, float(ry) + 5
        x1, y1 = float(rx) + float(w) - 5, float(ry) + float(h) - 5
        for px, py in ((x0, y0), (x0, y1), (x1, y0), (x1, y1)):
            benutzt.append((loch_bei(px, py), "Taster"))
        deckel.append(("Taster", (float(rx), float(ry), float(w), float(h))))
    for cx, cy, ry in re.findall(r'<ellipse cx="([\d.]+)" cy="([\d.]+)" rx="7" ry="([\d.]+)"', svg):
        for py in (float(cy) - float(ry) + 5, float(cy) + float(ry) - 5):
            benutzt.append((loch_bei(float(cx) - 2, py), "Fotowiderstand"))
    for rx, ry, h in re.findall(r'<rect x="([\d.]+)" y="([\d.]+)" width="20" height="([\d.]+)" rx="3" fill="#1565c0"', svg):
        yy = float(ry) + 7
        while yy <= float(ry) + float(h) - 7 + 0.1:
            benutzt.append((loch_bei(float(rx) + 10, yy), "Poti"))
            yy += sb.P
    for rx, ry, h in re.findall(r'<rect x="([\d.]+)" y="([\d.]+)" width="16" height="([\d.]+)" rx="2" fill="#2e7d32"', svg):
        yy = float(ry) + 8
        while yy <= float(ry) + float(h) - 8 + 0.1:
            benutzt.append((loch_bei(float(rx) + 8, yy), "Empfänger"))
            yy += sb.P
    for rx, ry in re.findall(r'<rect x="([\d.]+)" y="([\d.]+)" width="5" height="5" fill="#ffd54f"', svg):
        benutzt.append((loch_bei(float(rx) + 2.5, float(ry) + 2.5), "Stift"))

    fehler = []
    zaehler = {}
    for name, teil in benutzt:
        if name is None:
            fehler.append(f"Bauteilbein ausserhalb des Rasters ({teil})")
            continue
        zaehler.setdefault(name, []).append(teil)
    for name, teile in zaehler.items():
        if len(teile) > 1:
            fehler.append(f"Loch {name} doppelt: {', '.join(teile)}")
    for art, g in deckel:
        for name, teile in zaehler.items():
            if any(t.startswith(art.split()[0]) for t in teile):
                continue
            lx, ly = next(k for k, v in LOECHER.items() if v == name)
            if art == "Summer" and (lx - g[0]) ** 2 + (ly - g[1]) ** 2 < g[2] ** 2:
                fehler.append(f"Loch {name} liegt unter dem Summer ({', '.join(teile)})")
            if art == "Taster" and g[0] < lx < g[0] + g[2] and g[1] < ly < g[1] + g[3]:
                fehler.append(f"Loch {name} liegt unter dem Taster ({', '.join(teile)})")
    return len(zaehler), fehler


def main():
    alles_gut = True
    for t in range(1, 25):
        anzahl, fehler = pruefe(t)
        print(f"Tag {t:2d}: {anzahl:3d} Löcher belegt, " + ("ok" if not fehler else f"{len(fehler)} Auffälligkeiten"))
        for f in fehler:
            print("        " + f)
            alles_gut = False
    sys.exit(0 if alles_gut else 1)


if __name__ == "__main__":
    main()
