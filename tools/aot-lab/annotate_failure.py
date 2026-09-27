#!/usr/bin/env python3
"""Print one GitHub Actions error annotation from the proof log."""

from pathlib import Path

lines = Path("tools/aot-lab/evidence/gloomy-armv7-arm64-aot-poc/ci-log.txt").read_text(errors="replace").splitlines()
keys = ("error:", "undefined symbol", "fatal error", "ld:", "Traceback", "ANGLE", "missing rust", "AGR_SMOKE_PHASE")
picked = [line.strip() for line in lines if any(key in line for key in keys)]
message = " || ".join((picked or lines)[-12:])
print("::error::" + message[:1200].replace("%", "%25"))
