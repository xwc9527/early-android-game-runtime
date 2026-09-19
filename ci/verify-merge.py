#!/usr/bin/env python3
"""Reject a merge candidate whose commit/tree is not covered by closure evidence."""

import argparse,json,pathlib,subprocess,sys
ROOT=pathlib.Path(__file__).resolve().parents[1]
def git(*a):return subprocess.check_output(["git",*a],cwd=ROOT,text=True).strip()
def main():
 p=argparse.ArgumentParser();p.add_argument("summary");p.add_argument("--merged",action="store_true");a=p.parse_args();s=json.load(open(a.summary,encoding="utf-8"));c=s["closure"]
 head=git("rev-parse","HEAD");tree=git("rev-parse","HEAD^{tree}");errors=[]
 if not c.get("eligible_for_merge"):errors.append("closure evidence is not merge eligible")
 if not a.merged and head!=c.get("tested_commit"):errors.append("MERGE_CANDIDATE_HEAD != CLOSURE_TESTED_COMMIT")
 if tree!=c.get("tested_tree"):errors.append("current tree != closure tested tree")
 for e in errors:print(f"::error title=AGR merge gate::{e}")
 return 1 if errors else 0
if __name__=="__main__":raise SystemExit(main())
