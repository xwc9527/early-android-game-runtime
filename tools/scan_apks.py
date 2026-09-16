#!/usr/bin/env python3
"""Static scan and clustering pre-pass for the Simulator compatibility jobs."""
from __future__ import annotations

import argparse
import json
import pathlib
import struct
import zipfile

def inspect_elf(data: bytes) -> dict:
    if data[:5] != b"\x7fELF\x01" or data[5] != 1:
        raise ValueError("expected little-endian ELF32")
    phoff=struct.unpack_from("<I",data,28)[0]
    phentsize,phnum=struct.unpack_from("<HH",data,42)
    loads=[]; dynamic=None
    for index in range(phnum):
        values=struct.unpack_from("<IIIIIIII",data,phoff+index*phentsize)
        ptype,offset,vaddr,_,filesz,memsz,_,_=values
        if ptype==1: loads.append((vaddr,vaddr+memsz,offset,filesz))
        elif ptype==2: dynamic=(offset,filesz)
    def file_offset(address:int)->int:
        for start,end,offset,filesz in loads:
            if start <= address < end and address-start < filesz: return offset+address-start
        raise ValueError(f"unmapped ELF address 0x{address:x}")
    tags:dict[int,list[int]]={}
    if dynamic:
        for offset in range(dynamic[0],dynamic[0]+dynamic[1],8):
            tag,value=struct.unpack_from("<II",data,offset)
            if tag==0: break
            tags.setdefault(tag,[]).append(value)
    strtab=file_offset(tags[5][0]); strsz=tags.get(10,[len(data)-strtab])[0]
    strings=data[strtab:strtab+strsz]
    def string_at(offset:int)->str:
        end=strings.find(b"\0",offset)
        return strings[offset:end if end>=0 else None].decode("utf-8","replace")
    needed=[string_at(value) for value in tags.get(1,[])]
    symbol_count=0
    if 4 in tags:
        _,symbol_count=struct.unpack_from("<II",data,file_offset(tags[4][0]))
    relocation_symbols=[]
    for address_tag,size_tag in ((17,18),(23,2)):
        if address_tag not in tags: continue
        offset=file_offset(tags[address_tag][0]); size=tags.get(size_tag,[0])[0]
        for item in range(offset,offset+size,8):
            _,info=struct.unpack_from("<II",data,item); relocation_symbols.append(info>>8)
    if relocation_symbols: symbol_count=max(symbol_count,max(relocation_symbols)+1)
    imports=[]
    if 6 in tags:
        symtab=file_offset(tags[6][0]); syment=tags.get(11,[16])[0]
        for index in range(symbol_count):
            name,_,_,_,_,section=struct.unpack_from("<IIIBBH",data,symtab+index*syment)
            if section==0 and name: imports.append(string_at(name))
    return {"needed":sorted(set(needed)),"imports":sorted(set(imports))}


def scan(sample: dict, root: pathlib.Path) -> dict:
    apk = root / "samples" / f"{sample['id']}.apk"
    with zipfile.ZipFile(apk) as archive:
        names = archive.namelist()
        arm = [name for name in names if name.startswith(("lib/armeabi-v7a/", "lib/armeabi/")) and name.endswith(".so")]
        libraries = []
        needed: set[str] = set()
        imports: set[str] = set()
        for name in arm:
            elf = inspect_elf(archive.read(name))
            libraries.append({"member": name, **elf})
            needed.update(elf["needed"]); imports.update(elf["imports"])
        has_dex = any(name == "classes.dex" or re.fullmatch(r"classes\d+\.dex", name) for name in names)
    mode = "mixed" if arm and has_dex else "native" if arm else "dex" if has_dex else "resources"
    cluster_material = [mode, *sorted(needed)]
    return {
        **sample,
        "apk_path": str(apk),
        "mode": mode,
        "has_dex": has_dex,
        "armv7_libraries": libraries,
        "needed": sorted(needed),
        "imports": sorted(imports),
        "static_cluster": "|".join(cluster_material),
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--resolved", default="samples/resolved.json")
    parser.add_argument("--output", default="samples/static-scan.json")
    parser.add_argument("--plan", default="App/Resources/batch-plan.json")
    parser.add_argument("--shard-index", type=int, default=0)
    parser.add_argument("--shard-count", type=int, default=1)
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    samples = json.loads((root / args.resolved).read_text(encoding="utf-8"))["samples"]
    selected = [sample for index, sample in enumerate(samples) if index % args.shard_count == args.shard_index]
    records = [scan(sample, root) for sample in selected]
    (root / args.output).parent.mkdir(parents=True, exist_ok=True)
    (root / args.output).write_text(json.dumps({"samples": records}, indent=2), encoding="utf-8")
    plan = {"samples": [{
        "id": item["id"], "package": item["package"], "resource": item["resource"],
        "profile": item["profile"], "has_dex": item["has_dex"],
        "armv7_libraries": [lib["member"] for lib in item["armv7_libraries"]],
        "static_cluster": item["static_cluster"],
    } for item in records]}
    (root / args.plan).write_text(json.dumps(plan, indent=2), encoding="utf-8")


if __name__ == "__main__":
    main()
