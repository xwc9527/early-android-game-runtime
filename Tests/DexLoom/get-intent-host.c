/* API19 Activity.getIntent returns the Activity's current Intent identity. */
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

static DxObject *field_obj(DxObject *obj, const char *name) {
    DxValue value = DX_NULL_VALUE;
    if (!obj || dx_vm_get_field(obj, name, &value) != DX_OK || value.tag != DX_VAL_OBJ) return NULL;
    return value.obj;
}

static DxResult call_get_intent(DxVM *vm, DxObject *activity, DxValue *result) {
    DxClass *activity_cls = dx_vm_find_class(vm, "Landroid/app/Activity;");
    DxMethod *method = activity_cls ? dx_vm_find_method(activity_cls, "getIntent", "L") : NULL;
    DxValue args[1];
    if (!method || !activity) return DX_ERR_INVALID_FORMAT;
    args[0] = DX_OBJ_VALUE(activity);
    *result = DX_NULL_VALUE;
    return dx_vm_execute_method(vm, method, args, 1, result);
}

int main(int argc, char **argv) {
    const char *dex_path = argc > 1 ? argv[1] : "/tmp/activity-launch-fixture.dex";
    uint32_t dex_size = 0;
    uint8_t *dex = read_file(dex_path, &dex_size);
    agr_dex_game *game;
    DxVM *vm;
    DxClass *intent_cls;
    DxObject *activity;
    DxObject *launch;
    DxObject *window;
    DxObject *other;
    DxValue result;
    DxResult rc;
    uint32_t heap_before;
    int32_t features = -1;

    alarm(20);
    dx_log_set_level(DX_LOG_WARN);
    expect(dex != NULL, "activity launch fixture");
    if (!dex) return 1;
    game = agr_dex_game_create_for_launch(
        dex, dex_size, "Ltest/TestActivity;", "Ltest/TestApplication;", "test.activity.launch");
    expect(game && agr_dex_game_start_activity(game) == 0, "start activity with a launch Intent");
    if (!game) return 1;
    vm = agr_dex_game_vm(game);
    activity = vm->activity_instance;
    launch = field_obj(activity, "_intent");
    window = field_obj(activity, "_window");
    expect(activity && launch && launch == vm->launch_intent, "Activity _intent is the launch Intent");
    expect(window && dx_vm_get_field(window, "_features", &result) == DX_OK, "activity window is unchanged");
    features = result.i;

    heap_before = vm->heap_count;
    rc = call_get_intent(vm, activity, &result);
    expect(rc == DX_OK && result.tag == DX_VAL_OBJ && result.obj == launch,
           "getIntent returns the launch Intent identity");
    expect(field_obj(activity, "_intent") == launch, "getIntent leaves _intent unchanged");
    expect(field_obj(activity, "_window") == window, "getIntent leaves the window unchanged");
    expect(vm->launch_intent == launch, "getIntent leaves the launch Intent unchanged");
    expect(vm->heap_count == heap_before, "getIntent does not allocate");
    rc = call_get_intent(vm, activity, &result);
    expect(rc == DX_OK && result.obj == launch, "a second getIntent returns the same Intent");
    expect(vm->heap_count == heap_before, "the second getIntent does not allocate");

    intent_cls = dx_vm_find_class(vm, "Landroid/content/Intent;");
    other = intent_cls ? dx_vm_alloc_object(vm, intent_cls) : NULL;
    expect(other && other != launch, "a second Intent is a distinct object");
    expect(dx_vm_set_field(activity, "_intent", DX_OBJ_VALUE(other)) == DX_OK, "store Intent B on the Activity");
    heap_before = vm->heap_count;
    rc = call_get_intent(vm, activity, &result);
    expect(rc == DX_OK && result.tag == DX_VAL_OBJ && result.obj == other,
           "getIntent returns the Activity field, not the original launch Intent");
    expect(vm->launch_intent == launch && result.obj != launch,
           "the launch Intent remains the original object");
    expect(vm->heap_count == heap_before, "returning Intent B does not allocate");

    expect(dx_vm_set_field(activity, "_intent", DX_NULL_VALUE) == DX_OK, "clear Activity _intent");
    heap_before = vm->heap_count;
    rc = call_get_intent(vm, activity, &result);
    expect(rc == DX_OK && result.tag == DX_VAL_OBJ && result.obj == NULL,
           "a null _intent returns null");
    expect(field_obj(activity, "_intent") == NULL, "the null field stays null");
    expect(vm->heap_count == heap_before, "a null getIntent does not allocate");
    expect(field_obj(activity, "_window") == window, "lifecycle window identity stays put");
    expect(dx_vm_get_field(window, "_features", &result) == DX_OK && result.i == features,
           "getIntent does not change window feature state");

    agr_dex_game_destroy(game);
    free(dex);
    if (g_failures) {
        fprintf(stderr, "%d getIntent checks failed\n", g_failures);
        return 1;
    }
    printf("getIntent contract: PASS\n");
    return 0;
}
