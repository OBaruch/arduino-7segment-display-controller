# Code Overview

[← Back to README](../README.md)

This document explains the original sketch **without modifying it**. Line numbers refer to [`src/ejercicio-alumno/ejercicio-alumno.ino`](../src/ejercicio-alumno/ejercicio-alumno.ino).

## File

| Property | Value |
|---|---|
| Path | `src/ejercicio-alumno/ejercicio-alumno.ino` |
| Language | Arduino C/C++ |
| Lines | 273 (CRLF line endings) |
| Global state | `int buttonState;` (line 1) |
| Libraries | None |
| Comment language | Spanish |

## Function Map

| Function | Lines | Kind | Purpose | Hold time |
|---|---|---|---|---|
| `setup()` | 2–14 | Arduino entry point | Sets pins 1, 2, 4, 5, 6, 7, 9, 10 as `OUTPUT`, pin 12 as `INPUT` | — |
| `loop()` | 16–56 | Arduino entry point | Plays the letter sequence, polling the button between letters | — |
| `p()` | 58–69 | Glyph | Letter **P** (`////LetraP`) | 200 ms |
| `u()` | 72–83 | Glyph | Letter **U** | 200 ms |
| `t()` | 86–97 | Glyph | Letter **t** | 200 ms |
| `lo()` | 100–111 | Glyph | Letter **O** (also reused as digit 0) | 200 ms |
| `r()` | 114–125 | Glyph | Letter **R** | 200 ms |
| `f()` | 128–139 | Glyph | Letter **F** | 200 ms |
| `e()` | 142–153 | Glyph | Letter **E** | 200 ms |
| `n1()` | 156–167 | Glyph | Digit **1** | 800 ms |
| `n2()` | 170–181 | Glyph | Digit **2** | 800 ms |
| `n3()` | 184–195 | Glyph | Digit **3** | 800 ms |
| `n6()` | 198–209 | Glyph | Digit **6** | 800 ms |
| `n5()` | 213–224 | Glyph | Digit **5** | 800 ms |
| `n7()` | 227–238 | Glyph | Digit **7** | 800 ms |
| `nada()` | 240–251 | Glyph | Blank display (*"nada"* = nothing) | 200 ms |
| `codigo()` | 253–264 | Sequence | Displays the nine-character student code | ≈ 6.8 s |
| `boton()` | 265–273 | Input handler | Reads pin 12; if `LOW`, calls `codigo()` (*"botón"* = button) | 20 ms |

Digits 0, 4, 8 and 9 have no dedicated function; only the digits needed for the code were implemented. Digit 0 is rendered with the letter function `lo()`.

## Glyph Function Pattern

Every glyph function has the same shape: nine `digitalWrite()` calls (pins 1, 2, 4, 5, 6, 7, 8, 9, 10) that set the complete display state, followed by a `delay()`. Because each call writes every pin, the previous character is overwritten without an explicit clear. The resulting segment patterns are listed in [hardware.md](hardware.md#glyph-truth-table-confirmed-from-code).

## Execution Flow

### `loop()` (lines 16–56)

```
p()                       ← P
digitalRead(12); delay(20)   (value stored but not used here)
boton(); delay(300)
u()     boton(); delay(300)   ← U
t()     boton(); delay(300)   ← T
lo()    boton(); delay(300)   ← O
nada()  boton(); delay(300)   ← (space)
p()     boton(); delay(300)   ← P
r()     boton(); delay(300)   ← R
lo()    boton(); delay(300)   ← O
f()     boton(); delay(300)   ← F
e()     boton(); delay(300)   ← E
nada()  delay(300)            ← (space, no button check)
```

One full pass without a button press takes roughly 10 × (200 + 20 + 300) + 20 + 200 + 300 ≈ **5.7 s**.

### `boton()` (lines 265–273)

```
buttonState = digitalRead(12)
delay(20)
if buttonState == LOW → codigo()
```

The button is **polled**, not interrupt-driven. It is sampled once after each character, so it must be held down at the moment of sampling (roughly every 0.5 s) to trigger the code display.

### `codigo()` (lines 253–264)

Calls, in order: `n2, n1, n3, n6, lo (+ extra delay(200)), n5, n5, n7, n2`.

- Each `n*()` digit holds for 800 ms; the `lo()` "0" holds for 200 + 200 = 400 ms.
- The two consecutive `n5()` calls produce one continuous "5" for 1.6 s, because no blank is inserted between them.
- After `codigo()` returns, `loop()` continues with the next letter where it left off.

## Dependencies Observed

- Arduino core API only: `pinMode`, `digitalWrite`, `digitalRead`, `delay`, `HIGH`, `LOW`, `INPUT`, `OUTPUT`.
- No `Serial` usage, no libraries, no interrupts, no timers beyond `delay()`.

## Notable Characteristics (documented, not changed)

These are observations only. Suggested fixes are listed separately in [possible-improvements.md](possible-improvements.md).

- Pin 8 is written in every glyph but never configured with `pinMode`.
- Pin 5 is configured as `OUTPUT` but never set `HIGH`.
- Pin 1 is the Serial TX pin on Uno-class boards.
- The `digitalRead` on lines 18–19 stores a value that is overwritten by `boton()` before being used.
- No debouncing beyond the 20 ms delay; detection depends on polling timing.
