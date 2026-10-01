# Possible Improvements

[← Back to README](../README.md)

> **None of the items below have been applied.** The original sketch is preserved exactly as written to retain its historical context. This list exists only to show how the implementation could be modernized; any future change should go into a *new* file or folder, never into `src/ejercicio-alumno/ejercicio-alumno.ino`.

## Correctness / Hardware

| # | Observation | Effect | Possible improvement |
|---|---|---|---|
| 1 | Pin 8 is written in every glyph but never set with `pinMode(8, OUTPUT)`. | `digitalWrite(8, LOW)` only toggles the internal pull-up; the pin is not actively driven. | Configure it or remove it from the glyphs, depending on the real wiring. |
| 2 | Pin 1 (Serial TX) drives segment *e*. | Can interfere with uploading and prevents using `Serial`. | Move the segment to a free pin (e.g. D3 or D11). |
| 3 | Button on `INPUT` without pull-up. | Floating input if no external resistor is fitted. | Use `INPUT_PULLUP`. |
| 4 | Button is polled once per character. | Short presses are missed. | Poll continuously (`millis()`-based timing) or use an interrupt. |
| 5 | No debouncing beyond a 20 ms delay. | Possible false triggers. | Add debounce logic. |
| 6 | `n5(); n5();` with no blank between. | The repeated digit looks like a single long "5". | Insert a short blank between identical consecutive digits. |
| 7 | `lo()` used as digit 0 holds 400 ms vs. 800 ms for other digits. | Uneven rhythm in the code display. | Dedicated `n0()` with the same hold time. |

## Code Structure

| # | Observation | Possible improvement |
|---|---|---|
| 8 | 14 near-identical glyph functions (~170 lines). | A segment lookup table (`byte` bitmask per character) plus one `showGlyph()` function. |
| 9 | Pin numbers are repeated literals. | Named constants / a `segmentPins[]` array. |
| 10 | Message and code are hard-coded call sequences. | Store them as strings and iterate. |
| 11 | Blocking `delay()` everywhere. | Non-blocking state machine with `millis()`. |
| 12 | Redundant `digitalRead` + `delay(20)` at the start of `loop()`. | Remove. |
| 13 | Single-letter function names (`p`, `u`, `t`, `r`, `f`, `e`). | Descriptive names (`showLetterP`, …). |

## Repository-level (not code)

| # | Suggestion |
|---|---|
| 14 | Add a photo or schematic of the circuit if the original hardware is ever rebuilt. |
| 15 | If a modernized version is written, place it in a separate folder (e.g. `src/modernized/`) so the original stays untouched. |
