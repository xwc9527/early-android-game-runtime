#!/usr/bin/env python3
"""DEX fixture for independent java.lang.Thread execution contexts."""

import argparse
import hashlib
import pathlib
import struct
import zlib


def uleb(value: int) -> bytes:
    out = bytearray()
    while True:
        byte = value & 0x7F
        value >>= 7
        out.append(byte | (0x80 if value else 0))
        if not value:
            return bytes(out)


def align(data: bytearray, amount: int = 4) -> None:
    while len(data) % amount:
        data.append(0)


def build() -> bytes:
    strings = sorted({
        "<init>", "Boom.java", "Burner.java", "I", "J", "L", "Locker.java",
        "Lsynth/Boom;", "Lsynth/Burner;", "Lsynth/Locker;", "Lsynth/Markers;",
        "Lsynth/Probe;", "Lsynth/Sleeper;", "Lsynth/Waiter;", "Lsynth/Worker;",
        "Ljava/lang/Object;", "Ljava/lang/Thread;", "Markers.java", "Probe.java",
        "Sleeper.java", "V", "VJ", "VL", "Waiter.java", "Worker.java",
        "acquired", "afterStart", "beforeStart", "burned", "callerRelease",
        "gate", "held", "join", "lock", "probeAsync", "probeRecurse", "probeTwice",
        "recurseOk", "release", "run", "runEntered", "runExited", "sleep",
        "slept", "start",
    })
    sidx = {text: index for index, text in enumerate(strings)}
    types = sorted({text for text in strings if text.startswith("L") or text in {"I", "J", "V"}},
                   key=lambda text: sidx[text])
    tidx = {text: index for index, text in enumerate(types)}
    protos = [
        ("V", "V", ()),
        ("VJ", "V", ("J",)),
        ("VL", "V", ("Ljava/lang/Thread;",)),
    ]
    proto_index = {proto: index for index, proto in enumerate(protos)}

    field_names = [
        "acquired", "afterStart", "beforeStart", "burned", "callerRelease",
        "gate", "held", "lock", "recurseOk", "release", "runEntered", "runExited",
        "slept",
    ]
    fields = [("Lsynth/Markers;", "Ljava/lang/Object;" if name == "lock" else "I", name)
              for name in field_names]
    fidx = {field: index for index, field in enumerate(fields)}

    def method(owner, proto, name):
        return (owner, proto, name)

    thread_classes = ["Boom", "Burner", "Locker", "Sleeper", "Waiter", "Worker"]
    methods = [
        method("Ljava/lang/Object;", protos[0], "<init>"),
        method("Ljava/lang/Thread;", protos[0], "join"),
        method("Ljava/lang/Thread;", protos[1], "sleep"),
        method("Ljava/lang/Thread;", protos[0], "start"),
        method("Lsynth/Probe;", protos[2], "probeAsync"),
        method("Lsynth/Probe;", protos[0], "probeRecurse"),
        method("Lsynth/Probe;", protos[2], "probeTwice"),
    ]
    for name in thread_classes:
        owner = f"Lsynth/{name};"
        methods.append(method(owner, protos[0], "<init>"))
        methods.append(method(owner, protos[0], "run"))
    methods = sorted(methods, key=lambda item: (tidx[item[0]], sidx[item[2]], proto_index[item[1]]))
    midx = {item: index for index, item in enumerate(methods)}

    classes = [
        ("Lsynth/Markers;", "Ljava/lang/Object;", "Markers.java"),
        ("Lsynth/Boom;", "Ljava/lang/Thread;", "Boom.java"),
        ("Lsynth/Burner;", "Ljava/lang/Thread;", "Burner.java"),
        ("Lsynth/Locker;", "Ljava/lang/Thread;", "Locker.java"),
        ("Lsynth/Sleeper;", "Ljava/lang/Thread;", "Sleeper.java"),
        ("Lsynth/Waiter;", "Ljava/lang/Thread;", "Waiter.java"),
        ("Lsynth/Worker;", "Ljava/lang/Thread;", "Worker.java"),
        ("Lsynth/Probe;", "Ljava/lang/Object;", "Probe.java"),
    ]
    header_size = 0x70
    string_ids_off = header_size
    type_ids_off = string_ids_off + 4 * len(strings)
    proto_ids_off = type_ids_off + 4 * len(types)
    field_ids_off = proto_ids_off + 12 * len(protos)
    method_ids_off = field_ids_off + 8 * len(fields)
    class_defs_off = method_ids_off + 8 * len(methods)
    data_off = class_defs_off + 32 * len(classes)
    data = bytearray(b"\0" * data_off)

    string_offsets = []
    for text in strings:
        string_offsets.append(len(data))
        raw = text.encode("utf-8")
        data.extend(uleb(len(text)))
        data.extend(raw)
        data.append(0)
    align(data)

    param_offs = {}
    for proto in protos:
        params = proto[2]
        if not params or params in param_offs:
            continue
        param_offs[params] = len(data)
        data.extend(struct.pack("<I", len(params)))
        for param in params:
            data.extend(struct.pack("<H", tidx[param]))
        align(data)

    code_offsets = {}

    def add_code(key, registers, ins, outs, words):
        align(data)
        code_offsets[key] = len(data)
        data.extend(struct.pack("<HHHHII", registers, ins, outs, 0, 0, len(words)))
        data.extend(struct.pack("<" + "H" * len(words), *words))

    def invoke(opcode, owner, proto, name, regs):
        count = len(regs)
        encoded = sum((reg & 0xF) << (index * 4) for index, reg in enumerate(regs[:4]))
        fifth = regs[4] if count == 5 else 0
        return [opcode | (count << 12) | (fifth << 8), midx[method(owner, proto, name)], encoded]

    def const4(reg, value):
        return [0x12 | ((reg & 0xF) << 8) | ((value & 0xF) << 12)]

    def const16(reg, value):
        return [0x13 | ((reg & 0xFF) << 8), value & 0xFFFF]

    def const32(reg, value):
        value &= 0xFFFFFFFF
        return [0x14 | ((reg & 0xFF) << 8), value & 0xFFFF, (value >> 16) & 0xFFFF]

    def field(name):
        return fidx[("Lsynth/Markers;", "Ljava/lang/Object;" if name == "lock" else "I", name)]

    def sput(reg, name):
        return [0x67 | ((reg & 0xFF) << 8), field(name)]

    def sget(reg, name):
        return [0x60 | ((reg & 0xFF) << 8), field(name)]

    def sget_obj(reg, name):
        return [0x62 | ((reg & 0xFF) << 8), field(name)]

    def monitor(op, reg):
        return [op | ((reg & 0xFF) << 8)]

    obj_init = method("Ljava/lang/Object;", protos[0], "<init>")
    for name in thread_classes:
        init = method(f"Lsynth/{name};", protos[0], "<init>")
        add_code(init, 1, 1, 1, invoke(0x70, *obj_init, [0]) + [0x000E])

    worker_run = [
        *const4(0, 1),
        *sput(0, "runEntered"),
        *sget(0, "gate"),
        0x0039, 3,
        0xFC28,
        *const4(0, 1),
        *sput(0, "runExited"),
        0x000E,
    ]
    add_code(method("Lsynth/Worker;", protos[0], "run"), 2, 1, 0, worker_run)

    boom_run = [
        *const4(0, 1),
        *const4(1, 0),
        0x0093, 0x0100,
        0x000E,
    ]
    add_code(method("Lsynth/Boom;", protos[0], "run"), 3, 1, 0, boom_run)

    burner_run = [
        *const4(0, 0),
        *sput(0, "burned"),
        *const32(1, 150000),
        *sget(0, "burned"),
        0x00D8, 0x0100,
        *sput(0, "burned"),
        0x1034, 0xFFFA,
        0x000E,
    ]
    add_code(method("Lsynth/Burner;", protos[0], "run"), 3, 1, 0, burner_run)

    sleeper_run = [
        *const4(0, 1),
        *sput(0, "runEntered"),
        *const16(0, 150),
        0x0281,
        *invoke(0x71, "Ljava/lang/Thread;", protos[1], "sleep", [2, 3]),
        *const4(0, 1),
        *sput(0, "slept"),
        0x000E,
    ]
    add_code(method("Lsynth/Sleeper;", protos[0], "run"), 5, 1, 2, sleeper_run)

    locker_run = [
        *sget_obj(0, "lock"),
        *monitor(0x1D, 0),
        *const4(1, 1),
        *sput(1, "held"),
        *sget(1, "release"),
        0x0139, 3,
        0xFC28,
        *monitor(0x1E, 0),
        0x000E,
    ]
    add_code(method("Lsynth/Locker;", protos[0], "run"), 3, 1, 0, locker_run)

    waiter_run = [
        *sget_obj(0, "lock"),
        *monitor(0x1D, 0),
        *const4(1, 1),
        *sput(1, "acquired"),
        *monitor(0x1E, 0),
        0x000E,
    ]
    add_code(method("Lsynth/Waiter;", protos[0], "run"), 3, 1, 0, waiter_run)

    # registers=4 ins=1: argument is v3. Spin until the host releases the caller.
    probe_async = [
        *const4(0, 1),
        *sput(0, "beforeStart"),
        *invoke(0x6E, "Ljava/lang/Thread;", protos[0], "start", [3]),
        *sput(0, "afterStart"),
        *sget(0, "callerRelease"),
        0x0039, 3,
        0xFC28,
        0x000E,
    ]
    add_code(method("Lsynth/Probe;", protos[2], "probeAsync"), 4, 1, 1, probe_async)

    probe_twice = [
        *invoke(0x6E, "Ljava/lang/Thread;", protos[0], "start", [3]),
        *invoke(0x6E, "Ljava/lang/Thread;", protos[0], "start", [3]),
        0x000E,
    ]
    add_code(method("Lsynth/Probe;", protos[2], "probeTwice"), 4, 1, 1, probe_twice)

    probe_recurse = [
        *sget_obj(0, "lock"),
        *monitor(0x1D, 0),
        *monitor(0x1D, 0),
        *monitor(0x1E, 0),
        *monitor(0x1E, 0),
        *const4(0, 1),
        *sput(0, "recurseOk"),
        0x000E,
    ]
    add_code(method("Lsynth/Probe;", protos[0], "probeRecurse"), 1, 0, 0, probe_recurse)

    # The first Worker.run add_code is overwritten by the second call above.
    # Drop the unused early registration by keeping only the last code offset.
    class_data_offsets = {}

    def add_class_data(desc, static_fields, direct, virtual):
        class_data_offsets[desc] = len(data)
        data.extend(uleb(len(static_fields)))
        data.extend(uleb(0))
        data.extend(uleb(len(direct)))
        data.extend(uleb(len(virtual)))
        previous = 0
        for index, name in enumerate(static_fields):
            current = field(name)
            data.extend(uleb(current if index == 0 else current - previous))
            data.extend(uleb(0x9))
            previous = current
        for group, default_access in ((direct, 0x9), (virtual, 0x1)):
            previous = 0
            ordered = sorted(group, key=lambda item: midx[item[0]])
            for index, (item, access) in enumerate(ordered):
                current = midx[item]
                data.extend(uleb(current if index == 0 else current - previous))
                data.extend(uleb(access))
                data.extend(uleb(code_offsets[item]))
                previous = current

    add_class_data("Lsynth/Markers;", field_names, [], [])
    for name in thread_classes:
        owner = f"Lsynth/{name};"
        add_class_data(owner, [], [(method(owner, protos[0], "<init>"), 0x10001)],
                       [(method(owner, protos[0], "run"), 0x1)])
    add_class_data("Lsynth/Probe;", [], [
        (method("Lsynth/Probe;", protos[2], "probeAsync"), 0x9),
        (method("Lsynth/Probe;", protos[0], "probeRecurse"), 0x9),
        (method("Lsynth/Probe;", protos[2], "probeTwice"), 0x9),
    ], [])

    for index, offset in enumerate(string_offsets):
        struct.pack_into("<I", data, string_ids_off + index * 4, offset)
    for index, text in enumerate(types):
        struct.pack_into("<I", data, type_ids_off + index * 4, sidx[text])
    for index, (shorty, ret, params) in enumerate(protos):
        struct.pack_into("<III", data, proto_ids_off + index * 12, sidx[shorty], tidx[ret],
                         param_offs.get(params, 0))
    for index, (owner, typ, name) in enumerate(fields):
        struct.pack_into("<HHI", data, field_ids_off + index * 8, tidx[owner], tidx[typ], sidx[name])
    for index, (owner, proto, name) in enumerate(methods):
        struct.pack_into("<HHI", data, method_ids_off + index * 8, tidx[owner], proto_index[proto], sidx[name])
    for index, (desc, sup, source) in enumerate(classes):
        struct.pack_into("<IIIIIIII", data, class_defs_off + index * 32,
                         tidx[desc], 0x1, tidx[sup], 0, sidx[source], 0,
                         class_data_offsets[desc], 0)

    file_size = len(data)
    header = struct.pack("<8sI20s20I", b"dex\n035\0", 0, b"\0" * 20,
                         file_size, header_size, 0x12345678, 0, 0, 0,
                         len(strings), string_ids_off, len(types), type_ids_off,
                         len(protos), proto_ids_off, len(fields), field_ids_off,
                         len(methods), method_ids_off, len(classes), class_defs_off,
                         file_size - data_off, data_off)
    data[:header_size] = header
    data[12:32] = hashlib.sha1(data[32:]).digest()
    struct.pack_into("<I", data, 8, zlib.adler32(data[12:]) & 0xFFFFFFFF)
    return bytes(data)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("output", type=pathlib.Path)
    args = parser.parse_args()
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(build())


if __name__ == "__main__":
    main()
