#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"; BUILD="$ROOT/build"; APP="$BUILD/AGRSimulator.app"
MODE="${1:-all}"
PROFILE="${2:-${AGR_SIMULATOR_PROFILE:-full}}"
phase() { printf 'AGR_SMOKE_PHASE %s %s\n' "$(date -u +%Y-%m-%dT%H:%M:%SZ)" "$*"; }
ARTIFACTS="$BUILD/artifacts"
mkdir -p "$ARTIFACTS"

if [[ "$MODE" == "prepare" || "$MODE" == "all" ]]; then
  phase "prepare sample profile $PROFILE"
  python3 "$ROOT/tools/fetch_fdroid_samples.py" --profile "$PROFILE"
  python3 "$ROOT/tools/scan_apks.py" --shard-index "${SHARD_INDEX:-0}" --shard-count "${SHARD_COUNT:-1}"
  python3 "$ROOT/Tests/DexLoom/make_activity_launch_fixture.py" "$ROOT/App/Resources/activity-launch-fixture.dex"
fi
[[ "$MODE" == "prepare" ]] && exit 0

if [[ "$MODE" == "deps" || "$MODE" == "all" ]]; then
  SDK="$(xcrun --sdk iphonesimulator --show-sdk-path)"
  TARGET="arm64-apple-ios15.0-simulator"
  mkdir -p "$BUILD/obj" "$APP"
ANGLE_VERSION="v2.1.28252"
ANGLE_SHA256="59e4b1f68956c92441cde4dca0e9eb1a835bbccd107cefdd1d3d3d60e27410be"
ANGLE_ARCHIVE="$BUILD/angle-xcframeworks-$ANGLE_VERSION.zip"
ANGLE_ROOT="$BUILD/angle-$ANGLE_VERSION"
ANGLE_CACHED_SHA=""
if [[ -s "$ANGLE_ARCHIVE" ]]; then ANGLE_CACHED_SHA="$(shasum -a 256 "$ANGLE_ARCHIVE" | awk '{print $1}')"; fi
if [[ "$ANGLE_CACHED_SHA" != "$ANGLE_SHA256" || ! -d "$ANGLE_ROOT/dist/EGL.xcframework" || ! -d "$ANGLE_ROOT/dist/GLESv2.xcframework" ]]; then
  rm -f "$ANGLE_ARCHIVE"; rm -rf "$ANGLE_ROOT"
  curl -L --fail --retry 3 -o "$ANGLE_ARCHIVE" \
    "https://github.com/EdgeFirstAI/angle-package/releases/download/$ANGLE_VERSION/angle-xcframeworks-$ANGLE_VERSION.zip"
  echo "$ANGLE_SHA256  $ANGLE_ARCHIVE" | shasum -a 256 -c -
  rm -rf "$ANGLE_ROOT"; mkdir -p "$ANGLE_ROOT"; unzip -q "$ANGLE_ARCHIVE" -d "$ANGLE_ROOT"
fi
rustup target add aarch64-apple-ios-sim
fi
[[ "$MODE" == "deps" ]] && exit 0

if [[ "$MODE" == "build" || "$MODE" == "all" ]]; then
  SDK="$(xcrun --sdk iphonesimulator --show-sdk-path)"
  TARGET="arm64-apple-ios15.0-simulator"
  ANGLE_ROOT="$BUILD/angle-v2.1.28252"
  test -d "$ANGLE_ROOT/dist/EGL.xcframework"
  rustup target list --installed | grep -qx aarch64-apple-ios-sim
  rm -rf "$APP"
  mkdir -p "$APP"
  ANGLE_DIST="$ANGLE_ROOT/dist"
  ANGLE_EGL="$ANGLE_DIST/EGL.xcframework/ios-arm64-simulator/libEGL.framework"
  ANGLE_GLES="$ANGLE_DIST/GLESv2.xcframework/ios-arm64-simulator/libGLESv2.framework"
  ANGLE_FRAMEWORKS="$BUILD/angle-frameworks"
  rm -rf "$ANGLE_FRAMEWORKS"; mkdir -p "$ANGLE_FRAMEWORKS"
  ditto "$ANGLE_EGL" "$ANGLE_FRAMEWORKS/libEGL.framework"
  ditto "$ANGLE_GLES" "$ANGLE_FRAMEWORKS/libGLESv2.framework"
phase "compile Runtime and host"
cargo build --manifest-path "$ROOT/Runtime/ArmInterpreter/Cargo.toml" --target aarch64-apple-ios-sim --release
COMMON=(-target "$TARGET" -isysroot "$SDK" -mios-simulator-version-min=15.0 -O2)
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/NativeCore" -c "$ROOT/Runtime/NativeCore/agr_runtime.c" -o "$BUILD/obj/agr_runtime.o"
clang++ "${COMMON[@]}" -std=c++17 -fno-exceptions -fno-rtti -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -c "$ROOT/Runtime/Bionic/agr_bionic_allocator.cpp" -o "$BUILD/obj/agr_bionic_allocator.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/Process" -c "$ROOT/Runtime/Process/agr_guest_vma.c" -o "$BUILD/obj/agr_guest_vma.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/HostServices" -c "$ROOT/Runtime/HostServices/agr_host_services_darwin.c" -o "$BUILD/obj/agr_host_services_darwin.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/Bionic" -c "$ROOT/Runtime/Bionic/agr_bionic_thread_attr.c" -o "$BUILD/obj/agr_bionic_thread_attr.o"
for SOURCE in agr_futex_host.cpp agr_bionic_sync.cpp agr_bionic_tls.cpp agr_bionic_errno_host.cpp agr_bionic_thread_lifecycle.cpp; do
  clang++ "${COMMON[@]}" -std=c++17 -fexceptions -fno-rtti -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/HostServices" -c "$ROOT/Runtime/Bionic/$SOURCE" -o "$BUILD/obj/${SOURCE%.cpp}.o"
done
clang++ "${COMMON[@]}" -std=gnu++98 -fno-exceptions -fno-rtti -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -c "$ROOT/Runtime/Bionic/agr_bionic_mmap.cpp" -o "$BUILD/obj/agr_bionic_mmap.o"
clang++ "${COMMON[@]}" -std=gnu++98 -fno-exceptions -fno-rtti -I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore" -c "$ROOT/Runtime/AospLinker/agr_aosp_linker.cpp" -o "$BUILD/obj/agr_aosp_linker.o"
clang++ "${COMMON[@]}" -std=gnu++98 -fno-exceptions -fno-rtti -I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore" -c "$ROOT/Runtime/AospLinker/agr_aosp_dynamic.cpp" -o "$BUILD/obj/agr_aosp_dynamic.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/NativeCore" -c "$ROOT/Tests/Conformance/agr_contracts.c" -o "$BUILD/obj/agr_contracts.o"
clang "${COMMON[@]}" -std=c11 -DGL_GLES_PROTOTYPES=1 -I"$ROOT/Vendor/ANGLE-Headers" -I"$ROOT/Runtime/NativeCore" -I"$ROOT/Runtime/GuestRuntime" -I"$ROOT/Runtime/Ehabi" -c "$ROOT/Runtime/GuestRuntime/agr_guest_runtime.c" -o "$BUILD/obj/agr_guest_runtime.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/GuestRuntime" -c "$ROOT/Runtime/GuestRuntime/agr_thread_context.c" -o "$BUILD/obj/agr_thread_context.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/Ehabi" -I"$ROOT/Runtime/GuestRuntime" -I"$ROOT/Runtime/NativeCore" -c "$ROOT/Runtime/Ehabi/agr_ehabi.c" -o "$BUILD/obj/agr_ehabi.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/GuestRuntime" -c "$ROOT/Runtime/GuestRuntime/agr_service_dispatch.c" -o "$BUILD/obj/agr_service_dispatch.o"
clang "${COMMON[@]}" -std=c11 -c "$ROOT/Runtime/GuestRuntime/agr_jni_methods.c" -o "$BUILD/obj/agr_jni_methods.o"

AOSP="$ROOT/Vendor/AOSP"; AFW="$ROOT/Runtime/AndroidFw"; BITMAP="$ROOT/Runtime/Bitmap"
AFW_INCLUDES=(-I"$AFW/compat/include" -I"$AFW" -I"$AOSP/frameworks-base/include" -I"$AOSP/frameworks-native/include" -I"$AOSP/system-core/include")
AFW_DEFINES=(-DSTATIC_ANDROIDFW_FOR_TOOLS -DLIBUTILS_NATIVE=1 -DHAVE_PTHREADS -DHAVE_POSIX_FILEMAP -DHAVE_SYS_UIO_H -DHAVE_LITTLE_ENDIAN -DHAVE_PRINTF_ZD=1 -D_FILE_OFFSET_BITS=64 -DOS_PATH_SEPARATOR=47 -DNOT_USING_KLIBC=1)
AFW_SOURCES=("$AFW/agr_androidfw.cpp" "$AFW/host_log.cpp" "$AFW/host_cxx_runtime.cpp"
 "$AOSP/frameworks-base/libs/androidfw/Asset.cpp" "$AOSP/frameworks-base/libs/androidfw/AssetDir.cpp" "$AOSP/frameworks-base/libs/androidfw/AssetManager.cpp" "$AOSP/frameworks-base/libs/androidfw/misc.cpp" "$AOSP/frameworks-base/libs/androidfw/ResourceTypes.cpp" "$AOSP/frameworks-base/libs/androidfw/StreamingZipInflater.cpp" "$AOSP/frameworks-base/libs/androidfw/ZipFileRO.cpp" "$AOSP/frameworks-base/libs/androidfw/ZipUtils.cpp"
 "$AOSP/system-core/libutils/FileMap.cpp" "$AOSP/system-core/libutils/RefBase.cpp" "$AOSP/system-core/libutils/SharedBuffer.cpp" "$AOSP/system-core/libutils/Static.cpp" "$AOSP/system-core/libutils/String8.cpp" "$AOSP/system-core/libutils/String16.cpp" "$AOSP/system-core/libutils/Unicode.cpp" "$AOSP/system-core/libutils/VectorImpl.cpp" "$AOSP/system-core/libutils/misc.cpp" "$AOSP/system-core/libutils/Threads.cpp" "$AOSP/system-core/libutils/Timers.cpp")
INDEX=0; AFW_OBJECTS=()
for SOURCE in "${AFW_SOURCES[@]}"; do OBJECT="$BUILD/obj/afw-$INDEX.o"; clang++ "${COMMON[@]}" -std=gnu++98 -nostdinc++ -fno-exceptions -fno-rtti "${AFW_DEFINES[@]}" "${AFW_INCLUDES[@]}" -include "$AFW/host_compat.h" -c "$SOURCE" -o "$OBJECT"; AFW_OBJECTS+=("$OBJECT"); INDEX=$((INDEX+1)); done
clang "${COMMON[@]}" -std=c11 -c "$AFW/host_atomic.c" -o "$BUILD/obj/atomic.o"; AFW_OBJECTS+=("$BUILD/obj/atomic.o")

SKIA="$AOSP/skia"; PNG="$AOSP/libpng"; ZLIB="$AOSP/zlib"
PNG_OBJECTS=()
for SOURCE in "$PNG"/*.c "$ZLIB"/*.c; do
  case "$(basename "$SOURCE")" in example.c|pngtest.c) continue;; esac
  OBJECT="$BUILD/obj/codec-$(basename "$SOURCE" .c).o"; clang "${COMMON[@]}" -w -UMACOS -I"$PNG" -I"$ZLIB" -c "$SOURCE" -o "$OBJECT"; PNG_OBJECTS+=("$OBJECT")
done
SKIA_INCLUDES=(-I"$BITMAP" -I"$SKIA/include/core" -I"$SKIA/include/images" -I"$SKIA/include/utils" -I"$SKIA/src/core" -I"$SKIA/src/image" -I"$SKIA/src/images" -I"$SKIA/src/utils" -I"$PNG" -I"$ZLIB")
SKIA_SOURCES=("$BITMAP/agr_bitmap.cpp" "$SKIA/src/core/Sk64.cpp" "$SKIA/src/core/SkBitmap.cpp" "$SKIA/src/core/SkColor.cpp" "$SKIA/src/core/SkColorTable.cpp" "$SKIA/src/core/SkDebug.cpp" "$SKIA/src/core/SkDither.cpp" "$SKIA/src/core/SkError.cpp" "$SKIA/src/core/SkFlattenable.cpp" "$SKIA/src/core/SkImageInfo.cpp" "$SKIA/src/core/SkMallocPixelRef.cpp" "$SKIA/src/core/SkMath.cpp" "$SKIA/src/core/SkPixelRef.cpp" "$SKIA/src/core/SkStream.cpp" "$SKIA/src/core/SkString.cpp" "$SKIA/src/core/SkTLS.cpp" "$SKIA/src/core/SkTSearch.cpp" "$SKIA/src/core/SkUnPreMultiply.cpp" "$SKIA/src/core/SkUtils.cpp" "$SKIA/src/images/SkImageDecoder.cpp" "$SKIA/src/images/SkImageDecoder_FactoryDefault.cpp" "$SKIA/src/images/SkImageDecoder_FactoryRegistrar.cpp" "$SKIA/src/images/SkImageDecoder_libpng.cpp" "$SKIA/src/images/SkImageEncoder.cpp" "$SKIA/src/images/SkImageEncoder_Factory.cpp" "$SKIA/src/images/SkScaledBitmapSampler.cpp" "$SKIA/src/ports/SkDebug_stdio.cpp" "$SKIA/src/ports/SkMemory_malloc.cpp" "$SKIA/src/ports/SkThread_pthread.cpp" "$SKIA/src/ports/SkTLS_pthread.cpp")
INDEX=0; SKIA_OBJECTS=()
for SOURCE in "${SKIA_SOURCES[@]}"; do OBJECT="$BUILD/obj/skia-$INDEX.o"; clang++ "${COMMON[@]}" -std=gnu++98 -nostdinc++ -I"$AFW/compat/include" -w -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -include "$BITMAP/host_skia_config.h" "${SKIA_INCLUDES[@]}" -c "$SOURCE" -o "$OBJECT"; SKIA_OBJECTS+=("$OBJECT"); INDEX=$((INDEX+1)); done
DEX="$ROOT/Runtime/DexLoom"; DEX_INCLUDE="$DEX/Include"
DEX_SOURCES=("$DEX/Base/dx_log.c" "$DEX/Base/dx_memory.c" "$DEX/Base/dx_arena.c" "$DEX/DEX/dx_dex.c" "$DEX/DEX/dx_opcode.c" "$DEX/DEX/dx_verifier.c" "$DEX/VM/dx_vm.c" "$DEX/VM/dx_interpreter.c" "$DEX/VM/dx_jni.c" "$DEX/VM/dx_verifier.c" "$DEX/APK/dx_apk.c" "$DEX/APK/dx_manifest.c" "$DEX/AndroidMini/framework_viewroot.c" "$DEX/poc_host.c" "$DEX/game_dex_runner.c")
INDEX=0; DEX_OBJECTS=()
for SOURCE in "${DEX_SOURCES[@]}"; do OBJECT="$BUILD/obj/dex-$INDEX.o"; clang "${COMMON[@]}" -std=gnu11 -DGL_GLES_PROTOTYPES=1 -I"$ROOT/Vendor/ANGLE-Headers" -I"$DEX_INCLUDE" -c "$SOURCE" -o "$OBJECT"; DEX_OBJECTS+=("$OBJECT"); INDEX=$((INDEX+1)); done
clang "${COMMON[@]}" -fobjc-arc -I"$ROOT/Vendor/ANGLE-Headers" -I"$ROOT/Runtime/NativeCore" -I"$ROOT/Runtime/GuestRuntime" -I"$DEX" -I"$DEX_INCLUDE" -I"$AFW" -I"$BITMAP" -c "$ROOT/App/main.m" -o "$BUILD/obj/main.o"
clang++ "${COMMON[@]}" -Wl,-dead_strip -Wl,-rpath,@executable_path/Frameworks -F"$ANGLE_FRAMEWORKS" "$BUILD/obj/main.o" "$BUILD/obj/agr_runtime.o" "$BUILD/obj/agr_bionic_allocator.o" "$BUILD/obj/agr_guest_vma.o" "$BUILD/obj/agr_host_services_darwin.o" "$BUILD/obj/agr_bionic_thread_attr.o" "$BUILD/obj/agr_futex_host.o" "$BUILD/obj/agr_bionic_sync.o" "$BUILD/obj/agr_bionic_tls.o" "$BUILD/obj/agr_bionic_errno_host.o" "$BUILD/obj/agr_bionic_thread_lifecycle.o" "$BUILD/obj/agr_bionic_mmap.o" "$BUILD/obj/agr_aosp_linker.o" "$BUILD/obj/agr_aosp_dynamic.o" "$BUILD/obj/agr_ehabi.o" "$BUILD/obj/agr_contracts.o" "$BUILD/obj/agr_guest_runtime.o" "$BUILD/obj/agr_thread_context.o" "$BUILD/obj/agr_service_dispatch.o" "$BUILD/obj/agr_jni_methods.o" "${DEX_OBJECTS[@]}" "${AFW_OBJECTS[@]}" "${SKIA_OBJECTS[@]}" "${PNG_OBJECTS[@]}" "$ROOT/Runtime/ArmInterpreter/target/aarch64-apple-ios-sim/release/libtouchhle_arm_interpreter.a" -lz -framework UIKit -framework Foundation -framework CoreGraphics -framework Security -framework Metal -framework QuartzCore -framework libEGL -framework libGLESv2 -o "$APP/AGRSimulator"
cp "$ROOT/App/Info.plist" "$APP/Info.plist"; cp "$ROOT/App/Resources/"* "$APP/"
cp "$ROOT/Tests/Trajectories/kungfoo-barracuda.json" "$APP/"
mkdir -p "$APP/Frameworks"; ditto "$ANGLE_FRAMEWORKS/libEGL.framework" "$APP/Frameworks/libEGL.framework"; ditto "$ANGLE_FRAMEWORKS/libGLESv2.framework" "$APP/Frameworks/libGLESv2.framework"
codesign --force --sign - "$APP/Frameworks/libEGL.framework"; codesign --force --sign - "$APP/Frameworks/libGLESv2.framework"; codesign --force --sign - "$APP"
phase "Runtime app linked and signed"
fi
[[ "$MODE" == "build" ]] && exit 0

if [[ "$MODE" == "boot" || "$MODE" == "all" ]]; then
DEVICE="$(xcrun simctl list devices available -j | python3 -c 'import json,sys; d=json.load(sys.stdin)["devices"]; print(next(x["udid"] for xs in d.values() for x in xs if x["name"]=="iPhone 16 Pro"))')"
printf '%s\n' "$DEVICE" > "$ARTIFACTS/simulator-device.txt"
phase "boot Simulator $DEVICE"
phase "simulator boot requested $DEVICE"
xcrun simctl boot "$DEVICE" 2>/dev/null || true; xcrun simctl bootstatus "$DEVICE" -b
phase "simulator boot ready $DEVICE"
elif [[ "$MODE" == "install" || "$MODE" == "run" ]]; then
  test -s "$ARTIFACTS/simulator-device.txt"
  DEVICE="$(cat "$ARTIFACTS/simulator-device.txt")"
fi
[[ "$MODE" == "boot" ]] && exit 0

if [[ "$MODE" == "install" || "$MODE" == "all" ]]; then
  phase "install Runtime app"
xcrun simctl install "$DEVICE" "$APP"
fi
[[ "$MODE" == "install" ]] && exit 0

if [[ "$MODE" != "run" && "$MODE" != "all" ]]; then
  echo "unknown Simulator stage: $MODE" >&2
  exit 2
fi
if [[ "${DEX_PARSER_COMPATIBILITY:-0}" == "1" ]]; then
  ARTIFACTS="$BUILD/artifacts"; mkdir -p "$ARTIFACTS"
  DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)"
  RESULT_PATH="$DATA/Documents/dex-parser-simulator.json"
  rm -f "$RESULT_PATH"
  phase "launch focused DEX parser compatibility probe"
  xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator --args --dex-parser-compatibility
  for _ in $(seq 1 60); do [[ -s "$RESULT_PATH" ]] && break; sleep 1; done
  if [[ ! -s "$RESULT_PATH" ]]; then
    echo "focused DEX parser result was not produced within 60 seconds" >&2
    xcrun simctl spawn "$DEVICE" log show --last 2m --style compact \
      --predicate 'process == "AGRSimulator"' > "$ARTIFACTS/dex-parser-simulator.log" 2>&1 || true
    exit 124
  fi
  cp "$RESULT_PATH" "$ARTIFACTS/dex-parser-simulator.json"
  cat "$RESULT_PATH"
  python3 - "$RESULT_PATH" <<'PY'
import json,sys
r=json.load(open(sys.argv[1]))
for item in r.get("results", []):
    level="notice" if item.get("stage") == "dex_loaded" else "error"
    compact=json.dumps(item,sort_keys=True,separators=(",",":"))
    print(f"::{level} title=Simulator DEX evidence::{compact}")
assert r.get("passed") is True, r
assert {x.get("id") for x in r.get("results", [])} == {"pixel-dungeon", "frozen-bubble"}, r
assert all(x.get("stage") == "dex_loaded" for x in r["results"]), r
PY
  phase "focused DEX parser compatibility probe passed"
  exit 0
fi
if [[ "${ACTIVITY_LAUNCH_COMPATIBILITY:-0}" == "1" ]]; then
  ARTIFACTS="$BUILD/artifacts"; mkdir -p "$ARTIFACTS"
  DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)"
  RESULT_PATH="$DATA/Documents/framework-activity-launch.json"
  rm -f "$RESULT_PATH"
  phase "launch focused Framework Activity compatibility probe"
  xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator --args --activity-launch-compatibility
  for _ in $(seq 1 90); do [[ -s "$RESULT_PATH" ]] && break; sleep 1; done
  if [[ ! -s "$RESULT_PATH" ]]; then
    xcrun simctl spawn "$DEVICE" log show --last 2m --style compact \
      --predicate 'process == "AGRSimulator"' > "$ARTIFACTS/framework-activity-launch.log" 2>&1 || true
    echo "focused Activity launch result was not produced within 90 seconds" >&2
    exit 124
  fi
  cp "$RESULT_PATH" "$ARTIFACTS/framework-activity-launch.json"
  cat "$RESULT_PATH"
  python3 - "$RESULT_PATH" <<'PY'
import json,sys
r=json.load(open(sys.argv[1]))
assert r.get("contract",{}).get("passed") is True, r
assert {x.get("id") for x in r.get("real_apks",[])} == {"pixel-dungeon","frozen-bubble"}, r
assert all(x.get("activity_launch_crossed") is True for x in r["real_apks"]), r
assert r.get("passed") is True, r
PY
  phase "focused Framework Activity launch compatibility passed"
  exit 0
fi
if [[ "${FRAMEWORK_VIEWROOT_ATTACH_DISCOVERY:-0}" == "1" ]]; then
  ARTIFACTS="$BUILD/artifacts"; mkdir -p "$ARTIFACTS"
  DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)"
  RESULT_PATH="$DATA/Documents/framework-viewroot-attach.json"
  rm -f "$RESULT_PATH"
  phase "launch Framework ViewRoot attach discovery probe"
  xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator --args --framework-viewroot-attach-discovery
  for _ in $(seq 1 90); do [[ -s "$RESULT_PATH" ]] && break; sleep 1; done
  xcrun simctl spawn "$DEVICE" log show --last 3m --style compact \
    --predicate 'process == "AGRSimulator"' > "$ARTIFACTS/framework-viewroot-attach.log" 2>&1 || true
  if [[ ! -s "$RESULT_PATH" ]]; then
    echo "Framework ViewRoot attach result was not produced within 90 seconds" >&2
    exit 124
  fi
  cp "$RESULT_PATH" "$ARTIFACTS/framework-viewroot-attach.json"
  cat "$RESULT_PATH"
  python3 - "$RESULT_PATH" <<'PY'
import json,sys
r=json.load(open(sys.argv[1]))
assert r.get("sample") == "frozen-bubble", r
assert r.get("launch_result") == 0, r
assert r.get("launch_stage") == "resumed", r
assert r.get("harness_retained_runtime") is True, r
assert r.get("observation_ms") == 2000, r
assert r.get("contract",{}).get("passed") is True, r
assert r.get("after_snapshot",{}).get("post_resume_completed") == 1, r
for key in ("window_attached","window_added","window_visible","idle_handler_scheduled","viewroot_handoff",
            "viewroot_created","viewroot_root_assigned","traversal_scheduled",
            "window_session_attached","view_parent_assigned","viewroot_attach_completed"):
    assert r.get("after_snapshot",{}).get(key) == 1, (key,r)
assert r.get("after_snapshot",{}).get("method_trace"), r
trace=r.get("after_snapshot",{}).get("framework_trace",[])
for item in ("window_manager.add_view.enter","window_manager_global.add_view","viewroot.create",
             "viewroot.set_view.enter","viewroot.root_assigned","viewroot.request_layout",
             "viewroot.traversal.scheduled","window_session.add_to_display",
             "viewroot.parent_assigned","viewroot.attach.complete","handoff.viewroot_traversal"):
    assert item in trace, (item,r)
assert [trace.index(x) for x in ("viewroot.traversal.scheduled","window_session.add_to_display",
                                "viewroot.parent_assigned","viewroot.attach.complete")] == sorted(
       trace.index(x) for x in ("viewroot.traversal.scheduled","window_session.add_to_display",
                                "viewroot.parent_assigned","viewroot.attach.complete")), r
assert trace[-1] == "handoff.viewroot_traversal", r
assert r.get("classification") == "viewroot_traversal_handoff", r
assert not r.get("after_snapshot",{}).get("pending_exception"), r
assert not r.get("after_snapshot",{}).get("error"), r
PY
  phase "Framework ViewRoot attach evidence captured"
  exit 0
fi
if [[ "${ARCHITECTURE_FALSIFICATION_DISCOVERY:-0}" == "1" ]]; then
  ARTIFACTS="$BUILD/artifacts"; mkdir -p "$ARTIFACTS"
  DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)"
  RESULT_PATH="$DATA/Documents/architecture-falsification-discovery.json"
  rm -f "$RESULT_PATH"
  phase "launch architecture falsification frontier probe"
  xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator \
    --args --architecture-falsification-discovery
  # Poll for completion rather than first bytes: the probe rewrites the file
  # after every sample so that a terminating sample still leaves evidence.
  COMPLETE=0
  for _ in $(seq 1 600); do
    if [[ -s "$RESULT_PATH" ]] && python3 -c 'import json,sys;sys.exit(0 if json.load(open(sys.argv[1])).get("complete") else 1)' "$RESULT_PATH" 2>/dev/null; then
      COMPLETE=1; break
    fi
    sleep 1
  done
  xcrun simctl spawn "$DEVICE" log show --last 15m --style compact \
    --predicate 'process == "AGRSimulator"' > "$ARTIFACTS/architecture-falsification-discovery.log" 2>&1 || true
  if [[ ! -s "$RESULT_PATH" ]]; then
    echo "architecture falsification probe produced no result within 600 seconds" >&2
    exit 124
  fi
  cp "$RESULT_PATH" "$ARTIFACTS/architecture-falsification-discovery.json"
  cp "$ROOT/samples/resolved.json" "$ARTIFACTS/falsification-resolved.json"
  python3 - "$RESULT_PATH" <<'PY'
import json,sys
r=json.load(open(sys.argv[1]))
print(json.dumps({k:v for k,v in r.items() if k!="results"}, indent=2))
for item in r["results"]:
    print(f"{item['id']:<22} {item['last_stage']:<22} {item['failure_signature'][:110]}")
PY
  if [[ "$COMPLETE" != "1" ]]; then
    echo "probe stopped before completing every planned sample; partial evidence retained" >&2
    exit 125
  fi
  phase "architecture falsification frontier evidence captured"
  exit 0
fi
if [[ "${FRAMEWORK_FIRST_TRAVERSAL_DISCOVERY:-0}" == "1" ]]; then
  ARTIFACTS="$BUILD/artifacts"; mkdir -p "$ARTIFACTS"
  DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)"
  RESULT_PATH="$DATA/Documents/framework-first-traversal.json"
  rm -f "$RESULT_PATH"
  phase "launch focused Framework first traversal probe"
  xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator --args --framework-first-traversal-discovery
  for _ in $(seq 1 90); do [[ -s "$RESULT_PATH" ]] && break; sleep 1; done
  xcrun simctl spawn "$DEVICE" log show --last 3m --style compact \
    --predicate 'process == "AGRSimulator"' > "$ARTIFACTS/framework-first-traversal.log" 2>&1 || true
  if [[ ! -s "$RESULT_PATH" ]]; then
    echo "Framework first traversal result was not produced within 90 seconds" >&2
    exit 124
  fi
  cp "$RESULT_PATH" "$ARTIFACTS/framework-first-traversal.json"
  python3 ci/framework-first-traversal-contract.py "$RESULT_PATH"
  phase "Framework first traversal evidence captured"
  exit 0
fi
if [[ "${ZERO_INPUT_AB:-0}" == "1" ]]; then
  ARTIFACTS="$BUILD/artifacts"; mkdir -p "$ARTIFACTS"
  DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)"
  rm -f "$DATA/Documents/runtime-status.json" "$DATA/Documents/runtime-failure.json" \
    "$DATA/Documents/debug-failure.json" "$DATA/Documents/manual-replay.json" \
    "$DATA/Documents/failure-frame.png"
  phase "launch interactive zero-input Runtime"
  xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator --args --interactive
  for _ in $(seq 1 60); do
    [[ -s "$DATA/Documents/runtime-failure.json" ]] && break
    [[ -s "$DATA/Documents/runtime-status.json" ]] && \
      python3 - "$DATA/Documents/runtime-status.json" <<'PY' && break || true
import json,sys
d=json.load(open(sys.argv[1]))
raise SystemExit(0 if d.get("frame",0) >= 1 and not d.get("failure_signature") else 1)
PY
    sleep 1
  done
  for name in runtime-status.json runtime-failure.json debug-failure.json manual-replay.json failure-frame.png kungfoo-frame.png; do
    [[ -s "$DATA/Documents/$name" ]] && cp "$DATA/Documents/$name" "$ARTIFACTS/$name"
  done
  xcrun simctl io "$DEVICE" screenshot "$ARTIFACTS/simulator-zero-input.png"
  shasum -a 256 "$ROOT/App/Resources/kungfoo.apk" "$APP/AGRSimulator" > "$ARTIFACTS/zero-input-hashes.txt"
  printf '%s\n' "$DEVICE" > "$ARTIFACTS/zero-input-device.txt"
  test -s "$ARTIFACTS/runtime-status.json"
  test ! -s "$ARTIFACTS/runtime-failure.json"
  python3 - "$ARTIFACTS/runtime-status.json" <<'PY'
import json,sys
d=json.load(open(sys.argv[1]))
assert d.get("frame",0)>=1 and not d.get("failure_signature"), d
PY
  cat "$ARTIFACTS/runtime-status.json"
  phase "zero-input Runtime status captured"
  exit 0
fi
if [[ "${INTERACTIVE:-0}" == "1" ]]; then
  open -a Simulator
  xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator --args --interactive
  mkdir -p "$BUILD/artifacts"; printf '%s\n' "$DEVICE" > "$BUILD/artifacts/interactive-device.txt"
  exit 0
fi
xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator
RESULT_PATH="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)/Documents/runtime-smoke.json"
for _ in $(seq 1 30); do [[ -f "$RESULT_PATH" ]] && break; sleep 1; done
cat "$RESULT_PATH"
python3 - "$RESULT_PATH" <<'PY'
import json,sys
r=json.load(open(sys.argv[1]))
assert r["passed"], r
PY
mkdir -p "$BUILD/artifacts"; cp "$RESULT_PATH" "$BUILD/artifacts/runtime-smoke.json"; xcrun simctl io "$DEVICE" screenshot "$BUILD/artifacts/simulator.png"
FRAME_PATH="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)/Documents/kungfoo-frame.png"
test -s "$FRAME_PATH"; cp "$FRAME_PATH" "$BUILD/artifacts/kungfoo-frame.png"
TRAJECTORY_FRAME_PATH="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)/Documents/kungfoo-trajectory-frame.png"
if [[ -s "$TRAJECTORY_FRAME_PATH" ]]; then cp "$TRAJECTORY_FRAME_PATH" "$BUILD/artifacts/kungfoo-trajectory-frame.png"; fi
for checkpoint in "$(dirname "$FRAME_PATH")"/kungfoo-trajectory-??.png; do
  [[ -s "$checkpoint" ]] && cp "$checkpoint" "$BUILD/artifacts/"
done
cp "$ROOT/samples/resolved.json" "$ROOT/samples/static-scan.json" "$BUILD/artifacts/"
python3 "$ROOT/tools/cluster_results.py" "$RESULT_PATH"
