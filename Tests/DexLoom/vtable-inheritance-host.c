#include "dx_vm.h"
#include "dx_dex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int g_failures = 0;

static void expect_int(const char *name, int32_t actual, int32_t expected) {
    if (actual == expected) {
        printf("PASS %s = %d\n", name, actual);
        return;
    }
    printf("FAIL %s = %d expected %d\n", name, actual, expected);
    g_failures++;
}

static DxMethod *static_method(DxClass *cls, const char *name) {
    if (!cls) return NULL;
    for (uint32_t i = 0; i < cls->direct_method_count; i++) {
        if (cls->direct_methods[i].name && strcmp(cls->direct_methods[i].name, name) == 0)
            return &cls->direct_methods[i];
    }
    return NULL;
}

static int32_t call_int(DxVM *vm, DxMethod *method, DxObject *receiver) {
    DxValue arg = DX_OBJ_VALUE(receiver);
    DxValue result;
    memset(&result, 0, sizeof(result));
    DxResult rc = dx_vm_execute_method(vm, method, &arg, 1, &result);
    if (rc != DX_OK || result.tag != DX_VAL_INT) {
        printf("FAIL execute %s rc=%d tag=%d\n",
               method && method->name ? method->name : "?", (int)rc, (int)result.tag);
        g_failures++;
        return 0x80000000;
    }
    return result.i;
}

static void reset_hit(DxClass *markers) {
    if (markers && markers->static_fields && markers->static_field_count > 0)
        markers->static_fields[0] = DX_INT_VALUE(0);
}

static int32_t hit_of(DxClass *markers) {
    if (!markers || !markers->static_fields || markers->static_field_count == 0) return -1;
    return markers->static_fields[0].i;
}

int main(int argc, char **argv) {
    const char *path = argc > 1 ? argv[1] : "/tmp/vtable-inheritance.dex";
    FILE *file = fopen(path, "rb");
    if (!file) { perror(path); return 1; }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    uint8_t *bytes = malloc((size_t)size);
    if (!bytes || fread(bytes, 1, (size_t)size, file) != (size_t)size) return 1;
    fclose(file);

    DxDexFile *dex = NULL;
    if (dx_dex_parse(bytes, (uint32_t)size, &dex) != DX_OK) return 1;
    DxVM *vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK || dx_vm_load_dex(vm, dex) != DX_OK) return 1;

    const char *names[] = {
        "Lsynth/Markers;", "Lsynth/ObjChild;", "Lsynth/ObjOver;", "Lsynth/Base;",
        "Lsynth/Kid;", "Lsynth/Worker;", "Lsynth/Probe;"
    };
    DxClass *loaded[7] = {0};
    for (int i = 0; i < 7; i++) {
        if (dx_vm_load_class(vm, names[i], &loaded[i]) != DX_OK || !loaded[i]) {
            fprintf(stderr, "load failed %s\n", names[i]);
            return 1;
        }
    }
    DxClass *markers = loaded[0];
    DxClass *child = loaded[1];
    DxClass *over = loaded[2];
    DxClass *base = loaded[3];
    DxClass *kid = loaded[4];
    DxClass *worker = loaded[5];
    DxClass *probe = loaded[6];
    DxClass *object = dx_vm_find_class(vm, "Ljava/lang/Object;");
    DxClass *thread = dx_vm_find_class(vm, "Ljava/lang/Thread;");
    DxMethod *to_string = dx_vm_find_method(object, "toString", "L");
    DxMethod *hash_code = dx_vm_find_method(object, "hashCode", "I");
    DxMethod *start = dx_vm_find_method(thread, "start", "V");
    DxMethod *child_c = dx_vm_find_method(child, "c", "I");
    DxMethod *cleanup = dx_vm_find_method(worker, "cleanUp", "V");
    if (!to_string || !hash_code || !start || !child_c || !cleanup) return 1;

    printf("Object.vtable_size=%u Thread.vtable_size=%u Thread.start.vtable_idx=%d\n",
           object->vtable_size, thread->vtable_size, start->vtable_idx);
    printf("ObjChild.vtable[toString]=%s ObjChild.vtable[hashCode]=%s ObjChild.vtable[c]=%s\n",
           child->vtable[to_string->vtable_idx]->name,
           child->vtable[hash_code->vtable_idx]->name,
           child->vtable[child_c->vtable_idx]->name);
    printf("Worker.vtable[start]=%s.%s Worker.cleanUp.vtable_idx=%d\n",
           worker->vtable[start->vtable_idx]->declaring_class->descriptor,
           worker->vtable[start->vtable_idx]->name,
           cleanup->vtable_idx);

    DxObject *child_obj = dx_vm_alloc_object(vm, child);
    DxObject *over_obj = dx_vm_alloc_object(vm, over);
    DxObject *base_obj = dx_vm_alloc_object(vm, base);
    DxObject *kid_obj = dx_vm_alloc_object(vm, kid);
    DxObject *worker_obj = dx_vm_alloc_object(vm, worker);
    if (!child_obj || !over_obj || !base_obj || !kid_obj || !worker_obj) return 1;

    reset_hit(markers);
    expect_int("framework toString does not enter guest c",
               call_int(vm, static_method(probe, "probeToString"), child_obj) == 1 ? hit_of(markers) : -2,
               0);
    reset_hit(markers);
    int32_t child_hash = call_int(vm, static_method(probe, "probeHash"), child_obj);
    expect_int("framework hashCode is not the guest override", child_hash == 0x13572468, 0);
    expect_int("guest new virtual c", call_int(vm, static_method(probe, "probeC"), child_obj), 5);
    expect_int("guest override of framework hashCode",
               call_int(vm, static_method(probe, "probeOverHash"), over_obj), 0x13572468);
    reset_hit(markers);
    expect_int("framework toString does not enter override hashCode",
               call_int(vm, static_method(probe, "probeOverToString"), over_obj) == 1 ? hit_of(markers) : -2,
               0);
    expect_int("guest new virtual beside override",
               call_int(vm, static_method(probe, "probeOverC"), over_obj), 6);
    expect_int("guest superclass virtual b",
               call_int(vm, static_method(probe, "probeBaseB"), base_obj), 2);
    expect_int("guest inherited virtual a",
               call_int(vm, static_method(probe, "probeKidA"), kid_obj), 1);
    expect_int("guest override of guest virtual b",
               call_int(vm, static_method(probe, "probeKidB"), kid_obj), 8);
    expect_int("guest new virtual c on subclass",
               call_int(vm, static_method(probe, "probeKidC"), kid_obj), 3);
    reset_hit(markers);
    expect_int("Thread.start on guest subclass runs run, not slot 0",
               call_int(vm, static_method(probe, "probeStart"), worker_obj), 11);

    if (g_failures) {
        printf("vtable inheritance contract: FAIL (%d)\n", g_failures);
        return 1;
    }
    printf("vtable inheritance contract: PASS\n");
    return 0;
}
