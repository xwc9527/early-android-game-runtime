# AGR Offline Game Compiler architecture validation

## Judgment

`CURRENT_AOT_ARCHITECTURE_REMAINS_PREFERRED` for the implemented direct-AArch64 prototype. The prototype passes the tested architectural differential, but its generated code and source are larger than the existing generated-C backend on both fixed workloads. Its faster offline compilation does not offset the measured KungFoo execution regression. This does not refute every possible AGR-owned compiler design, and it does not change D011 or declare an ARM execution primary route.

## Exact comparison

All runs use the same `all-exidx`, relocatable, no-execution-trace-input policy and the existing AGR guest state, formal linker, Runtime boundary and interpreter fallback. The compared runs report the same macos27 ARM64 runner image, Xcode 27.0 and iOS 27.0 simulator runtime. Warm Gloomy generated-C data used a diagnostic table, so its warm timing is context rather than a strict no-diagnostic backend A/B.

| Measure | Gloomy generated-C | Gloomy direct ARM64 | KungFoo generated-C | KungFoo direct ARM64 |
| --- | ---: | ---: | ---: | ---: |
| Run | 36417253721 | 36420766742, warm 36422135091 | 36405016519 | 36422021199 |
| ELF / executable bytes | 9,376 / 4,114 | 9,376 / 4,114 | 882,136 / 542,032 | 882,136 / 542,032 |
| Generated source bytes | 136,626 C | 352,016 assembly + 56,029 C table = 408,045 | 18,316,808 C | 42,990,307 assembly + 6,902,728 C table = 49,893,035 |
| ARM64 `__text` bytes | 44,412 | 67,792 | 5,404,896 | 8,170,100 |
| Offline preparation seconds | 0.032 | 0.040 | 4.174 | 3.927 |
| Native compilation seconds | 0.49 | 0.32 assembly + 0.04 table | 82.40 | 27.33 assembly + 1.07 table |
| Static blocks | 308 | 314 | 33,548 | 37,395 |
| Executed compiled / total instructions | 153 / 174 | 153 / 174 | 26,404 / 29,703 | 11,498 / 29,703 |
| Ordinary fallback / IT / SVC instructions | 0 / 0 / 21 | 0 / 0 / 21 | 2,006 / 629 / 664 | 16,912 / 629 / 664 |
| Dynamic compiled blocks / dispatch calls | not recorded in comparable cold result | 32 / not recorded, fixed placement | 6,632 / 3,299 | 6,444 / 18,205 |
| Paired guest-engine median ratio, interpreter ÷ compiled route | warm 1.336, diagnostic build | warm 1.288, no-diagnostic build | 0.490, 7 samples | 0.139, 7 samples |

Gloomy direct ARM64 passed both fixed `0x02800000` and first-fit `0x10000` placements: 174 instruction oracle, 32 matching checkpoints, equal host call sequence and observables, zero ordinary fallback. The five warm pairs each ran 16,384 repetitions and passed host, observable and instruction-accounting checks. KungFoo passed the 29,703-instruction interpreter trace comparison, 6,444 matching checkpoints, host calls and Runtime-visible observables, fallback accounting, and 125-instruction unseen path accounting (84 compiled, 41 interpreter). Both original artifact ZIPs and every extracted raw member are included here. The ZIP SHA-256 values are `f7eb66319afb3a188c146e21ffbe5c3c78f2d55696267be08b1d841305d5b2f8` (KungFoo) and `822b71ad87a5ac2a0bd71ad67cd0780e19a259f7966fe01fa877613c77f3c70a` (Gloomy warm).

## Core questions

- **A — UNPROVEN in general; REFUTED for this prototype's size advantage.** The direct emitter is 2.99×/2.72× larger in generated source and 1.53×/1.51× larger in ARM64 text on Gloomy/KungFoo. Therefore merely replacing generated C with direct assembly does not remove the observed expansion. The experiment does not establish whether a different IR, block formation or register allocation would.
- **B — REFUTED for this prototype.** It preserves AGR ownership and reduces KungFoo native compilation time from 82.40 to 28.40 seconds, but it does not lower generated-code size or measured guest-engine cost. Gloomy generated-C and direct ARM64 have equal dynamic compiled-instruction coverage, so the larger text there is an especially direct comparison. KungFoo's much lower compiled coverage prevents isolating backend execution quality from fallback frequency.
- **C — PROVEN for tested safety, SUPPORTED as a performance limit at present.** All tested fallback handoffs preserve the compared architectural and host-visible results. KungFoo executes 16,912 ordinary lookup misses plus 629 IT-state fallbacks and 664 SVC boundaries. Its 0.139× route ratio shows that the current narrow compiler front end makes fallback a practical performance wall on this path; it does not prove fallback is inherently a wall at higher public capability coverage.
- **D — SUPPORTED for incremental public capability, UNPROVEN for long-term sufficiency.** No package, game identity, fixed guest PC or execution trace is used to select code. The most frequent KungFoo ordinary miss classes are common ARM operations: conditional branch 3,133, immediate compare 1,933, immediate add with flags 1,823, immediate store 1,535 and register compare 1,304. These are public ISA/compiler capabilities. Two workloads cannot prove that all future game coverage remains narrow, and this validation does not expand the opcode set to find out.

The direct emitter still materializes guest state for each operation, guards every instruction word, and uses the existing hash lookup and dispatcher. Those observed structural properties explain why it did not yield a lower-cost execution architecture. The correct next route decision at this stage is to retain the existing generated-C backend while treating a different compact IR/block-register strategy as a separate future proposal requiring its own evidence. No external compiler substrate is required by these results.
