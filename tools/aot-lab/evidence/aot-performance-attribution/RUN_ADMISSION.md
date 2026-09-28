# AOT performance attribution run admission

Question: can the exact entry register/CPSR state and sparse guest memory pages for the two trace-selected real compiled segments be captured during the existing iOS Simulator executions, so interpreter and translated payload can be replayed from identical inputs before any timing judgment?

Current uncertainty: the archived instruction traces contain pre-instruction registers and CPSR but omit the contents of pages read and written by the selected segments. The interpreter, generated-C, and region compiler cannot be compared on the same initial guest memory state from source inspection or those traces alone. The capture writes the selected entry state, the guest pages actually touched according to the archived path, and the exact original ELF bytes. It is test-only, runs once before the selected compiled entry, and does not change the game result.

Outcome A: both fixtures are captured, their PC/register/CPSR identities match the archived trace, and interpreter replay reaches the archived post-state. This admits repeated layered timing on the same real guest region. Outcome B: capture or replay differs. Then the fixture is invalid and the first mismatch must be isolated before timing. No compiler or Runtime optimization is authorized by either outcome.

Why macOS/Simulator: only the existing real Gloomy and KungFoo execution paths can provide the original guest memory at the selected entry. This run records fixtures; it is not a performance result. Both selections are reproducible from the committed trace selector and `selected_regions.json`; the translator still consumes ELF only.
