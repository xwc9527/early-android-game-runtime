#!/bin/bash
# Same fixture, runner, simulator and toolchain for interpreter/C/region replay.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
LABEL="$1"
EVIDENCE="$2"
CAPTURE="$3"
ELF="$4"
SPEC="$ROOT/tools/aot-lab/evidence/aot-performance-attribution/selected_regions.json"
PYTHON="$ROOT/build/offline-aot-python/bin/python"
SDK="$(xcrun --sdk iphonesimulator --show-sdk-path)"
TARGET=arm64-apple-ios15.0-simulator
RUST="$ROOT/Runtime/ArmInterpreter/target/aarch64-apple-ios-sim/release/libtouchhle_arm_interpreter.a"
DEVICE="$(tr -d '[:space:]' < "$ROOT/build/artifacts/simulator-device.txt")"
[[ -s "$RUST" && -s "$CAPTURE" && -s "$ELF" ]] || { echo "attribution replay prerequisite missing" >&2; exit 1; }
"$PYTHON" "$ROOT/tools/aot-lab/generate_attribution_header.py" \
  --selection "$SPEC" --label "$LABEL" --out "$EVIDENCE/attribution_segment.h"
"$PYTHON" "$ROOT/tools/aot-lab/verify_attribution_capture.py" \
  --selection "$SPEC" --label "$LABEL" --capture "$CAPTURE" \
  --out "$EVIDENCE/capture-verification.json"
COMMON=(-target "$TARGET" -isysroot "$SDK" -mios-simulator-version-min=15.0 -O2)
SOURCE="$ROOT/tools/aot-lab/attribution_replay.c"
clang "${COMMON[@]}" -std=c11 -I"$EVIDENCE" -I"$ROOT/Runtime/AotLab" \
  -c "$SOURCE" -o "$EVIDENCE/interpreter-replay.o"
clang++ "${COMMON[@]}" "$EVIDENCE/interpreter-replay.o" "$RUST" \
  -o "$EVIDENCE/interpreter-replay"

BASELINE="$EVIDENCE/generated-c"
mkdir -p "$BASELINE"
/usr/bin/time -p -o "$BASELINE/offline-preparation-time.txt" \
  "$PYTHON" "$ROOT/tools/aot-lab/translate_offline.py" \
    --elf "$ELF" --entry-policy all-exidx --load-bias runtime \
    --no-diagnostic --direct-lookup --relocatable \
    --out "$BASELINE/aot_blocks.c" \
    --manifest "$BASELINE/translation-manifest.json" \
    > "$BASELINE/translation.log"
/usr/bin/time -p -o "$BASELINE/native-compile-time.txt" \
  clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/AotLab" \
    -c "$BASELINE/aot_blocks.c" -o "$BASELINE/aot_blocks.o"
xcrun size -m "$BASELINE/aot_blocks.o" > "$BASELINE/object-sections.txt"
clang "${COMMON[@]}" -std=c11 -DAGR_ATTRIBUTION_COMPILED=1 \
  -I"$EVIDENCE" -I"$ROOT/Runtime/AotLab" \
  -c "$SOURCE" -o "$BASELINE/replay.o"
clang++ "${COMMON[@]}" "$BASELINE/replay.o" "$BASELINE/aot_blocks.o" "$RUST" \
  -o "$BASELINE/replay"

REGION="$EVIDENCE/indexed-region"
mkdir -p "$REGION"
cp "$EVIDENCE/translation-manifest.json" "$REGION/translation-manifest.json"
cp "$EVIDENCE/aot-compile-time.txt" "$REGION/native-compile-time.txt"
cp "$EVIDENCE/aot-object-sections.txt" "$REGION/object-sections.txt"
clang "${COMMON[@]}" -std=c11 -DAGR_ATTRIBUTION_COMPILED=1 \
  -DAGR_ATTRIBUTION_REGION=1 -I"$EVIDENCE" -I"$ROOT/Runtime/AotLab" \
  -c "$SOURCE" -o "$REGION/replay.o"
clang++ "${COMMON[@]}" "$REGION/replay.o" "$EVIDENCE/aot_blocks.o" "$RUST" \
  -o "$REGION/replay"

PAYLOAD="$EVIDENCE/guardless-region"
mkdir -p "$PAYLOAD"
/usr/bin/time -p -o "$PAYLOAD/offline-preparation-time.txt" \
  "$PYTHON" "$ROOT/tools/aot-lab/compile_attribution_payload.py" \
    --elf "$ELF" --selection "$SPEC" --label "$LABEL" \
    --out "$PAYLOAD/payload.c" --manifest "$PAYLOAD/translation-manifest.json" \
    > "$PAYLOAD/translation.log"
/usr/bin/time -p -o "$PAYLOAD/native-compile-time.txt" \
  clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/AotLab" \
    -c "$PAYLOAD/payload.c" -o "$PAYLOAD/payload.o"
xcrun size -m "$PAYLOAD/payload.o" > "$PAYLOAD/object-sections.txt"
clang "${COMMON[@]}" -std=c11 -DAGR_ATTRIBUTION_COMPILED=1 \
  -DAGR_ATTRIBUTION_PAYLOAD=1 -I"$EVIDENCE" -I"$ROOT/Runtime/AotLab" \
  -c "$SOURCE" -o "$PAYLOAD/replay.o"
clang++ "${COMMON[@]}" "$PAYLOAD/replay.o" "$PAYLOAD/payload.o" "$RUST" \
  -o "$PAYLOAD/replay"

SCALAR="$EVIDENCE/scalar-region"
mkdir -p "$SCALAR"
/usr/bin/time -p -o "$SCALAR/offline-preparation-time.txt" \
  "$PYTHON" "$ROOT/tools/aot-lab/compile_attribution_scalar.py" \
    --elf "$ELF" --selection "$SPEC" --label "$LABEL" \
    --out "$SCALAR/scalar.c" --manifest "$SCALAR/translation-manifest.json" \
    > "$SCALAR/translation.log"
/usr/bin/time -p -o "$SCALAR/native-compile-time.txt" \
  clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/AotLab" \
    -c "$SCALAR/scalar.c" -o "$SCALAR/scalar.o"
xcrun size -m "$SCALAR/scalar.o" > "$SCALAR/object-sections.txt"
clang "${COMMON[@]}" -std=c11 -DAGR_ATTRIBUTION_COMPILED=1 \
  -DAGR_ATTRIBUTION_SCALAR=1 -I"$EVIDENCE" -I"$ROOT/Runtime/AotLab" \
  -c "$SOURCE" -o "$SCALAR/replay.o"
clang++ "${COMMON[@]}" "$SCALAR/replay.o" "$SCALAR/scalar.o" "$RUST" \
  -o "$SCALAR/replay"

for mode in guard-only account-only guard-account guard-once; do
  PROBE="$EVIDENCE/$mode-region"
  mkdir -p "$PROBE"
  GENERATOR_FLAGS=()
  DEFINES=(-DAGR_ATTRIBUTION_COMPILED=1 -DAGR_ATTRIBUTION_PAYLOAD=1)
  if [[ "$mode" == guard-only || "$mode" == guard-account || "$mode" == guard-once ]]; then
    GENERATOR_FLAGS+=(--guard)
    DEFINES+=(-DAGR_ATTRIBUTION_GUARD=1)
  fi
  if [[ "$mode" == account-only || "$mode" == guard-account || "$mode" == guard-once ]]; then
    GENERATOR_FLAGS+=(--account)
    DEFINES+=(-DAGR_ATTRIBUTION_ACCOUNT=1)
  fi
  if [[ "$mode" == guard-once ]]; then
    GENERATOR_FLAGS+=(--guard-once)
    DEFINES+=(-DAGR_ATTRIBUTION_GUARD_ONCE=1)
  fi
  /usr/bin/time -p -o "$PROBE/offline-preparation-time.txt" \
    "$PYTHON" "$ROOT/tools/aot-lab/compile_attribution_payload.py" \
      --elf "$ELF" --selection "$SPEC" --label "$LABEL" \
      --out "$PROBE/payload.c" --manifest "$PROBE/translation-manifest.json" \
      "${GENERATOR_FLAGS[@]}" > "$PROBE/translation.log"
  /usr/bin/time -p -o "$PROBE/native-compile-time.txt" \
    clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/AotLab" \
      -c "$PROBE/payload.c" -o "$PROBE/payload.o"
  xcrun size -m "$PROBE/payload.o" > "$PROBE/object-sections.txt"
  clang "${COMMON[@]}" -std=c11 "${DEFINES[@]}" \
    -I"$EVIDENCE" -I"$ROOT/Runtime/AotLab" \
    -c "$SOURCE" -o "$PROBE/replay.o"
  clang++ "${COMMON[@]}" "$PROBE/replay.o" "$PROBE/payload.o" "$RUST" \
    -o "$PROBE/replay"
done

REPETITIONS=10000
[[ "$LABEL" == gloomy ]] && REPETITIONS=16384
for sample in 1 2 3 4 5; do
  for backend in interpreter-replay "$BASELINE/replay" "$REGION/replay" \
    "$PAYLOAD/replay" "$SCALAR/replay" \
    "$EVIDENCE/guard-only-region/replay" \
    "$EVIDENCE/account-only-region/replay" \
    "$EVIDENCE/guard-account-region/replay" \
    "$EVIDENCE/guard-once-region/replay"; do
    name="$(basename "$backend")"
    case "$backend" in
      interpreter-replay) out="$EVIDENCE/interpreter-$sample.json"; bin="$EVIDENCE/$backend" ;;
      "$BASELINE"/*) out="$BASELINE/sample-$sample.json"; bin="$backend" ;;
      "$PAYLOAD"/*) out="$PAYLOAD/sample-$sample.json"; bin="$backend" ;;
      "$SCALAR"/*) out="$SCALAR/sample-$sample.json"; bin="$backend" ;;
      "$EVIDENCE/guard-only-region"/*) out="$EVIDENCE/guard-only-region/sample-$sample.json"; bin="$backend" ;;
      "$EVIDENCE/account-only-region"/*) out="$EVIDENCE/account-only-region/sample-$sample.json"; bin="$backend" ;;
      "$EVIDENCE/guard-account-region"/*) out="$EVIDENCE/guard-account-region/sample-$sample.json"; bin="$backend" ;;
      "$EVIDENCE/guard-once-region"/*) out="$EVIDENCE/guard-once-region/sample-$sample.json"; bin="$backend" ;;
      *) out="$REGION/sample-$sample.json"; bin="$backend" ;;
    esac
    xcrun simctl spawn "$DEVICE" "$bin" "$CAPTURE" "$REPETITIONS" > "$out"
    cat "$out"
  done
done
"$PYTHON" "$ROOT/tools/aot-lab/check_attribution_replay.py" "$EVIDENCE"
