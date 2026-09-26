#!/bin/bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
FIXTURES="${1:?usage: test-ehabi-phase2-simulator.sh FIXTURE_DIR}"
BUILD="$ROOT/build"
APP="$BUILD/AGRPhase2ASimulator.app"
OBJ="$BUILD/obj"
SDK="$(xcrun --sdk iphonesimulator --show-sdk-path)"
TARGET="arm64-apple-ios15.0-simulator"
COMMON=(-target "$TARGET" -isysroot "$SDK" -mios-simulator-version-min=15.0 -O2)

for file in libgnustl_shared.so libagr_eh2_probe.so libagr_eh2_same.so \
            libagr_eh2_C.so libagr_eh2_B.so libagr_eh2_A.so; do
  test -s "$FIXTURES/$file"
done
test -s "$OBJ/agr_runtime.o"
test -s "$ROOT/Runtime/ArmInterpreter/target/aarch64-apple-ios-sim/release/libtouchhle_arm_interpreter.a"

clang "${COMMON[@]}" -std=c11 -DAGR_EHABI2_EMBEDDED=1 \
  -I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" \
  -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore" \
  -I"$ROOT/Runtime/HostServices" \
  -c "$ROOT/Tests/Android44EhabiPhase2Gate/agr_differential.c" \
  -o "$OBJ/agr_ehabi2_differential.o"
clang "${COMMON[@]}" -fobjc-arc \
  -c "$ROOT/Tests/Android44EhabiPhase2Gate/ios_main.m" \
  -o "$OBJ/agr_ehabi2_ios_main.o"

rm -rf "$APP"
mkdir -p "$APP"
clang++ "${COMMON[@]}" -Wl,-dead_strip \
  "$OBJ/agr_ehabi2_ios_main.o" "$OBJ/agr_ehabi2_differential.o" \
  "$OBJ/agr_runtime.o" "$OBJ/agr_bionic_allocator.o" "$OBJ/agr_guest_vma.o" "$OBJ/agr_host_services_darwin.o" \
  "$OBJ/agr_bionic_thread_attr.o" "$OBJ/agr_futex_host.o" "$OBJ/agr_bionic_sync.o" \
  "$OBJ/agr_bionic_tls.o" "$OBJ/agr_bionic_errno_host.o" "$OBJ/agr_bionic_clock.o" "$OBJ/agr_bionic_thread_lifecycle.o" \
  "$OBJ/agr_bionic_mmap.o" "$OBJ/agr_aosp_linker.o" "$OBJ/agr_aosp_dynamic.o" \
  "$OBJ/agr_thread_context.o" "$OBJ/agr_service_dispatch.o" \
  "$ROOT/Runtime/ArmInterpreter/target/aarch64-apple-ios-sim/release/libtouchhle_arm_interpreter.a" \
  -framework UIKit -framework Foundation -lpthread -lm \
  -o "$APP/AGRPhase2ASimulator"

cat > "$APP/Info.plist" <<'PLIST'
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0"><dict>
<key>CFBundleExecutable</key><string>AGRPhase2ASimulator</string>
<key>CFBundleIdentifier</key><string>dev.agr.ehabi2</string>
<key>CFBundleName</key><string>AGR EHABI2</string>
<key>CFBundlePackageType</key><string>APPL</string>
<key>CFBundleShortVersionString</key><string>1.0</string>
<key>CFBundleVersion</key><string>1</string>
<key>LSRequiresIPhoneOS</key><true/>
<key>UILaunchScreen</key><dict/>
</dict></plist>
PLIST
cp "$FIXTURES"/*.so "$APP/"
codesign --force --sign - "$APP"

DEVICE="$(xcrun simctl list devices booted -j | python3 -c 'import json,sys; d=json.load(sys.stdin)["devices"]; print(next(x["udid"] for xs in d.values() for x in xs))')"
xcrun simctl install "$DEVICE" "$APP"
DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.ehabi2 data)"
rm -f "$DATA/Documents/ehabi2-simulator.json" \
      "$DATA/Documents/ehabi2-stderr.log" \
      "$DATA/Documents/ehabi2-exit.txt"
xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.ehabi2
for _ in $(seq 1 180); do
  [[ -s "$DATA/Documents/ehabi2-exit.txt" ]] && break
  sleep 1
done
mkdir -p "$BUILD/artifacts"
for file in ehabi2-simulator.json ehabi2-stderr.log ehabi2-exit.txt; do
  [[ -f "$DATA/Documents/$file" ]] && cp "$DATA/Documents/$file" "$BUILD/artifacts/$file"
done
[[ -f "$BUILD/artifacts/ehabi2-stderr.log" ]] && cat "$BUILD/artifacts/ehabi2-stderr.log"
[[ -f "$BUILD/artifacts/ehabi2-exit.txt" ]] && cat "$BUILD/artifacts/ehabi2-exit.txt"
test -s "$DATA/Documents/ehabi2-exit.txt"
test "$(tr -d '\r\n' < "$DATA/Documents/ehabi2-exit.txt")" = 0
test -s "$DATA/Documents/ehabi2-simulator.json"
cp "$DATA/Documents/ehabi2-simulator.json" "$BUILD/artifacts/ehabi2-simulator.json"
python3 - "$BUILD/artifacts/ehabi2-simulator.json" <<'PY'
import json,sys
r=json.load(open(sys.argv[1]))
assert r['same']==[1,2] and r['cross']==[10,11,12,13],r
assert r['reload_cross']==[10,11,12,13],r
assert r['same_ok']==r['cross_ok']==r['reload_ok']==1,r
assert r['unload_stale']==0 and r['reload_owned']==1,r
assert r['exidx_mismatches']==0 and r['exidx'],r
symbols=[x['symbol'] for x in r['trace']]
assert 'cleanup_landing_pad' in symbols and 'handler_landing_pad' in symbols,symbols
print(json.dumps(r,sort_keys=True))
PY
