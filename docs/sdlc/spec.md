# Specification (As-Built)

[← Back to README](../../README.md) · [Intent](intent.md) · **Spec** · [Plan](plan.md)

> Reverse-engineered from [`src/ejercicio-alumno/ejercicio-alumno.ino`](../../src/ejercicio-alumno/ejercicio-alumno.ino). It describes what the original code **does**, not what it should do. Requirement IDs allow traceability to the code and to [plan.md](plan.md).

## 1. System Context

```
 ┌──────────┐   D12 (active LOW)   ┌──────────────┐  D1,D2,D4,D6,D7,D9,D10  ┌─────────────────┐
 │  Button  │ ───────────────────▶ │   Arduino    │ ──────────────────────▶ │ 7-segment (1 dig)│
 └──────────┘                      │  (sketch)    │  D5, D8 always LOW      └─────────────────┘
                                   └──────────────┘
```

## 2. Functional Requirements

| ID | Requirement | Code reference | Status |
|---|---|---|---|
| FR-1 | On start-up, configure pins 1, 2, 4, 5, 6, 7, 9, 10 as outputs and pin 12 as input. | `setup()` | Confirmed |
| FR-2 | Repeatedly display the sequence `P, U, T, O, blank, P, R, O, F, E, blank`. | `loop()` | Confirmed |
| FR-3 | Each letter is shown for 200 ms, followed by a 20 ms button read and a 300 ms pause. | glyph functions, `boton()`, `loop()` | Confirmed |
| FR-4 | After each of the first ten steps, sample pin 12; if `LOW`, run the code sequence. | `boton()` | Confirmed |
| FR-5 | The code sequence shows nine glyphs: `2, 1, 3, 6, 0, 5, 5, 7, 2`. | `codigo()` | Confirmed |
| FR-6 | Each code digit is shown for 800 ms, except `0` (400 ms). | `n*()`, `codigo()` | Confirmed |
| FR-7 | After the code sequence, resume the letter sequence at the next step. | `loop()` / `boton()` return | Confirmed |
| FR-8 | A blank display is produced by writing every segment pin `LOW`. | `nada()` | Confirmed |

## 3. Interface Specification

### 3.1 Pins

| Pin | Direction | Role | Status |
|---|---|---|---|
| D1 | Out | Segment e | Inferred mapping |
| D2 | Out | Segment d | Inferred mapping |
| D4 | Out | Segment c | Inferred mapping |
| D5 | Out | Always LOW (likely DP) | Confirmed LOW / role Inferred |
| D6 | Out | Segment b | Inferred mapping |
| D7 | Out | Segment a | Inferred mapping |
| D8 | (not configured) | Always written LOW | Confirmed |
| D9 | Out | Segment f | Inferred mapping |
| D10 | Out | Segment g | Inferred mapping |
| D12 | In | Button, pressed = LOW | Confirmed |

Full derivation and glyph truth table: [hardware.md](../hardware.md).

### 3.2 Electrical assumptions
- Segment ON = `HIGH` → common-cathode display. **(Inferred)**
- External pull-up on D12. **(Inferred)**
- Board, display part, resistor values. **(Unknown)**

## 4. Non-Functional Characteristics

| ID | Characteristic | Value | Status |
|---|---|---|---|
| NFR-1 | Letter-loop period (no press) | ≈ 5.7 s | Confirmed (computed from delays) |
| NFR-2 | Code-sequence duration | ≈ 6.8 s | Confirmed (computed) |
| NFR-3 | Input latency | Up to ≈ 0.5 s; press must coincide with a sample | Confirmed (polling) |
| NFR-4 | Dependencies | Arduino core only | Confirmed |
| NFR-5 | Memory/flash usage | Not measured | Unknown |

## 5. Acceptance Criteria (for verifying the original behavior on hardware)

- **AC-1** With the button released, the display cycles `P U t O _ P R O F E _` indefinitely.
- **AC-2** Holding the button during a letter step shows `2 1 3 6 0 5 5 7 2`, then returns to the next letter.
- **AC-3** Every glyph matches the truth table in [hardware.md](../hardware.md).
- **AC-4** The source file's SHA-256 is `e3b51b93e77f1a9661a3eaaf745de63b1f5c879b979ab124a7b770335d6c3267` (integrity of the preserved original).

## 6. Known Deviations / Defects (not fixed)

See [possible-improvements.md](../possible-improvements.md): unconfigured pin 8, Serial TX conflict on D1, polled input, missing digit glyphs (4, 8, 9), duplicate-digit rendering.
