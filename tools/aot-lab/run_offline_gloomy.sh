#!/bin/bash
# Independent APK/ELF-only preparation on the existing Gloomy renderer workload.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
AUTO_LOAD="${AGR_OFFLINE_GLOOMY_AUTO:-0}"
RELOCATABLE="${AGR_OFFLINE_GLOOMY_RELOCATABLE:-0}"
POLICY="${AGR_OFFLINE_ENTRY_POLICY:-exports}"
WARM="${AGR_OFFLINE_GLOOMY_WARM:-0}"
PREPARED_DIR="${AGR_OFFLINE_PREPARED_DIR:-}"
[[ "$AUTO_LOAD" == 0 || "$AUTO_LOAD" == 1 ]] || { echo "invalid AUTO_LOAD" >&2; exit 2; }
[[ "$RELOCATABLE" == 0 || "$RELOCATABLE" == 1 ]] || { echo "invalid RELOCATABLE" >&2; exit 2; }
[[ "$POLICY" == exports || "$POLICY" == all-exidx ]] || { echo "invalid POLICY" >&2; exit 2; }
[[ "$WARM" == 0 || "$WARM" == 1 ]] || { echo "invalid WARM" >&2; exit 2; }
SUFFIX=""
[[ "$AUTO_LOAD" == 1 ]] && SUFFIX="-auto-first"
[[ "$RELOCATABLE" == 1 ]] && SUFFIX="-relocatable"
[[ "$WARM" == 1 ]] && SUFFIX="$SUFFIX-warm"
[[ -n "$PREPARED_DIR" ]] && SUFFIX="$SUFFIX-prepared"
[[ "${AGR_GAME_COMPILER_ARM64:-0}" == 1 ]] && SUFFIX="$SUFFIX-game-compiler"
EVIDENCE="$ROOT/build/offline-aot-gloomy-$POLICY$SUFFIX"
mkdir -p "$EVIDENCE"
export AGR_SIMULATOR_PROFILE=gloomy
python3 -m venv "$ROOT/build/offline-aot-python"
PYTHON="$ROOT/build/offline-aot-python/bin/python"
"$PYTHON" -m pip install --disable-pip-version-check capstone==5.0.7 \
  > "$EVIDENCE/python-dependencies.log" 2>&1
"$PYTHON" -m pip freeze > "$EVIDENCE/python-dependencies.lock"
bash "$ROOT/scripts/build-and-run-simulator.sh" prepare
python3 - "$ROOT" "$EVIDENCE" <<'PY'
import hashlib,json,os,pathlib,shutil,subprocess,sys
root,evidence=map(pathlib.Path,sys.argv[1:])
prior=json.loads((root/'tools/aot-lab/evidence/gloomy-armv7-arm64-aot-poc/input-identity.json').read_text())
apk=root/'samples/gloomy-dungeons-2.apk'
native=root/'App/Resources/gloomy-librenderer.so'
assert hashlib.sha256(apk.read_bytes()).hexdigest()==prior['apk_sha256']
assert hashlib.sha256(native.read_bytes()).hexdigest()==prior['so_sha256']
shutil.copyfile(native,evidence/'input-armv7.so')
(evidence/'input-identity.json').write_text(json.dumps({
    'schema':'agr.offline-aot-input.v1','apk_sha256':prior['apk_sha256'],
    'native_sha256':prior['so_sha256'],'native_bytes':native.stat().st_size,
    'apk_member':prior['so'],'load_bias_policy':(
        'runtime formal linker result' if os.environ.get('AGR_OFFLINE_GLOOMY_RELOCATABLE')=='1' else
        'auto-first' if os.environ.get('AGR_OFFLINE_GLOOMY_AUTO')=='1' else prior['load_base']),
    'tested_commit':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),
    'tested_tree':subprocess.check_output(['git','rev-parse','HEAD^{tree}'],cwd=root,text=True).strip()
},indent=2)+'\n')
PY
LOAD_BIAS=0x02800000
[[ "$AUTO_LOAD" == 1 ]] && LOAD_BIAS=auto-first
TRANSLATION_FLAGS=()
if [[ "$RELOCATABLE" == 1 ]]; then
  LOAD_BIAS=runtime
  TRANSLATION_FLAGS+=(--relocatable)
fi
if [[ "${AGR_GAME_COMPILER_ARM64:-0}" == 1 ]]; then
  "$PYTHON" "$ROOT/tools/aot-lab/compile_game_arm64.py" \
    --elf "$EVIDENCE/input-armv7.so" \
    --asm "$ROOT/Runtime/AotLab/agr_compiled_blocks.S" \
    --table "$ROOT/Runtime/AotLab/aot_blocks.c" \
    --manifest "$EVIDENCE/translation-manifest.json" \
    > "$EVIDENCE/translation.log" 2>&1
  cp "$ROOT/Runtime/AotLab/agr_compiled_blocks.S" "$EVIDENCE/agr_compiled_blocks.S"
elif [[ -n "$PREPARED_DIR" ]]; then
  "$PYTHON" - "$ROOT" "$PREPARED_DIR" "$EVIDENCE" "$POLICY" <<'PY'
import hashlib,json,pathlib,shutil,sys
root,relative,evidence=pathlib.Path(sys.argv[1]),pathlib.Path(sys.argv[2]),pathlib.Path(sys.argv[3])
policy=sys.argv[4]
source=(root/relative).resolve()
manifest=json.loads((source/'translation-manifest.json').read_text())
native=(evidence/'input-armv7.so').read_bytes()
artifact=(source/'aot_blocks.c').read_bytes()
assert manifest['elf_sha256']==hashlib.sha256(native).hexdigest()
assert manifest['generated_c_sha256']==hashlib.sha256(artifact).hexdigest()
assert manifest['entry_policy']==policy and manifest['relocatable']
assert not manifest['execution_trace_input']
assert manifest['debug_entry_count']==0
shutil.copyfile(source/'translation-manifest.json',evidence/'translation-manifest.json')
shutil.copyfile(source/'aot_blocks.c',root/'Runtime/AotLab/aot_blocks.c')
(evidence/'prepared-artifact-identity.json').write_text(json.dumps({
    'source':str(relative),'elf_sha256':manifest['elf_sha256'],
    'generated_c_sha256':manifest['generated_c_sha256']},indent=2)+'\n')
(evidence/'translation.log').write_text('reused prebuilt APK preparation artifact\n')
PY
else
  "$PYTHON" "$ROOT/tools/aot-lab/translate_offline.py" \
    --elf "$EVIDENCE/input-armv7.so" --entry-policy "$POLICY" --load-bias "$LOAD_BIAS" \
    "${TRANSLATION_FLAGS[@]}" \
    --out "$ROOT/Runtime/AotLab/aot_blocks.c" \
    --manifest "$EVIDENCE/translation-manifest.json" \
    > "$EVIDENCE/translation.log" 2>&1
fi
cp "$ROOT/Runtime/AotLab/aot_blocks.c" "$EVIDENCE/aot_blocks.c"
bash "$ROOT/scripts/build-and-run-simulator.sh" deps
bash "$ROOT/scripts/build-and-run-simulator.sh" build
for name in ci-environment.json simulator-device.txt aot-compile-time.txt aot_blocks.o aot-object-sections.txt aot-asm-compile-time.txt agr_compiled_blocks.o aot-asm-object-sections.txt; do
  [[ ! -f "$ROOT/build/artifacts/$name" ]] || cp "$ROOT/build/artifacts/$name" "$EVIDENCE/$name"
done
cp "$ROOT/build/build-environment.json" "$EVIDENCE/build-environment.json"
PLACEMENTS=("$AUTO_LOAD")
[[ "$RELOCATABLE" == 1 ]] && PLACEMENTS=(0 1)
[[ "$WARM" == 1 ]] && PLACEMENTS=(1)
for placement in "${PLACEMENTS[@]}"; do
PAIR="$EVIDENCE"
if [[ "$RELOCATABLE" == 1 ]]; then
  PAIR="$EVIDENCE/fixed"
  [[ "$placement" == 1 ]] && PAIR="$EVIDENCE/first-fit"
  mkdir -p "$PAIR"
  for name in input-identity.json input-armv7.so translation-manifest.json aot_blocks.c agr_compiled_blocks.S; do
    [[ ! -f "$EVIDENCE/$name" ]] || cp "$EVIDENCE/$name" "$PAIR/$name"
  done
fi
run_one() {
  local mode="$1" prefix="$2" status name
  rm -f "$ROOT/build/artifacts/aot-result.json" "$ROOT/build/artifacts/aot-hosts.txt" \
    "$ROOT/build/artifacts/aot-trace.txt" "$ROOT/build/artifacts/aot-checkpoints.txt" \
    "$ROOT/build/artifacts/aot-fallbacks.txt"
  set +e
  local LAUNCH_MODE="$mode"
  [[ "$placement" == 1 ]] && LAUNCH_MODE="auto-$mode"
  bash "$ROOT/tools/aot-lab/launch_aot.sh" "$LAUNCH_MODE"
  status="$?"
  set -e
  printf '%s\n' "$status" > "$PAIR/$prefix.exit"
  for name in aot-result.json aot-hosts.txt aot-trace.txt aot-checkpoints.txt aot-fallbacks.txt; do
    [[ ! -f "$ROOT/build/artifacts/$name" ]] || cp "$ROOT/build/artifacts/$name" "$PAIR/$prefix-${name#aot-}"
  done
  [[ "$status" == 0 ]] || return "$status"
}
if [[ "$WARM" == 1 ]]; then
  for sample in 1 2 3 4 5; do
    run_one warm-baseline "baseline-performance-$sample"
    run_one warm-run "aot-performance-$sample"
  done
  "$PYTHON" "$ROOT/tools/aot-lab/offline_gloomy_warm_differential.py" "$PAIR"
else
  run_one trace interpreter
  run_one run aot
  "$PYTHON" "$ROOT/tools/aot-lab/offline_gloomy_differential.py" "$PAIR"
fi
done
