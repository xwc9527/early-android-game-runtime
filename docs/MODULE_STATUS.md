# AGR Module Status

Status controls modification permission, not total completeness. `stable` means the current contract is met and protected; `active` means it belongs to the active target; `experimental` means it has no closure claim.

| Module | Status | Closure commit | Regression gate | Reopen condition |
|---|---|---|---|---|
| Formal linker/libdl | stable | `6ec6673` lineage | API19 linker/libdl contracts and differential | direct mapping, symbol, relocation, or lifecycle regression |
| pthread/TLS/futex | stable | `bionic-thread-migration` closure lineage | Bionic pthread/futex contracts | proven guest-thread semantic failure |
| EHABI/C++ exceptions | stable | `503f88a`/`eb024d4`/`da20772` lineage | EHABI Phase 1/2A/2B differential | guest GCC exception regression |
| API19 allocator | stable | `dd83c742` baseline lineage | allocator contract/stress and API19 differential | heap semantic regression on primary path |
| APK bootstrap | stable | `1111664` | PVS bootstrap gate | manifest, DEX startup, loadLibrary, or binding regression |
| NativeActivity/Window | active | — | PVS1 target gate | current active target |
| Looper/InputQueue | active | — | PVS1 input contract | current active target |
| Simulator regression harness | active | — | bounded smoke and evidence gate | current primary blocker |
| DEX Runtime Activity lifecycle | active | — | Activity GC-root contract and PVS1 real-APK gate | discovery proved host-owned launched Activity was absent from VM roots |
| DEX/Dalvik completeness | experimental | — | focused DEX/JNI contracts | future declared migration target |
| Framework HLE | experimental | — | focused public API contracts | gameplay proves a public missing behavior |
| Audio/OpenSL ES | experimental | — | — | declared gameplay target requires audio |
| Product UI/library | experimental | — | — | product phase begins |

Stable modules are readable and diagnosable. A change requires an evidence-backed reopen reason in machine-readable run metadata.
