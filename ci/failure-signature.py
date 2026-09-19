#!/usr/bin/env python3
"""Create a cluster signature while retaining a raw diagnostic fingerprint."""

import argparse, hashlib, json, re, sys


def normalize(text: str) -> str:
    text = text.strip().replace("\\", "/")
    text = re.sub(r"(?:[A-Za-z]:)?/(?:[^\s:]+/)+[^\s:]+", "<path>", text)
    text = re.sub(r"\b(?:pid|thread)[ =:#-]*\d+\b", lambda m: m.group(0).split()[0] + "=<id>", text, flags=re.I)
    text = re.sub(r"0x[0-9a-fA-F]+", "<addr>", text)
    text = re.sub(r"\b[0-9a-fA-F]{12,40}\b", "<hash>", text)
    text = re.sub(r"\b\d{4}-\d\d-\d\d[T ][0-9:.+Z-]+", "<time>", text)
    text = re.sub(r"\s+", " ", text).strip().lower()
    return text or "unknown"


def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--stage", required=True)
    p.add_argument("--module", required=True)
    p.add_argument("--reason", required=True)
    p.add_argument("--location", default="unknown")
    p.add_argument("--raw", default="")
    args = p.parse_args()
    reason, location = normalize(args.reason), normalize(args.location)
    signature = f"{args.stage}:{args.module}:{reason}:{location}"
    raw = args.raw or "|".join((args.stage, args.module, args.reason, args.location))
    print(json.dumps({"normalized_signature": signature,
                      "raw_fingerprint": hashlib.sha256(raw.encode()).hexdigest()}, separators=(",", ":")))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
