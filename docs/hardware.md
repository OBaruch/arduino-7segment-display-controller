# Hardware and Pin Mapping

[← Back to README](../README.md)

No schematic, photo or wiring description of the original circuit exists. Everything below is **reconstructed from the code** and is labeled accordingly.

## Components (Confirmed by code usage)

- 1 × Arduino board (model **Unknown**)
- 1 × single-digit 7-segment display
- 1 × push button on digital pin 12

Resistors, display part number and breadboard layout: **Unknown**.

## Segment Naming

```
     a
   ─────
  │     │
 f│     │b
  │  g  │
   ─────
  │     │
 e│     │c
  │     │
   ─────
     d
```

## Reconstructed Pin → Segment Mapping (Inferred)

Solving the 14 glyph patterns in the sketch gives a single consistent mapping:

| Arduino pin | `pinMode` set? | Segment | Evidence |
|---|---|---|---|
| D1 | OUTPUT | **e** | Difference between `6` and `5` |
| D2 | OUTPUT | **d** | Only difference between `E` and `F` |
| D4 | OUTPUT | **c** | Difference between `6` and `E` |
| D5 | OUTPUT | — (never HIGH) | Likely decimal point (DP) |
| D6 | OUTPUT | **b** | Present in `P`, `O`, `U`, `2`, `3`, `7`; absent in `5`, `6` |
| D7 | OUTPUT | **a** | Difference between `O` and `U` |
| D8 | **not set** | — (always written LOW) | Possibly a common pin |
| D9 | OUTPUT | **f** | Present in `5`, `6`; absent in `2`, `3` |
| D10 | OUTPUT | **g** | Difference between `F` and the `R` glyph |
| D12 | INPUT | Button | Active LOW |

### Observation: pin numbers mirror the display's physical pins

A common 10-pin single-digit 7-segment display has the pinout `1=e, 2=d, 3=COM, 4=c, 5=DP, 6=b, 7=a, 8=COM, 9=f, 10=g`. The reconstructed mapping matches it exactly, and pins 3 and 8 (the commons) are the ones not used as segment outputs. **This strongly suggests Arduino pin *N* was wired to display pin *N*.** It cannot be confirmed without the original circuit.

### Display polarity (Inferred)

`nada()` writes every pin LOW to blank the display, and glyphs set lit segments HIGH. This implies a **common-cathode** display with the common pin(s) to GND.

### Button (Inferred)

Pin 12 is configured as plain `INPUT` (no internal pull-up) and a press is detected as `LOW`. The button therefore most likely connected pin 12 to GND with an external pull-up resistor to 5 V. Without that resistor the input would float.

## Glyph Truth Table (Confirmed from code)

`1` = pin written HIGH. Pins 5 and 8 are always LOW and omitted.

| Function | Glyph | D7 a | D6 b | D4 c | D2 d | D1 e | D9 f | D10 g |
|---|---|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| `p()` | P | 1 | 1 | 0 | 0 | 1 | 1 | 1 |
| `u()` | U | 0 | 1 | 1 | 1 | 1 | 1 | 0 |
| `t()` | t | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
| `lo()` | O / 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |
| `r()` | R (rendered as Γ: a, e, f) | 1 | 0 | 0 | 0 | 1 | 1 | 0 |
| `f()` | F | 1 | 0 | 0 | 0 | 1 | 1 | 1 |
| `e()` | E | 1 | 0 | 0 | 1 | 1 | 1 | 1 |
| `n1()` | 1 (left side: e, f) | 0 | 0 | 0 | 0 | 1 | 1 | 0 |
| `n2()` | 2 | 1 | 1 | 0 | 1 | 1 | 0 | 1 |
| `n3()` | 3 | 1 | 1 | 1 | 1 | 0 | 0 | 1 |
| `n5()` | 5 | 1 | 0 | 1 | 1 | 0 | 1 | 1 |
| `n6()` | 6 | 1 | 0 | 1 | 1 | 1 | 1 | 1 |
| `n7()` | 7 | 1 | 1 | 1 | 0 | 0 | 0 | 0 |
| `nada()` | blank | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

Every glyph decodes to the character named in its comment under this mapping, which is the main evidence that the mapping is correct.

## Caveats

- **D1 is the hardware Serial TX pin** on ATmega328P boards (Uno/Nano). Uploading a sketch uses it, so the segment may flicker during upload, and the connected segment can interfere with uploading.
- D8 is never configured as OUTPUT, so `digitalWrite(8, LOW)` leaves it as a high-impedance input rather than actively driving LOW.
