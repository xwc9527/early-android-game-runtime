# ELF-only AOT execution experiment

Question: can an AOT artifact generated exclusively from an original ARMv7 ELF and formal linker placement execute the later KungFoo loader-stage guest path with interpreter-equivalent state and observables, without using that path's trace as translation input?

The existing proof is trace-guided. Local static ELF analysis can identify candidate instructions and block entries, but cannot prove that the generated native code follows the guest's actual indirect targets or preserves execution semantics. The iOS ARM64 simulator run is needed for this differential; this run is a translation-input experiment, not another optimization of the known loader benchmark.

Input is the locked `armeabi-v7a` APK member SHA-256 `010baa4964cd7dbcf1ba038428ab4d6afc13ffd0a180b447be07b8f088f9ba9d`. The first policy seeds ELF init/fini and standard Android native ABI entry symbols, then follows statically resolved control flow. Load bias `0x10000` comes from the current formal linker VMA placement and is recorded explicitly. The interpreter trace is captured only after artifact generation.

If execution and differential pass with finite fallback, the result proves path-independent generation for this one held-out execution and quantifies the remaining static discovery gap. If it fails, raw fallback PC/mode/reason records and the first state or observable difference determine whether to repair a generic decoder/discovery mechanism, test a broader static seed policy, or classify an unresolved route limit. Neither outcome authorizes D011 or ownership changes.
