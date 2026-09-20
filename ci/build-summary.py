#!/usr/bin/env python3
"""Build the single compact AGR run-summary from existing result artifacts."""

import argparse, hashlib, importlib.util, json, os, pathlib, subprocess

ROOT = pathlib.Path(__file__).resolve().parents[1]


def git(*args):
    return subprocess.check_output(["git", *args], cwd=ROOT, text=True).strip()


def read_json(path):
    if not path: return {}
    p = ROOT / path
    try: return json.loads(p.read_text(encoding="utf-8"))
    except (OSError, ValueError): return {}


def status(value):
    value={"success":"pass","failure":"fail","cancelled":"blocked"}.get(value,value)
    return value if value in ("pass","fail","blocked","skipped") else "unknown"


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--platform", required=True)
    p.add_argument("--run-kind", choices=("discovery","closure","post-merge","build"), default="discovery")
    p.add_argument("--build-status", default="unknown")
    p.add_argument("--contracts-status", default="unknown")
    p.add_argument("--regressions-status", default="unknown")
    p.add_argument("--result")
    p.add_argument("--diagnostic")
    p.add_argument("--semantic-diff")
    p.add_argument("--valid-run", choices=("true","false"), default="true")
    p.add_argument("--output", default="build/artifacts/run-summary.json")
    args = p.parse_args()
    state = read_json("ci/governance/state.json")
    modules = read_json("ci/governance/modules.json").get("modules", [])
    reopens = read_json("ci/governance/reopens.json").get("reopens", [])
    target_def = read_json("ci/targets/PVS1.json")
    result = read_json(args.result)
    diagnostic = read_json(args.diagnostic)
    semantic = read_json(args.semantic_diff)
    map_entry = semantic.get("upstream",{}).get("map_entry",diagnostic.get("upstream_map_entry",""))
    computed_map_status = semantic.get("upstream",{}).get("map_status","UNVERIFIED")
    if map_entry:
        spec=importlib.util.spec_from_file_location("upstream_map_tool",ROOT/"ci/upstream-map.py")
        module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
        _,entries=module.evaluate(read_json("ci/governance/upstream-map.json"))
        computed_map_status=entries.get(map_entry,{}).get("effective_status","INVALID")
    head, tree = git("rev-parse","HEAD"), git("rev-parse","HEAD^{tree}")
    baseline = state.get("baseline",{}).get("commit","")
    try: files = [x for x in git("diff","--name-only",f"{baseline}...HEAD").splitlines() if x]
    except subprocess.CalledProcessError: files=[]
    touched=[m["name"] for m in modules if any(any(f.startswith(prefix) for prefix in m["paths"]) for f in files)]
    stable=[m["name"] for m in modules if m["name"] in touched and m["status"]=="stable"]
    closure_result=result.get("pvs1_closure",{})
    clean_teardown=bool(closure_result.get("clean_teardown",result.get("teardown_completed",False)))
    target_pass=bool(closure_result.get("passed",False) and clean_teardown)
    raw_reason=result.get("runtime_failure_signature") or result.get("gameplay_failure") or ""
    exit_classification=diagnostic.get("classification","")
    normalized=("pvs1:runtime:failure:runtime" if raw_reason else
                (f"pvs1:process_exit:{exit_classification.lower()}" if exit_classification and not target_pass else
                 ("" if target_pass else "pvs1:target:requirements_unmet:closure")))
    raw_hash=hashlib.sha256(json.dumps(result,sort_keys=True).encode()).hexdigest() if result else ""
    valid=args.valid_run=="true"
    eligible=(args.run_kind=="closure" and valid and status(args.build_status)=="pass" and
              status(args.contracts_status)=="pass" and status(args.regressions_status)=="pass" and target_pass)
    summary={
      "schema_version":1,
      "run":{"workflow_id":os.getenv("GITHUB_RUN_ID","local"),"tested_commit":head,"tested_tree":tree,
             "baseline_commit":baseline,"branch":os.getenv("GITHUB_REF_NAME",git("branch","--show-current")),
             "platform":args.platform,"runner":os.getenv("RUNNER_OS","local"),"valid_run":valid,"kind":args.run_kind},
      "changes":{"files":files,"modules":touched,"stable_modules_touched":stable,
                 "stable_module_reopens":[r for r in reopens if r.get("target")==state.get("active",{}).get("target") and r.get("module") in stable]},
      "build":{"status":status(args.build_status)},
      "contracts":{"status":status(args.contracts_status),"new_failures":[],"resolved_failures":[]},
      "regressions":{"status":status(args.regressions_status),"new_failures":[],"resolved_failures":[],"unchanged_failures":[]},
      "target":{"name":target_def.get("target","PVS1"),"status":"pass" if target_pass else "fail",
                "stage":result.get("gameplay_outcome","not_run"),"normalized_signature":normalized,
                "raw_fingerprint":raw_hash,"requirements":closure_result,"clean_teardown":clean_teardown,
                "process_exit_classification":exit_classification},
      "coverage_delta":{"new_imports":[],"new_android_api":[],"new_jni":[],"new_lifecycle":[]},
      "behavior_delta":[],"warnings":{"new":[],"resolved":[]},
      "diagnostics":{"passive":diagnostic.get("passive",True),"intrusive":diagnostic.get("intrusive",False),
                     "primary":args.diagnostic or "","classification":diagnostic.get("classification",""),
                     "remaining_candidates":diagnostic.get("remaining_candidates",[]),
                     "missing_evidence":diagnostic.get("missing_evidence",[]),
                     "experimental":diagnostic.get("experimental",False)},
      "diagnosis":{
          "observed_discontinuity":semantic.get("observed_discontinuity",diagnostic.get("observed_discontinuity","")),
          "android_subsystem":semantic.get("subsystem",diagnostic.get("subsystem","")),
          "upstream":{"map_entry":map_entry,
                      "map_status":computed_map_status,
                      "revision":semantic.get("upstream",{}).get("revision",""),
                      "path":semantic.get("upstream",{}).get("call_path",[]),
                      "source_verified":semantic.get("upstream",{}).get("source_verified",False)},
          "agr_path":semantic.get("agr",{}).get("call_path",[]),
          "earliest_evidenced_divergence":{"description":semantic.get("earliest_evidenced_divergence",diagnostic.get("earliest_evidenced_divergence","")),
                                            "semantic_class":semantic.get("semantic_class","PUBLIC_OBSERVABLE"),
                                            "causal_status":semantic.get("causal_status","OBSERVED"),
                                            "evidence_level":semantic.get("evidence_level","SOURCE_INFERRED")},
          "classification":semantic.get("classification",diagnostic.get("classification","UNKNOWN")) or "UNKNOWN",
          "remaining_uncertainty":semantic.get("remaining_uncertainty",diagnostic.get("remaining_candidates",[])),
          "next_action":semantic.get("next_action",diagnostic.get("next_action","")),
          "semantic_diff_artifact":args.semantic_diff or diagnostic.get("semantic_diff_artifact","")},
      "closure":{"target":target_def.get("target","PVS1"),"tested_commit":head,"tested_tree":tree,
                 "base_commit":baseline,"state":"CLOSED" if eligible else "IMPLEMENTED",
                 "eligible_for_merge":eligible},
      "artifacts":{"runtime_result":args.result or "","diagnostics":args.diagnostic or "",
                   "semantic_diff":args.semantic_diff or "","full_logs":""}
    }
    out=ROOT/args.output;out.parent.mkdir(parents=True,exist_ok=True)
    out.write_text(json.dumps(summary,indent=2)+"\n",encoding="utf-8")
    print("AGR RUN SUMMARY")
    print(f"Commit: {head}\nTarget: {summary['target']['status']} {normalized}\nMerge eligible: {eligible}\nArtifact: {args.output}")


if __name__ == "__main__": main()
