#!/usr/bin/env python3
"""Record CLOSED/MERGED state after identity checks; caller commits and runs post-merge gate."""

import argparse,json,pathlib,re,subprocess
ROOT=pathlib.Path(__file__).resolve().parents[1]
def git(*a):return subprocess.check_output(["git",*a],cwd=ROOT,text=True).strip()
def main():
 p=argparse.ArgumentParser();p.add_argument("summary");p.add_argument("--merged",action="store_true",required=True);p.add_argument("--merged-commit");a=p.parse_args()
 s=json.load(open(a.summary,encoding="utf-8"));c=s["closure"]
 if not c.get("eligible_for_merge"):raise SystemExit("closure is not merge eligible")
 head=git("rev-parse","HEAD");merged=a.merged_commit or head
 if subprocess.run(["git","merge-base","--is-ancestor",merged,head],cwd=ROOT).returncode:raise SystemExit("merged commit is not on current main")
 tree=git("rev-parse",f"{merged}^{{tree}}")
 if tree!=c["tested_tree"]:raise SystemExit("merged commit tree differs from closure tested tree")
 state_name="MERGED"
 closure=json.load(open(ROOT/"ci/governance/closure.json",encoding="utf-8"));closure.update({
  "state":state_name,"closure_tested_commit":c["tested_commit"],"closure_tested_tree":c["tested_tree"],
  "closure_base_commit":c["base_commit"],"eligible_for_merge":False,
  "merged_commit":merged,"merged_tree":tree})
 (ROOT/"ci/governance/closure.json").write_text(json.dumps(closure,indent=2)+"\n",encoding="utf-8")
 state=json.load(open(ROOT/"ci/governance/state.json",encoding="utf-8"));state["baseline"]["commit"]=merged;state["baseline"]["last_known_good"]=merged;state["active"]["lifecycle"]="MERGED";state["active"]["primary_blocker"]="none";state["active"]["first_broken_boundary"]="none";state["active"]["first_broken_boundary_evidence"]="closure evidence"
 (ROOT/"ci/governance/state.json").write_text(json.dumps(state,indent=2)+"\n",encoding="utf-8")
 modules=json.load(open(ROOT/"ci/governance/modules.json",encoding="utf-8"))
 if c.get("target")=="PVS1":
  for module in modules["modules"]:
   if module["name"] in ("NativeActivityInput","DEXRuntimeLifecycle"):module["status"]="stable";module["reopen_reason"]=None
 (ROOT/"ci/governance/modules.json").write_text(json.dumps(modules,indent=2)+"\n",encoding="utf-8")
 reopens=json.load(open(ROOT/"ci/governance/reopens.json",encoding="utf-8"));reopens["reopens"]=[r for r in reopens["reopens"] if r.get("target")!=c.get("target")]
 (ROOT/"ci/governance/reopens.json").write_text(json.dumps(reopens,indent=2)+"\n",encoding="utf-8")
 current=(ROOT/"docs/CURRENT_STATE.md").read_text(encoding="utf-8")
 current=re.sub(r"Baseline: `main @ [0-9a-f]+`",f"Baseline: `main @ {merged}`",current)
 current=re.sub(r"Last known good: `[^`]+` on formal `main`",f"Last known good: `{merged}` on formal `main`",current)
 current=re.sub(r"Lifecycle state: `[^`]+`[^\n]*",f"Lifecycle state: `MERGED` (`{c.get('target')}` closure-tested tree is on main)",current)
 (ROOT/"docs/CURRENT_STATE.md").write_text(current,encoding="utf-8")
 module_doc=(ROOT/"docs/MODULE_STATUS.md").read_text(encoding="utf-8")
 short=c["tested_commit"][:8]
 for name in ("NativeActivity/Window","Looper/InputQueue","Simulator regression harness","DEX Runtime Activity lifecycle"):
  module_doc=re.sub(rf"^\| {re.escape(name)} \| active \| — \|",f"| {name} | stable | `{short}` |",module_doc,flags=re.M)
 (ROOT/"docs/MODULE_STATUS.md").write_text(module_doc,encoding="utf-8")
 print(f"AGR state prepared: {state_name} {merged} tree {tree}")
if __name__=="__main__":main()
