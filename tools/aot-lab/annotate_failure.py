#!/usr/bin/env python3
"""Print one GitHub Actions error annotation from the proof log."""

from pathlib import Path

lines = Path("tools/aot-lab/evidence/gloomy-armv7-arm64-aot-poc/ci-log.txt").read_text(errors="replace").splitlines()
picked = []
index = 0
while index < len(lines):
    line = lines[index]
    if "Traceback" in line:
        picked.extend(item.strip() for item in lines[index:index + 12])
        index += 12
        continue
    if "warning:" not in line and any(key in line for key in (
        "error:", "unsupported", "Undefined symbols", "not found", "Exception", "compiled main.m")):
        picked.append(line.strip())
    index += 1
message = " || ".join((picked or [line.strip() for line in lines if "warning:" not in line])[-10:])
print("::error::" + message[:1500].replace("%", "%25"))
