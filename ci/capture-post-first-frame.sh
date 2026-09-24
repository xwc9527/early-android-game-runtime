#!/bin/bash
set -euo pipefail

DEVICE="$(cat build/artifacts/simulator-device.txt)"
ARTIFACTS=build/artifacts/post-first-frame
mkdir -p "$ARTIFACTS"
DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)"
DOCS="$DATA/Documents"

SIMCTL_CHILD_AGR_HOST_DISPLAY_WIDTH=1080 \
SIMCTL_CHILD_AGR_HOST_DISPLAY_HEIGHT=2340 \
  xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator \
  --args --post-first-frame-discovery

for _ in $(seq 1 32); do
  if [[ -s "$DOCS/agr-current-runtime.json" && -s "$DOCS/agr-current-manifest.json" ]]; then
    if python3 - "$DOCS/agr-current-runtime.json" <<'PY'
import json, sys
try:
    report = json.load(open(sys.argv[1], encoding="utf-8"))
    assert report.get("observation_mode") == "POST_FIRST_FRAME_ZERO_INPUT"
    assert report.get("stop_reason") in ("POST_FIRST_FRAME_DEADLINE", "RUNTIME_ERROR", "WATCHDOG_STALL")
except (OSError, ValueError, AssertionError, TypeError):
    sys.exit(1)
PY
    then break; fi
  fi
  sleep 1
done

test -s "$DOCS/agr-current-runtime.json"
for name in agr-current-manifest.json agr-current-run.json agr-current-trace.ndjson agr-current-runtime.json agr-current-crash.bin; do
  [[ -f "$DOCS/$name" ]] && cp "$DOCS/$name" "$ARTIFACTS/"
done
test -s "$ARTIFACTS/agr-current-manifest.json"
test -s "$ARTIFACTS/agr-current-run.json"
test -s "$ARTIFACTS/agr-current-trace.ndjson"
python3 ci/physical-runtime-evidence.py --dir "$ARTIFACTS" --source current \
  --summary "$ARTIFACTS/runtime-evidence.json" > /dev/null
python3 ci/classify-post-first-frame.py "$ARTIFACTS/agr-current-runtime.json" \
  --output "$ARTIFACTS/observation.json"
xcrun simctl io "$DEVICE" screenshot "$ARTIFACTS/simulator-screen.png"
