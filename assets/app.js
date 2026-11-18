// Funk-Adventskalender: Türchen, Sperre bis zum jeweiligen Tag, Spoiler-Schalter, Tagesseiten.

const TITEL = [
  "Hallo Steckbrett", "Die erste LED blinkt", "Drei flackernde Kerzen", "Licht per Knopf",
  "Jingle Bells", "Nikolaus spielt Licht-Theremin", "Das Nachtlicht", "Die Luft ist voller Strom",
  "Der Brumm-Melder", "Der Knacks-Detektor", "Das Ultraschall-Theremin", "Der Morse-Übersetzer",
  "Der Radar-Wächter", "Zahlen per Licht", "So klingt Funkstille", "Eine Antenne bauen",
  "Wer funkt denn hier?", "Der eigene Sender", "Die Keksdose als Funkbunker", "Die Weihnachtsfernbedienung",
  "Die Funk-Postkarte", "Wie falsch geht der Arduino?", "Die Atomuhr hören", "Der funkgesteuerte Weihnachtsbaum",
];

// Feste, gemischte Reihenfolge wie bei einem echten Kalender
const REIHENFOLGE = [7, 18, 3, 22, 11, 1, 15, 9, 24, 5, 13, 20, 2, 17, 10, 6, 21, 14, 4, 23, 12, 19, 8, 16];

const SEITEN = {
  vorbereitung: { datei: "kalender/00_vorbereitung.md", titel: "Bevor es losgeht" },
  steckplan: { datei: "kalender/steckplan.md", titel: "Steckplan" },
  einkauf: { datei: "kalender/einkauf.md", titel: "Einkaufsliste" },
};

// Bei geaenderten Steckbildern hochzaehlen, damit Browser nicht die alte Fassung aus dem Cache zeigen
const BILD_VERSION = 9;

const SPEICHER = "funkadvent";

function speicher() {
  try { return JSON.parse(localStorage.getItem(SPEICHER)) || {}; } catch { return {}; }
}
function speichern(daten) {
  try { localStorage.setItem(SPEICHER, JSON.stringify(daten)); } catch { /* privates Fenster */ }
}

// Heutiges Datum in Deutschland, unabhängig von der Zeitzone des Rechners
function heute() {
  const teile = new Intl.DateTimeFormat("de-DE", { timeZone: "Europe/Berlin", year: "numeric", month: "numeric", day: "numeric" })
    .formatToParts(new Date());
  const wert = (t) => Number(teile.find((p) => p.type === t).value);
  return { jahr: wert("year"), monat: wert("month"), tag: wert("day") };
}

function spoiler() {
  return new URLSearchParams(location.search).get("spoiler") === "1" || speicher().spoiler === true;
}

// Ein Türchen ist offen ab dem jeweiligen Dezembertag. Im Rest des Jahres (Januar bis Oktober) ist alles offen.
function istOffen(n) {
  if (spoiler()) return true;
  const { monat, tag } = heute();
  if (monat === 12) return tag >= n;
  if (monat === 11) return false;
  return true;
}

function tageBis(n) {
  const { jahr, monat, tag } = heute();
  const jetzt = Date.UTC(jahr, monat - 1, tag);
  const ziel = Date.UTC(monat === 12 ? jahr : jahr, 11, n);
  return Math.max(1, Math.round((ziel - jetzt) / 86400000));
}

function melden(text) {
  const m = document.getElementById("meldung");
  if (!m) return;
  m.textContent = text;
  m.classList.add("zeigen");
  clearTimeout(melden.t);
  melden.t = setTimeout(() => m.classList.remove("zeigen"), 2600);
}

function spoilerKnopf(knopf) {
  const zeigen = () => {
    const an = speicher().spoiler === true;
    knopf.textContent = an ? "🔓 Spoiler an" : "🔒 Spoiler aus";
    knopf.classList.toggle("an", an);
  };
  zeigen();
  knopf.addEventListener("click", () => {
    const d = speicher();
    d.spoiler = !d.spoiler;
    speichern(d);
    zeigen();
    if (document.getElementById("raster")) kalenderZeichnen();
    else location.reload();
  });
}

// ---------- Startseite ----------
function kalenderZeichnen() {
  const raster = document.getElementById("raster");
  const besucht = speicher().besucht || [];
  raster.innerHTML = "";
  for (const n of REIHENFOLGE) {
    const offen = istOffen(n);
    const war = besucht.includes(n);
    const tuer = document.createElement("button");
    tuer.className = "tuer" + (offen ? "" : " zu") + (war ? " offen" : "");
    tuer.setAttribute("aria-label", offen ? `Türchen ${n} öffnen` : `Türchen ${n}, noch geschlossen`);
    tuer.innerHTML =
      `<div class="innen"><strong>${n}</strong>${war ? TITEL[n - 1] : "🎁"}</div>` +
      `<div class="vorne"><span class="zahl">${n}</span>${offen ? "" : '<span class="schloss">🔒</span>'}</div>`;
    tuer.addEventListener("click", () => {
      if (!istOffen(n)) {
        tuer.classList.remove("wackeln");
        void tuer.offsetWidth;
        tuer.classList.add("wackeln");
        const tage = tageBis(n);
        melden(tage === 1 ? `Türchen ${n} geht morgen auf.` : `Noch ${tage} Tage bis Türchen ${n}. Geduld!`);
        return;
      }
      const d = speicher();
      d.besucht = [...new Set([...(d.besucht || []), n])];
      speichern(d);
      tuer.classList.add("offen");
      setTimeout(() => (location.href = `tag.html?t=${n}`), 650);
    });
    raster.appendChild(tuer);
  }
}

function startseite() {
  kalenderZeichnen();
  spoilerKnopf(document.getElementById("spoiler"));
  const { monat, tag } = heute();
  const h = document.getElementById("stand");
  if (monat === 11) {
    const tage = tageBis(1);
    h.innerHTML = `Noch <strong>${tage} ${tage === 1 ? "Tag" : "Tage"}</strong> bis zum ersten Türchen. ` +
      `Zeit genug, um die <a href="tag.html?s=einkauf">Teile zu besorgen</a> und die ` +
      `<a href="tag.html?s=vorbereitung">Vorbereitung</a> zu lesen.`;
  } else if (monat === 12 && tag <= 24) {
    h.innerHTML = `Heute ist Türchen <strong>${tag}</strong> dran. Viel Spaß!`;
  } else {
    h.innerHTML = "Alle Türchen sind offen. Viel Spaß beim Nachbauen, auch nach Weihnachten!";
  }
}

// ---------- Tagesseite ----------
function linksUmschreiben(wurzel) {
  for (const a of wurzel.querySelectorAll("a[href]")) {
    const href = a.getAttribute("href");
    if (/^https?:/.test(href)) { a.target = "_blank"; a.rel = "noopener"; continue; }
    let m;
    if ((m = href.match(/tag(\d\d)\.md/))) a.href = `tag.html?t=${Number(m[1])}`;
    else if (href.includes("00_vorbereitung.md")) a.href = "tag.html?s=vorbereitung";
    else if (href.includes("steckplan.md")) a.href = "tag.html?s=steckplan" + (href.includes("#") ? "#nano" : "");
    else if (href.includes("einkauf.md")) a.href = "tag.html?s=einkauf";
    else if (href.startsWith("../")) a.href = href.slice(3);
  }
  for (const img of wurzel.querySelectorAll("img[src^='../']")) {
    img.src = img.getAttribute("src").slice(3);
    img.loading = "lazy";
  }
}

async function codeKaesten(blatt) {
  const pfade = [...new Set([...blatt.querySelectorAll("a[href$='.ino']")].map((a) => a.getAttribute("href")))];
  for (const pfad of pfade) {
    let code;
    try {
      const antwort = await fetch(pfad, { cache: "no-cache" });
      if (!antwort.ok) continue;
      code = await antwort.text();
    } catch { continue; }
    const name = pfad.split("/").pop();
    const kasten = document.createElement("div");
    kasten.className = "code-kasten";
    kasten.innerHTML = `<div class="code-kopf"><span>📄 ${name}</span><span>` +
      `<button type="button">Kopieren</button> <a href="${pfad}" download>Herunterladen</a></span></div>` +
      `<pre><code class="language-cpp"></code></pre>`;
    kasten.querySelector("code").textContent = code;
    kasten.querySelector("button").addEventListener("click", async (e) => {
      try { await navigator.clipboard.writeText(code); e.target.textContent = "Kopiert ✓"; }
      catch { e.target.textContent = "Bitte markieren und kopieren"; }
    });
    blatt.appendChild(kasten);
    if (window.hljs) window.hljs.highlightElement(kasten.querySelector("code"));
  }
}

async function tagesseite() {
  spoilerKnopf(document.getElementById("spoiler"));
  const p = new URLSearchParams(location.search);
  const blatt = document.getElementById("blatt");
  const n = Number(p.get("t"));
  const seite = SEITEN[p.get("s")];
  let datei;

  if (seite) {
    datei = seite.datei;
    document.title = `${seite.titel} – Funk-Adventskalender`;
  } else if (n >= 1 && n <= 24) {
    if (!istOffen(n)) {
      const tage = tageBis(n);
      blatt.innerHTML = `<div class="gesperrt"><div class="gross">🔒</div><h1>Türchen ${n} ist noch zu</h1>` +
        `<p>Noch ${tage} ${tage === 1 ? "Tag" : "Tage"}. Wer nicht warten mag, schaltet oben den Spoiler an.</p></div>`;
      return;
    }
    datei = `kalender/tag${String(n).padStart(2, "0")}.md`;
    document.title = `Türchen ${n}: ${TITEL[n - 1]} – Funk-Adventskalender`;
    const navi = document.getElementById("navi");
    navi.innerHTML =
      (n > 1 ? `<a class="knopf" href="tag.html?t=${n - 1}">← Türchen ${n - 1}</a>` : "<span></span>") +
      (n < 24 ? `<a class="knopf" href="tag.html?t=${n + 1}">Türchen ${n + 1} →</a>` : "<span></span>");
    const d = speicher();
    d.besucht = [...new Set([...(d.besucht || []), n])];
    speichern(d);
  } else {
    location.href = "index.html";
    return;
  }

  try {
    const md = await (await fetch(datei, { cache: "no-cache" })).text();
    blatt.innerHTML = window.marked.parse(md);
  } catch {
    blatt.innerHTML = "<p>Die Seite konnte nicht geladen werden.</p>";
    return;
  }
  if (n && !seite) {
    const nr = String(n).padStart(2, "0");
    const fig = document.createElement("figure");
    fig.className = "steckbild";
    fig.innerHTML = `<a href="bilder/tag${nr}.svg?v=${BILD_VERSION}" target="_blank"><img src="bilder/tag${nr}.svg?v=${BILD_VERSION}" ` +
      `alt="Steckbild für Türchen ${n}"></a><figcaption>Steckbild. Antippen zum Vergrößern. ` +
      `Gelb leuchtend = heute neu.</figcaption>`;
    const h1 = blatt.querySelector("h1");
    h1 ? h1.after(fig) : blatt.prepend(fig);
  }
  for (const h of blatt.querySelectorAll("h2")) if (/Ab Tag 18/.test(h.textContent)) h.id = "nano";
  linksUmschreiben(blatt);
  await codeKaesten(blatt);
  if (location.hash) document.querySelector(location.hash)?.scrollIntoView();
}

// ---------- Schnee ----------
function schnee() {
  const c = document.getElementById("schnee");
  if (!c || matchMedia("(prefers-reduced-motion: reduce)").matches) return;
  const ctx = c.getContext("2d");
  let flocken = [];
  const groesse = () => {
    c.width = innerWidth; c.height = innerHeight;
    flocken = Array.from({ length: Math.min(120, Math.floor(innerWidth / 10)) }, () => ({
      x: Math.random() * c.width, y: Math.random() * c.height, r: Math.random() * 2 + 0.6, v: Math.random() * 0.6 + 0.3,
    }));
  };
  groesse();
  addEventListener("resize", groesse);
  (function schritt() {
    ctx.clearRect(0, 0, c.width, c.height);
    ctx.fillStyle = "rgba(255,255,255,0.8)";
    for (const f of flocken) {
      f.y += f.v; f.x += Math.sin(f.y / 40) * 0.3;
      if (f.y > c.height) { f.y = -5; f.x = Math.random() * c.width; }
      ctx.beginPath(); ctx.arc(f.x, f.y, f.r, 0, Math.PI * 2); ctx.fill();
    }
    requestAnimationFrame(schritt);
  })();
}

document.addEventListener("DOMContentLoaded", () => {
  schnee();
  if (document.getElementById("raster")) startseite();
  else tagesseite();
});
