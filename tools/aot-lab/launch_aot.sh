#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
MODE="${1:-trace}"
ARTIFACTS="$ROOT/build/artifacts"
APP="$ROOT/build/AGRSimulator.app"
mkdir -p "$ARTIFACTS"
python3 "$ROOT/ci/select-simulator-runtime.py" "$ARTIFACTS/ci-environment.json" > "$ARTIFACTS/simulator-device.txt"
if grep -q '^CREATE$' "$ARTIFACTS/simulator-device.txt"; then
  RUNTIME_ID="$(python3 -c 'import json,sys; print(json.load(open(sys.argv[1]))["simulator_runtime_actual"])' "$ARTIFACTS/ci-environment.json")"
  DEVICE_TYPE="$(python3 -c 'import json,sys; print(json.load(open(sys.argv[1]))["simulator_device_type_actual"])' "$ARTIFACTS/ci-environment.json")"
  DEVICE_NAME="$(python3 -c 'import json,sys; print(json.load(open(sys.argv[1]))["simulator_device_type_name"])' "$ARTIFACTS/ci-environment.json")"
  DEVICE="$(xcrun simctl create "$DEVICE_NAME" "$DEVICE_TYPE" "$RUNTIME_ID")"
  printf '%s\n' "$DEVICE" > "$ARTIFACTS/simulator-device.txt"
else
  DEVICE="$(tr -d '[:space:]' < "$ARTIFACTS/simulator-device.txt")"
fi
xcrun simctl boot "$DEVICE" 2>/dev/null || true
xcrun simctl bootstatus "$DEVICE" -b
xcrun simctl install "$DEVICE" "$APP"
DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)"
rm -f "$DATA/Documents/aot-result.json" "$DATA/Documents/aot-trace.txt" "$DATA/Documents/aot-hosts.txt"
ARG="--aot-trace"
if [[ "$MODE" == "run" ]]; then ARG="--aot-run"; fi
xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator --args "$ARG"
for _ in $(seq 1 180); do
  [[ -s "$DATA/Documents/aot-result.json" ]] && break
  sleep 1
done
test -s "$DATA/Documents/aot-result.json"
cp "$DATA/Documents/aot-result.json" "$ARTIFACTS/aot-result.json"
[[ -f "$DATA/Documents/aot-hosts.txt" ]] && cp "$DATA/Documents/aot-hosts.txt" "$ARTIFACTS/aot-hosts.txt"
[[ -f "$DATA/Documents/aot-trace.txt" ]] && cp "$DATA/Documents/aot-trace.txt" "$ARTIFACTS/aot-trace.txt"
[[ -f "$DATA/Documents/aot-checkpoints.txt" ]] && cp "$DATA/Documents/aot-checkpoints.txt" "$ARTIFACTS/aot-checkpoints.txt"
python3 -c 'import json,sys; d=json.load(open(sys.argv[1])); print("error: aot-result", json.dumps(d)); raise SystemExit(0 if d.get("passed") else 1)' "$ARTIFACTS/aot-result.json"
