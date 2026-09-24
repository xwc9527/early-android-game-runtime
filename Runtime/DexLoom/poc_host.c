#include "dx_vm.h"
#include "dx_dex.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

typedef int32_t (*PocGuestFn)(void *vm, int32_t value, void *str, void *obj, int which);
static PocGuestFn g_guest_fn;

static DxResult native_roundtrip(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t n) {
    if (!g_guest_fn || n != 3 || args[0].tag != DX_VAL_INT ||
        args[1].tag != DX_VAL_OBJ || args[2].tag != DX_VAL_OBJ) return DX_ERR_INVALID_FORMAT;
    frame->result = DX_INT_VALUE(g_guest_fn(vm, args[0].i, args[1].obj, args[2].obj, 0));
    frame->has_result = true;
    return DX_OK;
}

static DxResult native_use_global(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t n) {
    if (!g_guest_fn || n != 1 || args[0].tag != DX_VAL_INT) return DX_ERR_INVALID_FORMAT;
    frame->result = DX_INT_VALUE(g_guest_fn(vm, args[0].i, NULL, NULL, 1));
    frame->has_result = true;
    return DX_OK;
}

static DxMethod *method(DxVM *vm, const char *name, const char *shorty) {
    DxClass *cls = NULL;
    if (dx_vm_load_class(vm, "Lpoc/Bridge;", &cls) != DX_OK || !cls) return NULL;
    return dx_vm_find_method(cls, name, shorty);
}

EXPORT DxVM *poc_create(const uint8_t *data, uint32_t size) {
    DxDexFile *dex = NULL;
    if (dx_dex_parse(data, size, &dex) != DX_OK) return NULL;
    DxVM *vm = dx_vm_create(NULL);
    if (!vm) { dx_dex_free(dex); return NULL; }
    if (dx_vm_load_dex(vm, dex) != DX_OK || dx_register_java_lang(vm) != DX_OK) return NULL;
    DxClass *cls = NULL;
    if (dx_vm_load_class(vm, "Lpoc/Bridge;", &cls) != DX_OK) return NULL;
    DxMethod *a = dx_vm_find_method(cls, "nativeRoundTrip", "IILL");
    DxMethod *b = dx_vm_find_method(cls, "nativeUseGlobal", "II");
    if (!a || !b) return NULL;
    a->native_fn = native_roundtrip; a->is_native = true;
    b->native_fn = native_use_global; b->is_native = true;
    return vm;
}

EXPORT void poc_set_guest_bridge(PocGuestFn fn) { g_guest_fn = fn; }

EXPORT int32_t poc_run(DxVM *vm, const char *name, int32_t *out) {
    DxMethod *m = method(vm, name, "I");
    if (!m) return DX_ERR_METHOD_NOT_FOUND;
    DxValue result = DX_INT_VALUE(0);
    DxResult r = dx_vm_execute_method(vm, m, NULL, 0, &result);
    if (r == DX_OK && result.tag == DX_VAL_INT) *out = result.i;
    return r;
}

EXPORT int32_t poc_callback(DxVM *vm, int32_t value, DxObject *str, DxObject *obj, int32_t *out) {
    DxMethod *m = method(vm, "callback", "IILL");
    if (!m) return DX_ERR_METHOD_NOT_FOUND;
    DxValue args[3] = { DX_INT_VALUE(value), DX_OBJ_VALUE(str), DX_OBJ_VALUE(obj) };
    DxValue result = DX_INT_VALUE(0);
    DxResult r = dx_vm_execute_method(vm, m, args, 3, &result);
    if (r == DX_OK && result.tag == DX_VAL_INT) *out = result.i;
    return r;
}

EXPORT const char *poc_string(DxObject *obj) { return dx_vm_get_string_value(obj); }

/* A temporary frame exposes bridge-owned global refs as GC roots. */
EXPORT int32_t poc_gc_with_roots(DxVM *vm, DxObject **roots, uint32_t count) {
    DxMethod fake_method;
    DxFrame fake_frame;
    memset(&fake_method, 0, sizeof(fake_method));
    memset(&fake_frame, 0, sizeof(fake_frame));
    fake_method.has_code = true;
    fake_method.code.registers_size = count > DX_MAX_REGISTERS ? DX_MAX_REGISTERS : count;
    fake_frame.method = &fake_method;
    fake_frame.caller = dx_vm_current_exec(vm)->current_frame;
    for (uint32_t i = 0; i < count && i < DX_MAX_REGISTERS; i++) fake_frame.registers[i] = DX_OBJ_VALUE(roots[i]);
    dx_vm_current_exec(vm)->current_frame = &fake_frame;
    DxResult r = dx_vm_gc_collect(vm);
    dx_vm_current_exec(vm)->current_frame = fake_frame.caller;
    return r;
}

EXPORT uint32_t poc_heap_count(DxVM *vm) { return vm ? vm->heap_count : 0; }
