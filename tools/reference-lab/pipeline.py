"""Build a JNI source index from a pinned Jni.cpp and close one entry.

The index is limited to symbols present in the JNINativeInterface table.
"""

import argparse
import json
from pathlib import Path

from source_closure import close_entry
from source_index import build_index, write_index


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--jni", required=True)
    parser.add_argument("--out", required=True)
    parser.add_argument("--symbol", default="GetStaticIntField")
    parser.add_argument("--require-closed", action="store_true")
    args = parser.parse_args()
    document = build_index(args.jni)
    out = Path(args.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    write_index(out, document)
    manifest = close_entry(
        {"dependency_id": "JNI_BINDING:" + args.symbol, "canonical_name": args.symbol},
        document,
    )
    manifest_path = out.with_suffix(".manifest.json")
    manifest_path.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    if args.require_closed and manifest["status"] != "SOURCE_CLOSED":
        raise SystemExit("source closure not reviewed for " + args.symbol)
    print(manifest_path)


if __name__ == "__main__":
    main()
