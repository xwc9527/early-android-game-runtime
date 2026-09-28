#!/usr/bin/env python3
"""Verify the one-shot Simulator guest snapshot against the archived trace."""

import argparse
import hashlib
import json
from pathlib import Path
import struct


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--selection", required=True)
    parser.add_argument("--label", choices=("gloomy", "kungfoo"), required=True)
    parser.add_argument("--capture", required=True)
    parser.add_argument("--out", required=True)
    args = parser.parse_args()
    spec = next(x for x in json.loads(Path(args.selection).read_text())["segments"]
                if x["label"] == args.label)
    data = Path(args.capture).read_bytes()
    if len(data) < 88:
        raise ValueError("short capture")
    magic, version, pc, cpsr, count = struct.unpack_from("<5I", data)
    regs = struct.unpack_from("<16I", data, 20)
    elf_bytes = struct.unpack_from("<I", data, 84)[0]
    if (magic, version) != (0x41504341, 1):
        raise ValueError("capture header identity")
    expected_bytes = 88 + count * (4 + 4096) + elf_bytes
    if len(data) != expected_bytes:
        raise ValueError(f"capture length {len(data)} != {expected_bytes}")
    pages = {}
    offset = 88
    for _ in range(count):
        page = struct.unpack_from("<I", data, offset)[0]
        if page & 4095 or page in pages:
            raise ValueError("misaligned or duplicate guest page")
        pages[page] = data[offset + 4:offset + 4100]
        offset += 4100
    elf = data[offset:]
    checks = {
        "pc_equal": pc == spec["guest_pc_first"],
        "cpsr_equal": cpsr == spec["entry_cpsr"],
        "registers_equal": list(regs) == spec["entry_registers"],
        "pages_equal": sorted(pages) == spec["snapshot_guest_pages"],
        "elf_hash_equal": hashlib.sha256(elf).hexdigest() == spec["elf_sha256"],
    }
    result = {
        "schema": "agr.aot-attribution-capture-verification.v1",
        "label": args.label,
        "capture_sha256": hashlib.sha256(data).hexdigest(),
        "elf_sha256": hashlib.sha256(elf).hexdigest(),
        "capture_bytes": len(data),
        "elf_bytes": elf_bytes,
        "guest_page_count": count,
        "checks": checks,
        "passed": all(checks.values()),
    }
    Path(args.out).write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result))
    if not result["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
