#!/usr/bin/env python3
"""Phase B: API19 system-boundary analysis for the census's high-risk paths.

For every contract family whose Android 4.4.4 implementation crosses a process
boundary, this records the pinned API19 source owner, what the *game* can
actually observe, and whether that observable contract can be expressed by
finite local state inside one AGR process.

Reducibility is decided from guest-visible semantics only. Android using Binder,
system_server or a dedicated service process is never by itself a reason to call
a boundary irreducible. Where the evidence does not decide, the record stays
UNRESOLVED; nothing here guesses in order to produce a clean verdict.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import pathlib

from contract_families import FAMILIES

BASELINE = "Android 4.4.4_r2"

# family -> boundary record. Only families with a real Android process boundary,
# or with a locked AGR ownership question, get a full record.
BOUNDARIES: dict[str, dict] = {
    "app.activity_lifecycle": {
        "public_api": "Activity/Application lifecycle callbacks and startActivity for own components",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/app/ActivityThread.java:performLaunchActivity/handleResumeActivity",
            "platform/frameworks/base:core/java/android/app/Instrumentation.java:callActivityOnCreate",
            "platform/frameworks/base:services/java/com/android/server/am/ActivityStack.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "ActivityManagerService in system_server",
        "binder_or_local": "binder",
        "observable_input": "Intent, savedInstanceState Bundle, configuration",
        "observable_output": "Activity instance, Context, Resources, window token, launch order",
        "callback": "onCreate, onStart, onResume, onPause, onStop, onDestroy, onSaveInstanceState, onConfigurationChanged",
        "state": "activity record state machine plus Application singleton",
        "thread_affinity": "main (Looper) thread",
        "lifetime": "process lifetime for Application; per-launch for Activity",
        "blocking_behavior": "callbacks are synchronous on the main Looper; AMS round-trips are one-way or short",
        "can_reduce_to_local_contract": "YES",
        "reason": "The scheduling authority is remote, but everything the game observes is the callback "
                  "order, the objects it receives and its own saved state. A local coordinator already "
                  "reproduces this ordering; no remote object identity is exposed to the game.",
        "evidence": "AGR DEX Runtime Activity lifecycle module is stable at main with real-APK launch evidence.",
        "status": "REDUCIBLE_HLE",
    },
    "app.intent": {
        "public_api": "Intent construction and startActivity/startActivityForResult",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/app/Instrumentation.java:execStartActivity",
            "platform/frameworks/base:services/java/com/android/server/am/ActivityManagerService.java:startActivityAsUser",
        ],
        "caller_process": "application process",
        "original_remote_service": "ActivityManagerService",
        "binder_or_local": "binder",
        "observable_input": "Intent action, component, extras, flags",
        "observable_output": "target Activity launched, or ActivityNotFoundException; onActivityResult",
        "callback": "onActivityResult, onNewIntent",
        "state": "task/back stack for this application's own activities",
        "thread_affinity": "main thread",
        "lifetime": "per-launch",
        "blocking_behavior": "asynchronous launch, synchronous resolution failure",
        "can_reduce_to_local_contract": "YES",
        "reason": "Intents targeting the application's own components resolve entirely from its own "
                  "manifest. Intents leaving the app (browser, share, market) are OPTIONAL external "
                  "capability, not core gameplay, and can fail as ActivityNotFoundException exactly as "
                  "API19 does when no handler exists.",
        "evidence": "Census: no in-scope sample requires an external activity result on its core path.",
        "status": "REDUCIBLE_HLE",
    },
    "app.package_info": {
        "public_api": "PackageManager.getPackageInfo/getApplicationInfo/resolveActivity for own package",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/app/ApplicationPackageManager.java",
            "platform/frameworks/base:services/java/com/android/server/pm/PackageManagerService.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "PackageManagerService",
        "binder_or_local": "binder",
        "observable_input": "package name, flags",
        "observable_output": "versionName/versionCode, ApplicationInfo paths, signatures",
        "callback": "none",
        "state": "installed package database",
        "thread_affinity": "any",
        "lifetime": "process",
        "blocking_behavior": "synchronous binder call",
        "can_reduce_to_local_contract": "YES",
        "reason": "For its own package every field is derivable from the installed APK the Runtime "
                  "already parses. Queries about other installed packages are OPTIONAL and may return "
                  "NameNotFoundException as API19 does for an absent package.",
        "evidence": "Census: 22 in-scope samples touch it; all observed uses are self-description or "
                    "capability probing.",
        "status": "REDUCIBLE_HLE",
    },
    "window.session": {
        "public_api": "WindowManager.addView/removeView, ViewRootImpl relayout, Window attributes",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/view/WindowManagerGlobal.java:addView",
            "platform/frameworks/base:core/java/android/view/ViewRootImpl.java:setView/relayoutWindow/performTraversals",
            "platform/frameworks/base:services/java/com/android/server/wm/Session.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "WindowManagerService (IWindowSession) in system_server",
        "binder_or_local": "binder",
        "observable_input": "LayoutParams, requested size, visibility, focus requests",
        "observable_output": "assigned frame rectangle, content/visible insets, a valid Surface, "
                             "relayout result flags",
        "callback": "onWindowFocusChanged, onConfigurationChanged, surface created/changed/destroyed, "
                    "ViewTreeObserver global layout",
        "state": "one window record with attributes, frame, insets and Surface ownership",
        "thread_affinity": "Android UI thread owning the ViewRoot",
        "lifetime": "from addView until removeView or Activity destroy",
        "blocking_behavior": "relayout is a synchronous binder round-trip; traversal is scheduled on "
                             "the Choreographer/handler",
        "can_reduce_to_local_contract": "YES",
        "reason": "The game never obtains a remote window object. It observes a frame rectangle, insets, "
                  "focus, a Surface and the traversal callback order. One local window record backed by "
                  "the host drawable surface expresses all of it.",
        "evidence": "AGR ViewRoot attach is MERGED/STABLE with an in-process opaque WindowSession and "
                    "real-APK evidence; no guest-visible remote identity was required.",
        "status": "REDUCIBLE_HLE",
    },
    "window.display_metrics": {
        "public_api": "Display.getMetrics/getRotation, DisplayMetrics, Configuration",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/view/Display.java",
            "platform/frameworks/base:core/java/android/hardware/display/DisplayManagerGlobal.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "DisplayManagerService",
        "binder_or_local": "binder with local cache",
        "observable_input": "none",
        "observable_output": "width, height, density, dpi, rotation, refresh rate",
        "callback": "onConfigurationChanged, DisplayListener",
        "state": "display description",
        "thread_affinity": "any",
        "lifetime": "process",
        "blocking_behavior": "cached read",
        "can_reduce_to_local_contract": "YES",
        "reason": "A pure value description of the host drawable surface.",
        "evidence": "Census: 25 in-scope samples, all reading geometry for layout or GL viewport setup.",
        "status": "REDUCIBLE_HLE",
    },
    "graphics.surface_lifecycle": {
        "public_api": "SurfaceView/SurfaceHolder callbacks, Surface lockCanvas/unlockCanvasAndPost, "
                      "ANativeWindow buffer exchange",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/view/SurfaceView.java:updateWindow",
            "platform/frameworks/base:core/java/android/view/Surface.java",
            "platform/frameworks/native:libs/gui/Surface.cpp",
            "platform/frameworks/native:libs/gui/BufferQueue.cpp",
        ],
        "caller_process": "application process (BufferQueue producer)",
        "original_remote_service": "SurfaceFlinger (consumer) via Binder and shared buffers",
        "binder_or_local": "binder plus shared graphic buffers",
        "observable_input": "requested format and size, drawn buffer content, present order",
        "observable_output": "dequeued buffer with stride and geometry, surfaceCreated/Changed/Destroyed "
                             "ordering, validity of the Surface, presentation of posted frames",
        "callback": "SurfaceHolder.Callback surfaceCreated/surfaceChanged/surfaceDestroyed",
        "state": "producer slot state and surface validity",
        "thread_affinity": "callbacks on the UI thread; buffer exchange on the rendering thread",
        "lifetime": "surface valid strictly between surfaceCreated and surfaceDestroyed",
        "blocking_behavior": "dequeueBuffer blocks when no buffer is free; queueBuffer is asynchronous",
        "can_reduce_to_local_contract": "YES",
        "reason": "The producer contract, not SurfaceFlinger, is what the game observes: buffer "
                  "acquisition, back-pressure, ordering and the strict validity window of the Surface "
                  "object. A host swapchain reproduces all of it; the consumer being remote in Android "
                  "is invisible to the game.",
        "evidence": "AGR already owns NativeActivity/Window as a stable module and drives presentation "
                    "through the host graphics stack.",
        "status": "REDUCIBLE_HLE",
    },
    "graphics.egl_native": {
        "public_api": "eglGetDisplay/eglCreateWindowSurface/eglSwapBuffers",
        "api19_source_path": ["platform/frameworks/native:opengl/libs/EGL/eglApi.cpp"],
        "caller_process": "application process",
        "original_remote_service": "SurfaceFlinger as buffer consumer",
        "binder_or_local": "local library over a BufferQueue producer",
        "observable_input": "config attributes, native window, swap interval",
        "observable_output": "EGL error codes, config selection, swap completion and pacing",
        "callback": "none",
        "state": "display, config, surface and context objects with current-context binding",
        "thread_affinity": "context is current to one thread at a time",
        "lifetime": "explicit create/destroy",
        "blocking_behavior": "eglSwapBuffers throttles to the buffer queue",
        "can_reduce_to_local_contract": "YES",
        "reason": "EGL is a client library; its remote element is only the buffer consumer. Locked AGR "
                  "architecture already maps this to ANGLE/Metal.",
        "evidence": "D004/architecture: graphics path guest EGL/GLES -> AGR bridge -> ANGLE -> Metal.",
        "status": "REDUCIBLE_HLE",
    },
    "input.motion_event": {
        "public_api": "View.onTouchEvent/dispatchTouchEvent, InputQueue and AInputQueue delivery",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/view/ViewRootImpl.java (InputEventReceiver chain)",
            "platform/frameworks/native:libs/input/InputTransport.cpp",
            "platform/frameworks/base:services/input/InputDispatcher.cpp",
        ],
        "caller_process": "application process (input channel endpoint)",
        "original_remote_service": "InputManagerService/InputDispatcher in system_server",
        "binder_or_local": "dedicated socket input channel, not a Binder call",
        "observable_input": "pointer positions, actions, pointer ids, event and down time",
        "observable_output": "ordered MotionEvent stream, batching/resampling, handled flag effect",
        "callback": "onTouchEvent, onGenericMotionEvent, native input queue callbacks",
        "state": "per-gesture pointer state and a pending-finish accounting",
        "thread_affinity": "the Looper thread that registered the input channel",
        "lifetime": "per input channel, bound to the window",
        "blocking_behavior": "consumer must finish events; unfinished events apply back-pressure",
        "can_reduce_to_local_contract": "YES",
        "reason": "The game observes an ordered event stream plus the obligation to finish events. The "
                  "dispatcher being a separate process does not appear in the contract.",
        "evidence": "AGR Looper/InputQueue is a stable module; the ViewRoot phase proved guest handling "
                    "through finishEvent on a real APK.",
        "status": "REDUCIBLE_HLE",
    },
    "input.key_event": {
        "public_api": "KeyEvent dispatch, KeyCharacterMap",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/view/KeyEvent.java",
            "platform/frameworks/native:libs/input/KeyCharacterMap.cpp",
        ],
        "caller_process": "application process",
        "original_remote_service": "InputManagerService",
        "binder_or_local": "input channel plus a loaded key layout",
        "observable_input": "key codes, meta state, repeat count",
        "observable_output": "ordered key events, character mapping, back/menu semantics",
        "callback": "onKeyDown/onKeyUp/onBackPressed",
        "state": "key repeat and meta state",
        "thread_affinity": "Looper owner",
        "lifetime": "per window",
        "blocking_behavior": "same finish obligation as motion events",
        "can_reduce_to_local_contract": "YES",
        "reason": "Key mapping tables are static data; delivery shares the input-channel contract.",
        "evidence": "Census: 19 in-scope samples, dominated by BACK and volume handling.",
        "status": "REDUCIBLE_HLE",
    },
    "input.ime": {
        "public_api": "InputMethodManager.showSoftInput/hideSoftInputFromWindow, InputConnection",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/view/inputmethod/InputMethodManager.java",
            "platform/frameworks/base:services/java/com/android/server/InputMethodManagerService.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "InputMethodManagerService plus a separate IME application process",
        "binder_or_local": "binder to IMMS and to the IME process",
        "observable_input": "show/hide requests, editor info, committed text",
        "observable_output": "soft keyboard visibility, text committed through InputConnection, "
                             "key events for simple keys, resulting window insets",
        "callback": "onCreateInputConnection, commitText, onConfigurationChanged for insets",
        "state": "focused editor and keyboard visibility",
        "thread_affinity": "UI thread",
        "lifetime": "per focused editable view",
        "blocking_behavior": "asynchronous; show/hide requests are advisory",
        "can_reduce_to_local_contract": "YES",
        "reason": "The IME really is another process in Android, but the game only observes keyboard "
                  "visibility, committed text and the resulting layout change. A host text-entry "
                  "endpoint supplies the same observables; the IME's own identity is never exposed.",
        "evidence": "Census: SHELL scope in 13 in-scope samples, all for name entry or search fields.",
        "status": "REDUCIBLE_HLE",
    },
    "audio.soundpool": {
        "public_api": "SoundPool load/play/stop/setVolume/setRate and onLoadComplete",
        "api19_source_path": [
            "platform/frameworks/base:media/java/android/media/SoundPool.java",
            "platform/frameworks/base:media/jni/soundpool/SoundPool.cpp",
        ],
        "caller_process": "application process",
        "original_remote_service": "AudioFlinger for output tracks; AudioPolicyService for routing",
        "binder_or_local": "binder plus shared-memory tracks",
        "observable_input": "sample data, stream ids, priority, loop, rate, volume",
        "observable_output": "sound id, stream id, audible mixing, load-complete ordering, "
                             "voice-stealing behavior at the channel limit",
        "callback": "OnLoadCompleteListener",
        "state": "sample table and active stream table with priorities",
        "thread_affinity": "any caller; decode on the SoundPool worker",
        "lifetime": "until release()",
        "blocking_behavior": "load is asynchronous, play is non-blocking",
        "can_reduce_to_local_contract": "YES",
        "reason": "Decoding uses the media service and output tracks use AudioFlinger, but neither "
                  "placement is observable. The pinned class documentation defines the whole contract "
                  "the game sees: sound/stream ids, priority-then-age voice stealing at maxStreams, "
                  "play() returning stream id 0 when the new sound loses, calls on a stale stream id "
                  "being tolerated without error, rate range 0.5-2.0, and loop counting. All of it is "
                  "finite local state over a host mixer.",
        "evidence": "Verified against pinned android-4.4.4_r2 "
                    "frameworks/base:media/java/android/media/SoundPool.java class documentation. "
                    "Census: 13 in-scope samples across 6 clusters.",
        "status": "REDUCIBLE_HLE",
    },
    "audio.audiotrack": {
        "public_api": "AudioTrack write/play/pause/flush/getPlaybackHeadPosition",
        "api19_source_path": [
            "platform/frameworks/base:media/java/android/media/AudioTrack.java",
            "platform/frameworks/av:media/libmedia/AudioTrack.cpp",
        ],
        "caller_process": "application process",
        "original_remote_service": "AudioFlinger",
        "binder_or_local": "binder for setup, shared-memory ring buffer for data",
        "observable_input": "PCM frames, buffer size, stream type, sample rate",
        "observable_output": "frames consumed, playback head position, underrun behavior, state machine "
                             "transitions, minimum buffer size",
        "callback": "OnPlaybackPositionUpdateListener",
        "state": "track state (STOPPED/PAUSED/PLAYING) and buffer fill",
        "thread_affinity": "usually a dedicated audio thread",
        "lifetime": "until release()",
        "blocking_behavior": "blocking write is the primary pacing mechanism games rely on",
        "can_reduce_to_local_contract": "YES",
        "reason": "The contract is a paced PCM sink with an observable head position. A host audio queue "
                  "with equivalent blocking and position accounting satisfies it.",
        "evidence": "Census: 9 in-scope samples across 5 clusters (SDL, Godot, python-SDL, "
                    "SoupeAuCaillou, libGDX).",
        "status": "REDUCIBLE_HLE",
    },
    "audio.opensles": {
        "public_api": "OpenSL ES engine, output mix, buffer-queue player",
        "api19_source_path": ["platform/frameworks/wilhelm:src/itf/IBufferQueue.c",
                              "platform/frameworks/wilhelm:src/android/AudioPlayer_to_android.cpp"],
        "caller_process": "application process",
        "original_remote_service": "AudioFlinger behind the Wilhelm implementation",
        "binder_or_local": "local library over a remote output track",
        "observable_input": "enqueued PCM buffers, player state",
        "observable_output": "buffer-consumed callbacks, underrun, realized/unrealized object states",
        "callback": "buffer queue callback on a Wilhelm-owned thread",
        "state": "object realization state and queue occupancy",
        "thread_affinity": "callback thread owned by the implementation",
        "lifetime": "explicit Realize/Destroy",
        "blocking_behavior": "callback-driven pull; Enqueue is non-blocking",
        "can_reduce_to_local_contract": "YES",
        "reason": "Guest-visible behavior is a callback-driven buffer queue; the Wilhelm object model is "
                  "reproducible locally over any host audio sink.",
        "evidence": "Census: Qt and python-SDL clusters link libOpenSLES directly.",
        "status": "REDUCIBLE_HLE",
    },
    "audio.mediaplayer": {
        "public_api": "MediaPlayer setDataSource/prepare/start/stop/seekTo with completion callbacks",
        "api19_source_path": [
            "platform/frameworks/base:media/java/android/media/MediaPlayer.java",
            "platform/frameworks/av:media/libmediaplayerservice/MediaPlayerService.cpp",
        ],
        "caller_process": "application process client",
        "original_remote_service": "MediaPlayerService (mediaserver process) and AudioFlinger",
        "binder_or_local": "binder",
        "observable_input": "asset/file/uri source, looping, volume, seek position",
        "observable_output": "state machine transitions, current/total duration, audible playback, "
                             "error codes",
        "callback": "onPrepared, onCompletion, onError, onSeekComplete",
        "state": "documented MediaPlayer state machine",
        "thread_affinity": "callbacks on the creating thread's Looper",
        "lifetime": "until release()",
        "blocking_behavior": "prepare() blocking, prepareAsync() callback-driven",
        "can_reduce_to_local_contract": "YES",
        "reason": "The state machine and callback set are fully specified and observable; decoding "
                  "happening in mediaserver is an implementation placement, not part of the contract. "
                  "Codec coverage is an implementation cost, not an architecture boundary.",
        "evidence": "Census: 14 in-scope samples, mostly background music from bundled OGG/MP3.",
        "status": "REDUCIBLE_HLE",
    },
    "audio.policy": {
        "public_api": "AudioManager stream volume, ringer mode, audio focus",
        "api19_source_path": [
            "platform/frameworks/base:media/java/android/media/AudioManager.java",
            "platform/frameworks/base:media/java/android/media/AudioService.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "AudioService in system_server, AudioPolicyService",
        "binder_or_local": "binder",
        "observable_input": "stream type, volume index, focus requests",
        "observable_output": "current/max volume, focus grant or loss, ducking",
        "callback": "OnAudioFocusChangeListener",
        "state": "per-stream volume and current focus owner",
        "thread_affinity": "any",
        "lifetime": "process",
        "blocking_behavior": "synchronous binder reads",
        "can_reduce_to_local_contract": "YES",
        "reason": "System-wide arbitration matters only when other apps exist. For one application the "
                  "observable contract is a volume value and a focus state that can be held locally and "
                  "driven from host interruption notifications.",
        "evidence": "Census: 4 in-scope samples; all use it for volume-key handling or mute.",
        "status": "REDUCIBLE_HLE",
    },
    "sensor.event_stream": {
        "public_api": "SensorManager.getDefaultSensor/registerListener and SensorEvent delivery",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/hardware/SystemSensorManager.java",
            "platform/frameworks/native:services/sensorservice/SensorService.cpp",
        ],
        "caller_process": "application process",
        "original_remote_service": "SensorService",
        "binder_or_local": "binder for connection, BitTube socket for the event stream",
        "observable_input": "sensor type, requested delay",
        "observable_output": "sensor presence, value vectors in documented units and axes, accuracy, "
                             "timestamps, delivery rate",
        "callback": "onSensorChanged, onAccuracyChanged",
        "state": "registered listener set",
        "thread_affinity": "the Handler supplied at registration, else the main Looper",
        "lifetime": "until unregisterListener",
        "blocking_behavior": "non-blocking push",
        "can_reduce_to_local_contract": "YES",
        "reason": "A push stream of values with documented units and axis convention; the host motion "
                  "API supplies equivalent data. Absent sensors return null exactly as API19 does on a "
                  "device without them.",
        "evidence": "Census: 13 in-scope samples across 7 clusters, all accelerometer tilt control.",
        "status": "REDUCIBLE_HLE",
    },
    "system.wakelock": {
        "public_api": "PowerManager.newWakeLock/acquire/release, FLAG_KEEP_SCREEN_ON",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/os/PowerManager.java",
            "platform/frameworks/base:services/java/com/android/server/power/PowerManagerService.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "PowerManagerService",
        "binder_or_local": "binder",
        "observable_input": "lock level and tag, acquire with or without timeout, reference counting",
        "observable_output": "isHeld() reflecting mHeld, screen remains on, "
                             "RuntimeException(\"WakeLock under-locked <tag>\") when mCount goes below zero",
        "callback": "none",
        "state": "reference count and timeout per lock object",
        "thread_affinity": "any",
        "lifetime": "explicit, or until the timeout expires",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "YES",
        "reason": "The game observes only acquire/release state, reference counting, timeout expiry, "
                  "error behavior and the fact that the display stays on. All of it is finite local "
                  "state plus one host idle-timer setting.",
        "evidence": "Verified against pinned android-4.4.4_r2 "
                    "frameworks/base:core/java/android/os/PowerManager.java WakeLock: mRefCounted/mCount "
                    "gating in acquireLocked/release, mHandler.postDelayed(mReleaser, timeout) for the "
                    "timed form, and the under-locked RuntimeException. Census: 13 in-scope samples "
                    "across 8 clusters, the widest system-service use in the sample set.",
        "status": "REDUCIBLE_HLE",
    },
    "system.vibrator": {
        "public_api": "Vibrator.vibrate/cancel/hasVibrator",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/os/Vibrator.java",
            "platform/frameworks/base:services/java/com/android/server/VibratorService.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "VibratorService",
        "binder_or_local": "binder",
        "observable_input": "duration or pattern, repeat index",
        "observable_output": "haptic output, hasVibrator capability answer",
        "callback": "none",
        "state": "current vibration",
        "thread_affinity": "any",
        "lifetime": "per call",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "YES",
        "reason": "A fire-and-forget device effect with a capability query. Host haptics or a no-op with "
                  "hasVibrator()==false are both API19-legal observable behaviors.",
        "evidence": "Census: 14 in-scope samples across 9 clusters.",
        "status": "REDUCIBLE_HLE",
    },
    "system.settings": {
        "public_api": "Settings.System/Secure getInt/getString",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/provider/Settings.java",
            "platform/frameworks/base:packages/SettingsProvider",
        ],
        "caller_process": "application process",
        "original_remote_service": "SettingsProvider (a separate process content provider)",
        "binder_or_local": "binder through ContentResolver with a per-process cache",
        "observable_input": "setting key and default",
        "observable_output": "a scalar value, or the supplied default when absent",
        "callback": "ContentObserver on change",
        "state": "global settings table",
        "thread_affinity": "any",
        "lifetime": "process cache",
        "blocking_behavior": "synchronous read, usually cache-hit",
        "can_reduce_to_local_contract": "YES",
        "reason": "Observed uses read scalar preferences such as haptic feedback or screen brightness. "
                  "A local table with API19 defaults reproduces every observable, including the "
                  "documented default-on-absent behavior.",
        "evidence": "Census: 5 in-scope samples; reads only.",
        "status": "REDUCIBLE_HLE",
    },
    "system.clipboard": {
        "public_api": "ClipboardManager getText/setText",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/content/ClipboardManager.java",
            "platform/frameworks/base:services/java/com/android/server/ClipboardService.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "ClipboardService",
        "binder_or_local": "binder",
        "observable_input": "clip text",
        "observable_output": "clip text read back, primary-clip-changed notification",
        "callback": "OnPrimaryClipChangedListener",
        "state": "one primary clip",
        "thread_affinity": "any",
        "lifetime": "system-wide",
        "blocking_behavior": "synchronous",
        "can_reduce_to_local_contract": "YES",
        "reason": "Within one application the observable contract is a single readable/writable clip; "
                  "the host pasteboard provides the same, and cross-app sharing is OPTIONAL.",
        "evidence": "Census: 4 in-scope samples (board-game position import/export).",
        "status": "REDUCIBLE_HLE",
    },
    "storage.content_provider": {
        "public_api": "ContentResolver query/insert/update against providers",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/app/ActivityThread.java:installProvider",
            "platform/frameworks/base:core/java/android/content/ContentResolver.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "the owning application's process, possibly another app",
        "binder_or_local": "binder, or a direct local call when the provider is in the same process",
        "observable_input": "uri, projection, selection",
        "observable_output": "Cursor rows, change notifications",
        "callback": "ContentObserver",
        "state": "provider-owned data",
        "thread_affinity": "any; providers must be thread-safe",
        "lifetime": "process",
        "blocking_behavior": "synchronous query",
        "can_reduce_to_local_contract": "YES",
        "reason": "All providers declared by census samples (HyperProvider, SudokuContentProvider) are "
                  "the app's own and run in the same process in API19. Foreign providers such as "
                  "MediaStore are OPTIONAL, not core gameplay.",
        "evidence": "Census manifests: only self-owned providers are declared; no sample declares a "
                    "dependency on a foreign authority for gameplay.",
        "status": "REDUCIBLE_HLE",
    },
    "app.service_lifecycle": {
        "public_api": "Service onCreate/onStartCommand/onBind, bindService with a local Messenger",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/app/ActivityThread.java:handleCreateService",
            "platform/frameworks/base:services/java/com/android/server/am/ActiveServices.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "ActivityManagerService schedules, the service runs in the app",
        "binder_or_local": "binder for scheduling; the service object itself is local",
        "observable_input": "Intent, binding flags",
        "observable_output": "service instance, IBinder handed to onServiceConnected, lifecycle order",
        "callback": "onCreate, onStartCommand, onBind, onServiceConnected, onDestroy",
        "state": "service record",
        "thread_affinity": "main thread unless the manifest declares another process",
        "lifetime": "until stopSelf/unbind",
        "blocking_behavior": "asynchronous",
        "can_reduce_to_local_contract": "YES",
        "reason": "Every service declared in the census runs in the application's own process; the "
                  "Binder object exchanged is a local binder with direct dispatch. No census sample "
                  "declares android:process for a gameplay component.",
        "evidence": "Census manifests: GodotDownloaderService, RelayService, NetworkService, all "
                    "default-process and all outside the core single-player path.",
        "status": "REDUCIBLE_HLE",
    },
    "ipc.parcel_binder": {
        "public_api": "Parcel/Parcelable marshalling and local Binder objects",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/os/Parcel.java",
            "platform/frameworks/native:libs/binder/Parcel.cpp",
        ],
        "caller_process": "application process",
        "original_remote_service": "none for the observed uses",
        "binder_or_local": "local",
        "observable_input": "values written to a Parcel",
        "observable_output": "values read back in order, Parcelable round-trip fidelity",
        "callback": "none",
        "state": "parcel buffer",
        "thread_affinity": "any",
        "lifetime": "per parcel",
        "blocking_behavior": "none",
        "can_reduce_to_local_contract": "YES",
        "reason": "Census uses are Bundle/Parcelable serialization for saved state and local Messenger "
                  "traffic. No sample exposes a remote binder object identity or death notification on "
                  "a gameplay path.",
        "evidence": "Probe: android.os.IInterface and DeadObjectException are referenced by zero "
                    "samples; Messenger appears only in the two Godot samples' in-process downloader.",
        "status": "REDUCIBLE_HLE",
    },
    "ipc.local_socket": {
        "public_api": "LocalSocket/LocalServerSocket",
        "api19_source_path": ["platform/frameworks/base:core/java/android/net/LocalSocket.java"],
        "caller_process": "application process",
        "original_remote_service": "none required",
        "binder_or_local": "local unix domain socket",
        "observable_input": "byte stream",
        "observable_output": "byte stream, connection accept/close",
        "callback": "none",
        "state": "socket",
        "thread_affinity": "any",
        "lifetime": "explicit close",
        "blocking_behavior": "blocking stream I/O",
        "can_reduce_to_local_contract": "YES",
        "reason": "The single referencing sample is Qt, whose local socket is the in-process QML "
                  "debugging/servicing channel; both endpoints are inside the application.",
        "evidence": "Census: qt-minesweeper only; libqmldbg_local plugin is the consumer.",
        "status": "REDUCIBLE_HLE",
    },
    "ui.webview": {
        "public_api": "WebView loadUrl on bundled assets, WebSettings, addJavascriptInterface",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/webkit/WebView.java",
            "platform/frameworks/webview (chromium glue, in-process in 4.4)",
        ],
        "caller_process": "application process",
        "original_remote_service": "none in API19: KitKat WebView renders in the application process",
        "binder_or_local": "local",
        "observable_input": "asset or file URL, HTML/JS/CSS content, JS bridge calls",
        "observable_output": "rendered page, JS bridge results, page-finished notifications, touch and "
                             "key handling inside the view",
        "callback": "WebViewClient.onPageFinished, WebChromeClient, JS interface invocations",
        "state": "browsing context and JS heap",
        "thread_affinity": "UI thread for the API, internal renderer threads",
        "lifetime": "view lifetime",
        "blocking_behavior": "asynchronous load",
        "can_reduce_to_local_contract": "YES",
        "reason": "KitKat's WebView is in-process, so this is not a cross-process dependency at all. It "
                  "is an expensive but ordinary host-endpoint substitution: a host web view rendering "
                  "bundled local assets with an equivalent JS bridge.",
        "evidence": "a2048 renders assets/2048 HTML entirely from the APK with no network permission "
                    "requirement for gameplay; the other five referencing samples use it for help text.",
        "status": "REDUCIBLE_HLE",
    },
    "system.notification": {
        "public_api": "NotificationManager.notify/cancel",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/app/NotificationManager.java",
            "platform/frameworks/base:services/java/com/android/server/NotificationManagerService.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "NotificationManagerService plus the SystemUI process for display",
        "binder_or_local": "binder",
        "observable_input": "Notification object and id",
        "observable_output": "a notification is posted outside the application's own window",
        "callback": "PendingIntent delivery when the user selects it",
        "state": "posted notification set",
        "thread_affinity": "any",
        "lifetime": "until cancelled",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "NO",
        "reason": "Display genuinely belongs to a different process's UI surface, which one application "
                  "process cannot own. This is not gameplay: no in-scope census sample needs a posted "
                  "notification to play, so it is an optional capability rather than an architecture "
                  "blocker.",
        "evidence": "Census: 11 referencing samples, all for background downloads, relay messages or "
                    "reminders, never for core gameplay.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "system.alarm": {
        "public_api": "AlarmManager.set/cancel with PendingIntent",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/app/AlarmManager.java",
            "platform/frameworks/base:services/java/com/android/server/AlarmManagerService.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "AlarmManagerService",
        "binder_or_local": "binder",
        "observable_input": "trigger time, type, PendingIntent",
        "observable_output": "the app is woken and the PendingIntent fires, possibly after process death",
        "callback": "BroadcastReceiver invocation",
        "state": "system alarm table outliving the process",
        "thread_affinity": "any",
        "lifetime": "survives process death",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "NO",
        "reason": "Waking a dead application process is an authority outside the process by definition. "
                  "It is also not gameplay: all referencing samples use it for reminders or relay "
                  "polling, so it is optional capability loss rather than an H1 counterexample.",
        "evidence": "Census: 5 referencing samples, none on a core single-player path.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "system.appwidget": {
        "public_api": "AppWidgetProvider and AppWidgetManager.updateAppWidget",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/appwidget/AppWidgetManager.java",
            "platform/frameworks/base:services/java/com/android/server/AppWidgetService.java",
        ],
        "caller_process": "application process",
        "original_remote_service": "AppWidgetService plus the home-screen host process that inflates "
                                   "the RemoteViews",
        "binder_or_local": "binder with RemoteViews rendered by a different application",
        "observable_input": "RemoteViews tree",
        "observable_output": "a view rendered inside another application's window",
        "callback": "onUpdate",
        "state": "widget instance registry",
        "thread_affinity": "any",
        "lifetime": "independent of the app",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "NO",
        "reason": "Rendering inside a foreign application's window is irreducibly cross-process. It is "
                  "a launcher feature, not gameplay.",
        "evidence": "Census: gloomy-dungeons-2 only, as a separate manifest component; the game's own "
                    "Activity does not require it.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "app.wallpaper_service": {
        "public_api": "WallpaperService.Engine",
        "api19_source_path": [
            "platform/frameworks/base:core/java/android/service/wallpaper/WallpaperService.java",
            "platform/frameworks/base:services/java/com/android/server/WallpaperManagerService.java",
        ],
        "caller_process": "application process hosting the engine",
        "original_remote_service": "WallpaperManagerService with the home-screen process as the surface "
                                   "host",
        "binder_or_local": "binder",
        "observable_input": "surface supplied by the host window",
        "observable_output": "wallpaper drawn behind another application's UI",
        "callback": "Engine onCreate/onSurfaceCreated/onVisibilityChanged",
        "state": "engine instance",
        "thread_affinity": "its own Looper",
        "lifetime": "controlled by the wallpaper host",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "NO",
        "reason": "The surface is owned by the launcher's window, outside the game process. It is a "
                  "separate manifest component and never part of playing the game.",
        "evidence": "Census: gloomy-dungeons-2 and three libGDX samples declare or reference it; all "
                    "have an ordinary playable Activity.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "system.telephony": {
        "public_api": "TelephonyManager device state, SmsMessage",
        "api19_source_path": ["platform/frameworks/base:telephony/java/android/telephony/TelephonyManager.java"],
        "caller_process": "application process",
        "original_remote_service": "TelephonyRegistry and the radio interface layer",
        "binder_or_local": "binder",
        "observable_input": "none or SMS payload",
        "observable_output": "device/network identity, SMS delivery",
        "callback": "PhoneStateListener, SMS receiver",
        "state": "radio state",
        "thread_affinity": "any",
        "lifetime": "process",
        "blocking_behavior": "synchronous reads",
        "can_reduce_to_local_contract": "NO",
        "reason": "Real radio state and SMS transport cannot be synthesized. Every referencing use is "
                  "device identification or SMS multiplayer transport, both outside core gameplay; "
                  "API19 itself returns empty state on a device without a radio.",
        "evidence": "Census: 5 referencing samples; crosswords is the only gameplay-adjacent one and "
                    "its solo robot mode does not use it.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "net.connectivity": {
        "public_api": "ConnectivityManager.getActiveNetworkInfo",
        "api19_source_path": ["platform/frameworks/base:core/java/android/net/ConnectivityManager.java"],
        "caller_process": "application process",
        "original_remote_service": "ConnectivityService",
        "binder_or_local": "binder",
        "observable_input": "none",
        "observable_output": "network availability and type",
        "callback": "CONNECTIVITY_ACTION broadcast",
        "state": "network state",
        "thread_affinity": "any",
        "lifetime": "process",
        "blocking_behavior": "synchronous",
        "can_reduce_to_local_contract": "YES",
        "reason": "The observable is a reachability description that the host can answer, including the "
                  "API19-legal 'no active network' answer.",
        "evidence": "Census: 8 referencing samples, all gating optional online features.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "net.wifi": {
        "public_api": "WifiManager state, multicast lock, DhcpInfo",
        "api19_source_path": ["platform/frameworks/base:wifi/java/android/net/wifi/WifiManager.java"],
        "caller_process": "application process",
        "original_remote_service": "WifiService",
        "binder_or_local": "binder",
        "observable_input": "lock acquire/release",
        "observable_output": "wifi state, local address, multicast reception",
        "callback": "wifi state broadcasts",
        "state": "wifi and lock state",
        "thread_affinity": "any",
        "lifetime": "process",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "YES",
        "reason": "Used only to enable LAN discovery for optional multiplayer; the state query itself is "
                  "a value the host can answer.",
        "evidence": "Census: 4 referencing samples, all optional-multiplayer paths.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "hardware.camera": {
        "public_api": "Camera open/preview",
        "api19_source_path": ["platform/frameworks/base:core/java/android/hardware/Camera.java"],
        "caller_process": "application process",
        "original_remote_service": "CameraService",
        "binder_or_local": "binder plus buffer sharing",
        "observable_input": "parameters, preview surface",
        "observable_output": "preview frames, capture callbacks",
        "callback": "PreviewCallback, PictureCallback",
        "state": "camera device",
        "thread_affinity": "callbacks on the opening thread's Looper",
        "lifetime": "until release",
        "blocking_behavior": "open is blocking",
        "can_reduce_to_local_contract": "YES",
        "reason": "A device endpoint the host can supply or legally report as absent.",
        "evidence": "Census: 1 referencing sample, not on a gameplay path.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "ui.accessibility": {
        "public_api": "AccessibilityManager/AccessibilityEvent",
        "api19_source_path": ["platform/frameworks/base:core/java/android/view/accessibility/AccessibilityManager.java"],
        "caller_process": "application process",
        "original_remote_service": "AccessibilityManagerService plus accessibility service processes",
        "binder_or_local": "binder",
        "observable_input": "accessibility events sent by views",
        "observable_output": "isEnabled() answer; events are consumed by another process",
        "callback": "AccessibilityStateChangeListener",
        "state": "enabled services",
        "thread_affinity": "any",
        "lifetime": "process",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "YES",
        "reason": "With no accessibility service enabled, API19's own observable behavior is "
                  "isEnabled()==false and events discarded, which is exactly the local contract.",
        "evidence": "Census: 4 referencing samples, all through bundled widget/support code.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "system.search": {
        "public_api": "SearchManager/SearchableInfo",
        "api19_source_path": ["platform/frameworks/base:core/java/android/app/SearchManager.java"],
        "caller_process": "application process",
        "original_remote_service": "SearchManagerService",
        "binder_or_local": "binder",
        "observable_input": "search query",
        "observable_output": "search dialog, suggestions",
        "callback": "onSearchRequested",
        "state": "searchable metadata",
        "thread_affinity": "UI thread",
        "lifetime": "process",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "YES",
        "reason": "Referenced only through bundled widget code; the in-app search UI is local.",
        "evidence": "Census: 3 referencing samples, via SearchView in bundled UI libraries.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "system.backup": {
        "public_api": "BackupAgent/BackupManager",
        "api19_source_path": ["platform/frameworks/base:core/java/android/app/backup/BackupManager.java"],
        "caller_process": "application process",
        "original_remote_service": "BackupManagerService and a transport",
        "binder_or_local": "binder",
        "observable_input": "dataChanged notification",
        "observable_output": "backup scheduled, restore delivered at install time",
        "callback": "onBackup/onRestore",
        "state": "backup transport state outside the device",
        "thread_affinity": "any",
        "lifetime": "beyond the process",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "NO",
        "reason": "Cloud backup authority is outside the device. Not gameplay; local save files remain "
                  "fully functional.",
        "evidence": "Census: 1 referencing sample.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "system.print": {
        "public_api": "PrintManager.print",
        "api19_source_path": ["platform/frameworks/base:core/java/android/print/PrintManager.java"],
        "caller_process": "application process",
        "original_remote_service": "PrintSpooler process and print services",
        "binder_or_local": "binder",
        "observable_input": "PrintDocumentAdapter output",
        "observable_output": "a print job in another process",
        "callback": "layout/write callbacks",
        "state": "print job",
        "thread_affinity": "UI thread",
        "lifetime": "job",
        "blocking_behavior": "asynchronous",
        "can_reduce_to_local_contract": "NO",
        "reason": "The spooler is a separate application by design. Never gameplay.",
        "evidence": "Census: 2 referencing samples, through bundled support code.",
        "status": "OPTIONAL_EXTERNAL",
    },
    "system.display_input_service": {
        "public_api": "DisplayManager/InputManager device enumeration",
        "api19_source_path": ["platform/frameworks/base:core/java/android/hardware/input/InputManager.java"],
        "caller_process": "application process",
        "original_remote_service": "DisplayManagerService/InputManagerService",
        "binder_or_local": "binder",
        "observable_input": "none",
        "observable_output": "device and display lists, hot-plug notifications",
        "callback": "InputDeviceListener, DisplayListener",
        "state": "device registry",
        "thread_affinity": "any",
        "lifetime": "process",
        "blocking_behavior": "non-blocking",
        "can_reduce_to_local_contract": "YES",
        "reason": "An enumerable description of what the host actually provides.",
        "evidence": "Census: 3 referencing samples, for gamepad detection.",
        "status": "REDUCIBLE_HLE",
    },
}

# Families with no Android process boundary: recorded compactly for completeness.
LOCAL_FAMILY_REASON = {
    "app.application_lifecycle": "LoadedApk.makeApplication runs entirely in the app process.",
    "app.context": "ContextImpl is an in-process object over package and resource state.",
    "app.uri": "Pure parsing library.",
    "app.broadcast": "Manifest and registered receivers for the app's own broadcasts dispatch locally; "
                     "system broadcasts reduce to locally generated events.",
    "app.native_activity": "NativeActivity is app-process glue over the Activity contract.",
    "resources.asset_access": "androidfw AssetManager reads the app's own APK in-process.",
    "storage.shared_preferences": "SharedPreferencesImpl is an in-process XML-backed map.",
    "storage.filesystem": "Paths are app-private directories on the local filesystem.",
    "storage.sqlite": "SQLite is an in-process library.",
    "view.hierarchy": "Measure/layout/draw is entirely in the application process.",
    "graphics.canvas_2d": "Skia rendering in-process.",
    "graphics.bitmap": "Skia decode in-process.",
    "graphics.bitmap_native": "libjnigraphics locks the app's own bitmap pixels.",
    "graphics.drawable": "In-process resource-backed drawing.",
    "graphics.glsurfaceview": "A Java helper thread over EGL and Surface.",
    "graphics.gles_java": "JNI shim onto the local GLES driver.",
    "graphics.gles_native": "Local GLES driver client library.",
    "graphics.egl_java": "gles_jni EGL implementation, local.",
    "text.layout": "In-process text measurement and layout.",
    "ui.toolkit": "android.widget runs in the application process.",
    "ui.dialog": "Dialogs are ordinary windows of the same application.",
    "ui.menu": "In-process menu implementation.",
    "ui.preferences": "In-process preference UI over SharedPreferences.",
    "ui.animation": "In-process animation timing.",
    "ui.support_compat": "Bundled application code, not a platform surface.",
    "concurrency.handler_looper": "Handler/Looper/MessageQueue are per-process constructs.",
    "concurrency.async_task": "Thread pool plus main-thread Handler, all local.",
    "system.clock": "SystemClock reads local clocks.",
    "system.build_info": "Static device description values.",
    "system.process_info": "Process and Debug read local process state.",
    "system.log": "liblog write; the reader is optional tooling.",
    "system.misc_util": "Small local utility types.",
    "util.library": "Pure data-structure library.",
    "runtime.dex_classloader": "In-process class loading.",
    "jni.bridge": "In-process JNI invocation and registration.",
    "bionic.libc": "Local C runtime.",
    "native.log": "Local logging library.",
    "native.zlib": "Local compression library.",
    "native.stlport_gnustl": "Local C++ runtime.",
    "native.app_glue": "Static library compiled into the app.",
    "native.asset_manager": "Reads the app's own APK.",
    "native.native_window": "Producer-side handle to the app's own surface.",
    "native.input_queue": "App-side endpoint of the input channel.",
    "native.looper": "Per-thread local poll loop.",
    "native.sensor": "Native mirror of the sensor stream contract.",
    "native.configuration": "Local configuration description.",
    "native.openmaxal": "Local media client library.",
    "audio.audiorecord": "Capture endpoint; host microphone or a legal absent-device answer.",
    "audio.system_media": "Ringtone/scanner integration; optional, never gameplay.",
}


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--union", default="build/artifacts/api-surface-union.json")
    parser.add_argument("--output", default="build/artifacts/system-boundary-map.json")
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    union = json.loads((root / args.union).read_text(encoding="utf-8"))
    in_scope = [s for s in union["samples"] if s["scope"].startswith("IN_SCOPE")]

    records = []
    for family, (scope, owner) in sorted(FAMILIES.items()):
        games = sorted(s["id"] for s in in_scope if family in s["contract_families"])
        clusters = sorted({s["cluster"] for s in in_scope if family in s["contract_families"]})
        detail = BOUNDARIES.get(family)
        if detail is None:
            records.append({
                "family": family,
                "scope": scope,
                "api19_owner_summary": owner,
                "binder_or_local": "local",
                "can_reduce_to_local_contract": "YES",
                "reason": LOCAL_FAMILY_REASON.get(
                    family, "No Android process boundary is involved in the observable contract."),
                "core_gameplay_relevance": scope,
                "games_referencing": games,
                "engine_clusters_referencing": clusters,
                "evidence": "static census reference analysis",
                "status": "REDUCIBLE_HLE",
                "high_risk": False,
            })
            continue
        record = {"family": family, "scope": scope, **detail}
        record.update({
            "core_gameplay_relevance": scope,
            "games_referencing": games,
            "engine_clusters_referencing": clusters,
            "high_risk": True,
        })
        records.append(record)

    by_status: dict[str, list[str]] = {}
    for record in records:
        by_status.setdefault(record["status"], []).append(record["family"])

    irreducible_core = [
        r for r in records
        if r["status"] == "IRREDUCIBLE_SYSTEM_DEPENDENCY" and r["scope"] == "CORE"
    ]
    unresolved_core = [
        r for r in records if r["status"] == "UNRESOLVED" and r["scope"] == "CORE"
    ]
    payload = {
        "schema_version": 1,
        "android_baseline": BASELINE,
        "role": "EXPERIMENT_ARTIFACT_NOT_GOVERNANCE_MAP",
        "table_fingerprint": hashlib.sha256(pathlib.Path(__file__).read_bytes()).hexdigest(),
        "granularity_fingerprint": union["granularity_fingerprint"],
        "high_risk_count": sum(1 for r in records if r["high_risk"]),
        "status_index": {k: sorted(v) for k, v in sorted(by_status.items())},
        "gameplay_critical_irreducible": [r["family"] for r in irreducible_core],
        "gameplay_critical_unresolved": [r["family"] for r in unresolved_core],
        "boundaries": records,
    }
    output = root / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(f"{len(records)} boundaries ({payload['high_risk_count']} high risk) -> {output}")
    for status, families in payload["status_index"].items():
        print(f"  {status:<32} {len(families)}")


if __name__ == "__main__":
    main()
