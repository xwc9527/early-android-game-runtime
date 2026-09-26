#!/usr/bin/env python3
"""Pin paired API19 generated DisplayManager Binder transactions."""

import argparse
import hashlib
import json
import re
from pathlib import Path


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def one(pattern, content, label):
    matches = re.findall(pattern, content)
    if len(matches) != 1:
        raise ValueError(label + " must occur exactly once")
    return matches[0]


def inspect(clean, trace, clean_callback, trace_callback, ibinder):
    source = ibinder.read_text(encoding="utf-8")
    first = int(one(r"\bFIRST_CALL_TRANSACTION\s*=\s*(0x[0-9a-fA-F]+|\d+)\s*;",
                    source, "FIRST_CALL_TRANSACTION"), 0)
    if first != 1:
        raise ValueError("unexpected API19 FIRST_CALL_TRANSACTION")
    result = {"schema_version": 1, "baseline": "android-4.4.4_r2",
              "ibinder_source_sha256": digest(ibinder), "first_call_transaction": first}
    parsed = []
    for role, path, callback in (("clean", clean, clean_callback),
                                 ("trace", trace, trace_callback)):
        text = path.read_text(encoding="utf-8")
        cb_text = callback.read_text(encoding="utf-8")
        descriptor = one(r'\bDESCRIPTOR\s*=\s*"([^"]+)"\s*;', text, "descriptor")
        if descriptor != "android.hardware.display.IDisplayManager":
            raise ValueError("unexpected display interface descriptor")
        codes = {}
        for name in ("getDisplayInfo", "registerCallback"):
            offset = int(one(r"\bTRANSACTION_" + name +
                             r"\s*=\s*\(android\.os\.IBinder\.FIRST_CALL_TRANSACTION\s*\+\s*(\d+)\)",
                             text, name))
            codes[name] = first + offset
        callback_offset = int(one(
            r"\bTRANSACTION_onDisplayEvent\s*=\s*\(android\.os\.IBinder\.FIRST_CALL_TRANSACTION\s*\+\s*(\d+)\)",
            cb_text, "onDisplayEvent"))
        if "FLAG_ONEWAY" not in cb_text:
            raise ValueError("display callback lacks oneway transact")
        row = {"display_aidl_sha256": digest(path),
               "callback_aidl_sha256": digest(callback),
               "interface_descriptor": descriptor,
               "transactions": {**codes, "onDisplayEvent_callback": first + callback_offset},
               "callback_oneway": True}
        result[role] = row
        parsed.append((descriptor, row["transactions"], row["callback_oneway"]))
    if parsed[0] != parsed[1] or result["clean"]["display_aidl_sha256"] != result["trace"]["display_aidl_sha256"] or result["clean"]["callback_aidl_sha256"] != result["trace"]["callback_aidl_sha256"]:
        raise ValueError("CLEAN/TRACE generated DisplayManager AIDL differs")
    return result


def main():
    parser = argparse.ArgumentParser()
    for name in ("clean", "trace", "clean-callback", "trace-callback", "ibinder", "out"):
        parser.add_argument("--" + name, required=True, type=Path)
    args = parser.parse_args()
    record = inspect(args.clean, args.trace, args.clean_callback,
                     args.trace_callback, args.ibinder)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(record, indent=2, sort_keys=True) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
