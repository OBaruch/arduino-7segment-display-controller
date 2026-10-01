# Project Context

[← Back to README](../README.md)

## Summary

| Attribute | Value | Status |
|---|---|---|
| Project origin | Coursework / Assignment | **Inferred** |
| Domain | Embedded systems / digital electronics introduction | Inferred |
| Platform | Arduino | Confirmed |
| Author | Baruch Lopez | Confirmed (LICENSE, git history) |
| First upload | 2021-02-20 | Confirmed (git history) |
| University / course / assignment | — | **Unknown** |
| Original requirements document | None in repository | Confirmed absent |

## Evidence

The repository originally contained only three files: `LICENSE`, the sketch, and (from 2024) a Spanish README. No PDF, Word, PowerPoint, image, diagram, dataset or output file exists in the repository or its git history, so context was reconstructed from the code, file names and history.

| Source | Observation | What it suggests |
|---|---|---|
| Original file name `PtoProfeMAScambioACodigoDeAlumno.ino` | Spanish abbreviations: *"Profe"* (teacher), *"cambio a código de alumno"* (switch to student code). *"Pto"* matches the letters the sketch displays (see below). | The sketch was written for a class context and addresses a teacher. |
| 2025 rename to `ejercicio-alumno` | *"ejercicio"* = exercise, *"alumno"* = student. | The author later labeled it as a student exercise. |
| Displayed letter sequence | `P U T O · P R O F E` (letters rendered by `p, u, t, lo, nada, p, r, lo, f, e`). | Message aimed at the teacher; consistent with the original file name. |
| `codigo()` function | Shows nine digit glyphs; `codigo` = *code*. | Combined with the file name, a student ID number. |
| Comments (`////Letra P`, `////Numero 1` …) | Spanish, one per glyph function. | Author is a Spanish speaker; teaching-level code. |
| Coding style | One hard-coded function per glyph, no arrays/loops, no libraries. | Introductory-level exercise. |
| `LICENSE` | MIT, "Copyright (c) 2021 Baruch Lopez". | Authorship and year. |

## Contradictions Found

| Topic | Source A | Source B | Resolution |
|---|---|---|---|
| Behavior | Legacy README (2024): displays digits 0–9 in sequence, 1 s apart. | Code: displays a letter message; digits only on button press, 800 ms each. | Code is authoritative. Legacy README archived unchanged. |
| Wiring | Legacy README: segments A–G, DP on D2–D9. | Code: pins 1, 2, 4, 5, 6, 7, 9, 10 (+ 8 written, 12 input). | Mapping reconstructed from code in [hardware.md](hardware.md). |
| Contents | Legacy README mentions `diagram.png`, multiple examples, 74HC595 support, thermometer and clock examples. | None of these exist in the repository or history. | Documented as not present. |
| Display type | Legacy README: common cathode *or* anode supported. | Code assumes HIGH = segment on (common cathode, inferred). | Only common-cathode behavior is supported by the code. |

## Timeline

| Date | Event |
|---|---|
| 2021-02-20 | Repository created; sketch uploaded as `PtoProfeMAScambioACodigoDeAlumno.ino`. |
| 2024-11-18 | Spanish `README.md` added (generic description, see contradictions). |
| 2025-03-31 | Sketch renamed to `ejercicio-alumno.ino.ino` (content unchanged). |
| Repository refactor | Repository reorganized and documented in English; sketch moved to `src/ejercicio-alumno/ejercicio-alumno.ino`, content unchanged. |

## Scope

**In scope of the original project (Confirmed):** one display, one button, a fixed message, a fixed code sequence.

**Not part of the original project:** multi-digit multiplexing, shift registers, sensors, RTC modules, numeric counters — these appear only in the 2024 README.

## Unknowns

- Institution, course name, instructor and assignment statement.
- Exact board model, display part number, resistor values, and how the button was wired.
- Whether the sketch was ever submitted/graded, and its result.
- Whether the "student code" belongs to the author.

*The original repository does not provide enough information to determine these.*
