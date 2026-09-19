#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"; FIXTURES="${1:?usage: $0 FIXTURE_DIR}"
BUILD="$ROOT/build"; OBJ="$BUILD/obj"; APP="$BUILD/AGRPhase2BSimulator.app"
SDK="$(xcrun --sdk iphonesimulator --show-sdk-path)"; TARGET="arm64-apple-ios15.0-simulator"
COMMON=(-target "$TARGET" -isysroot "$SDK" -mios-simulator-version-min=15.0 -O2)
for file in libgnustl_shared.so libagr_eh2b_probe.so libagr_eh2b_types.so libagr_eh2b_suite.so; do test -s "$FIXTURES/$file"; done
clang "${COMMON[@]}" -fobjc-arc -I"$ROOT/Runtime/GuestRuntime" -c "$ROOT/Tests/Android44EhabiPhase2BGate/ios_guest_main.m" -o "$OBJ/agr_ehabi2b_ios_main.o"
rm -rf "$APP"; mkdir -p "$APP/Frameworks"
clang++ "${COMMON[@]}" -Wl,-dead_strip -Wl,-rpath,@executable_path/Frameworks -F"$BUILD/angle-frameworks" \
  "$OBJ/agr_ehabi2b_ios_main.o" "$OBJ/agr_runtime.o" "$OBJ/agr_guest_vma.o" "$OBJ/agr_host_services_darwin.o" \
  "$OBJ/agr_bionic_thread_attr.o" "$OBJ/agr_futex_host.o" "$OBJ/agr_bionic_sync.o" "$OBJ/agr_bionic_tls.o" \
  "$OBJ/agr_bionic_errno_host.o" "$OBJ/agr_bionic_thread_lifecycle.o" "$OBJ/agr_bionic_mmap.o" \
  "$OBJ/agr_aosp_linker.o" "$OBJ/agr_aosp_dynamic.o" "$OBJ/agr_ehabi.o" "$OBJ/agr_guest_runtime.o" \
  "$OBJ/agr_thread_context.o" "$OBJ/agr_service_dispatch.o" "$OBJ/agr_jni_methods.o" \
  "$OBJ"/dex-*.o "$OBJ"/afw-*.o "$OBJ"/skia-*.o "$OBJ"/codec-*.o "$OBJ/atomic.o" \
  "$ROOT/Runtime/ArmInterpreter/target/aarch64-apple-ios-sim/release/libtouchhle_arm_interpreter.a" \
  -lz -framework UIKit -framework Foundation -framework CoreGraphics -framework Security -framework Metal -framework QuartzCore -framework libEGL -framework libGLESv2 -lpthread -lm \
  -o "$APP/AGRPhase2BSimulator"
cat > "$APP/Info.plist" <<'PLIST'
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0"><dict><key>CFBundleExecutable</key><string>AGRPhase2BSimulator</string><key>CFBundleIdentifier</key><string>dev.agr.ehabi2b</string><key>CFBundleName</key><string>AGR EHABI2B</string><key>CFBundlePackageType</key><string>APPL</string><key>CFBundleShortVersionString</key><string>1</string><key>CFBundleVersion</key><string>1</string><key>LSRequiresIPhoneOS</key><true/><key>UILaunchScreen</key><dict/></dict></plist>
PLIST
cp "$FIXTURES"/*.so "$APP/"
ditto "$BUILD/angle-frameworks/libEGL.framework" "$APP/Frameworks/libEGL.framework"
ditto "$BUILD/angle-frameworks/libGLESv2.framework" "$APP/Frameworks/libGLESv2.framework"
codesign --force --sign - "$APP/Frameworks/libEGL.framework"; codesign --force --sign - "$APP/Frameworks/libGLESv2.framework"; codesign --force --sign - "$APP"
DEVICE="$(xcrun simctl list devices booted -j | python3 -c 'import json,sys;d=json.load(sys.stdin)["devices"];print(next(x["udid"] for xs in d.values() for x in xs))')"
xcrun simctl install "$DEVICE" "$APP"; DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.ehabi2b data)"
rm -f "$DATA/Documents/ehabi2b-guest.json" "$DATA/Documents/ehabi2b-guest-exit.txt"
xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.ehabi2b
for _ in $(seq 1 120); do [[ -s "$DATA/Documents/ehabi2b-guest-exit.txt" ]] && break; sleep 1; done
mkdir -p "$BUILD/artifacts"; cp "$DATA/Documents/ehabi2b-guest.json" "$BUILD/artifacts/"; cp "$DATA/Documents/ehabi2b-guest-exit.txt" "$BUILD/artifacts/"
test "$(tr -d '\r\n' < "$DATA/Documents/ehabi2b-guest-exit.txt")" = 0
python3 - "$BUILD/artifacts/ehabi2b-guest.json" <<'PY'
import json,sys
r=json.load(open(sys.argv[1])); print(json.dumps(r,sort_keys=True))
assert r['status']==0 and r['typed']==2 and r['inheritance']==21 and r['multiple']==33,r
assert r['pointer']==43 and r['rethrow']==54 and r['nested']==6199,r
assert r['lifetime_ref']==r['lifetime_value']==r['lifetime_rethrow']==0,r
assert r['threads']==1,r
assert r['thread_one']==r['thread_ret_one'] and r['thread_two']==r['thread_ret_two'],r
assert r['thread_id_one'] and r['thread_id_two'] and r['thread_id_one']!=r['thread_id_two'],r
assert r['globals_one'] and r['globals_two'] and r['globals_one']!=r['globals_two'],r
assert r['globals_one']==r['globals_after_one'] and r['globals_two']==r['globals_after_two'],r
for forbidden in ('__cxa_allocate_exception','__cxa_free_exception','__cxa_throw','__cxa_type_match','__cxa_begin_catch','__cxa_end_catch','__cxa_rethrow','__gxx_personality_v0','_Unwind_RaiseException','_Unwind_Resume'):
    assert forbidden not in r['imports'],(forbidden,r)
PY
