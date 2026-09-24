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

Decision: pinned Android 4.4.4/API19 source, supplemented by the minimum Android 4.4 ARM reference execution needed to resolve ambiguity, defines the observable compatibility contract. AGR begins diagnosis by mapping that upstream path, extracting behavior and invariants, and locating the earliest evidenced divergence. Different host mechanisms are allowed only at an explicitly declared kernel, service, device, or HostServices boundary. Semantic equivalence does not authorize an original implementation when an API19/AOSP source owner exists. `REFERENCE_MIGRATION_RULES.md` outranks this decision for Android-visible source ownership. `UPSTREAM_MAP` is a disposable navigation cache and does not create architectural authority.

Discovery may use marked, temporary counterfactual experiments. Closure excludes them and requires a public fix, focused contract, real-APK confirmation where applicable, and exact commit/tree evidence.

Reopen only if authoritative evidence proves the pinned source/reference cannot define a required observable behavior. A real-game gap does not itself authorize a Framework API or HLE. Framework migration follows `REFERENCE_MIGRATION_RULES.md`.

The former “Physical Surface post/display boundary (active candidate)” text is history in `docs/history/PRE_REFERENCE_RECOVERY_STATE.md`. It is not an active decision.

## D009 — Local Reference Mapping and CLEAN/TRACE Separation

Status: LOCKED

API19 TRACE is the default local dependency-mapping environment.

API19 CLEAN remains the uninstrumented semantic oracle.

TRACE determines what the game reaches. Pinned source determines implementation. CLEAN differential verifies semantics.

TRACE evidence never authorizes an original AGR implementation.

Dependency mapping and semantic differential are separate workflows.

For the new migration workflow, D009 decides when reference execution is used. That decision outranks D008's older limit that executable API19 reference runs only for unresolved observable ambiguity. D008 remains the locked rule for source-first semantic differential. It is not rewritten by this decision.
