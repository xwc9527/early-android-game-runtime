# Second-game ELF-only AOT experiment

Question: can the same public ARM translator prepare the existing Gloomy renderer path from its original APK/ELF and exported symbols, without using the renderer's observed instruction trace as a translation input?

The prior Gloomy proof used a trace-guided artifact. Its 174 executed instructions and 153 AOT-eligible instructions are only an oracle. The new artifact must be generated before the interpreter trace is recorded. The input is the locked F-Droid APK SHA-256 `40a67842345b879fc4b4be90159787f04664d9530f6a3e676c13fa412ad98733`, its `lib/armeabi-v7a/librenderer.so` SHA-256 `2b8672e79da33de4661f6aa0bcb79df2a302637aca9829d53fff8077a6895638`, ELF executable code and exported symbols, and the existing test harness's explicit linker base `0x02800000`.

The iOS ARM64 simulator is required because static scanning cannot establish guest execution, host-call sequence, framebuffer equivalence, or actual AOT/fallback coverage. The run will archive the original APK member, generated C and object, trace, checkpoints, host calls, observable results, and compile/preparation cost. Its small renderer path can support a cross-game reuse claim only within this measured scope; it cannot by itself prove large-game scaling or general load-bias automation.
