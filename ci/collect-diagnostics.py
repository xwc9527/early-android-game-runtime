#!/usr/bin/env python3
import argparse, hashlib, json, pathlib, time


def main():
    p=argparse.ArgumentParser();p.add_argument("--stage",required=True);p.add_argument("--module",required=True);p.add_argument("--reason",required=True);p.add_argument("--evidence",action="append",default=[]);p.add_argument("--intrusive",action="store_true");p.add_argument("--output",required=True);a=p.parse_args()
    files={}
    raw=[]
    for name in a.evidence:
        path=pathlib.Path(name)
        if path.is_file():
            text=path.read_text(encoding="utf-8",errors="replace");raw.append(text);files[name]=text[-8192:]
    reason=" ".join(a.reason.split()).lower()
    doc={"schema_version":1,"stage":a.stage,"module":a.module,
         "normalized_signature":f"{a.stage}:{a.module}:{reason}:unknown",
         "raw_fingerprint":hashlib.sha256("\n".join(raw+[a.reason]).encode()).hexdigest(),
         "captured_at_epoch":time.time(),"passive":not a.intrusive,"intrusive":a.intrusive,"evidence":files}
    out=pathlib.Path(a.output);out.parent.mkdir(parents=True,exist_ok=True);out.write_text(json.dumps(doc,indent=2)+"\n",encoding="utf-8")


if __name__=="__main__":main()
