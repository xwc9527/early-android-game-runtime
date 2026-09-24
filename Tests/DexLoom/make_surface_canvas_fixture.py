#!/usr/bin/env python3
"""DEX fixture for SurfaceHolder.lockCanvas / unlockCanvasAndPost.

The harness does not call lockCanvas. surfaceCreated on the child SurfaceView
performs the lock, same-context reentry, cross-thread exclusion, unlock, and
relock. A later activity method checks the failure returns.
"""

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


def utf16(text: str) -> bytes:
    return struct.pack("<H", len(text)) + text.encode("utf-16le")


def axml(root_name: str, child_name: str, child_id: int, width: int, height: int) -> bytes:
    strings = ["layout_width", "layout_height", "id", root_name, child_name]
    pool = bytearray()
    offsets = []
    for item in strings:
        offsets.append(len(pool))
        pool.extend(utf16(item))
    align(pool)
    string_count = len(strings)
    strings_start = 28 + 4 * string_count
    chunk = bytearray()
    chunk.extend(struct.pack("<HHIIIIII", 0x0001, 28, strings_start + len(pool),
                             string_count, 0, 0, strings_start, 0))
    for offset in offsets:
        chunk.extend(struct.pack("<I", offset))
    chunk.extend(pool)

    def start_tag(name_index: int, attrs: list) -> bytes:
        body = struct.pack("<IIHHHHHH", 0xFFFFFFFF, name_index, 20, 20, len(attrs), 0, 0, 0)
        raw = bytearray(body)
        for name, value_type, value in attrs:
            raw.extend(struct.pack("<III", 0xFFFFFFFF, name, 0xFFFFFFFF))
            raw.extend(struct.pack("<HBBI", 8, 0, value_type, value & 0xFFFFFFFF))
        header_size = 16
        return (struct.pack("<HHII", 0x0102, header_size, header_size + len(raw), 0) +
                struct.pack("<I", 0xFFFFFFFF) + bytes(raw))

    def end_tag(name_index: int) -> bytes:
        return struct.pack("<HHIIIII", 0x0103, 16, 24, 0, 0xFFFFFFFF, 0xFFFFFFFF, name_index)

    match = 0xFFFFFFFF
    elements = start_tag(3, [(0, 0x10, match), (1, 0x10, match)])
    elements += start_tag(4, [(0, 0x10, width & 0xFFFFFFFF), (1, 0x10, height & 0xFFFFFFFF), (2, 0x01, child_id)])
    elements += end_tag(4)
    elements += end_tag(3)
    return struct.pack("<II", 0x00080003, 8 + len(chunk) + len(elements)) + bytes(chunk) + elements


class Asm:
    def __init__(self):
        self.words = []
        self.labels = {}
        self.patches = []

    def label(self, name: str) -> None:
        self.labels[name] = len(self.words)

    def emit(self, *words: int) -> None:
        self.words.extend(words)

    def const4(self, reg: int, value: int) -> None:
        self.words.append(0x12 | ((reg & 0xF) << 8) | ((value & 0xF) << 12))

    def const16(self, reg: int, value: int) -> None:
        self.words.append(0x13 | ((reg & 0xFF) << 8))
        self.words.append(value & 0xFFFF)

    def branch(self, opcode: int, reg: int, name: str) -> None:
        at = len(self.words)
        self.words.append(opcode | ((reg & 0xFF) << 8))
        self.words.append(0)
        self.patches.append((at, name))

    def goto(self, name: str) -> None:
        at = len(self.words)
        self.words.append(0x29)
        self.words.append(0)
        self.patches.append((at, name))

    def pc(self) -> int:
        return len(self.words)

    def finish(self) -> list:
        for at, name in self.patches:
            offset = self.labels[name] - at
            if offset < -32768 or offset > 32767:
                raise SystemExit(f"branch {name} offset {offset}")
            self.words[at + 1] = offset & 0xFFFF
        return self.words


def build_dex() -> bytes:
    strings = sorted({
        "<init>", "CanvasActivity.java", "CanvasApplication.java", "CanvasView.java",
        "CanvasWaiter.java", "I", "L", "LL", "Landroid/app/Activity;",
        "Landroid/app/Application;", "Landroid/content/Context;", "Landroid/graphics/Canvas;",
        "Landroid/graphics/Rect;", "Landroid/os/Bundle;", "Landroid/util/AttributeSet;",
        "Landroid/view/SurfaceHolder;", "Landroid/view/SurfaceView;", "J", "Ljava/lang/Object;",
        "Ljava/lang/Thread;", "Ltest/CanvasActivity;", "Ltest/CanvasApplication;",
        "Ltest/CanvasView;", "Ltest/CanvasWaiter;", "V", "VI", "VJ", "VL", "VLIII", "VLL",
        "_format", "_generation", "_height", "_locked", "_rowBytes", "_width", "acquired",
        "addCallback", "canvasFormat", "canvasGeneration", "canvasHeight", "canvasLocked",
        "canvasObj", "canvasRowBytes", "canvasWidth", "changed", "getHolder", "holder",
        "join", "lockCanvas", "lockOk", "notLocked", "onCreate", "probeFailures",
        "reentryNull", "relockOk", "run", "sleep", "start", "surfaceChanged",
        "surfaceCreated", "unlockCanvasAndPost", "waiter", "waiterBlocked", "waiting",
        "wrongCanvas",
    })
    sidx = {item: index for index, item in enumerate(strings)}
    types = sorted({item for item in strings if item in {"I", "J", "V"} or item.startswith("L")},
                   key=lambda item: sidx[item])
    tidx = {item: index for index, item in enumerate(types)}
    protos = [
        ("V", "V", ()),
        ("VL", "V", ("Landroid/os/Bundle;",)),
        ("VLL", "V", ("Landroid/content/Context;", "Landroid/util/AttributeSet;")),
        ("VL", "V", ("Landroid/view/SurfaceHolder;",)),
        ("L", "Landroid/view/SurfaceHolder;", ()),
        ("LL", "Landroid/graphics/Canvas;", ("Landroid/graphics/Rect;",)),
        ("L", "Landroid/graphics/Canvas;", ()),
        ("VL", "V", ("Landroid/graphics/Canvas;",)),
        ("VLIII", "V", ("Landroid/view/SurfaceHolder;", "I", "I", "I")),
        ("VJ", "V", ("J",)),
        ("I", "I", ()),
    ]
    proto_index = {proto: index for index, proto in enumerate(protos)}

    int_names = [
        "acquired", "canvasFormat", "canvasGeneration", "canvasHeight", "canvasLocked",
        "canvasRowBytes", "canvasWidth", "changed", "lockOk", "notLocked", "reentryNull",
        "relockOk", "waiterBlocked", "waiting", "wrongCanvas",
    ]
    fields = [("Ltest/CanvasView;", "I", name) for name in int_names]
    fields.append(("Ltest/CanvasView;", "Landroid/graphics/Canvas;", "canvasObj"))
    fields.append(("Ltest/CanvasView;", "Landroid/view/SurfaceHolder;", "holder"))
    fields.append(("Ltest/CanvasView;", "Ljava/lang/Thread;", "waiter"))
    canvas_fields = [
        ("Landroid/graphics/Canvas;", "I", "_width"),
        ("Landroid/graphics/Canvas;", "I", "_height"),
        ("Landroid/graphics/Canvas;", "I", "_rowBytes"),
        ("Landroid/graphics/Canvas;", "I", "_generation"),
        ("Landroid/graphics/Canvas;", "I", "_format"),
        ("Landroid/graphics/Canvas;", "I", "_locked"),
    ]
    fields.extend(canvas_fields)
    fields = sorted(fields, key=lambda field: (tidx[field[0]], sidx[field[2]], tidx[field[1]]))
    fidx = {field: index for index, field in enumerate(fields)}

    def method(owner, proto, name):
        return (owner, proto, name)

    methods = [
        method("Landroid/app/Activity;", protos[0], "<init>"),
        method("Landroid/app/Activity;", protos[1], "onCreate"),
        method("Landroid/app/Application;", protos[0], "<init>"),
        method("Landroid/graphics/Canvas;", protos[0], "<init>"),
        method("Landroid/view/SurfaceHolder;", protos[6], "lockCanvas"),
        method("Landroid/view/SurfaceHolder;", protos[5], "lockCanvas"),
        method("Landroid/view/SurfaceHolder;", protos[3], "addCallback"),
        method("Landroid/view/SurfaceHolder;", protos[7], "unlockCanvasAndPost"),
        method("Landroid/view/SurfaceView;", protos[2], "<init>"),
        method("Landroid/view/SurfaceView;", protos[4], "getHolder"),
        method("Ljava/lang/Object;", protos[0], "<init>"),
        method("Ljava/lang/Thread;", protos[0], "<init>"),
        method("Ljava/lang/Thread;", protos[0], "join"),
        method("Ljava/lang/Thread;", protos[9], "sleep"),
        method("Ljava/lang/Thread;", protos[0], "start"),
        method("Ltest/CanvasActivity;", protos[0], "<init>"),
        method("Ltest/CanvasActivity;", protos[1], "onCreate"),
        method("Ltest/CanvasActivity;", protos[10], "probeFailures"),
        method("Ltest/CanvasApplication;", protos[0], "<init>"),
        method("Ltest/CanvasApplication;", protos[0], "onCreate"),
        method("Ltest/CanvasView;", protos[2], "<init>"),
        method("Ltest/CanvasView;", protos[8], "surfaceChanged"),
        method("Ltest/CanvasView;", protos[3], "surfaceCreated"),
        method("Ltest/CanvasWaiter;", protos[0], "<init>"),
        method("Ltest/CanvasWaiter;", protos[0], "run"),
    ]
    methods = sorted(methods, key=lambda item: (tidx[item[0]], sidx[item[2]], proto_index[item[1]]))
    midx = {item: index for index, item in enumerate(methods)}

    def invoke(opcode, owner, proto, name, regs):
        count = len(regs)
        encoded = sum((reg & 0xF) << (index * 4) for index, reg in enumerate(regs[:4]))
        fifth = regs[4] if count == 5 else 0
        word0 = opcode | (count << 12) | ((fifth & 0xF) << 8)
        return [word0, midx[method(owner, proto, name)], encoded]

    def field_ref(name, opcode):
        if opcode in (0x60, 0x67):
            typ = "I"
        else:
            typ = {
                "canvasObj": "Landroid/graphics/Canvas;",
                "holder": "Landroid/view/SurfaceHolder;",
                "waiter": "Ljava/lang/Thread;",
            }[name]
        return [opcode | ((0) << 8), fidx[("Ltest/CanvasView;", typ, name)]]

    def sput(reg, name, opcode=0x67):
        words = field_ref(name, opcode)
        words[0] = opcode | ((reg & 0xFF) << 8)
        return words

    def sget(reg, name, opcode=0x60):
        return sput(reg, name, opcode)

    def iget(dst, obj, name):
        return [0x52 | ((dst & 0xF) << 8) | ((obj & 0xF) << 12),
                fidx[("Landroid/graphics/Canvas;", "I", name)]]

    def move_result_object(reg):
        return [0x0C | ((reg & 0xFF) << 8)]

    def new_instance(reg, desc):
        return [0x22 | ((reg & 0xFF) << 8), tidx[desc]]

    def ret_void():
        return [0x000E]

    def ret_int(reg):
        return [0x0F | ((reg & 0xFF) << 8)]

    view = "Ltest/CanvasView;"
    created = Asm()
    created.const4(0, 0)
    created.emit(*invoke(0x72, "Landroid/view/SurfaceHolder;", protos[5], "lockCanvas", [9, 0]))
    created.emit(*move_result_object(1))
    created.branch(0x38, 1, "fail")
    for reg_name, field_name in (
        ("_width", "canvasWidth"), ("_height", "canvasHeight"),
        ("_generation", "canvasGeneration"), ("_rowBytes", "canvasRowBytes"),
        ("_format", "canvasFormat"), ("_locked", "canvasLocked"),
    ):
        created.emit(*iget(2, 1, reg_name))
        created.emit(*sput(2, field_name))
    created.emit(*sput(1, "canvasObj", 0x69))
    created.const4(0, 0)
    created.emit(*invoke(0x72, "Landroid/view/SurfaceHolder;", protos[5], "lockCanvas", [9, 0]))
    created.emit(*move_result_object(2))
    created.branch(0x39, 2, "after_reentry")
    created.const4(3, 1)
    created.emit(*sput(3, "reentryNull"))
    created.label("after_reentry")
    created.emit(*sput(9, "holder", 0x69))
    created.emit(*new_instance(3, "Ltest/CanvasWaiter;"))
    created.emit(*invoke(0x70, "Ltest/CanvasWaiter;", protos[0], "<init>", [3]))
    created.emit(*invoke(0x6E, "Ljava/lang/Thread;", protos[0], "start", [3]))
    created.emit(*sput(3, "waiter", 0x69))
    created.const16(0, 80)
    created.emit(0x0281)
    created.emit(*invoke(0x71, "Ljava/lang/Thread;", protos[9], "sleep", [2, 3]))
    created.emit(*sget(4, "waiting", 0x60))
    created.branch(0x38, 4, "fail")
    created.emit(*sget(4, "acquired", 0x60))
    created.branch(0x39, 4, "fail")
    created.const4(4, 1)
    created.emit(*sput(4, "waiterBlocked"))
    created.emit(*invoke(0x72, "Landroid/view/SurfaceHolder;", protos[7], "unlockCanvasAndPost", [9, 1]))
    created.emit(*sget(3, "waiter", 0x62))
    created.emit(*invoke(0x6E, "Ljava/lang/Thread;", protos[0], "join", [3]))
    created.emit(*sget(4, "acquired", 0x60))
    created.branch(0x38, 4, "fail")
    created.const4(4, 1)
    created.emit(*sput(4, "lockOk"))
    created.emit(*invoke(0x72, "Landroid/view/SurfaceHolder;", protos[6], "lockCanvas", [9]))
    created.emit(*move_result_object(1))
    created.branch(0x38, 1, "fail")
    created.emit(*invoke(0x72, "Landroid/view/SurfaceHolder;", protos[7], "unlockCanvasAndPost", [9, 1]))
    created.const4(4, 1)
    created.emit(*sput(4, "relockOk"))
    created.label("fail")
    created.emit(*ret_void())
    created_words = created.finish()

    changed = [
        *sget(0, "changed", 0x60),
        0x00D8, 0x0100,
        *sput(0, "changed"),
        0x000E,
    ]

    waiter = Asm()
    waiter.const4(0, 1)
    waiter.emit(*sput(0, "waiting"))
    waiter.emit(*sget(1, "holder", 0x62))
    waiter.const4(0, 0)
    waiter.emit(*invoke(0x72, "Landroid/view/SurfaceHolder;", protos[5], "lockCanvas", [1, 0]))
    waiter.emit(*move_result_object(2))
    waiter.branch(0x38, 2, "done")
    waiter.const4(0, 1)
    waiter.emit(*sput(0, "acquired"))
    waiter.emit(*invoke(0x72, "Landroid/view/SurfaceHolder;", protos[7], "unlockCanvasAndPost", [1, 2]))
    waiter.label("done")
    waiter.emit(*ret_void())
    waiter_words = waiter.finish()

    probe = Asm()
    probe.emit(*sget(1, "holder", 0x62))
    probe.emit(*new_instance(0, "Landroid/graphics/Canvas;"))
    try_wrong = probe.pc()
    probe.emit(*invoke(0x72, "Landroid/view/SurfaceHolder;", protos[7], "unlockCanvasAndPost", [1, 0]))
    try_wrong_end = probe.pc()
    probe.goto("after_wrong")
    probe.label("catch_wrong")
    probe.const4(2, 1)
    probe.emit(*sput(2, "wrongCanvas"))
    probe.label("after_wrong")
    probe.emit(*sget(0, "canvasObj", 0x62))
    try_idle = probe.pc()
    probe.emit(*invoke(0x72, "Landroid/view/SurfaceHolder;", protos[7], "unlockCanvasAndPost", [1, 0]))
    try_idle_end = probe.pc()
    probe.goto("after_idle")
    probe.label("catch_idle")
    probe.const4(2, 1)
    probe.emit(*sput(2, "notLocked"))
    probe.label("after_idle")
    probe.const4(0, 1)
    probe.emit(*ret_int(0))
    probe_words = probe.finish()
    probe_tries = [
        (try_wrong, try_wrong_end - try_wrong, probe.labels["catch_wrong"]),
        (try_idle, try_idle_end - try_idle, probe.labels["catch_idle"]),
    ]

    view_init = (
        invoke(0x70, "Landroid/view/SurfaceView;", protos[2], "<init>", [0, 1, 2]) +
        invoke(0x6E, "Landroid/view/SurfaceView;", protos[4], "getHolder", [0]) +
        move_result_object(1) +
        invoke(0x72, "Landroid/view/SurfaceHolder;", protos[3], "addCallback", [1, 0]) +
        ret_void()
    )
    app_init = invoke(0x70, "Landroid/app/Application;", protos[0], "<init>", [0]) + ret_void()
    app_create = ret_void()
    act_init = invoke(0x70, "Landroid/app/Activity;", protos[0], "<init>", [0]) + ret_void()
    act_create = invoke(0x6F, "Landroid/app/Activity;", protos[1], "onCreate", [0, 1]) + ret_void()
    waiter_init = invoke(0x70, "Ljava/lang/Object;", protos[0], "<init>", [0]) + ret_void()

    codes = {
        method("Ltest/CanvasApplication;", protos[0], "<init>"): (1, 1, 1, app_init, []),
        method("Ltest/CanvasApplication;", protos[0], "onCreate"): (1, 1, 0, app_create, []),
        method("Ltest/CanvasActivity;", protos[0], "<init>"): (1, 1, 1, act_init, []),
        method("Ltest/CanvasActivity;", protos[1], "onCreate"): (2, 2, 2, act_create, []),
        method("Ltest/CanvasActivity;", protos[10], "probeFailures"): (5, 1, 2, probe_words, probe_tries),
        method("Ltest/CanvasView;", protos[2], "<init>"): (3, 3, 3, view_init, []),
        method("Ltest/CanvasView;", protos[3], "surfaceCreated"): (10, 2, 2, created_words, []),
        method("Ltest/CanvasView;", protos[8], "surfaceChanged"): (6, 5, 0, changed, []),
        method("Ltest/CanvasWaiter;", protos[0], "<init>"): (1, 1, 1, waiter_init, []),
        method("Ltest/CanvasWaiter;", protos[0], "run"): (4, 1, 2, waiter_words, []),
    }

    classes = [
        ("Ltest/CanvasApplication;", "Landroid/app/Application;", "CanvasApplication.java"),
        ("Ltest/CanvasActivity;", "Landroid/app/Activity;", "CanvasActivity.java"),
        ("Ltest/CanvasView;", "Landroid/view/SurfaceView;", "CanvasView.java"),
        ("Ltest/CanvasWaiter;", "Ljava/lang/Thread;", "CanvasWaiter.java"),
    ]
    header_size = 0x70
    data_off = (header_size + 4 * len(strings) + 4 * len(types) + 12 * len(protos) +
                8 * len(fields) + 8 * len(methods) + 32 * len(classes))
    data = bytearray(b"\0" * data_off)
    string_offsets = []
    for item in strings:
        string_offsets.append(len(data))
        data.extend(uleb(len(item)))
        data.extend(item.encode("utf-8"))
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

    def add_code(key):
        registers, ins, outs, words, tries = codes[key]
        align(data)
        offset = len(data)
        data.extend(struct.pack("<HHHHI I".replace(" ", ""), registers, ins, outs, len(tries), 0, len(words)))
        data.extend(struct.pack("<" + "H" * len(words), *words))
        if len(words) % 2:
            data.extend(b"\0\0")
        if tries:
            handlers = bytearray()
            items = []
            for start, count, addr in tries:
                handler_off = len(handlers)
                handlers.append(0)
                handlers.extend(uleb(addr))
                items.append((start, count, handler_off))
            for start, count, handler_off in items:
                data.extend(struct.pack("<IHH", start, count, handler_off))
            data.extend(handlers)
            align(data)
        return offset

    code_offsets = {key: add_code(key) for key in codes}

    def class_data(static_fields, direct, virtual):
        offset = len(data)
        data.extend(uleb(len(static_fields)))
        data.extend(uleb(0))
        data.extend(uleb(len(direct)))
        data.extend(uleb(len(virtual)))
        previous = 0
        ordered_fields = sorted(static_fields, key=lambda item: fidx[item])
        for index, field in enumerate(ordered_fields):
            current = fidx[field]
            data.extend(uleb(current if index == 0 else current - previous))
            data.extend(uleb(0x9))
            previous = current
        for group in (direct, virtual):
            previous = 0
            ordered = sorted(group, key=lambda item: midx[item])
            for index, item in enumerate(ordered):
                current = midx[item]
                data.extend(uleb(current if index == 0 else current - previous))
                flags = 0x10001 if item[2] == "<init>" else 0x1
                data.extend(uleb(flags))
                data.extend(uleb(code_offsets[item]))
                previous = current
        return offset

    view_fields = [field for field in fields if field[0] == view]
    class_data_offsets = {
        "Ltest/CanvasApplication;": class_data([], [
            method("Ltest/CanvasApplication;", protos[0], "<init>")
        ], [
            method("Ltest/CanvasApplication;", protos[0], "onCreate")
        ]),
        "Ltest/CanvasActivity;": class_data([], [
            method("Ltest/CanvasActivity;", protos[0], "<init>")
        ], [
            method("Ltest/CanvasActivity;", protos[1], "onCreate"),
            method("Ltest/CanvasActivity;", protos[10], "probeFailures"),
        ]),
        "Ltest/CanvasView;": class_data(view_fields, [
            method("Ltest/CanvasView;", protos[2], "<init>")
        ], [
            method("Ltest/CanvasView;", protos[8], "surfaceChanged"),
            method("Ltest/CanvasView;", protos[3], "surfaceCreated"),
        ]),
        "Ltest/CanvasWaiter;": class_data([], [
            method("Ltest/CanvasWaiter;", protos[0], "<init>")
        ], [
            method("Ltest/CanvasWaiter;", protos[0], "run")
        ]),
    }
    string_ids_off = header_size
    type_ids_off = string_ids_off + 4 * len(strings)
    proto_ids_off = type_ids_off + 4 * len(types)
    field_ids_off = proto_ids_off + 12 * len(protos)
    method_ids_off = field_ids_off + 8 * len(fields)
    class_defs_off = method_ids_off + 8 * len(methods)
    for index, offset in enumerate(string_offsets):
        struct.pack_into("<I", data, string_ids_off + index * 4, offset)
    for index, name in enumerate(types):
        struct.pack_into("<I", data, type_ids_off + index * 4, sidx[name])
    for index, (shorty, ret, _params) in enumerate(protos):
        struct.pack_into("<III", data, proto_ids_off + index * 12,
                         sidx[shorty], tidx[ret], param_offs.get(_params, 0))
    for index, (owner, typ, name) in enumerate(fields):
        struct.pack_into("<HHI", data, field_ids_off + index * 8, tidx[owner], tidx[typ], sidx[name])
    for index, (owner, proto, name) in enumerate(methods):
        struct.pack_into("<HHI", data, method_ids_off + index * 8,
                         tidx[owner], proto_index[proto], sidx[name])
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
    parser.add_argument("dex_output", type=pathlib.Path)
    parser.add_argument("layout_dir", type=pathlib.Path)
    args = parser.parse_args()
    args.dex_output.parent.mkdir(parents=True, exist_ok=True)
    args.layout_dir.mkdir(parents=True, exist_ok=True)
    args.dex_output.write_bytes(build_dex())
    layout = axml("FrameLayout", "test.CanvasView", 0x7F060020, 0xFFFFFFFF, 0xFFFFFFFF)
    (args.layout_dir / "canvas.xml").write_bytes(layout)


if __name__ == "__main__":
    main()
