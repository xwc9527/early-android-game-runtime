#!/bin/bash
# Trace-guided ARMv7 to ARM64 AOT proof for the Gloomy renderer path.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
EVIDENCE="$ROOT/tools/aot-lab/evidence/gloomy-armv7-arm64-aot-poc"
mkdir -p "$EVIDENCE" "$ROOT/build/artifacts"
export AGR_SIMULATOR_PROFILE=gloomy

bash "$ROOT/scripts/build-and-run-simulator.sh" prepare
python3 - <<PY
import hashlib, pathlib
root = pathlib.Path(r"$ROOT")
so = root / "App/Resources/gloomy-librenderer.so"
apk = next((root / "samples").glob("gloomy-dungeons-2.apk"))
(pathlib.Path(r"$EVIDENCE") / "input-identity.json").write_text(
    '{"apk":"%s","apk_sha256":"%s","so":"lib/armeabi-v7a/librenderer.so","so_sha256":"%s","load_base":"0x02800000"}\n' % (
        apk.name, hashlib.sha256(apk.read_bytes()).hexdigest(), hashlib.sha256(so.read_bytes()).hexdigest()),
    encoding="utf-8")
PY

bash "$ROOT/scripts/build-and-run-simulator.sh" deps
bash "$ROOT/scripts/build-and-run-simulator.sh" build
set +e
bash "$ROOT/tools/aot-lab/launch_aot.sh" trace
trace_status=$?
set -e
cp "$ROOT/build/artifacts/aot-trace.txt" "$EVIDENCE/interpreter-trace.txt"
cp "$ROOT/build/artifacts/aot-hosts.txt" "$EVIDENCE/interpreter-hosts.txt"
cp "$ROOT/build/artifacts/aot-result.json" "$EVIDENCE/interpreter-result.json"
if [[ "$trace_status" -ne 0 ]]; then exit "$trace_status"; fi

python3 "$ROOT/tools/aot-lab/translate.py" \
  --trace "$EVIDENCE/interpreter-trace.txt" \
  --out "$ROOT/Runtime/AotLab/aot_blocks.c" \
  --manifest "$EVIDENCE/translation-manifest.json"
python3 "$ROOT/tools/aot-lab/no_jit_proof.py" "$ROOT/Runtime/AotLab/aot_blocks.c" "$EVIDENCE/no-jit.json"

bash "$ROOT/scripts/build-and-run-simulator.sh" build
set +e
bash "$ROOT/tools/aot-lab/launch_aot.sh" run
run_status=$?
set -e
cp "$ROOT/build/artifacts/aot-hosts.txt" "$EVIDENCE/aot-hosts.txt"
cp "$ROOT/build/artifacts/aot-result.json" "$EVIDENCE/aot-result.json"
if [[ -f "$ROOT/build/artifacts/aot-checkpoints.txt" ]]; then
  cp "$ROOT/build/artifacts/aot-checkpoints.txt" "$EVIDENCE/aot-checkpoints.txt"
else
  : > "$EVIDENCE/aot-checkpoints.txt"
fi
cp "$ROOT/Runtime/AotLab/aot_blocks.c" "$EVIDENCE/aot_blocks.c"
{
  echo "SIMULATOR_OBJECT"
  otool -hv "$ROOT/build/obj/aot_blocks.o"
  echo "SIMULATOR_SIGNATURE"
  codesign -dv "$ROOT/build/AGRSimulator.app" 2>&1
} | tee "$EVIDENCE/simulator-macho.txt"
bash "$ROOT/tools/aot-lab/link_iphoneos.sh" | tee "$EVIDENCE/iphoneos-link.txt"
python3 "$ROOT/tools/aot-lab/disposition.py" "$EVIDENCE"
