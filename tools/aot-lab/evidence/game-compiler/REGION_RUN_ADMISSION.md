# Region compiler run admission

Question: does a register-resident, directly chained offline region compiler preserve AGR architectural state and fallback handoff on the two fixed ARMv7 workloads, and does changing block execution structure reduce dynamic dispatch, code size or guest-engine time relative to the archived per-block generated-C and direct-assembly runs?

Current uncertainty: local static generation establishes region counts, direct-edge candidates and guard placement, but cannot compile and execute `arm64-apple-ios-simulator` output or observe actual dynamic chaining, host calls, guest state and performance. The previous direct-assembly run retained the original per-block execution model and cannot answer this question.

Outcome A: matching interpreter differential and measured structural advantage supports the region architecture for further compiler work. Outcome B: a differential mismatch isolates a compiler correctness defect; matching differential without structural advantage rejects this implementation, without rejecting every specialized compiler design. The fixed Gloomy and KungFoo inputs are sufficient for this comparison; no new workload or Android laboratory work is needed.
