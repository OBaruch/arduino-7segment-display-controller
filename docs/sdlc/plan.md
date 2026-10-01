# Plan

[← Back to README](../../README.md) · [Intent](intent.md) · [Spec](spec.md) · **Plan**

> Two parts: (A) the original implementation plan, reconstructed from the code's structure, and (B) the repository-refactor plan that produced the current layout.

## A. Original Implementation Plan (Reconstructed — Inferred)

The code structure suggests the sketch was built in these steps:

| Step | Work | Evidence in code | Spec IDs |
|---|---|---|---|
| A1 | Wire the display and choose pins (apparently Arduino pin *N* → display pin *N*). | Pin set 1, 2, 4–10 matches a standard display pinout | FR-1 |
| A2 | Configure pins in `setup()`. | `setup()` | FR-1 |
| A3 | Write one function per required glyph, each setting all segment pins. | `p … e`, `n1 … n7`, `nada` | FR-3, FR-6, FR-8 |
| A4 | Compose the message by calling glyphs in order inside `loop()`. | `loop()` | FR-2 |
| A5 | Add the button: `boton()` checks pin 12 and triggers `codigo()`. | `boton()`, `codigo()` | FR-4, FR-5, FR-7 |
| A6 | Interleave `boton()` calls between letters. | repeated `boton(); delay(300);` | FR-4 |

## B. Repository Refactor Plan (Executed)

### Constraints
- **C1** Do not modify any byte of the source file.
- **C2** Do not delete historical material; archive it.
- **C3** Do not add build/CI/container infrastructure.
- **C4** Tag every documented claim as Confirmed / Inferred / Unknown.

### Tasks

| ID | Task | Output | Status |
|---|---|---|---|
| B1 | Inventory all files and git history. | Findings in [project-context.md](../project-context.md) | Done |
| B2 | Reverse-engineer pin→segment mapping and glyphs. | [hardware.md](../hardware.md) | Done |
| B3 | Document every function and the execution flow. | [code-overview.md](../code-overview.md) | Done |
| B4 | Move sketch to `src/ejercicio-alumno/ejercicio-alumno.ino` (Arduino sketch-folder convention) with `git mv`. | Same blob `c0f6015` | Done |
| B5 | Archive the 2024 Spanish README unchanged. | [archive/README.es-2024.md](../archive/README.es-2024.md) | Done |
| B6 | Write English README with context, structure and historical note. | [README.md](../../README.md) | Done |
| B7 | Record possible improvements separately, unapplied. | [possible-improvements.md](../possible-improvements.md) | Done |
| B8 | Produce SDLC artifacts (intent, spec, plan). | `docs/sdlc/` | Done |
| B9 | Add `.gitattributes` (protect CRLF bytes of `.ino`) and minimal `.gitignore`. | Root files | Done |
| B10 | Add `AGENTS.md` guardrails for automated contributors. | [AGENTS.md](../../AGENTS.md) | Done |

### Verification

| Check | Method | Expected |
|---|---|---|
| V1 Source unchanged | `sha256sum src/ejercicio-alumno/ejercicio-alumno.ino` | `e3b51b93…c3267` (see spec AC-4) |
| V2 History follows the file | `git log --follow src/ejercicio-alumno/ejercicio-alumno.ino` | Shows 2021 upload and 2025 rename |
| V3 Links resolve | Open each relative link in the docs | No broken links |

## C. Future Work Workflow

Any future change follows **intent → spec → plan → implement → verify**:

1. Update [intent.md](intent.md) with the new goal.
2. Add new requirements to [spec.md](spec.md) with new IDs; do not rewrite as-built requirements.
3. Add tasks here.
4. Implement **outside** `src/ejercicio-alumno/` (e.g. `src/modernized/`) so V1 keeps passing.
