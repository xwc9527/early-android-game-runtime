/* Phase 3A0: Boot/Application classpath identity. Independent of any game APK. */
#include "dx_vm.h"
#include "dx_dex.h"
#include "dx_log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int g_failures = 0;

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

static DxDexFile *load_dex(const char *path) {
    FILE *file = fopen(path, "rb");
    long size;
    uint8_t *bytes;
    DxDexFile *dex = NULL;
    if (!file) return NULL;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    bytes = (uint8_t *)malloc((size_t)size);
    if (!bytes || fread(bytes, 1, (size_t)size, file) != (size_t)size) {
        fclose(file);
        free(bytes);
        return NULL;
    }
    fclose(file);
    if (dx_dex_parse(bytes, (uint32_t)size, &dex) != DX_OK) {
        free(bytes);
        return NULL;
    }
    return dex;
}

static DxClass *resolve(DxVM *vm, DxClassLoader *loader, const char *descriptor, DxResult *result) {
    DxClass *cls = NULL;
    *result = dx_vm_resolve_class(vm, loader, descriptor, &cls);
    return cls;
}

int main(int argc, char **argv) {
    DxVM *vm;
    DxDexFile *boot_dex;
    DxDexFile *app_dex;
    DxDexFile *dup_dex;
    DxDexFile *left_dex;
    DxDexFile *right_dex;
    DxDexFile *ninth[9];
    DxClassLoader *app;
    DxClassLoader *left;
    DxClassLoader *right;
    DxClass *boot_only;
    DxClass *shared;
    DxClass *app_only;
    DxClass *object_cls;
    DxClass *missing;
    DxClass *dup;
    DxClass *left_foo;
    DxClass *right_foo;
    DxClass *ninth_cls;
    DxResult result;
    int i;
    char path[256];
    alarm(20);
    if (argc < 2) return 2;
    dx_log_set_level(DX_LOG_ERROR);
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK) return 1;
    app = dx_vm_application_loader(vm);
    snprintf(path, sizeof(path), "%s/boot.dex", argv[1]);
    boot_dex = load_dex(path);
    snprintf(path, sizeof(path), "%s/app.dex", argv[1]);
    app_dex = load_dex(path);
    snprintf(path, sizeof(path), "%s/dup.dex", argv[1]);
    dup_dex = load_dex(path);
    snprintf(path, sizeof(path), "%s/left.dex", argv[1]);
    left_dex = load_dex(path);
    snprintf(path, sizeof(path), "%s/right.dex", argv[1]);
    right_dex = load_dex(path);
    expect(boot_dex && app_dex && dup_dex && left_dex && right_dex, "parse classpath fixtures");
    if (g_failures) return 1;
    expect(dx_vm_load_dex_on_loader(vm, dx_vm_boot_loader(vm), boot_dex) == DX_OK, "load boot dex");
    expect(dx_vm_load_dex_on_loader(vm, app, app_dex) == DX_OK, "load application dex");
    expect(dx_vm_load_dex_on_loader(vm, app, dup_dex) == DX_OK, "load duplicate application dex");

    boot_only = resolve(vm, app, "Lboot/Only;", &result);
    expect(result == DX_OK && boot_only && boot_only->defining_loader == dx_vm_boot_loader(vm),
           "boot class beats application class");
    shared = resolve(vm, app, "Lshared/Name;", &result);
    expect(result == DX_OK && shared && shared->defining_loader == dx_vm_boot_loader(vm),
           "parent delegation returns the boot identity");
    app_only = resolve(vm, app, "Lapp/Only;", &result);
    expect(result == DX_OK && app_only && app_only->defining_loader == app,
           "application class is defined by the application loader");
    object_cls = resolve(vm, app, "Ljava/lang/Object;", &result);
    expect(result == DX_OK && object_cls && object_cls->defining_loader == dx_vm_boot_loader(vm),
           "application dex cannot redefine a boot class");
    missing = resolve(vm, app, "Lmissing/Name;", &result);
    expect(result == DX_ERR_CLASS_NOT_FOUND && !missing, "missing class is not found");
    expect(dx_vm_find_class(vm, "Lother/Name;") == NULL, "suffix fallback is not used");
    dup = resolve(vm, app, "Ldup/C;", &result);
    expect(result == DX_OK && dup && dup->defining_loader == app && dup->dex_file == app_dex,
           "duplicate class keeps the first classpath DEX");

    left = dx_vm_create_loader(vm, dx_vm_boot_loader(vm));
    right = dx_vm_create_loader(vm, dx_vm_boot_loader(vm));
    expect(left && right && dx_vm_load_dex_on_loader(vm, left, left_dex) == DX_OK, "left loader");
    expect(dx_vm_load_dex_on_loader(vm, right, right_dex) == DX_OK, "right loader");
    left_foo = resolve(vm, left, "Ltwin/Foo;", &result);
    right_foo = resolve(vm, right, "Ltwin/Foo;", &result);
    expect(left_foo && right_foo && left_foo != right_foo, "same descriptor under different loaders has different identity");
    expect(left_foo->defining_loader == left && right_foo->defining_loader == right, "defining loader is part of class identity");

    for (i = 0; i < 9; i++) {
        snprintf(path, sizeof(path), "%s/n%d.dex", argv[1], i);
        ninth[i] = load_dex(path);
        expect(ninth[i] && dx_vm_load_dex(vm, ninth[i]) == DX_OK, "dynamic classpath entry");
    }
    ninth_cls = resolve(vm, app, "Lninth/C;", &result);
    expect(result == DX_OK && ninth_cls && ninth_cls->defining_loader == app, "classpath accepts more than 8 DEX files");
    expect(vm->dex_count > 8, "DEX count is not capped at 8");
    return g_failures ? 1 : 0;
}
