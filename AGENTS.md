# AGENTS.md

Guidance for automated coding agents and other contributors working in this repository.

## Project in one line
Historical Arduino sketch that drives a single 7-segment display and a push button. See [README.md](README.md).

## Hard rules
1. **Never modify `src/ejercicio-alumno/ejercicio-alumno.ino`.** Not its logic, formatting, comments, names or line endings (CRLF). Its SHA-256 must remain `e3b51b93e77f1a9661a3eaaf745de63b1f5c879b979ab124a7b770335d6c3267`.
2. **Never delete or edit archived material** in `docs/archive/`.
3. Do not add build systems, CI, containers, linters or package managers unless explicitly requested.
4. Tag documentation claims as **Confirmed**, **Inferred** or **Unknown**; never present inferences as facts.

## Workflow
Follow intent → spec → plan before implementing anything:
- [docs/sdlc/intent.md](docs/sdlc/intent.md)
- [docs/sdlc/spec.md](docs/sdlc/spec.md)
- [docs/sdlc/plan.md](docs/sdlc/plan.md)

New or modernized code goes in a separate folder (e.g. `src/modernized/`), never into the original sketch.

## Verify before committing
```bash
sha256sum src/ejercicio-alumno/ejercicio-alumno.ino
```
