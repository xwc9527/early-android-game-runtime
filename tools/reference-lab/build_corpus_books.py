#!/usr/bin/env python3
"""Create non-authorizing static Migration Books for the locked five-APK corpus."""

import argparse
import json
from pathlib import Path

from mapper import build_book, corpus_union, write_book
from static_scan import apk_identity, scan_apk
from workflow import save, validate_book


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--matrix", required=True, type=Path)
    parser.add_argument("--out-dir", required=True, type=Path)
    args = parser.parse_args()
    matrix = json.loads(args.matrix.read_text())
    if matrix.get("baseline") != "android-4.4.4_r2" or len(matrix.get("samples", [])) != 5:
        raise SystemExit("expected the verified five-sample API19 matrix")
    books = []
    summary = []
    for sample in matrix["samples"]:
        apk = Path(sample["apk"])
        identity = apk_identity(apk)
        if identity["sha256"] != sample["apk_sha256"]:
            raise SystemExit("sample identity changed: " + sample["id"])
        book = build_book(identity, [], scan_apk(apk))
        validate_book(book)
        if book["variant"] != "STATIC_ONLY":
            raise SystemExit("static corpus book falsely claims a TRACE run")
        path = args.out_dir / (sample["id"] + "-static.json")
        write_book(path, book)
        books.append(book)
        summary.append({"id": sample["id"], "apk_sha256": identity["sha256"],
                        "static_references": len(book["dependencies"]), "book": str(path)})
    union = corpus_union(books)
    save(args.out_dir / "corpus-static-union.json", union)
    save(args.out_dir / "summary.json", {"variant": "STATIC_ONLY",
                                         "source_closure_authorized": False,
                                         "samples": summary,
                                         "union_dependencies": len(union["dependencies"])})
    print(json.dumps({"samples": summary, "union_dependencies": len(union["dependencies"])}))


if __name__ == "__main__":
    main()
