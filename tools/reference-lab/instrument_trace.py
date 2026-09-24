#!/usr/bin/env python3
"""Apply the minimal API19 Dalvik game-to-boot method observer to TRACE only."""

import argparse
import hashlib
import subprocess
from pathlib import Path

DALVIK_REVISION = "36e356c96640775f0a3f167bd2426ea0f0093b8b"

HOOK = r'''#ifdef AGR_TRACE
        if (curMethod != NULL && curMethod->clazz != NULL &&
                curMethod->clazz->classLoader != NULL &&
                methodToCall != NULL && methodToCall->clazz != NULL &&
                methodToCall->clazz->classLoader == NULL) {
            const DexFile* dexFile = curMethod->clazz->pDvmDex->pDexFile;
            const u1 opcode = INST_INST(FETCH(0));
            const bool indexed = (opcode >= 0x6e && opcode <= 0x72) ||
                    (opcode >= 0x74 && opcode <= 0x78);
            const u4 methodIdx = indexed ? FETCH(1) : 0xffffffffU;
            const DexMethodId* methodId = indexed &&
                    methodIdx < dexFile->pHeader->methodIdsSize ?
                    dexGetMethodId(dexFile, methodIdx) : NULL;
            const char* targetClass = methodId != NULL ?
                    dexStringByTypeIdx(dexFile, methodId->classIdx) :
                    methodToCall->clazz->descriptor;
            const char* targetName = methodId != NULL ?
                    dexStringById(dexFile, methodId->nameIdx) : methodToCall->name;
            DexProto targetDexProto;
            if (methodId != NULL) {
                dexProtoSetFromMethodId(&targetDexProto, dexFile, methodId);
            }
            char* targetProto = methodId != NULL ?
                    dexProtoCopyMethodDescriptor(&targetDexProto) :
                    dexProtoCopyMethodDescriptor(&methodToCall->prototype);
            char* callerProto = dexProtoCopyMethodDescriptor(&curMethod->prototype);
            char* resolvedProto = dexProtoCopyMethodDescriptor(&methodToCall->prototype);
            static volatile int agrTraceSequence = 0;
            const unsigned int sequence = __sync_add_and_fetch(&agrTraceSequence, 1);
            ALOGI("AGRTRACE|v1|%u|%s->%s%s|%u|%u|%u|%s->%s%s|%s->%s%s",
                    sequence, curMethod->clazz->descriptor, curMethod->name,
                    callerProto, (unsigned int)(pc - curMethod->insns),
                    (unsigned int)opcode, (unsigned int)methodIdx,
                    targetClass, targetName, targetProto,
                    methodToCall->clazz->descriptor, methodToCall->name,
                    resolvedProto);
            free(targetProto);
            free(callerProto);
            free(resolvedProto);
        }
#endif
'''


def run(*args, cwd=None):
    return subprocess.check_output(args, cwd=cwd, text=True).strip()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("source_root", type=Path)
    args = parser.parse_args()
    root = args.source_root.resolve()
    if not (root / ".repo").is_dir():
        raise SystemExit("TRACE source must be a repo checkout")
    dalvik = root / "dalvik"
    if run("git", "rev-parse", "HEAD", cwd=dalvik) != DALVIK_REVISION:
        raise SystemExit("Dalvik revision differs from pinned android-4.4.4_r2")
    if run("git", "status", "--porcelain", cwd=dalvik):
        raise SystemExit("Dalvik source must be clean before instrumentation")
    template = dalvik / "vm/mterp/c/gotoTargets.cpp"
    original = template.read_text()
    anchor = "        STUB_HACK(vsrc1 = count; vdst = regs; methodToCall = _methodToCall;);\n"
    if original.count(anchor) != 1:
        raise SystemExit("invokeMethod anchor changed")
    template.write_text(original.replace(anchor, anchor + "\n" + HOOK, 1))
    makefile = dalvik / "vm/Android.mk"
    make_text = makefile.read_text()
    flag_anchor = "LOCAL_MODULE := libdvm\nLOCAL_CFLAGS += $(target_smp_flag)\n"
    if make_text.count(flag_anchor) != 1:
        raise SystemExit("libdvm flag anchor changed")
    makefile.write_text(make_text.replace(
        flag_anchor, flag_anchor + "LOCAL_CFLAGS += -DAGR_TRACE=1\n", 1))
    mterp = dalvik / "vm/mterp"
    run("python2", "gen-mterp.py", "x86", "out", cwd=mterp)
    run("python2", "gen-mterp.py", "portable", "out", cwd=mterp)
    portable_asm = mterp / "out/InterpAsm-portable.S"
    if portable_asm.exists():
        portable_asm.unlink()  # Generator artifact; the portable VM uses C++.
    generated = mterp / "out/InterpC-x86.cpp"
    if "AGRTRACE|v1" not in generated.read_text():
        raise SystemExit("generated x86 interpreter lacks TRACE observer")
    if "AGRTRACE|v1" not in (mterp / "out/InterpC-portable.cpp").read_text():
        raise SystemExit("generated portable interpreter lacks TRACE observer")
    patch = run("git", "diff", "--binary", cwd=dalvik)
    digest = hashlib.sha256((patch + "\n").encode()).hexdigest()
    print("dalvik_diff_sha256=" + digest)
    print(run("git", "status", "--short", cwd=dalvik))


if __name__ == "__main__":
    main()
