#!/bin/bash
# Test whether ELF-only translation executes a path withheld from translation.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
POLICY="${AGR_OFFLINE_ENTRY_POLICY:-abi}"
STAGE="${AGR_OFFLINE_STAGE:-loader}"
FAST_ONLY="${AGR_OFFLINE_NO_DIAGNOSTIC:-0}"
POLICY_COMPARE="${AGR_OFFLINE_POLICY_COMPARE:-0}"
RELOCATABLE="${AGR_OFFLINE_RELOCATABLE:-0}"
[[ "$STAGE" == loader || "$STAGE" == oncreate ]] || { echo "unknown stage: $STAGE" >&2; exit 2; }
[[ "$FAST_ONLY" == 0 || "$FAST_ONLY" == 1 ]] || { echo "invalid FAST_ONLY: $FAST_ONLY" >&2; exit 2; }
[[ "$RELOCATABLE" == 0 || "$RELOCATABLE" == 1 ]] || { echo "invalid RELOCATABLE: $RELOCATABLE" >&2; exit 2; }
SUFFIX=""
[[ "$FAST_ONLY" == 1 ]] && SUFFIX="-fast-only"
[[ "$RELOCATABLE" == 1 ]] && SUFFIX="$SUFFIX-relocatable"
[[ "${AGR_GAME_COMPILER_ARM64:-0}" == 1 ]] && SUFFIX="$SUFFIX-game-compiler"
[[ "${AGR_GAME_COMPILER_REGION:-0}" == 1 ]] && SUFFIX="$SUFFIX-region-compiler"
EVIDENCE="$ROOT/build/offline-aot-$POLICY-$STAGE$SUFFIX"
mkdir -p "$EVIDENCE"
export AGR_SIMULATOR_PROFILE=aot-kungfoo
python3 -m venv "$ROOT/build/offline-aot-python"
PYTHON="$ROOT/build/offline-aot-python/bin/python"
"$PYTHON" -m pip install --disable-pip-version-check capstone==5.0.7 \
  > "$EVIDENCE/python-dependencies.log" 2>&1
"$PYTHON" -m pip freeze > "$EVIDENCE/python-dependencies.lock"

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
TRANSLATION_FLAGS=()
[[ "$FAST_ONLY" == 1 ]] && TRANSLATION_FLAGS+=(--no-diagnostic)
[[ "${AGR_OFFLINE_DIRECT_LOOKUP:-0}" == 1 ]] && TRANSLATION_FLAGS+=(--direct-lookup)
LOAD_BIAS=0x10000
if [[ "$RELOCATABLE" == 1 ]]; then
  LOAD_BIAS=runtime
  TRANSLATION_FLAGS+=(--relocatable)
fi
if [[ "${AGR_GAME_COMPILER_REGION:-0}" == 1 ]]; then
  "$PYTHON" "$ROOT/tools/aot-lab/compile_game_regions.py" \
    --elf "$EVIDENCE/input-armv7.so" \
    --out "$ROOT/Runtime/AotLab/aot_blocks.c" \
    --manifest "$EVIDENCE/translation-manifest.json" \
    > "$EVIDENCE/translation.log" 2>&1
elif [[ "${AGR_GAME_COMPILER_ARM64:-0}" == 1 ]]; then
  "$PYTHON" "$ROOT/tools/aot-lab/compile_game_arm64.py" \
    --elf "$EVIDENCE/input-armv7.so" \
    --asm "$ROOT/Runtime/AotLab/agr_compiled_blocks.S" \
    --table "$ROOT/Runtime/AotLab/aot_blocks.c" \
    --manifest "$EVIDENCE/translation-manifest.json" \
    > "$EVIDENCE/translation.log" 2>&1
  cp "$ROOT/Runtime/AotLab/agr_compiled_blocks.S" "$EVIDENCE/agr_compiled_blocks.S"
else
  "$PYTHON" "$ROOT/tools/aot-lab/translate_offline.py" \
    --elf "$EVIDENCE/input-armv7.so" --entry-policy "$POLICY" --load-bias "$LOAD_BIAS" \
    "${TRANSLATION_FLAGS[@]}" \
    --out "$ROOT/Runtime/AotLab/aot_blocks.c" \
    --manifest "$EVIDENCE/translation-manifest.json" \
    > "$EVIDENCE/translation.log" 2>&1
fi
cp "$ROOT/Runtime/AotLab/aot_blocks.c" "$EVIDENCE/aot_blocks.c"
if [[ "$STAGE" == oncreate ]]; then
  PRIOR="$ROOT/tools/aot-lab/evidence/offline-generalization/run-36373038682"
  cp "$PRIOR/interpreter-trace.txt" "$EVIDENCE/prior-loader-interpreter-trace.txt"
  cp "$PRIOR/fast-audit-stage-result.json" "$EVIDENCE/prior-loader-fast-audit-stage-result.json"
  cp "$PRIOR/translation-manifest.json" "$EVIDENCE/prior-loader-translation-manifest.json"
fi
bash "$ROOT/scripts/build-and-run-simulator.sh" deps
bash "$ROOT/scripts/build-and-run-simulator.sh" build
for name in ci-environment.json simulator-device.txt aot-compiler-optimization.txt aot-compile-time.txt aot_blocks.o aot-object-sections.txt aot-asm-compile-time.txt agr_compiled_blocks.o aot-asm-object-sections.txt; do
  [[ ! -f "$ROOT/build/artifacts/$name" ]] || cp "$ROOT/build/artifacts/$name" "$EVIDENCE/$name"
done
cp "$ROOT/build/build-environment.json" "$EVIDENCE/build-environment.json"

run_one() {
  local mode="$1" prefix="$2" status name
  rm -f "$ROOT/build/artifacts/aot-stage-result.json" "$ROOT/build/artifacts/aot-hosts.txt" \
    "$ROOT/build/artifacts/aot-prefix-result.json" \
    "$ROOT/build/artifacts/aot-trace.txt" "$ROOT/build/artifacts/aot-checkpoints.txt" \
    "$ROOT/build/artifacts/aot-fallbacks.txt"
  set +e
  bash "$ROOT/tools/aot-lab/launch_aot.sh" "$mode"
  status=$?
  set -e
  printf '%s\n' "$status" > "$EVIDENCE/$prefix.exit"
  for name in aot-stage-result.json aot-prefix-result.json aot-hosts.txt aot-trace.txt aot-checkpoints.txt aot-fallbacks.txt; do
    [[ ! -f "$ROOT/build/artifacts/$name" ]] || cp "$ROOT/build/artifacts/$name" "$EVIDENCE/$prefix-${name#aot-}"
  done
  if [[ "$status" -ne 0 ]]; then
    echo "probe mode $mode failed with status $status; preserving current raw evidence" >&2
    return "$status"
  fi
}

# The interpreter trace is captured only after the generated artifact is fixed.
MODE_PREFIX=kungfoo
[[ "$STAGE" == oncreate ]] && MODE_PREFIX=kungfoo-oncreate
run_one "$MODE_PREFIX-trace" interpreter
run_one "$MODE_PREFIX-baseline" baseline
[[ "$FAST_ONLY" == 1 ]] || run_one "$MODE_PREFIX-run" diagnostic
run_one "$MODE_PREFIX-fast-audit" fast-audit
SAMPLES=3
[[ "$FAST_ONLY" == 1 ]] && SAMPLES=7
for sample in $(seq 1 "$SAMPLES"); do
  run_one "$MODE_PREFIX-baseline" "baseline-performance-$sample"
  run_one "$MODE_PREFIX-performance" "performance-$sample"
done
if [[ "$FAST_ONLY" == 1 ]]; then
  if [[ "$POLICY_COMPARE" == 1 ]]; then
    "$PYTHON" "$ROOT/tools/aot-lab/offline_policy_differential.py" "$EVIDENCE"
  else
    "$PYTHON" "$ROOT/tools/aot-lab/offline_fast_only_differential.py" "$EVIDENCE"
  fi
else
  "$PYTHON" "$ROOT/tools/aot-lab/offline_differential.py" "$EVIDENCE"
fi
