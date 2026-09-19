#!/bin/bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
ARTIFACTS="$ROOT/build/artifacts"
DEVICE="$(cat "$ARTIFACTS/zero-input-device.txt")"
DATA="$(xcrun simctl get_app_container "$DEVICE" dev.agr.simulator data)"
RESULT="$DATA/Documents/runtime-smoke.json"

rm -f "$RESULT"
xcrun simctl launch --terminate-running-process "$DEVICE" dev.agr.simulator
for _ in $(seq 1 120); do
  [[ -s "$RESULT" ]] && break
  sleep 1
done
test -s "$RESULT"
cp "$RESULT" "$ARTIFACTS/runtime-smoke.json"
python3 - "$RESULT" <<'PY'
import json, sys
r = json.load(open(sys.argv[1]))
print(json.dumps(r, indent=2))
if not r["passed"]:
    failures=" | ".join(map(str,r.get("failures",[])))[:900]
    print(f"::error title=Simulator real-game regression::{failures}")
    evidence={
        "pvs1_closure":r.get("pvs1_closure",{}),
        "gameplay_outcome":r.get("gameplay_outcome"),
        "gameplay_failure":r.get("gameplay_failure"),
        "runtime_failure_signature":r.get("runtime_failure_signature"),
        "replay_events":r.get("replay_events"),
        "replay_consumed":r.get("replay_consumed"),
        "input_trace":r.get("nativeactivity_input_trace",[])[-64:],
    }
    print("PVS1_EVIDENCE "+json.dumps(evidence,separators=(",",":")))
assert r["passed"], r
PY
