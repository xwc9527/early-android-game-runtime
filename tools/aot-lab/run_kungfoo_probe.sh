#!/bin/bash
# Capture the original KungFoo ARMv7 dlopen/constructor path inside AGR.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
EVIDENCE="$ROOT/build/kungfoo-aot-probe"
mkdir -p "$EVIDENCE"
export AGR_SIMULATOR_PROFILE=aot-kungfoo

bash "$ROOT/scripts/build-and-run-simulator.sh" prepare
bash "$ROOT/scripts/build-and-run-simulator.sh" deps
bash "$ROOT/scripts/build-and-run-simulator.sh" build

set +e
bash "$ROOT/tools/aot-lab/launch_aot.sh" kungfoo-trace
probe_status=$?
set -e

for name in aot-trace.txt aot-hosts.txt aot-result.json pvs-progress.json aot-simulator-log.txt aot-process-list.txt ci-environment.json simulator-device.txt; do
  if [[ -f "$ROOT/build/artifacts/$name" ]]; then
    cp "$ROOT/build/artifacts/$name" "$EVIDENCE/$name"
  fi
done
cp "$ROOT/build/build-environment.json" "$EVIDENCE/build-environment.json"
python3 - "$ROOT" "$EVIDENCE" "$probe_status" <<'PY'
import hashlib, json, pathlib, sys
root, evidence, status = pathlib.Path(sys.argv[1]), pathlib.Path(sys.argv[2]), int(sys.argv[3])
apk = root / "samples/kungfoo-barracuda.apk"
record = {"schema_version": 1, "workload": "kungfoo-armv7-native-dlopen-to-gameplay",
          "probe_exit_status": status,
          "apk_sha256": hashlib.sha256(apk.read_bytes()).hexdigest(),
          "tested_commit": __import__("subprocess").check_output(["git", "rev-parse", "HEAD"], cwd=root, text=True).strip(),
          "tested_tree": __import__("subprocess").check_output(["git", "rev-parse", "HEAD^{tree}"], cwd=root, text=True).strip()}
(evidence / "input-identity.json").write_text(json.dumps(record, indent=2) + "\n")
PY

if [[ -s "$EVIDENCE/aot-trace.txt" ]]; then
  set +e
  python3 "$ROOT/tools/aot-lab/translate.py" \
    --trace "$EVIDENCE/aot-trace.txt" \
    --out "$ROOT/build/kungfoo-aot-blocks.c" \
    --manifest "$EVIDENCE/translation-manifest.json" \
    > "$EVIDENCE/translation.log" 2>&1
  translate_status=$?
  set -e
  printf '%s\n' "$translate_status" > "$EVIDENCE/translation.exit"
  if [[ "$translate_status" -eq 0 ]]; then
    cp "$ROOT/build/kungfoo-aot-blocks.c" "$EVIDENCE/aot_blocks.c"
  fi
fi
exit "$probe_status"
