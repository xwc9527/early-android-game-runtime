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

for name in ci-environment.json simulator-device.txt; do
  if [[ -f "$ROOT/build/artifacts/$name" ]]; then
    cp "$ROOT/build/artifacts/$name" "$EVIDENCE/$name"
  fi
done
for pair in aot-trace.txt:interpreter-trace.txt aot-hosts.txt:interpreter-hosts.txt aot-stage-result.json:interpreter-stage-result.json pvs-progress.json:interpreter-progress.json aot-simulator-log.txt:interpreter-simulator-log.txt aot-process-list.txt:interpreter-process-list.txt; do
  source_name="${pair%%:*}"; destination_name="${pair#*:}"
  if [[ -f "$ROOT/build/artifacts/$source_name" ]]; then
    cp "$ROOT/build/artifacts/$source_name" "$EVIDENCE/$destination_name"
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

if [[ "$probe_status" -eq 0 && -s "$EVIDENCE/interpreter-trace.txt" ]]; then
  set +e
  python3 "$ROOT/tools/aot-lab/translate.py" \
    --trace "$EVIDENCE/interpreter-trace.txt" \
    --partial-baseline-trace "$ROOT/tools/aot-lab/evidence/gloomy-armv7-arm64-aot-poc/interpreter-trace.txt" \
    --out "$EVIDENCE/aot_blocks.c" \
    --manifest "$EVIDENCE/translation-manifest.json" \
    > "$EVIDENCE/translation.log" 2>&1
  translate_status=$?
  set -e
  printf '%s\n' "$translate_status" > "$EVIDENCE/translation.exit"
  if [[ "$translate_status" -eq 0 ]]; then
    cmp "$EVIDENCE/aot_blocks.c" "$ROOT/Runtime/AotLab/aot_blocks.c"
    set +e
    bash "$ROOT/tools/aot-lab/launch_aot.sh" kungfoo-baseline
    baseline_status=$?
    set -e
    [[ -f "$ROOT/build/artifacts/aot-stage-result.json" ]] && cp "$ROOT/build/artifacts/aot-stage-result.json" "$EVIDENCE/baseline-stage-result.json"
    [[ -f "$ROOT/build/artifacts/aot-hosts.txt" ]] && cp "$ROOT/build/artifacts/aot-hosts.txt" "$EVIDENCE/baseline-hosts.txt"
    printf '%s\n' "$baseline_status" > "$EVIDENCE/baseline.exit"
    [[ "$baseline_status" -eq 0 ]] || exit "$baseline_status"
    set +e
    bash "$ROOT/tools/aot-lab/launch_aot.sh" kungfoo-run
    aot_status=$?
    set -e
    for name in aot-stage-result.json aot-hosts.txt aot-checkpoints.txt; do
      [[ -f "$ROOT/build/artifacts/$name" ]] && cp "$ROOT/build/artifacts/$name" "$EVIDENCE/$name"
    done
    [[ -f "$ROOT/build/artifacts/pvs-progress.json" ]] && cp "$ROOT/build/artifacts/pvs-progress.json" "$EVIDENCE/aot-progress.json"
    printf '%s\n' "$aot_status" > "$EVIDENCE/aot.exit"
    [[ "$aot_status" -eq 0 ]] || exit "$aot_status"
    python3 "$ROOT/tools/aot-lab/kungfoo_stage_differential.py" "$EVIDENCE"
    exit $?
  fi
  exit "$translate_status"
fi
if [[ "$probe_status" -eq 0 ]]; then
  echo "missing interpreter trace" >&2
  exit 1
fi
exit "$probe_status"
