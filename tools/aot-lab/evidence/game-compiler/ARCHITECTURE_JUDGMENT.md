# AGR Offline Game Compiler architecture validation

## Judgment

`CURRENT_AOT_ARCHITECTURE_REMAINS_PREFERRED` for the current engineering choice. The direct AArch64 emitter is separately `DIRECT_AARCH64_EMITTER_ARCHITECTURE_REFUTED`; the later offline region compiler changes dispatch and state handoff but does not demonstrate a net code-size or execution advantage on the two fixed workloads. This stage judgment does not establish that all possible specialized compilers are inferior, change D011, or declare an ARM execution primary route. The direct-emitter comparison below remains its original, narrower negative evidence; the region comparison follows it.

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

The direct emitter still materializes guest state for each operation, guards every instruction word, and uses the existing hash lookup and dispatcher. Those observed structural properties explain why it did not yield a lower-cost execution architecture. A register-resident region compiler with direct intra-region control flow is the next in-scope architecture experiment. No external compiler substrate is required by these results.

## Offline region compiler judgment

The region prototype groups statically discovered decoded blocks into 64-entry regions, copies guest registers/CPSR into local state once per entry, uses direct intra-region branches, a dense PC index and a dense region entry ordinal, and checks the live guest instruction bytes once per entered block against a validated snapshot of the original ELF. A guest write ends its block before any next code guard. The checkpoint audit uses a one-block budget; checkpoint-free performance runs permit up to 64 blocks per entry. The local register array does **not** prove that all guest registers remain in host registers. No game identity, package name, traced path, or guest PC exception selects translation behavior.

The indexed-entry implementation was tested at commit `0e3c28943901d7732411b22ddf7aef9ee267dffd`, tree `78ed6b98854c75a52f6407900df20013819d6116`, in Gloomy run `36450794539` and KungFoo run `36450798560`. Both reported `macos27` ARM64 image `20260921.0210.1`, Xcode 27.0 and iOS 27.0 simulator. The Gloomy warm run passed five 16,384-iteration pairs with matching observables, host calls, and instruction accounting. KungFoo passed the full 29,703-instruction interpreter comparison, all 9,600 checkpoints, host calls, Runtime-visible fields, fallback accounting, and the 125-instruction unseen path (117 compiled, 8 interpreter). The raw ZIPs and all extracted members are at `run-36450794539-original.zip` / `run-36450794539/` and `run-36450798560-original.zip` / `run-36450798560/`; SHA-256 values are `c965b8599b6d46917f4d966febbcf683e298b022fcf54bd6ba0dbdacd0f585d9` and `0dbbcdf6b599bc5abbbddc0cf3309256a4af817a9c9015c7442d21c8f4bb58bd`.

| Measure | Generated-C baseline | Indexed region compiler |
| --- | ---: | ---: |
| KungFoo run | 36405016519 | 36450798560 |
| Original ELF / executable bytes | 882,136 / 542,032 | 882,136 / 542,032 |
| Generated C bytes | 18,316,808 | 37,603,456 |
| ARM64 `__text` bytes | 5,404,896 | 7,910,356 |
| ARM64 object file bytes | 13,670,192 | 10,920,464 |
| Offline preparation seconds | 4.174 | 2.743 |
| Native compilation seconds | 82.40 | 69.16 |
| Compiled / interpreter instructions on compared path | 26,404 / 3,299 | 26,404 / 3,299 |
| IT / ordinary lookup / SVC fallback instructions | 629 / 2,006 / 664 | 629 / 2,006 / 664 |
| Dynamic compiled blocks | 6,632 | 9,600 after write splits |
| Intra-region chained blocks | not applicable; per-block dispatcher | 6,633 of 9,600 |
| Seven-pair guest-engine ratio, interpreter / compiled route | 0.490 | 0.427 |

The seven KungFoo samples are short and noisy: individual paired ratios span 0.293–0.690 for generated C and 0.180–0.553 for indexed regions. The table uses each run's ratio of median guest-engine times, not whole app time. The region run's median AOT drive time was 0.868 ms versus 0.811 ms for generated C; fallback interpreter time was 0.169 ms versus 0.202 ms. The compared runs use the same ELF hash `010baa4964cd7dbcf1ba038428ab4d6afc13ffd0a180b447be07b8f088f9ba9d` and runner image, but separate CI executions. These data prove no measured performance win for this candidate; they do not quantify a universal performance limit. The Gloomy generated-C warm baseline used a diagnostic table, so it is context only, not a strict warm backend A/B. Indexed-region Gloomy warm yielded a 1.336 ratio with 58,916 bytes of ARM64 `__text`; its raw differential is in `run-36450794539/first-fit/warm-differential.json`.

The earlier full-capability region run `36444944896` used 10,082,896 bytes of ARM64 text and yielded a 0.392 ratio. The immutable-ELF guard snapshot run `36448007079` reduced text to 7,479,436 bytes but yielded a 0.369 ratio. The indexed entry lowered native compilation to 69.16 seconds and raised the ratio to 0.427, while increasing text to 7,910,356 bytes. Those two focused changes demonstrate that duplicated guard constants and sparse entry selection had avoidable cost; neither produced a clear overall advantage over generated C.

### A–D findings and decision boundary

- **A — REFUTED_FOR_CURRENT_IMPLEMENTATION as a size advantage; UNPROVEN generally.** Direct AArch64 and the materially different region compiler both emit more ARM64 text than generated C on the fixed workloads. The region object file is smaller, but its executable text and generated source are larger. This identifies costs of the tested representations, not an inherent AOT/SBT expansion law.
- **B — PROVEN for dispatch reduction, REFUTED_FOR_CURRENT_IMPLEMENTATION for net advantage.** KungFoo chained 6,633 of 9,600 compiled blocks without dispatcher reentry, with the same guest and host observables. Region-local state reduces explicit outer-state handoffs, while actual host register residency remains UNPROVEN. Larger text and lack of a measured guest-engine win make continued generated-C evolution the lower-risk current choice. The separate-run timing noise prevents claiming a precise slowdown percentage.
- **C — PROVEN for safe fallback on the compared path; UNPROVEN as a universal performance limit.** The interpreter handled 2,006 lookup misses, 629 IT-state instructions and 664 SVC instructions with full accounting and equal checkpoints/observables. Fallback is 3,299/29,703 instructions; it is finite and not the main instruction path. The measured compiled drive itself does not beat generated C, so the result cannot be assigned solely to fallback.
- **D — SUPPORTED for incremental public capability; UNPROVEN across the game library.** The same 48 existing decoded operation kinds were admitted to the region compiler without a game-specific branch, and the unseen KungFoo path compiled 117/125 instructions. The two fixed games show reusable ARM semantics, not complete ARMv7 or whole-library closure.

`AGR_SPECIALIZED_COMPILER_ARCHITECTURE_SUPPORTED` is not supported by the measured net result. `EXTERNAL_COMPILER_SUBSTRATE_REQUIRED` is not supported because no in-scope blocker requiring one was found. `DECISION_REQUIRED` is not triggered: no guest contract, D004/D005, Runtime ownership, fallback principle, or locked architecture needs changing to preserve the current generated-C route. A future scalar-register/IR optimizer remains possible but is not validated by this prototype and is not a basis for changing the present route decision.
