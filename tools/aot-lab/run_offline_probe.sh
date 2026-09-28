#!/bin/bash
# Test whether ELF-only translation executes a path withheld from translation.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
POLICY="${AGR_OFFLINE_ENTRY_POLICY:-abi}"
EVIDENCE="$ROOT/build/offline-aot-$POLICY"
mkdir -p "$EVIDENCE"
export AGR_SIMULATOR_PROFILE=aot-kungfoo

bash "$ROOT/scripts/build-and-run-simulator.sh" prepare
python3 - "$ROOT" "$EVIDENCE" <<'PY'
import hashlib,json,pathlib,shutil,sys
root,evidence=map(pathlib.Path,sys.argv[1:])
native=root/'App/Resources/kungfoo-native.so'
identity=json.loads((root/'tools/aot-lab/evidence/kungfoo-armv7-reference/apk-native-identity.json').read_text())
actual=hashlib.sha256(native.read_bytes()).hexdigest()
assert actual==identity['armv7_sha256'], (actual,identity['armv7_sha256'])
shutil.copyfile(native,evidence/'input-armv7.so')
(evidence/'input-identity.json').write_text(json.dumps({
    'schema':'agr.offline-aot-input.v1','native_sha256':actual,
    'native_bytes':native.stat().st_size,'apk_sha256':identity['apk_sha256'],
    'apk_member':identity['armv7_member'],
    'tested_commit':__import__('subprocess').check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),
    'tested_tree':__import__('subprocess').check_output(['git','rev-parse','HEAD^{tree}'],cwd=root,text=True).strip()},indent=2)+'\n')
PY
python3 "$ROOT/tools/aot-lab/translate_offline.py" \
  --elf "$EVIDENCE/input-armv7.so" --entry-policy "$POLICY" --load-bias 0x10000 \
  --out "$ROOT/Runtime/AotLab/aot_blocks.c" \
  --manifest "$EVIDENCE/translation-manifest.json" \
  > "$EVIDENCE/translation.log" 2>&1
cp "$ROOT/Runtime/AotLab/aot_blocks.c" "$EVIDENCE/aot_blocks.c"
bash "$ROOT/scripts/build-and-run-simulator.sh" deps
bash "$ROOT/scripts/build-and-run-simulator.sh" build
for name in ci-environment.json simulator-device.txt aot-compile-time.txt aot_blocks.o aot-object-sections.txt; do
  [[ ! -f "$ROOT/build/artifacts/$name" ]] || cp "$ROOT/build/artifacts/$name" "$EVIDENCE/$name"
done
cp "$ROOT/build/build-environment.json" "$EVIDENCE/build-environment.json"

run_one() {
  local mode="$1" prefix="$2" status name
  rm -f "$ROOT/build/artifacts/aot-stage-result.json" "$ROOT/build/artifacts/aot-hosts.txt" \
    "$ROOT/build/artifacts/aot-trace.txt" "$ROOT/build/artifacts/aot-checkpoints.txt" \
    "$ROOT/build/artifacts/aot-fallbacks.txt"
  set +e
  bash "$ROOT/tools/aot-lab/launch_aot.sh" "$mode"
  status=$?
  set -e
  printf '%s\n' "$status" > "$EVIDENCE/$prefix.exit"
  for name in aot-stage-result.json aot-hosts.txt aot-trace.txt aot-checkpoints.txt aot-fallbacks.txt; do
    [[ ! -f "$ROOT/build/artifacts/$name" ]] || cp "$ROOT/build/artifacts/$name" "$EVIDENCE/$prefix-${name#aot-}"
  done
}

# The interpreter trace is captured only after the generated artifact is fixed.
run_one kungfoo-trace interpreter
run_one kungfoo-baseline baseline
run_one kungfoo-run diagnostic
run_one kungfoo-fast-audit fast-audit
for sample in 1 2 3; do
  run_one kungfoo-baseline "baseline-performance-$sample"
  run_one kungfoo-performance "performance-$sample"
done
python3 "$ROOT/tools/aot-lab/offline_differential.py" "$EVIDENCE"
