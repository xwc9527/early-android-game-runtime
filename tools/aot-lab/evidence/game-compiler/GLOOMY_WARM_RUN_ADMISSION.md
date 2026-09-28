# Gloomy compiler warm run admission

Question: At identical original ELF, `all-exidx` discovery, 153 compiled and 21 SVC instructions per renderer pair, does the direct ARM64 artifact improve repeated guest-engine cost relative to the interpreter and the existing generated-C AOT baseline?

Current uncertainty: The two-address cold differential passes, while ARM64 `__text` grows from 44,412 to 67,792 bytes. A cold 174-instruction call is too short to distinguish backend cost from timer noise. Static analysis cannot measure runtime dispatch, guest-state traffic, or the cost of instruction guards.

Outcome A: Five independent, 16,384-iteration pairs pass semantic/host/accounting checks and materially improve guest-engine time relative to the old artifact. This would establish a runtime advantage despite the code-size increase.

Outcome B: The new artifact is no faster, or its semantic/host/accounting checks fail. This removes performance as support for the current direct-assembly template; any change would need another explicit architecture experiment, not per-game tuning.

No new workload, Android Runtime change, or trace-based translation is involved. The existing iOS Simulator is required for native ARM64 execution and guest-engine timing.
