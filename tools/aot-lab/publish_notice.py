#!/usr/bin/env python3
"""Publish the proof files as public job annotations.

The Actions log and artifact download require authentication. Check-run
annotations do not. The zip is split so each annotation stays under the
message limit.
"""

import base64
import io
import json
import pathlib
import sys
import zipfile


def main():
    evidence = pathlib.Path(sys.argv[1])
    differential = json.loads((evidence / "differential.json").read_text(encoding="utf-8"))
    print("::notice title=aot-differential::" + json.dumps(differential, separators=(",", ":")))
    buffer = io.BytesIO()
    with zipfile.ZipFile(buffer, "w", compression=zipfile.ZIP_DEFLATED) as archive:
        for path in sorted(evidence.rglob("*")):
            if path.is_file() and path.name != "ci-log.txt":
                archive.write(path, path.relative_to(evidence).as_posix())
    payload = base64.b64encode(buffer.getvalue()).decode("ascii")
    chunk_size = 48000
    parts = [payload[index:index + chunk_size] for index in range(0, len(payload), chunk_size)] or [""]
    for index, part in enumerate(parts):
        print(f"::notice title=aot-evidence-{index}-of-{len(parts)}::{part}")


if __name__ == "__main__":
    main()
