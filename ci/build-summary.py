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
    p.add_argument("--infrastructure-defect", action="append", default=[], choices=("HARNESS_DEFECT","RUNNER_DEFECT","COLLECTOR_DEFECT","ARTIFACT_DEFECT","TIMEOUT_HIERARCHY_DEFECT","WORKFLOW_DEFECT"))
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
    runtime_reason=result.get("runtime_failure_signature") or ""
    runtime_outcome=result.get("gameplay_outcome")=="runtime_failure"
    raw_reason=runtime_reason or (result.get("gameplay_failure") or "" if runtime_outcome else "")
    exit_classification="" if target_pass else diagnostic.get("classification","")
    normalized=("" if target_pass else
                ("pvs1:runtime:failure:runtime" if raw_reason else
                 (f"pvs1:process_exit:{exit_classification.lower()}" if exit_classification else
                  "pvs1:target:requirements_unmet:closure")))
    raw_hash=hashlib.sha256(json.dumps(result,sort_keys=True).encode()).hexdigest() if result else ""
    normalized_stages={
      "contracts":{"pass":"PASS","fail":"FAIL","blocked":"NOT_RUN_DEFECT","skipped":"NOT_RUN_DEFECT","unknown":"NOT_RUN_DEFECT"}[status(args.contracts_status)],
      "simulator_smoke":{"pass":"PASS","fail":"FAIL","blocked":"NOT_RUN_DEFECT","skipped":"NOT_RUN_DEFECT","unknown":"NOT_RUN_DEFECT"}[status(args.build_status)],
      "regressions":{"pass":"PASS","fail":"FAIL","blocked":"BLOCKED_BY_VALID_FAILURE" if status(args.build_status)=="fail" else "NOT_RUN_DEFECT",
                     "skipped":"BLOCKED_BY_VALID_FAILURE" if status(args.build_status)=="fail" else "NOT_RUN_DEFECT",
                     "unknown":"NOT_RUN_DEFECT"}[status(args.regressions_status)]}
    result_present=bool(args.result and (ROOT/args.result).is_file())
    diagnostic_present=bool(args.diagnostic and (ROOT/args.diagnostic).is_file())
    evidence={"target_or_failure_evidence":result_present or diagnostic_present,
              "diagnostic":diagnostic_present,
              "semantic_diff":bool(args.semantic_diff and (ROOT/args.semantic_diff).is_file())}
    defects=list(dict.fromkeys(args.infrastructure_defect))
    if args.run_kind=="closure" and diagnostic.get("classification")=="HARNESS_BUG": defects.append("HARNESS_DEFECT")
    if args.run_kind=="closure" and diagnostic.get("classification")=="EXTERNAL_SERVICE_FAILURE": defects.append("EXTERNAL_SERVICE_FAILURE")
    attempt={"classification":"NOT_APPLICABLE","consumes_budget":False,"automatic_rerun_permitted":False,
             "required_stages":normalized_stages if args.run_kind=="closure" else {},
             "required_evidence":evidence if args.run_kind=="closure" else {},
             "infrastructure_defects":list(dict.fromkeys(defects))}
    summary={
      "schema_version":1,
      "run":{"workflow_id":os.getenv("GITHUB_RUN_ID","local"),"tested_commit":head,"tested_tree":tree,
             "baseline_commit":baseline,"branch":os.getenv("GITHUB_REF_NAME",git("branch","--show-current")),
             "platform":args.platform,"runner":os.getenv("RUNNER_OS","local"),"valid_run":False,"kind":args.run_kind,
             "closure_attempt":attempt},
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
                 "base_commit":baseline,"state":"IMPLEMENTED","eligible_for_merge":False},
      "artifacts":{"runtime_result":args.result or "","diagnostics":args.diagnostic or "",
                   "semantic_diff":args.semantic_diff or "","full_logs":""}
    }
    if args.run_kind=="closure":
        spec=importlib.util.spec_from_file_location("closure_attempt_tool",ROOT/"ci/closure-attempt.py")
        attempt_tool=importlib.util.module_from_spec(spec);spec.loader.exec_module(attempt_tool)
        classification,reasons=attempt_tool.classify_summary(summary)
        attempt.update({"classification":classification,"reasons":reasons,
                        "consumes_budget":classification in ("VALID_PASS","VALID_FAIL"),
                        "automatic_rerun_permitted":classification=="INVALID"})
        summary["run"]["valid_run"]=classification in ("VALID_PASS","VALID_FAIL")
        eligible=(classification=="VALID_PASS" and status(args.build_status)=="pass" and
                  status(args.contracts_status)=="pass" and status(args.regressions_status)=="pass" and target_pass)
        summary["closure"]["state"]="CLOSED" if eligible else "IMPLEMENTED"
        summary["closure"]["eligible_for_merge"]=eligible
    else:
        eligible=False
    out=ROOT/args.output;out.parent.mkdir(parents=True,exist_ok=True)
    out.write_text(json.dumps(summary,indent=2)+"\n",encoding="utf-8")
    print("AGR RUN SUMMARY")
    print(f"Commit: {head}\nTarget: {summary['target']['status']} {normalized}\nMerge eligible: {eligible}\nArtifact: {args.output}")


if __name__ == "__main__": main()
