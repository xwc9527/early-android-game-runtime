#!/bin/bash
# Compile and run the production Bionic clock port for CLOCK_REALTIME and CLOCK_MONOTONIC.
# iPhoneOS is link-only. The iOS 27.0 Simulator executes agr_bionic_clock_gettime.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
ARTIFACTS="$ROOT/build/artifacts/bionic-clock-port"
mkdir -p "$ARTIFACTS"
cd "$ROOT"

{
  echo "BRANCH $(git rev-parse --abbrev-ref HEAD)"
  echo "HEAD $(git rev-parse HEAD)"
  echo "TREE $(git rev-parse 'HEAD^{tree}')"
  echo "SW_VERS $(sw_vers -productVersion)"
  echo "UNAME $(uname -m)"
  xcodebuild -version
  echo "IPHONEOS_SDK_VERSION $(xcrun --sdk iphoneos --show-sdk-version)"
  echo "IPHONEOS_SDK_PATH $(xcrun --sdk iphoneos --show-sdk-path)"
  echo "IPHONESIMULATOR_SDK_VERSION $(xcrun --sdk iphonesimulator --show-sdk-version)"
  echo "IPHONESIMULATOR_SDK_PATH $(xcrun --sdk iphonesimulator --show-sdk-path)"
} | tee "$ARTIFACTS/identity.txt"

XCODE_LINE="$(xcodebuild -version | head -n 1)"
IPHONEOS_SDK="$(xcrun --sdk iphoneos --show-sdk-version)"
SIM_SDK="$(xcrun --sdk iphonesimulator --show-sdk-version)"
if [[ "$XCODE_LINE" != "Xcode 27.0" || "$IPHONEOS_SDK" != "27.0" || "$SIM_SDK" != "27.0" ]]; then
  echo "ENVIRONMENT_BASELINE_MISMATCH Xcode=$XCODE_LINE iphoneos=$IPHONEOS_SDK simulator=$SIM_SDK" >&2
  exit 3
fi

HOST="$ROOT/Runtime/HostServices/agr_host_services_darwin.c"
CLOCK="$ROOT/Runtime/Bionic/agr_bionic_clock.c"
ERRNO="$ROOT/Runtime/Bionic/agr_bionic_errno_host.cpp"
PROBE="$ROOT/Tests/BionicClock/bionic_clock_port_probe.cpp"
IPHONEOS_BIN="$ARTIFACTS/bionic-clock-port-iphoneos"
SIM_BIN="$ARTIFACTS/bionic-clock-port-iphonesimulator"

xcrun --sdk iphoneos clang++ -target arm64-apple-ios15.0 -miphoneos-version-min=15.0 -O2 \
  -std=c++17 -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/HostServices" \
  "$PROBE" "$CLOCK" "$ERRNO" "$HOST" -o "$IPHONEOS_BIN"
echo "IPHONEOS_LINK rc=0" | tee "$ARTIFACTS/iphoneos-link.txt"
nm "$IPHONEOS_BIN" | grep agr_bionic_clock_gettime | tee -a "$ARTIFACTS/iphoneos-link.txt" || true

xcrun --sdk iphonesimulator clang++ -target arm64-apple-ios15.0-simulator -mios-simulator-version-min=15.0 -O2 \
  -std=c++17 -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/HostServices" \
  "$PROBE" "$CLOCK" "$ERRNO" "$HOST" -o "$SIM_BIN"
codesign --force --sign - "$SIM_BIN"
echo "IPHONESIMULATOR_LINK rc=0" | tee "$ARTIFACTS/simulator-link.txt"

python3 - "$ARTIFACTS/simulator-device.txt" <<'PY'
import json, subprocess, sys
runtime_id = "com.apple.CoreSimulator.SimRuntime.iOS-27-0"
product_version = "27.0"
def simctl(kind):
    return json.loads(subprocess.check_output(["xcrun", "simctl", "list", kind, "-j"], text=True))
runtimes = [item for item in simctl("runtimes").get("runtimes", [])
            if item.get("identifier") == runtime_id and item.get("version") == product_version
            and item.get("isAvailable")]
if not runtimes:
    raise SystemExit("exact iOS 27.0 Simulator runtime is unavailable")
iphones = [item for item in simctl("devicetypes").get("devicetypes", [])
           if item.get("identifier", "").startswith("com.apple.CoreSimulator.SimDeviceType.iPhone-")
           and item.get("isAvailable", True)]
if not iphones:
    raise SystemExit("no available iPhone Simulator device type")
iphones.sort(key=lambda item: ("iPhone 17" not in item.get("name", ""), item.get("name", "")))
device_type = iphones[0]
udid = subprocess.check_output(
    ["xcrun", "simctl", "create", "AGR Bionic Clock Port", device_type["identifier"], runtime_id],
    text=True).strip()
open(sys.argv[1], "w", encoding="utf-8").write(udid + "\n")
print(udid)
print(device_type["name"], device_type["identifier"], runtime_id)
PY

DEVICE="$(tr -d '[:space:]' < "$ARTIFACTS/simulator-device.txt")"
cleanup() {
  xcrun simctl shutdown "$DEVICE" >/dev/null 2>&1 || true
  xcrun simctl delete "$DEVICE" >/dev/null 2>&1 || true
}
trap cleanup EXIT
xcrun simctl boot "$DEVICE"
xcrun simctl bootstatus "$DEVICE" -b
set +e
xcrun simctl spawn "$DEVICE" "$SIM_BIN" | tee "$ARTIFACTS/simulator-probe.txt"
PROBE_RC="${PIPESTATUS[0]}"
set -e
echo "SIMULATOR_PROBE rc=$PROBE_RC" | tee "$ARTIFACTS/simulator-probe-rc.txt"
exit "$PROBE_RC"
