# AGR Decisions

This file is append-only. A decision is reopened only under its stated condition.

## D001 — Compatibility Runtime, not Android OS

Status: LOCKED

Decision: preserve original APK/DEX/ARMv7 binaries and provide their observable Android game environment inside one host process. Do not boot a complete Android system.

Reopen only if authoritative evidence proves a required game-visible behavior cannot be implemented without an Android system process.

## D002 — Host-side DEX runtime

Status: LOCKED

Decision: DEX executes in the host-side Runtime. ARMv7 native libraries execute in the guest domain and communicate through JNI.

Rejected: a full guest Dalvik/Android process and per-game Java rewrites.

## D003 — ProcessRuntime and GuestThreadContext

Status: LOCKED

Decision: one Android application process has shared `ProcessRuntime` state. Every guest pthread maps to one Darwin pthread with an independent `GuestThreadContext`. Host services use service-specific affinity.

Rejected: a cooperative scheduler, one global serialized Runtime, and one complete host context per thread.

## D004 — Formal linker ownership

Status: LOCKED

Decision: the pinned KitKat AOSP linker source port exclusively owns ELF layout, dynamic linking, relocations, constructors/finalizers, and libdl lifecycle in production.

## D005 — Guest C++ EHABI ownership

Status: LOCKED

Decision: real GCC 4.8 exception propagation, personalities, cleanup, landing pads, RTTI, catch, rethrow, and exception lifetime remain GUEST-ARM. Host HLE owns only the true `__gnu_Unwind_Find_exidx` boundary backed by formal linker metadata.

## D006 — API19 source and behavior baseline

Status: LOCKED

Decision: Android 4.4.4/API19 and corresponding NDK r10e/GCC 4.8 components are the migration baseline. Modern Android behavior is not imported by assumption.

## D007 — Branch, closure, and merge evidence

Status: LOCKED

Decision: closure attaches to an exact commit and Git tree. The merge candidate HEAD and tree must match closure evidence. Conflict-free merge results must preserve tree equivalence. Squash is not the default because it destroys the tested commit identity.

Required lifecycle: feature branch, implementation, discovery CI, fix, closure CI, closure evidence, merge review, main merge, post-merge smoke, baseline update.

Reopen only if the source control platform cannot preserve or verify commit/tree identity.

## D008 — API19 behavior oracle and source-first differential

Status: LOCKED

Decision: pinned Android 4.4.4/API19 source, supplemented by the minimum Android 4.4 ARM reference execution needed to resolve ambiguity, defines the observable compatibility contract. AGR begins diagnosis by mapping that upstream path, extracting behavior and invariants, and locating the earliest evidenced divergence. AGR may use different host mechanisms when they preserve those semantics. `UPSTREAM_MAP` is a disposable navigation cache and does not create architectural authority.

Discovery may use marked, temporary counterfactual experiments. Closure excludes them and requires a public fix, focused contract, real-APK confirmation where applicable, and exact commit/tree evidence.

Reopen only if authoritative evidence proves the pinned source/reference cannot define a required observable behavior.
# Physical Surface post/display boundary (active candidate, not closed)

The exact current iPhone run `000168ac811f20380000fd326ab452e5` on `cdbaf341` reached a changed child-Surface post, but the UIKit root stayed black. API19 `Surface.unlockCanvasAndPost` calls the native `Surface::unlockAndPost`, whose KitKat implementation queues the buffer to `IGraphicBufferProducer`; the Binder/SurfaceFlinger consumer and device display are not portable in-process services. AGR keeps its existing Android-visible SurfaceHolder/Canvas producer. A bounded completed-post snapshot, keyed by Surface identity/generation/post count, is handed to UIKit on the main thread at that genuine platform boundary. UIKit does not run guest code or choose Android state. This is `HOST_ADAPTATION_BUG` / host-endpoint HLE, rather than a Bitmap or Canvas rewrite.

The physical observer also finalized and destroyed the process while the second game draw was active. That is a separate `HARNESS_BUG`: ending a forensic window must not end a healthy game process. The candidate keeps the producer alive after sealing and distinguishes producer post, host acquisition, host submission, and verified screen presentation. The historical physical run's `agr-current-run.json` does not match its manifest hash because a later lifecycle update rewrote it; current/previous files and that integrity defect remain historical evidence. The post-seal write guard is part of this candidate. Simulator and iPhone visible output remain **UNVERIFIED** until exact-candidate evidence is collected.
