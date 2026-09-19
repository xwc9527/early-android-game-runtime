#!/usr/bin/env python3
"""Create or validate the compact AGR semantic-differential artifact."""
import argparse,json,pathlib,sys

ROOT=pathlib.Path(__file__).resolve().parents[1]
CLASSIFICATIONS={"ANDROID_SEMANTIC_BUG","HOST_ADAPTATION_BUG","AGR_INTERNAL_BUG","HARNESS_BUG","REFERENCE_MISMATCH","UNKNOWN"}

def validate(doc):
 errors=[]
 required=("schema_version","classification","subsystem","observed_discontinuity","upstream","required_semantics","agr","differences","first_relevant_difference","confidence","needs_experiment","validation")
 for key in required:
  if key not in doc:errors.append(f"missing:{key}")
 if doc.get("schema_version")!=1:errors.append("schema_version must be 1")
 if doc.get("classification") not in CLASSIFICATIONS:errors.append("invalid classification")
 upstream=doc.get("upstream",{})
 if upstream.get("version")!="Android 4.4.4_r2":errors.append("upstream.version must be Android 4.4.4_r2")
 if not isinstance(upstream.get("files"),list) or not isinstance(upstream.get("call_path"),list):errors.append("upstream files/call_path must be arrays")
 agr=doc.get("agr",{})
 if not isinstance(agr.get("files"),list) or not isinstance(agr.get("call_path"),list):errors.append("agr files/call_path must be arrays")
 if not isinstance(doc.get("required_semantics"),list):errors.append("required_semantics must be an array")
 if not isinstance(doc.get("differences"),list):errors.append("differences must be an array")
 for index,difference in enumerate(doc.get("differences",[])):
  if not isinstance(difference,dict) or not all(key in difference for key in ("id","description","relevance")):errors.append(f"difference {index} requires id/description/relevance")
 if doc.get("confidence") not in ("low","medium","high","proven"):errors.append("invalid confidence")
 if not isinstance(doc.get("active_explanations",[]),list):errors.append("active_explanations must be an array")
 if not isinstance(doc.get("validation"),list):errors.append("validation must be an array")
 if doc.get("needs_experiment") and not doc.get("next_discriminating_action"):errors.append("experiment requires next_discriminating_action")
 if doc.get("experimental") and doc.get("confidence")=="proven":errors.append("experimental result cannot be proven")
 return errors

def main():
 p=argparse.ArgumentParser();sub=p.add_subparsers(dest="command",required=True)
 new=sub.add_parser("new");new.add_argument("--subsystem",required=True);new.add_argument("--observed",required=True);new.add_argument("--output",required=True)
 check=sub.add_parser("validate");check.add_argument("path")
 a=p.parse_args()
 if a.command=="new":
  doc={"schema_version":1,"classification":"UNKNOWN","subsystem":a.subsystem,"observed_discontinuity":a.observed,
   "upstream":{"version":"Android 4.4.4_r2","files":[],"call_path":[]},"required_semantics":[],
   "agr":{"files":[],"call_path":[]},"differences":[],"first_relevant_difference":"","confidence":"low",
   "needs_experiment":True,"active_explanations":[],"next_discriminating_action":"define one experiment that separates the remaining explanations",
   "host_adaptation":"","validation":[],"experimental":True}
  out=pathlib.Path(a.output);out.parent.mkdir(parents=True,exist_ok=True);out.write_text(json.dumps(doc,indent=2)+"\n",encoding="utf-8");return 0
 doc=json.loads(pathlib.Path(a.path).read_text(encoding="utf-8"));errors=validate(doc)
 for error in errors:print(error,file=sys.stderr)
 return 1 if errors else 0
if __name__=="__main__":raise SystemExit(main())
