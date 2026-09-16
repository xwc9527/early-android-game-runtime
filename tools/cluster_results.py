#!/usr/bin/env python3
"""Normalize runtime records into frequency-ranked compatibility gaps."""
from __future__ import annotations
import argparse, collections, json, pathlib

def main() -> None:
    parser=argparse.ArgumentParser()
    parser.add_argument("runtime")
    parser.add_argument("--output",default="build/artifacts/compatibility-summary.json")
    args=parser.parse_args()
    runtime=json.loads(pathlib.Path(args.runtime).read_text(encoding="utf-8"))
    records=runtime.get("batch_results",[])
    counts=collections.Counter(item.get("outcome","unknown") for item in records)
    signatures=collections.Counter(item.get("signature","unknown") for item in records)
    summary={
        "total":len(records),
        "outcomes":dict(sorted(counts.items())),
        "failure_clusters":[{"signature":key,"count":count,
          "samples":[item["id"] for item in records if item.get("signature")==key]}
          for key,count in signatures.most_common() if not key.startswith("success:")],
        "results":records,
    }
    output=pathlib.Path(args.output); output.parent.mkdir(parents=True,exist_ok=True)
    output.write_text(json.dumps(summary,indent=2),encoding="utf-8")
    print(json.dumps(summary,indent=2))

if __name__ == "__main__": main()
