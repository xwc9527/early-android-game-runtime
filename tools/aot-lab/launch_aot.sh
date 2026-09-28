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
rm -f "$DATA/Documents/aot-result.json" "$DATA/Documents/aot-stage-result.json" "$DATA/Documents/aot-prefix-result.json" "$DATA/Documents/aot-trace.txt" "$DATA/Documents/aot-hosts.txt" "$DATA/Documents/aot-checkpoints.txt" "$DATA/Documents/aot-fallbacks.txt" "$DATA/Documents/pvs-progress.json"
case "$MODE" in
  trace) ARG="--aot-trace" ;;
  run) ARG="--aot-run" ;;
  auto-trace) ARG="--aot-auto-trace" ;;
  auto-run) ARG="--aot-auto-run" ;;
  kungfoo-trace) ARG="--aot-kungfoo-trace" ;;
  kungfoo-run) ARG="--aot-kungfoo-run" ;;
  kungfoo-performance) ARG="--aot-kungfoo-performance" ;;
  kungfoo-fast-audit) ARG="--aot-kungfoo-fast-audit" ;;
  kungfoo-baseline) ARG="--aot-kungfoo-baseline" ;;
  kungfoo-oncreate-trace) ARG="--aot-kungfoo-oncreate-trace" ;;
  kungfoo-oncreate-run) ARG="--aot-kungfoo-oncreate-run" ;;
  kungfoo-oncreate-baseline) ARG="--aot-kungfoo-oncreate-baseline" ;;
  kungfoo-oncreate-fast-audit) ARG="--aot-kungfoo-oncreate-fast-audit" ;;
  kungfoo-oncreate-performance) ARG="--aot-kungfoo-oncreate-performance" ;;
  *) echo "unknown AOT launch mode: $MODE" >&2; exit 2 ;;
esac
RESULT_NAME=aot-result.json
[[ "$MODE" == kungfoo-* ]] && RESULT_NAME=aot-stage-result.json
xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator --args "$ARG"
for _ in $(seq 1 180); do
  [[ -s "$DATA/Documents/$RESULT_NAME" ]] && break
  sleep 1
done
for name in aot-result.json aot-stage-result.json aot-prefix-result.json aot-hosts.txt aot-trace.txt aot-checkpoints.txt aot-fallbacks.txt pvs-progress.json; do
  [[ -f "$DATA/Documents/$name" ]] && cp "$DATA/Documents/$name" "$ARTIFACTS/$name"
done
if [[ ! -s "$ARTIFACTS/$RESULT_NAME" ]]; then
  xcrun simctl spawn "$DEVICE" log show --last 15m --style compact \
    --predicate 'process == "AGRSimulator" OR process == "runningboardd"' \
    > "$ARTIFACTS/aot-simulator-log.txt" 2>&1 || true
  xcrun simctl spawn "$DEVICE" launchctl list > "$ARTIFACTS/aot-process-list.txt" 2>&1 || true
  printf 'AOT_RESULT_TIMEOUT\n' >&2
  [[ -s "$ARTIFACTS/pvs-progress.json" ]] && cat "$ARTIFACTS/pvs-progress.json" >&2
  exit 1
fi
python3 -c 'import json,sys; d=json.load(open(sys.argv[1])); print("aot-result", json.dumps(d)); raise SystemExit(0 if d.get("passed") else 1)' "$ARTIFACTS/$RESULT_NAME"
