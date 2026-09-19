#!/usr/bin/env python3
"""Maintain normalized clusters without losing distinct raw fingerprints."""

import argparse,json,pathlib,time
def main():
 p=argparse.ArgumentParser();p.add_argument("database");p.add_argument("diagnostic");p.add_argument("--game",default="");p.add_argument("--commit",default="");a=p.parse_args()
 dbpath=pathlib.Path(a.database);diag=json.load(open(a.diagnostic,encoding="utf-8"));db=json.loads(dbpath.read_text(encoding="utf-8")) if dbpath.exists() else {"schema_version":1,"clusters":{}}
 sig=diag["normalized_signature"];raw=diag["raw_fingerprint"];cluster=db["clusters"].setdefault(sig,{"count":0,"games":[],"commits":[],"raw_fingerprints":{},"first_seen":time.time(),"last_seen":None})
 cluster["count"]+=1;cluster["last_seen"]=time.time()
 if a.game and a.game not in cluster["games"]:cluster["games"].append(a.game)
 if a.commit and a.commit not in cluster["commits"]:cluster["commits"].append(a.commit)
 raw_entry=cluster["raw_fingerprints"].setdefault(raw,{"count":0,"first_diagnostic":a.diagnostic});raw_entry["count"]+=1
 dbpath.parent.mkdir(parents=True,exist_ok=True);dbpath.write_text(json.dumps(db,indent=2)+"\n",encoding="utf-8")
if __name__=="__main__":main()
