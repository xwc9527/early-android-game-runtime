#!/bin/bash
# Independent APK/ELF-only preparation on the existing Gloomy renderer workload.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
AUTO_LOAD="${AGR_OFFLINE_GLOOMY_AUTO:-0}"
[[ "$AUTO_LOAD" == 0 || "$AUTO_LOAD" == 1 ]] || { echo "invalid AUTO_LOAD" >&2; exit 2; }
SUFFIX=""
[[ "$AUTO_LOAD" == 1 ]] && SUFFIX="-auto-first"
EVIDENCE="$ROOT/build/offline-aot-gloomy-exports$SUFFIX"
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
    'apk_member':prior['so'],'load_bias_policy':'auto-first' if os.environ.get('AGR_OFFLINE_GLOOMY_AUTO')=='1' else prior['load_base'],
    'tested_commit':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),
    'tested_tree':subprocess.check_output(['git','rev-parse','HEAD^{tree}'],cwd=root,text=True).strip()
},indent=2)+'\n')
PY
LOAD_BIAS=0x02800000
[[ "$AUTO_LOAD" == 1 ]] && LOAD_BIAS=auto-first
"$PYTHON" "$ROOT/tools/aot-lab/translate_offline.py" \
  --elf "$EVIDENCE/input-armv7.so" --entry-policy exports --load-bias "$LOAD_BIAS" \
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
for mode in trace run; do
  rm -f "$ROOT/build/artifacts/aot-result.json" "$ROOT/build/artifacts/aot-hosts.txt" \
    "$ROOT/build/artifacts/aot-trace.txt" "$ROOT/build/artifacts/aot-checkpoints.txt" \
    "$ROOT/build/artifacts/aot-fallbacks.txt"
  set +e
  LAUNCH_MODE="$mode"
  [[ "$AUTO_LOAD" == 1 ]] && LAUNCH_MODE="auto-$mode"
  bash "$ROOT/tools/aot-lab/launch_aot.sh" "$LAUNCH_MODE"
  status=$?
  set -e
  prefix=interpreter
  [[ "$mode" == run ]] && prefix=aot
  printf '%s\n' "$status" > "$EVIDENCE/$prefix.exit"
  for name in aot-result.json aot-hosts.txt aot-trace.txt aot-checkpoints.txt aot-fallbacks.txt; do
    [[ ! -f "$ROOT/build/artifacts/$name" ]] || cp "$ROOT/build/artifacts/$name" "$EVIDENCE/$prefix-${name#aot-}"
  done
done
"$PYTHON" "$ROOT/tools/aot-lab/offline_gloomy_differential.py" "$EVIDENCE"
