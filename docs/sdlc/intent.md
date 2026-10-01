# Intent

[← Back to README](../../README.md) · **Intent** · [Spec](spec.md) · [Plan](plan.md)

> Reconstructed retroactively from the existing repository. This is not an original 2021 document. Labels: **Confirmed** (directly supported by files/code), **Inferred** (reasonable deduction), **Unknown**.

## 1. Original Project Intent

### Why it exists
A student exercise to learn how to drive a 7-segment display directly from Arduino digital pins and react to a digital input. **(Inferred** — from the original file name `PtoProfeMAScambioACodigoDeAlumno.ino` and the later name `ejercicio-alumno`.)

### Who it was for
The author's instructor/class. **(Inferred** — "Profe" in the file name.)

### Desired outcome
| Outcome | Status |
|---|---|
| Show a fixed letter message on one 7-segment display, character by character, forever. | Confirmed |
| When a push button is pressed, show the student code digit by digit. | Confirmed (behavior); "student code" meaning Inferred |
| Use only the Arduino core API (no libraries, no driver ICs). | Confirmed |

### Non-goals
Multi-digit displays, multiplexing, shift registers, sensors, counters, serial communication. **(Confirmed** — none present in the code.)

### Success criteria (as the original author would have checked them)
- Every glyph is recognizable as its intended character. **(Inferred)**
- Pressing the button switches to the code sequence and then returns to the message. **(Confirmed by code flow)**

## 2. Repository Refactor Intent

### Why
Turn a loose, partially mis-documented legacy repository into a clear, navigable portfolio entry **without altering the original implementation**.

### Principles
1. **Modernize the repository, not the project.** The sketch's bytes must not change.
2. **Evidence over assumption.** Every claim is tagged Confirmed / Inferred / Unknown.
3. **Preserve history.** Previous documentation is archived, not deleted.
4. **No artificial complexity.** No CI, build systems, containers or frameworks.

### Stakeholders
| Role | Interest |
|---|---|
| Author (Baruch Lopez) | Portfolio presentation; historical accuracy |
| Readers / reviewers | Understand the project in minutes |
| Automated contributors | Clear guardrails (see [AGENTS.md](../../AGENTS.md)) |
