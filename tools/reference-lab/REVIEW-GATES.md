# API19 reference review gates

These gates apply to the pinned `android-4.4.4_r2` source and to the local
CLEAN/TRACE pair. The five locked games supply observed lower bounds; they do
not define the Android runtime or prove that unobserved code is unused.

1. **Dalvik equivalence.** Both guests run with
   `dalvik.vm.execution-mode=int:portable`. The pair record pins identical
   resolved source manifests, host toolchains, build flavor, and build-only
   patch; it records the separate `libdvm.so` hashes and the exact TRACE
   instrumentation patch. Live probes pull and hash the guest `libdvm.so`,
   capture interpreter, dexopt, CheckJNI, and JIT properties, and compare the
   CLEAN and TRACE configurations for the same APK and scenario. In this
   API19 Dalvik revision, `vm/Init.cpp` starts the JIT compiler only when
   execution mode is `kExecutionModeJit`; portable mode disables it. These
   checks establish build and configuration parity. They do not assert that
   instrumentation has zero timing effects.

2. **ABI.** `sample_matrix.py` records each locked APK's actual library ABIs.
   Vector Pinball includes ARM native libraries without an x86 variant.
   Its x86 result cannot validate its native path. The separate `aosp_arm-eng`
   CLEAN/TRACE queue uses the same pinned source revisions and portable mode.

3. **Zygote inheritance.** `probe_pair.py` captures boot logcat before clearing
   it for app events, checks the guest `framework.jar` against the build, and
   reads its `preloaded-classes` resource. `preload_inventory.py` marks a class
   `PRELOADED_IN_ZYGOTE` only when the completion count matches the configured
   list minus individually logged failures. The current x86 boot reports
   2777 successful classes and one missing class,
   `java.lang.UnsafeByteSequence`. The probe also captures Zygote and app
   memory maps; common libraries are labelled inheritance candidates, since
   maps alone do not prove how each mapping entered the app process. The
   pinned API19 `ZygoteInit.java` calls `preloadClasses`, `preloadResources`,
   and `preloadOpenGL`. A linked later revision additionally calls
   `preloadSharedLibraries`; that later behavior is not assumed for this tag.

4. **Observer scope.** The current Dalvik hook records app DEX method invokes
   that resolve into boot-classloader methods through the portable interpreter.
   It is tagged `APP_DEX_TO_BOOT_METHOD_INVOKE`. It is not a global dependency
   trace. Class load/init/resolution, fields, quickened target identity,
   reflection, JNI/RegisterNatives, dynamic native loads, native callbacks,
   resources, services, graphics, input, storage, and audio require separate
   observation paths. `trace-run.json` and Migration Books state
   `APP_TRIGGERED_OBSERVED_LOWER_BOUND` and cannot authorize pruning.
   `boot_owner_index.py` classifies Java dependencies by the declaring
   class's exact definition in the CLEAN image's BOOTCLASSPATH JARs. This
   assigns original AOSP repo and broad owner cluster with JAR hashes; it
   does not locate a source file or close a subcluster. Unknown classes stay
   unresolved.
   TRACE event sequence numbers are checked for duplicates and gaps for each
   game process. Thread scheduling can reorder logcat records, so the check
   compares the complete sequence set rather than arrival order. A gap fails
   the trace. The first logcat transport lost records even with guest-side
   file capture. The current observer appends directly from Dalvik to a guest
   file precreated by the probe under API19 SELinux permissions; host logcat
   remains runtime diagnostic evidence. A direct-file
   transport still must pass the sequence check before it is called complete.
   The pinned `external/sepolicy/file_contexts` labels `/data/local/tmp` as
   `shell_data_file`, and `external/sepolicy/untrusted_app.te` grants an app
   read/write permission on files of that type but only read/search permission
   on the directory. The probe therefore creates and chmods the file before
   the app starts, in both CLEAN and TRACE.

5. **Service boundaries.** A source-located service boundary cannot be closed
   as `BOUNDARY` until its reviewed index entry includes the interface
   descriptor, transaction code, request/response schemas, callback list,
   lifecycle, and error semantics. Missing contracts remain
   `BOUNDARY_CANDIDATE`. This does not claim system_server internals were
   migrated.

6. **Deletion rule.** `NOT_OBSERVED != UNUSED`. Books and corpus unions mark
   unobserved dependencies `UNKNOWN` and `may_authorize_pruning=false`.
   Deletion requires a separate controlled same-sample, same-trajectory CLEAN
   differential with no semantic divergence. No deletion approval is produced
   by the current mapper or static corpus.

`pair_concordance.py` compares matched probe inputs and structural runtime
states. Its strongest result is `STATE_CONCORDANT`; it does not establish
game semantic equivalence or authorize deletion.

Current game probes are staged evidence. Frozen Bubble has a confirmed game
frame, input changes, HOME transition, resumed game, and further input on
CLEAN. KungFoo Barracuda passes a native-backed gameplay lifecycle after its
on-screen confirm control starts a scored game loop. Gloomy Dungeons 2 enters
its tutorial from PLAY on a
landscape reference and reaches a first-person gameplay scene; the matched
CLEAN/TRACE path passes structural lifecycle comparison. Pixel
Dungeon exits on the initial non-GPU emulator with `No configs match
configSpec`; GPU-enabled headless CLEAN runs pass process and lifecycle checks,
while ScreenshotClient/BufferQueue capture has failed. A matched TRACE run
is incomplete because its 200 MB data partition fills during direct event
writing. Ext4 journal recovery on a copy leaves only six free 4 KB blocks.
The tested 512 MB and 1 GB data templates trigger system WindowManager
fatal exceptions before app installation on this legacy emulator. Pixel's
gameplay validity remains undetermined; it is not a prerequisite for other
samples. Vector Pinball passes a paired ARM lifecycle with `libgdx.so`
mapped. A single-color or failed frame capture is inconclusive. Sample
usability requires runtime lifecycle, input,
exception, process, and native/graphics evidence; screenshots only support
those findings.

Old emulator graphics behavior is a reference-carrier fidelity risk. A guest
process that survives, accrues CPU time, accepts lifecycle transitions, and
maps expected libraries establishes activity, not correct rendering or game
semantics. Record host emulator faults, guest fatal signals, graphics driver
errors, and screenshot transport failures separately. If a reproducible
graphics limitation prevents the normal path, compare the same pinned API19
CLEAN/TRACE guest builds on a more reliable carrier before changing Android
guest code. A carrier change requires fresh matched runtime evidence; old
emulator runs cannot certify its GPU behavior.

For each game, a usable runtime scenario must establish: SHA-pinned APK
installation; app process and resumed/focused Activity after launch and a
stability interval; an input-driven transition into the game's normal path;
HOME/background and foreground return; process termination and fresh launch;
no app fatal exception or native fatal signal; and expected native libraries
loaded for that guest ABI. The probe records process ID, thread count, memory,
CPU ticks, window/Activity focus, mapped libraries, logcat, and frames at
each step. A screenshot cannot alone grant or revoke sample qualification.
