# CI execution-composition baseline

Measured before the CI composition changes in this branch.

## Evidence

GitHub Actions closure run `35530434859` on commit `a5c5958af1a65763808fc2a4de669c4e76694876` completed in **6m54s**. Its two Simulator macOS jobs overlapped:

| Job | Elapsed | Relevant steps |
|---|---:|---|
| `focused-simulator` | 4m55s | bounded continuation discovery, including sample fetch, build, boot, install and probe |
| `runtime-regressions` | 6m24s | contracts 32s; bounded smoke 231s; real-game regressions 91s |
| `iphoneos` | 57s | device build |
| `source-contract` | 8s | pinned source and fixture gate |
| `closure-evidence` | 6s | exact-candidate evidence assembly |

The concurrent Simulator jobs consumed about **11m19s** of macOS time together (295s + 384s), before counting the separate 57s iphoneos runner. The Simulator lane repeated environment preparation because the bounded smoke in `runtime-regressions` called the full build-and-run script again.

The focused job log markers provide these preparation measurements:

| Stage | Measured / bound | Interpretation |
|---|---:|---|
| sample fetch and preparation | 40s | exact marker interval |
| compile and link | 23s | exact marker interval |
| Simulator boot readiness | 80s | exact marker interval |
| install | <98s | marker interval from install start to probe launch; includes any intervening harness work, so this is an upper bound, not an isolated `simctl install` duration |
| focused probe | about 10s | launch-to-result markers |
| focused evidence upload | 5s | Actions step duration |
| Runtime contracts | 32s | Actions step duration |
| bounded Runtime smoke | 231s | full build/boot/install/run path |
| real-game regressions | 91s | Actions step duration |
| Runtime regression artifact upload | 2s | Actions step duration |

Sources: [run 35530434859](https://github.com/xwc9527/early-android-game-runtime/actions/runs/35530434859), `focused-simulator` job `106129976488`, `runtime-regressions` job `106129976523`, and [job log](https://github.com/xwc9527/early-android-game-runtime/actions/runs/35530434859). Times are rounded to whole seconds from GitHub job/step timestamps or the old script's timestamp markers. The old script did not emit isolated dependency-restore or `simctl install` timings; those are recorded as unavailable/bounds rather than inferred as exact values.

This is a baseline record only. It does not change Runtime behavior, closure semantics, or the definition of any module state.

## First composed validation (cold ANGLE/Rust caches)

GitHub Actions run `35554563644` validated commit `8e717294670a8ab19f2d7ca62e13a5c6c2315751`, tree `0f0d0c8c226d1c3651c670821e38125b29480212`. Source contract, focused Framework probe, Runtime contracts, bounded smoke, real-APK regressions, iphoneos build, and the run summary all passed. Closure evidence was skipped because this was a validation run.

| Stage | Seconds | Cache / execution evidence |
|---|---:|---|
| Sample preparation | 10 | APK cache hit; lock hashes verified on Ubuntu |
| Simulator sample prep | <1 | reused the prepared APK cache; no index lookup |
| Dependency preparation | 8 | Rust target preparation |
| Compile/link | 172 | ANGLE and Rust caches missed on this run |
| Simulator boot total | 180 | started in parallel with preparation/build |
| Simulator boot wait after build | <1 | readiness was already reached |
| Install | 15 | one app install for all Simulator stages |
| Focused probe | 9 | pass |
| Runtime contracts | 70 | pass |
| Bounded smoke | 32 | pass, reusing the installed Simulator app |
| Real-APK regressions | 75 | pass, reusing the same Simulator |
| iphoneos build | 32 | pass on separate macOS runner |
| Workflow wall time | 7m39s | all required validation stages passed |

This first validation demonstrates runner reuse and removal of the second Simulator build/boot/install path. It is not a warm-cache timing comparison: ANGLE and Rust were cold, and the sample cache had already been populated by an earlier attempt. The Rust workflow key also initially hashed an ignored, untracked `Cargo.lock`; the follow-up changes key it from the tracked `Cargo.toml`, Rust version, and target triple. A subsequent validation is required to measure the corrected cold-sample path and warm-cache path separately.
