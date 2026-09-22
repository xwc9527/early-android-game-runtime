/* API19 Canvas.save(int) / clipRect(float x4, Region.Op) / restore.
   The guest surfaceCreated protocol locks and unlocks. This harness then
   calls the public Canvas methods on that locked content Canvas. */
#include "game_dex_runner.h"
#include "dx_vm.h"
#include "dx_log.h"
#include <GLES2/gl2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void glGenTextures(GLsizei n, GLuint *textures) {
    for (GLsizei i = 0; i < n; i++) if (textures) textures[i] = 1;
}
void glBindTexture(GLenum target, GLuint texture) { (void)target; (void)texture; }
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    (void)target; (void)pname; (void)param;
}
void glDeleteTextures(GLsizei n, const GLuint *textures) { (void)n; (void)textures; }

static int g_failures = 0;

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

static uint8_t *read_file(const char *path, uint32_t *size) {
    FILE *file = fopen(path, "rb");
    long length;
    uint8_t *bytes;
    if (!file) return NULL;
    if (fseek(file, 0, SEEK_END) != 0) { fclose(file); return NULL; }
    length = ftell(file);
    if (length <= 0) { fclose(file); return NULL; }
    rewind(file);
    bytes = malloc((size_t)length);
    if (!bytes || fread(bytes, 1, (size_t)length, file) != (size_t)length) {
        free(bytes);
        fclose(file);
        return NULL;
    }
    fclose(file);
    *size = (uint32_t)length;
    return bytes;
}

static DxValue flt(float value) {
    DxValue out;
    memset(&out, 0, sizeof(out));
    out.tag = DX_VAL_FLOAT;
    out.f = value;
    return out;
}

static int call_ok(DxVM *vm, DxMethod *method, DxValue *args, uint32_t argc, DxValue *result) {
    DxResult rc;
    if (result) *result = DX_NULL_VALUE;
    rc = dx_vm_execute_method(vm, method, args, argc, result);
    return rc == DX_OK && dx_vm_current_exec(vm)->pending_exception == NULL;
}

static void clear_exception(DxVM *vm) {
    dx_vm_current_exec(vm)->pending_exception = NULL;
}

static int clip_is(const agr_dex_game *game, int l, int t, int r, int b, int saves) {
    int al = -1, at = -1, ar = -1, ab = -1, count = -1;
    if (agr_dex_game_content_clip(game, &al, &at, &ar, &ab, &count) != 0) return 0;
    return al == l && at == t && ar == r && ab == b && count == saves;
}

static uint32_t pixel_at(const agr_dex_game *game, int x, int y) {
    uint32_t pixel = 0;
    if (agr_dex_game_content_pixel(game, x, y, &pixel) != 0) return 0xffffffffu;
    return pixel;
}

static uint64_t buffer_hash(const agr_dex_game *game) {
    uint64_t hash = 14695981039346656037ull;
    int y, x;
    for (y = 0; y < 480; y++) {
        for (x = 0; x < 320; x++) {
            uint32_t pixel = pixel_at(game, x, y);
            hash ^= pixel;
            hash *= 1099511628211ull;
        }
    }
    return hash;
}

static DxObject *decode_scaled(DxVM *vm, const uint8_t *png, uint32_t png_size) {
    DxClass *factory = dx_vm_find_class(vm, "Landroid/graphics/BitmapFactory;");
    DxClass *bitmap_cls = dx_vm_find_class(vm, "Landroid/graphics/Bitmap;");
    DxMethod *decode = factory ? dx_vm_find_method(factory, "decodeByteArray", "L[BII") : NULL;
    DxMethod *scale = bitmap_cls ? dx_vm_find_method(bitmap_cls, "createScaledBitmap", "LLIIZ") : NULL;
    DxObject *array;
    DxValue args[4];
    DxValue result = DX_NULL_VALUE;
    uint32_t i;
    if (!decode || !scale) return NULL;
    array = dx_vm_alloc_array(vm, png_size);
    if (!array || !array->array_elements) return NULL;
    for (i = 0; i < png_size; i++) array->array_elements[i] = DX_INT_VALUE(png[i]);
    args[0] = DX_OBJ_VALUE(array);
    args[1] = DX_INT_VALUE(0);
    args[2] = DX_INT_VALUE((int32_t)png_size);
    if (!call_ok(vm, decode, args, 3, &result) || result.tag != DX_VAL_OBJ || !result.obj)
        return NULL;
    args[0] = result;
    args[1] = DX_INT_VALUE(48);
    args[2] = DX_INT_VALUE(48);
    args[3] = DX_INT_VALUE(0);
    result = DX_NULL_VALUE;
    if (!call_ok(vm, scale, args, 4, &result) || result.tag != DX_VAL_OBJ) return NULL;
    return result.obj;
}

int main(int argc, char **argv) {
    const char *dex_path = argc > 1 ? argv[1] : "/tmp/surface-canvas.dex";
    const char *layout_path = argc > 2 ? argv[2] : "/tmp/surface-canvas-layouts/canvas.xml";
    const char *png_path = argc > 3 ? argv[3] : "Tests/DexLoom/fixtures/fixture-2x2.png";
    uint32_t dex_size = 0, xml_size = 0, png_size = 0;
    uint8_t *dex = read_file(dex_path, &dex_size);
    uint8_t *xml = read_file(layout_path, &xml_size);
    uint8_t *png = read_file(png_path, &png_size);
    agr_dex_game *game;
    DxVM *vm;
    DxObject *holder;
    DxObject *canvas;
    DxObject *bitmap;
    DxObject *replace;
    DxClass *holder_cls;
    DxClass *canvas_cls;
    DxClass *op_cls;
    DxMethod *lock_method;
    DxMethod *unlock_method;
    DxMethod *save_method;
    DxMethod *clip_method;
    DxMethod *restore_method;
    DxMethod *draw_method;
    DxValue args[6];
    DxValue result;
    DxValue native_int = DX_NULL_VALUE;
    uint32_t before_inside, before_outside, after_inside, after_outside, restored_outside;
    uint64_t hash_before, hash_after;
    int save_count = -1;

    alarm(30);
    dx_log_set_level(DX_LOG_WARN);
    expect(dex && xml && png, "fixture dex, layout, and png");
    if (!dex || !xml || !png) return 1;
    game = agr_dex_game_create_for_launch(
        dex, dex_size, "Ltest/CanvasActivity;", "Ltest/CanvasApplication;", "test.canvas");
    expect(game != NULL, "create game");
    if (!game) return 1;
    expect(agr_dex_game_set_host_display(game, 320, 480) == 0, "host display");
    expect(agr_dex_game_start_activity(game) == 0, "start activity");
    expect(agr_dex_game_provide_layout(game, 0x7f030020, xml, xml_size) == 0, "provide layout");
    expect(agr_dex_game_set_content_layout(game, 0x7f030020) == 0, "set content layout");
    expect(agr_dex_game_choreographer_frame(game) == 0, "frame 1");
    expect(agr_dex_game_choreographer_frame(game) == 0, "frame 2 creates the surface");
    holder = agr_dex_game_content_holder(game);
    vm = agr_dex_game_vm(game);
    holder_cls = dx_vm_find_class(vm, "Landroid/view/SurfaceHolder;");
    canvas_cls = dx_vm_find_class(vm, "Landroid/graphics/Canvas;");
    op_cls = dx_vm_find_class(vm, "Landroid/graphics/Region$Op;");
    lock_method = holder_cls ? dx_vm_find_method(holder_cls, "lockCanvas", "L") : NULL;
    unlock_method = holder_cls ? dx_vm_find_method(holder_cls, "unlockCanvasAndPost", "VL") : NULL;
    save_method = canvas_cls ? dx_vm_find_method(canvas_cls, "save", "II") : NULL;
    clip_method = canvas_cls ? dx_vm_find_method(canvas_cls, "clipRect", "ZFFFFL") : NULL;
    restore_method = canvas_cls ? dx_vm_find_method(canvas_cls, "restore", "V") : NULL;
    draw_method = canvas_cls ? dx_vm_find_method(canvas_cls, "drawBitmap", "VLFFL") : NULL;
    expect(holder && lock_method && unlock_method && save_method && clip_method &&
           restore_method && draw_method && op_cls && op_cls->static_field_count == 1,
           "canvas methods and Region.Op.REPLACE are registered");
    if (g_failures) return 1;
    replace = op_cls->static_fields[0].obj;
    dx_vm_get_field(replace, "nativeInt", &native_int);
    expect(replace && native_int.tag == DX_VAL_INT && native_int.i == 5,
           "sget Region.Op.REPLACE has nativeInt 5");

    args[0] = DX_OBJ_VALUE(holder);
    expect(call_ok(vm, lock_method, args, 1, &result) && result.tag == DX_VAL_OBJ && result.obj,
           "lockCanvas(null) returns the content canvas");
    canvas = result.obj;
    expect(clip_is(game, 0, 0, 320, 480, 1), "base clip is the full content surface");

    bitmap = decode_scaled(vm, png, png_size);
    expect(bitmap != NULL, "scaled fixture bitmap");
    if (!bitmap) return 1;

    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = DX_INT_VALUE(0x02);
    expect(call_ok(vm, save_method, args, 2, &result) && result.tag == DX_VAL_INT && result.i == 1,
           "save(CLIP_SAVE_FLAG) returns 1");
    expect(clip_is(game, 0, 0, 320, 480, 2), "save pushes one level above the base");

    args[1] = flt(8.f);
    args[2] = flt(8.f);
    args[3] = flt(16.f);
    args[4] = flt(16.f);
    args[5] = DX_OBJ_VALUE(replace);
    expect(call_ok(vm, clip_method, args, 6, &result) && result.tag == DX_VAL_INT && result.i == 1,
           "clipRect REPLACE of a smaller rect returns true");
    expect(clip_is(game, 8, 8, 16, 16, 2), "REPLACE replaces the current clip");

    before_inside = pixel_at(game, 10, 10);
    before_outside = pixel_at(game, 0, 0);
    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = DX_OBJ_VALUE(bitmap);
    args[2] = flt(0.f);
    args[3] = flt(0.f);
    args[4] = DX_NULL_VALUE;
    expect(call_ok(vm, draw_method, args, 5, &result), "drawBitmap under the replaced clip");
    after_inside = pixel_at(game, 10, 10);
    after_outside = pixel_at(game, 0, 0);
    expect(after_inside != before_inside, "pixels inside the clip change");
    expect(after_outside == before_outside && pixel_at(game, 20, 20) == before_outside,
           "pixels outside the clip stay unchanged");

    args[0] = DX_OBJ_VALUE(canvas);
    expect(call_ok(vm, restore_method, args, 1, &result), "restore");
    expect(clip_is(game, 0, 0, 320, 480, 1), "restore returns the base clip");
    args[1] = DX_OBJ_VALUE(bitmap);
    args[2] = flt(0.f);
    args[3] = flt(0.f);
    args[4] = DX_NULL_VALUE;
    expect(call_ok(vm, draw_method, args, 5, &result), "drawBitmap after restore");
    restored_outside = pixel_at(game, 0, 0);
    expect(restored_outside != before_outside && pixel_at(game, 20, 20) != before_outside,
           "pixels outside the prior clip can change after restore");

    hash_before = buffer_hash(game);
    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = DX_INT_VALUE(0x02);
    expect(call_ok(vm, save_method, args, 2, &result) && result.i == 1, "save before empty clip");
    args[1] = flt(5.f);
    args[2] = flt(5.f);
    args[3] = flt(5.f);
    args[4] = flt(12.f);
    args[5] = DX_OBJ_VALUE(replace);
    expect(call_ok(vm, clip_method, args, 6, &result) && result.i == 0,
           "empty clipRect returns false");
    expect(clip_is(game, 0, 0, 0, 0, 2), "empty clip stores an empty rectangle");
    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = DX_OBJ_VALUE(bitmap);
    args[2] = flt(0.f);
    args[3] = flt(0.f);
    args[4] = DX_NULL_VALUE;
    expect(call_ok(vm, draw_method, args, 5, &result), "drawBitmap on an empty clip");
    hash_after = buffer_hash(game);
    expect(hash_before == hash_after, "empty clip writes no pixels");
    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = flt(400.f);
    args[2] = flt(400.f);
    args[3] = flt(420.f);
    args[4] = flt(430.f);
    args[5] = DX_OBJ_VALUE(replace);
    expect(call_ok(vm, clip_method, args, 6, &result) && result.i == 0,
           "clipRect that misses the device returns false");
    expect(call_ok(vm, restore_method, (DxValue[]){ DX_OBJ_VALUE(canvas) }, 1, &result),
           "restore after empty clip");

    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = flt(-10.f);
    args[2] = flt(-4.f);
    args[3] = flt(15.f);
    args[4] = flt(25.f);
    args[5] = DX_OBJ_VALUE(replace);
    expect(call_ok(vm, clip_method, args, 6, &result) && result.i == 1 &&
           clip_is(game, 0, 0, 15, 25, 1),
           "REPLACE is constrained to the device origin");
    args[1] = flt(10.5f);
    args[2] = flt(20.5f);
    args[3] = flt(30.5f);
    args[4] = flt(40.5f);
    expect(call_ok(vm, clip_method, args, 6, &result) && result.i == 1 &&
           clip_is(game, 11, 21, 31, 41, 1),
           "float clip edges use SkRect.round");

    args[0] = DX_OBJ_VALUE(holder);
    args[1] = DX_OBJ_VALUE(canvas);
    expect(call_ok(vm, unlock_method, args, 2, &result), "unlock before the nested stack");
    args[0] = DX_OBJ_VALUE(holder);
    expect(call_ok(vm, lock_method, args, 1, &result) && result.obj == canvas,
           "relock for the nested stack");
    expect(clip_is(game, 0, 0, 320, 480, 1), "relock restores the base clip");

    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = DX_INT_VALUE(0x02);
    expect(call_ok(vm, save_method, args, 2, &result) && result.i == 1, "nested save A");
    args[1] = flt(10.f); args[2] = flt(10.f); args[3] = flt(80.f); args[4] = flt(80.f);
    args[5] = DX_OBJ_VALUE(replace);
    expect(call_ok(vm, clip_method, args, 6, &result) && clip_is(game, 10, 10, 80, 80, 2),
           "clip A");
    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = DX_INT_VALUE(0x1F);
    expect(call_ok(vm, save_method, args, 2, &result) && result.i == 2, "nested save B returns 2");
    args[1] = flt(20.f); args[2] = flt(20.f); args[3] = flt(40.f); args[4] = flt(40.f);
    args[5] = DX_OBJ_VALUE(replace);
    expect(call_ok(vm, clip_method, args, 6, &result) && clip_is(game, 20, 20, 40, 40, 3),
           "clip B");
    expect(call_ok(vm, restore_method, (DxValue[]){ DX_OBJ_VALUE(canvas) }, 1, &result) &&
           clip_is(game, 10, 10, 80, 80, 2),
           "restore returns clip A");
    expect(call_ok(vm, restore_method, (DxValue[]){ DX_OBJ_VALUE(canvas) }, 1, &result) &&
           clip_is(game, 0, 0, 320, 480, 1),
           "second restore returns the base clip");

    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = flt(4.f); args[2] = flt(4.f); args[3] = flt(20.f); args[4] = flt(20.f);
    args[5] = DX_OBJ_VALUE(replace);
    expect(call_ok(vm, clip_method, args, 6, &result), "clip before matrix-only save");
    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = DX_INT_VALUE(0x01);
    expect(call_ok(vm, save_method, args, 2, &result) && result.i == 1,
           "save(MATRIX_SAVE_FLAG) still returns a save count");
    args[1] = flt(30.f); args[2] = flt(30.f); args[3] = flt(50.f); args[4] = flt(50.f);
    args[5] = DX_OBJ_VALUE(replace);
    expect(call_ok(vm, clip_method, args, 6, &result) && clip_is(game, 30, 30, 50, 50, 2),
           "clip changes after a matrix-only save");
    expect(call_ok(vm, restore_method, (DxValue[]){ DX_OBJ_VALUE(canvas) }, 1, &result) &&
           clip_is(game, 30, 30, 50, 50, 1),
           "restore without CLIP_SAVE_FLAG keeps the shared clip");

    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = DX_INT_VALUE(0x02);
    expect(call_ok(vm, save_method, args, 2, &result), "unbalanced save");
    args[1] = flt(5.f); args[2] = flt(5.f); args[3] = flt(15.f); args[4] = flt(15.f);
    args[5] = DX_OBJ_VALUE(replace);
    expect(call_ok(vm, clip_method, args, 6, &result), "temporary clip before unlock");
    args[0] = DX_OBJ_VALUE(holder);
    args[1] = DX_OBJ_VALUE(canvas);
    expect(call_ok(vm, unlock_method, args, 2, &result), "unlock drops the lock");
    args[0] = DX_OBJ_VALUE(holder);
    expect(call_ok(vm, lock_method, args, 1, &result) && result.obj == canvas,
           "the next lockCanvas reuses the content canvas");
    expect(clip_is(game, 0, 0, 320, 480, 1),
           "a new lock does not inherit the previous save stack or clip");
    agr_dex_game_content_clip(game, NULL, NULL, NULL, NULL, &save_count);
    expect(save_count == 1, "new lock save count is the base");

    args[0] = DX_OBJ_VALUE(canvas);
    args[1] = flt(1.f); args[2] = flt(1.f); args[3] = flt(2.f); args[4] = flt(2.f);
    args[5] = DX_NULL_VALUE;
    expect(dx_vm_execute_method(vm, clip_method, args, 6, &result) == DX_ERR_EXCEPTION &&
           dx_vm_current_exec(vm)->pending_exception &&
           dx_vm_current_exec(vm)->pending_exception->klass &&
           strstr(dx_vm_current_exec(vm)->pending_exception->klass->descriptor, "NullPointerException"),
           "null Region.Op throws NullPointerException");
    clear_exception(vm);
    expect(clip_is(game, 0, 0, 320, 480, 1), "null Op does not change the clip");

    args[5] = DX_OBJ_VALUE(dx_vm_alloc_object(vm, dx_vm_find_class(vm, "Ljava/lang/Object;")));
    expect(dx_vm_execute_method(vm, clip_method, args, 6, &result) == DX_ERR_EXCEPTION,
           "a non-REPLACE Op is not treated as REPLACE");
    clear_exception(vm);
    expect(clip_is(game, 0, 0, 320, 480, 1), "rejected Op does not change the clip");

    args[0] = DX_OBJ_VALUE(holder);
    args[1] = DX_OBJ_VALUE(canvas);
    expect(call_ok(vm, unlock_method, args, 2, &result), "final unlock");

    agr_dex_game_destroy(game);
    free(dex);
    free(xml);
    free(png);
    printf("canvas state clip contract: %s\n", g_failures ? "FAIL" : "PASS");
    return g_failures ? 1 : 0;
}
