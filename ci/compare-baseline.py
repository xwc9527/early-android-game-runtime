#!/usr/bin/env python3
import argparse, json, pathlib


def main():
    p=argparse.ArgumentParser();p.add_argument("baseline");p.add_argument("current");p.add_argument("--output",default="build/artifacts/baseline-delta.json");a=p.parse_args()
    old=json.load(open(a.baseline,encoding="utf-8"));new=json.load(open(a.current,encoding="utf-8"))
    def sigs(doc,kind):
        block=doc.get(kind,{})
        return set(block.get("new_failures",[])+block.get("unchanged_failures",[]))
    before=sigs(old,"contracts")|sigs(old,"regressions");after=sigs(new,"contracts")|sigs(new,"regressions")
    delta={"schema_version":1,"new_failures":sorted(after-before),"resolved_failures":sorted(before-after),
           "changed_failures":[],"new_coverage":new.get("coverage_delta",{}),
           "behavior_changes":new.get("behavior_delta",[]),"new_warnings":new.get("warnings",{}).get("new",[])}
    out=pathlib.Path(a.output);out.parent.mkdir(parents=True,exist_ok=True);out.write_text(json.dumps(delta,indent=2)+"\n",encoding="utf-8");print(json.dumps(delta,separators=(",",":")))


if __name__=="__main__":main()
