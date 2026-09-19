#!/usr/bin/env python3
"""Fetch closure evidence for the tree merged into main from GitHub artifacts."""

import io,json,os,pathlib,subprocess,urllib.request,zipfile
ROOT=pathlib.Path(__file__).resolve().parents[1]
OUT=ROOT/"build"/"artifacts"/"closure-run-summary.json"
def git(*a):return subprocess.check_output(["git",*a],cwd=ROOT,text=True).strip()
def api(url):
 req=urllib.request.Request(url,headers={"Authorization":f"Bearer {os.environ['GITHUB_TOKEN']}","Accept":"application/vnd.github+json","X-GitHub-Api-Version":"2022-11-28"})
 with urllib.request.urlopen(req,timeout=30) as r:return json.load(r)
def bytes_url(url):
 req=urllib.request.Request(url,headers={"Authorization":f"Bearer {os.environ['GITHUB_TOKEN']}","Accept":"application/vnd.github+json"})
 with urllib.request.urlopen(req,timeout=60) as r:return r.read()
def main():
 repo=os.environ["GITHUB_REPOSITORY"];parents=git("rev-list","--parents","-n1","HEAD").split();candidates=parents
 current_tree=git("rev-parse","HEAD^{tree}")
 for sha in candidates:
  runs=api(f"https://api.github.com/repos/{repo}/actions/workflows/runtime.yml/runs?head_sha={sha}&status=success&per_page=20")
  for run in runs.get("workflow_runs",[]):
   arts=api(run["artifacts_url"])
   for art in arts.get("artifacts",[]):
    if not art["name"].startswith("ios-simulator-runtime-smoke-"):continue
    with zipfile.ZipFile(io.BytesIO(bytes_url(art["archive_download_url"]))) as z:
     names=[n for n in z.namelist() if n.endswith("run-summary.json")]
     if not names:continue
     summary=json.loads(z.read(names[0]))
     c=summary.get("closure",{})
     if c.get("eligible_for_merge") and c.get("tested_commit")==sha and c.get("tested_tree")==current_tree:
      OUT.parent.mkdir(parents=True,exist_ok=True);OUT.write_text(json.dumps(summary,indent=2)+"\n",encoding="utf-8");print(f"closure evidence run {run['id']} commit {sha}");return 0
 raise SystemExit("no eligible closure evidence matches the merged main tree")
if __name__=="__main__":raise SystemExit(main())
