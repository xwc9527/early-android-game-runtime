# KungFoo compiler prototype run admission

Question: On the same 882,136-byte original ARMv7 ELF and bounded 29,703-instruction path, does direct AArch64 generation reduce final code/build/dispatch costs enough to offset conservative block guards and its intentionally incomplete common-op set?

Current uncertainty: Gloomy passes architectural differential at equal 153/174 AOT coverage but increases `__text` from 44,412 to 67,792 bytes. That small ELF cannot decide how source and object sizes scale, how many KungFoo instructions remain compiled, or whether ordinary interpreter fallback becomes a performance wall.

Outcome A: KungFoo state/host differential passes with materially smaller object or guest-engine cost at useful compiled share. This supports the native-code representation even if common ARM ops remain to add.

Outcome B: Differential fails, fallback dominates, or object/compile/engine cost worsens. This rules out the current direct-assembly template as a sufficient architecture; it does not rule out AOT or every possible specialized compiler.

Source and local analysis cannot supply ARM64 object sections, simulator guest-engine timing, linker binding, or real fallback transition evidence. The run generates code from ELF before collecting the interpreter oracle. No game identity or observed PC is a translation input.
