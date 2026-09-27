#!/usr/bin/env python3
"""Print one GitHub Actions error annotation from the proof log."""

from pathlib import Path

lines = Path("tools/aot-lab/evidence/gloomy-armv7-arm64-aot-poc/ci-log.txt").read_text(errors="replace").splitlines()
keys = ("error:", "Undefined symbols", "not found", "fatal error", "Traceback", "missing rust", "compiled main.m")
picked = [line.strip() for line in lines if "warning:" not in line and any(key in line for key in keys)]
message = " || ".join((picked or [line for line in lines if "warning:" not in line])[-8:])
print("::error::" + message[:900].replace("%", "%25"))
