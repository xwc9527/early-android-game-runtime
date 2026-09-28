#!/usr/bin/env python3
"""Discover ARM code from ELF metadata and static control flow only."""

import argparse
from collections import Counter, deque
import json
from pathlib import Path
import time

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
from capstone.arm import ARM_OP_IMM
from capstone import CS_GRP_CALL, CS_GRP_JUMP, CS_GRP_RET

from offline_elf import Elf32Arm
from translate import decode, is_terminal


def scan(image: Elf32Arm, policy: str):
    decoder = {False: Cs(CS_ARCH_ARM, CS_MODE_ARM),
               True: Cs(CS_ARCH_ARM, CS_MODE_THUMB)}
    for item in decoder.values():
        item.detail = True
    seeds = {(item.address, item.thumb) for item in image.init_array_entries()}
    seeds.update((item.address, item.thumb) for item in image.symbols()
                 if item.name in {"JNI_OnLoad", "ANativeActivity_onCreate"})
    if policy in {"exports", "all-exidx"}:
        seeds.update((item.address, item.thumb) for item in image.symbols())
    if policy == "all-exidx":
        seeds.update((address, True) for address in image.exidx_starts())
        for section in image.executable:
            if section.name == ".plt":
                seeds.add((section.address, False))
    queue = deque(sorted(seeds))
    seen = set()
    rows = {}
    starts = set(seeds)
    reasons = Counter()
    while queue:
        address, thumb = queue.popleft()
        if (address, thumb) in seen:
            continue
        if (address, not thumb) in seen:
            # The current AOT hash is PC-only. Count this before changing it.
            reasons["dual_mode_conflict"] += 1
            continue
        if image.code_at(address, 2 if thumb else 4) is None:
            reasons["outside_executable"] += 1
            continue
        seen.add((address, thumb))
        data = image.code_at(address, 4) or image.code_at(address, 2)
        instruction = next(decoder[thumb].disasm(data, address, count=1), None)
        if instruction is None:
            reasons["disassembly_stopped"] += 1
            continue
        if thumb and instruction.size == 4:
            raw = (int.from_bytes(instruction.bytes[:2], "little") << 16 |
                   int.from_bytes(instruction.bytes[2:4], "little"))
        else:
            raw = int.from_bytes(instruction.bytes, "little")
        rows[address] = {"pc": address, "insn": raw, "len": instruction.size,
                         "thumb": int(thumb), "cpsr": 0x20 if thumb else 0}
        next_address = address + instruction.size
        groups = set(instruction.groups)
        direct = [operand.imm for operand in instruction.operands if operand.type == ARM_OP_IMM]
        mnemonic = instruction.mnemonic.split(".")[0]
        is_call = CS_GRP_CALL in groups or mnemonic in {"bl", "blx"}
        is_jump = CS_GRP_JUMP in groups or mnemonic in {"cbz", "cbnz"}
        is_return = CS_GRP_RET in groups or mnemonic in {"bx", "pop"} and "pc" in instruction.op_str
        if is_call or is_jump:
            if direct:
                target = direct[-1] & ~1
                target_thumb = (not thumb if mnemonic == "blx" else thumb)
                if image.code_at(target, 2 if target_thumb else 4) is not None:
                    starts.add((target, target_thumb))
                    queue.append((target, target_thumb))
                else:
                    reasons["direct_target_outside_image"] += 1
            else:
                reasons["indirect_target"] += 1
            if is_call or mnemonic not in {"b", "b.w"}:
                starts.add((next_address, thumb))
                queue.append((next_address, thumb))
            continue
        try:
            operation = decode(address, raw, instruction.size, thumb)
        except ValueError:
            operation = None
        if is_return or operation is not None and is_terminal(operation):
            continue
        queue.append((next_address, thumb))
    return rows, starts, seeds, reasons


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--elf", required=True)
    parser.add_argument("--policy", choices=("abi", "exports", "all-exidx"), required=True)
    parser.add_argument("--out", required=True)
    args = parser.parse_args()
    started = time.perf_counter()
    image = Elf32Arm(args.elf)
    rows, starts, seeds, reasons = scan(image, args.policy)
    supported = Counter()
    unsupported = Counter()
    for row in rows.values():
        try:
            op = decode(row["pc"], row["insn"], row["len"], row["thumb"])
        except ValueError:
            unsupported["decoder_reject"] += 1
        else:
            supported[op[0]] += 1
    result = {
        "schema": "agr.offline-elf-scan.v1",
        "elf_sha256": image.sha256,
        "elf_bytes": len(image.data),
        "policy": args.policy,
        "input_types": ["ELF32 ARM executable sections", "ELF dynamic symbols", "ELF init/fini arrays",
                        "ELF EHABI exidx"],
        "trace_used_for_generation": False,
        "seed_count": len(seeds),
        "discovered_pc_modes": len(rows),
        "static_block_entries": len(starts),
        "supported_operation_counts": dict(sorted(supported.items())),
        "unsupported_discovered": dict(sorted(unsupported.items())),
        "discovery_reasons": dict(sorted(reasons.items())),
        "scan_wall_seconds": time.perf_counter() - started,
    }
    Path(args.out).write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
