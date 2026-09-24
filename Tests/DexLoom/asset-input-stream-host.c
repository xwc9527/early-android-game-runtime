/* API19 AssetManager.open / AssetInputStream byte and lifetime contract.
 * The APK is the unchanged external test input, not a Runtime special case. */
#include "game_dex_runner.h"
#include "dx_vm.h"
#include <GLES2/gl2.h>
#include <stdio.h>
#include <string.h>

void glGenTextures(GLsizei n, GLuint *p) { for (GLsizei i=0;i<n;i++) if(p) p[i]=1; }
void glBindTexture(GLenum a, GLuint b) { (void)a;(void)b; }
void glTexParameteri(GLenum a, GLenum b, GLint c) { (void)a;(void)b;(void)c; }
void glDeleteTextures(GLsizei n, const GLuint *p) { (void)n;(void)p; }

static int failures;
static void check(int value, const char *message) {
    if (!value) { fprintf(stderr, "FAIL asset stream: %s\n", message); failures++; }
}
static DxResult invoke(DxVM *vm, DxClass *cls, const char *name, const char *shorty,
                       DxValue *args, uint32_t count, DxValue *result) {
    DxMethod *method = cls ? dx_vm_find_method(cls, name, shorty) : NULL;
    check(method != NULL, name);
    return method ? dx_vm_execute_method(vm, method, args, count, result) : DX_ERR_INVALID_FORMAT;
}

int main(int argc, char **argv) {
    if (argc != 2) return 2;
    agr_apk_package *package = agr_apk_package_open(argv[1]);
    check(package != NULL, "open APK");
    if (!package) return 1;
    agr_dex_game *game = agr_dex_game_create_from_apk(package);
    check(game != NULL, "create APK VM");
    if (!game) { agr_apk_package_close(package); return 1; }
    DxVM *vm = agr_dex_game_vm(game);
    DxClass *manager_cls = dx_vm_find_class(vm, "Landroid/content/res/AssetManager;");
    DxClass *stream_cls = dx_vm_find_class(vm, "Ljava/io/InputStream;");
    DxObject *manager = dx_vm_alloc_object(vm, manager_cls);
    DxObject *name = dx_vm_create_string(vm, "levels.txt");
    DxValue args[4] = { DX_OBJ_VALUE(manager), DX_OBJ_VALUE(name), DX_NULL_VALUE, DX_NULL_VALUE };
    DxValue result = DX_NULL_VALUE;
    check(invoke(vm, manager_cls, "open", "LL", args, 2, &result) == DX_OK &&
          result.tag == DX_VAL_OBJ && result.obj, "open levels.txt");
    DxObject *stream = result.obj;
    args[0] = DX_OBJ_VALUE(stream);
    check(invoke(vm, stream_cls, "available", "I", args, 1, &result) == DX_OK &&
          result.tag == DX_VAL_INT && result.i == 29099, "initial available bytes");
    DxObject *buffer = dx_vm_alloc_array(vm, 32);
    args[1] = DX_OBJ_VALUE(buffer);
    check(invoke(vm, stream_cls, "read", "IL", args, 2, &result) == DX_OK &&
          result.tag == DX_VAL_INT && result.i == 32, "read byte array");
    check(buffer->array_elements[0].i == '6' && buffer->array_elements[1].i == ' ' &&
          buffer->array_elements[4].i == '6', "original first level prefix");
    check(invoke(vm, stream_cls, "available", "I", args, 1, &result) == DX_OK &&
          result.i == 29067, "available decreases after read");
    args[2] = DX_INT_VALUE(4);
    args[3] = DX_INT_VALUE(3);
    check(invoke(vm, stream_cls, "read", "ILII", args, 4, &result) == DX_OK &&
          result.i == 3, "offset read");
    DxObject *tail = dx_vm_alloc_array(vm, 29064);
    args[1] = DX_OBJ_VALUE(tail);
    check(invoke(vm, stream_cls, "read", "IL", args, 2, &result) == DX_OK &&
          result.i == 29064, "read remaining bytes");
    check(invoke(vm, stream_cls, "available", "I", args, 1, &result) == DX_OK &&
          result.i == 0, "available at EOF");
    check(invoke(vm, stream_cls, "read", "I", args, 1, &result) == DX_OK &&
          result.i == -1, "single-byte EOF");
    check(invoke(vm, stream_cls, "close", "V", args, 1, NULL) == DX_OK,
          "close stream");
    check(invoke(vm, stream_cls, "close", "V", args, 1, NULL) == DX_OK,
          "idempotent close");
    check(invoke(vm, stream_cls, "read", "I", args, 1, &result) == DX_ERR_EXCEPTION,
          "read after close throws");
    agr_dex_game_destroy(game);
    agr_apk_package_close(package);
    if (failures) return 1;
    puts("API19 APK asset InputStream contract PASS");
    return 0;
}
