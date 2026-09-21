#!/usr/bin/env python3
"""Fetch the closure artifact named by the current formal merge binding."""

import io,json,os,pathlib,urllib.parse,urllib.request,zipfile
ROOT=pathlib.Path(__file__).resolve().parents[1]
OUT=ROOT/"build"/"artifacts"/"closure-run-summary.json"
FOCUSED_OUT=ROOT/"build"/"artifacts"/"framework-viewroot-attach.json"
def load(path):return json.loads((ROOT/path).read_text(encoding="utf-8"))
def api(url):
 req=urllib.request.Request(url,headers={"Authorization":f"Bearer {os.environ['GITHUB_TOKEN']}","Accept":"application/vnd.github+json","X-GitHub-Api-Version":"2022-11-28"})
 with urllib.request.urlopen(req,timeout=30) as r:return json.load(r)
class ArtifactRedirectHandler(urllib.request.HTTPRedirectHandler):
 def redirect_request(self,req,fp,code,msg,headers,newurl):
  redirected=super().redirect_request(req,fp,code,msg,headers,newurl)
  if redirected and urllib.parse.urlsplit(req.full_url).netloc!=urllib.parse.urlsplit(newurl).netloc:
   redirected.remove_header("Authorization")
  return redirected
def bytes_url(url):
 req=urllib.request.Request(url,headers={"Authorization":f"Bearer {os.environ['GITHUB_TOKEN']}","Accept":"application/vnd.github+json"})
 with urllib.request.build_opener(ArtifactRedirectHandler()).open(req,timeout=60) as r:return r.read()
def artifact_entry(artifacts,name,entry):
 matches=[art for art in artifacts if art.get("name")==name and not art.get("expired")]
 if len(matches)!=1:raise SystemExit(f"expected one live artifact {name}, found {len(matches)}")
 with zipfile.ZipFile(io.BytesIO(bytes_url(matches[0]["archive_download_url"]))) as z:
  names=[item for item in z.namelist() if item==entry or item.endswith("/"+entry)]
  if len(names)!=1:raise SystemExit(f"artifact {name} does not contain exactly one {entry}")
  return z.read(names[0])
def main():
 binding=load("ci/governance/post-merge-binding.json")
 state=load("ci/governance/state.json")
 closure=load("ci/governance/closure.json")
 ledger=load("ci/governance/closure-attempts.json")
 target=binding["target"]
 if target!=state["active"]["target"] or target!=closure["target"] or target!=ledger["active_target"]:
  raise SystemExit("POST_MERGE_TARGET_MISMATCH")
 for field in ("closure_tested_commit","closure_tested_tree","merged_commit","merged_tree"):
  if binding[field]!=closure[field]:raise SystemExit(f"POST_MERGE_BINDING_MISMATCH:{field}")
 matching=[item for item in ledger["attempts"] if item.get("run_id")==binding["closure_run_id"]
           and item.get("target")==target and item.get("classification")=="VALID_PASS"
           and item.get("tested_commit")==binding["closure_tested_commit"]
           and item.get("tested_tree")==binding["closure_tested_tree"]]
 if len(matching)!=1:raise SystemExit("POST_MERGE_CLOSURE_LEDGER_MISMATCH")
 repo=os.environ["GITHUB_REPOSITORY"]
 run=api(f"https://api.github.com/repos/{repo}/actions/runs/{binding['closure_run_id']}")
 if str(run.get("id"))!=binding["closure_run_id"] or run.get("head_sha")!=binding["closure_tested_commit"] or run.get("conclusion")!="success":
  raise SystemExit("POST_MERGE_CLOSURE_RUN_MISMATCH")
 artifacts=api(run["artifacts_url"]).get("artifacts",[])
 summary=json.loads(artifact_entry(artifacts,binding["closure_artifact"],binding["closure_entry"]))
 c=summary.get("closure",{})
 if (c.get("target")!=target or c.get("tested_commit")!=binding["closure_tested_commit"]
     or c.get("tested_tree")!=binding["closure_tested_tree"] or not c.get("eligible_for_merge")
     or summary.get("run",{}).get("closure_attempt",{}).get("classification")!="VALID_PASS"
     or str(summary.get("run",{}).get("workflow_id"))!=binding["closure_run_id"]):
  raise SystemExit("POST_MERGE_CLOSURE_ARTIFACT_MISMATCH")
 focused=artifact_entry(artifacts,binding["focused_artifact"],binding["focused_entry"])
 OUT.parent.mkdir(parents=True,exist_ok=True)
 OUT.write_text(json.dumps(summary,indent=2)+"\n",encoding="utf-8")
 FOCUSED_OUT.write_bytes(focused)
 print(f"closure evidence run {binding['closure_run_id']} target {target} commit {c['tested_commit']}")
 return 0
if __name__=="__main__":raise SystemExit(main())
