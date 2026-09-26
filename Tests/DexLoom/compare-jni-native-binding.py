#!/usr/bin/env python3
"""Compare pinned API19 CLEAN and AGR RegisterNatives JSON.

Prints MATCH or DIVERGED. This observation is not a governance authority.
"""
import json
import sys


API19_SYMBOL = "dalvik/vm/Jni.cpp RegisterNatives / dvmRegisterJNIMethod"
AGR_FUNCTION = "Runtime/DexLoom/VM/dx_jni.c jni_RegisterNatives"


def load_json(path):
    with open(path, "r", encoding="utf-8") as handle:
        return json.load(handle)


def case_index(document):
    cases = document.get("cases")
    if not isinstance(cases, list):
        raise SystemExit("JSON has no cases array")
    order = []
    found = {}
    for item in cases:
        if not isinstance(item, dict) or "case" not in item:
            raise SystemExit("case entry is missing its name")
        name = item["case"]
        if name in found:
            raise SystemExit("duplicate case %s" % name)
        order.append(name)
        found[name] = item
    return order, found


def main(argv):
    if len(argv) != 3:
        sys.stderr.write("usage: compare-jni-native-binding.py CLEAN.json AGR.json\n")
        return 2
    clean = load_json(argv[1])
    agr = load_json(argv[2])
    if clean == agr:
        print("MATCH")
        return 0
    print("DIVERGED")
    clean_order, clean_cases = case_index(clean)
    agr_order, agr_cases = case_index(agr)
    names = []
    for name in clean_order + agr_order:
        if name not in names:
            names.append(name)
    matched = []
    saw_difference = False
    for name in names:
        left = clean_cases.get(name)
        right = agr_cases.get(name)
        if left == right:
            matched.append(str(name))
            continue
        saw_difference = True
        print("case: %s" % name)
        print("CLEAN observed: %s" % json.dumps(left, sort_keys=True, separators=(",", ":")))
        print("AGR observed: %s" % json.dumps(right, sort_keys=True, separators=(",", ":")))
        print("API19 source symbol: %s" % API19_SYMBOL)
        print("AGR source function: %s" % AGR_FUNCTION)
    if not saw_difference:
        print("structural: documents differ outside per-case equality")
        print("CLEAN observed: %s" % json.dumps(clean, sort_keys=True, separators=(",", ":")))
        print("AGR observed: %s" % json.dumps(agr, sort_keys=True, separators=(",", ":")))
        print("API19 source symbol: %s" % API19_SYMBOL)
        print("AGR source function: %s" % AGR_FUNCTION)
    if matched:
        print("matched: %s" % " ".join(matched))
    return 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
