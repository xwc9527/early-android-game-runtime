/* API19 Activity.requestWindowFeature / PhoneWindow.requestFeature.
   FEATURE_NO_TITLE is stored on the Activity's Window. */
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

static void clear_exception(DxVM *vm) {
    if (dx_vm_current_exec(vm)) dx_vm_current_exec(vm)->pending_exception = NULL;
}

static const char *exception_name(DxVM *vm) {
    DxObject *exception = dx_vm_current_exec(vm) ? dx_vm_current_exec(vm)->pending_exception : NULL;
    if (!exception || !exception->klass || !exception->klass->descriptor) return "";
    return exception->klass->descriptor;
}

static const char *exception_message(DxVM *vm) {
    DxObject *exception = dx_vm_current_exec(vm) ? dx_vm_current_exec(vm)->pending_exception : NULL;
    DxValue message = DX_NULL_VALUE;
    const char *text;
    if (!exception) return "";
    if (dx_vm_get_field(exception, "detailMessage", &message) != DX_OK ||
        message.tag != DX_VAL_OBJ || !message.obj)
        return "";
    text = dx_vm_get_string_value(message.obj);
    return text ? text : "";
}

static int field_int(DxObject *obj, const char *name, int32_t *out) {
    DxValue value = DX_NULL_VALUE;
    if (!obj || dx_vm_get_field(obj, name, &value) != DX_OK || value.tag != DX_VAL_INT) return 0;
    *out = value.i;
    return 1;
}

static DxObject *field_obj(DxObject *obj, const char *name) {
    DxValue value = DX_NULL_VALUE;
    if (!obj || dx_vm_get_field(obj, name, &value) != DX_OK || value.tag != DX_VAL_OBJ) return NULL;
    return value.obj;
}

static agr_dex_game *open_game(const uint8_t *dex, uint32_t dex_size) {
    agr_dex_game *game = agr_dex_game_create_for_launch(
        dex, dex_size, "Ltest/TestActivity;", "Ltest/TestApplication;", "test.activity.launch");
    if (!game) return NULL;
    if (agr_dex_game_start_activity(game) != 0) {
        agr_dex_game_destroy(game);
        return NULL;
    }
    return game;
}

static DxResult request_feature(DxVM *vm, DxObject *activity, int32_t feature_id, DxValue *result) {
    DxClass *activity_cls = dx_vm_find_class(vm, "Landroid/app/Activity;");
    DxMethod *method = activity_cls ? dx_vm_find_method(activity_cls, "requestWindowFeature", "ZI") : NULL;
    DxValue args[2];
    if (!method || !activity) return DX_ERR_INVALID_FORMAT;
    args[0] = DX_OBJ_VALUE(activity);
    args[1] = DX_INT_VALUE(feature_id);
    *result = DX_NULL_VALUE;
    return dx_vm_execute_method(vm, method, args, 2, result);
}

int main(int argc, char **argv) {
    const char *dex_path = argc > 1 ? argv[1] : "/tmp/activity-launch-fixture.dex";
    uint32_t dex_size = 0;
    uint8_t *dex = read_file(dex_path, &dex_size);
    agr_dex_game *game;
    agr_dex_game *conflict;
    agr_dex_game *custom;
    DxVM *vm;
    DxObject *activity;
    DxObject *window;
    DxObject *same;
    DxValue result;
    DxResult rc;
    int32_t features = -1;
    int32_t local_features = -1;

    alarm(20);
    dx_log_set_level(DX_LOG_WARN);
    expect(dex != NULL, "activity launch fixture");
    if (!dex) return 1;

    game = open_game(dex, dex_size);
    expect(game != NULL, "start activity before content");
    if (!game) return 1;
    vm = agr_dex_game_vm(game);
    activity = vm->activity_instance;
    window = field_obj(activity, "_window");
    expect(activity && window, "activity holds a window");
    expect(field_int(window, "_features", &features) && features == 65, "default features are 65");
    expect(field_int(window, "_localFeatures", &local_features) && local_features == 65,
           "default local features match features");
    expect(field_obj(window, "_contentParent") == NULL, "content is not installed");

    rc = request_feature(vm, activity, 1, &result);
    expect(rc == DX_OK && result.tag == DX_VAL_INT && result.i == 1,
           "FEATURE_NO_TITLE before content returns true");
    expect(field_obj(activity, "_window") == window, "request keeps the same window");
    expect(field_int(window, "_features", &features) && features == 67,
           "FEATURE_NO_TITLE bit is stored on that window");
    expect(field_int(window, "_localFeatures", &local_features) && local_features == 67,
           "local features follow features when there is no container");

    rc = request_feature(vm, activity, 1, &result);
    expect(rc == DX_OK && result.i == 1 && field_int(window, "_features", &features) && features == 67,
           "repeat FEATURE_NO_TITLE stays true and keeps the bit");

    rc = request_feature(vm, activity, 8, &result);
    expect(rc == DX_OK && result.i == 0 && field_int(window, "_features", &features) && features == 67,
           "ACTION_BAR requested after NO_TITLE returns false and does not set the bit");

    expect(agr_dex_game_set_content_view(game) == 0, "setContentView installs content");
    same = field_obj(activity, "_window");
    expect(same == window, "setContentView keeps the activity window");
    expect(field_int(window, "_features", &features) && features == 67,
           "FEATURE_NO_TITLE remains after setContentView");
    expect(field_obj(window, "_contentParent") != NULL, "content parent is that same window");

    rc = request_feature(vm, activity, 1, &result);
    expect(rc == DX_ERR_EXCEPTION &&
           strcmp(exception_name(vm), "Landroid/util/AndroidRuntimeException;") == 0 &&
           strcmp(exception_message(vm), "requestFeature() must be called before adding content") == 0,
           "request after content throws AndroidRuntimeException");
    expect(field_int(window, "_features", &features) && features == 67,
           "the failed request does not change feature bits");
    clear_exception(vm);
    agr_dex_game_destroy(game);

    conflict = open_game(dex, dex_size);
    expect(conflict != NULL, "second activity for the action-bar conflict");
    if (!conflict) return 1;
    vm = agr_dex_game_vm(conflict);
    activity = vm->activity_instance;
    window = field_obj(activity, "_window");
    rc = request_feature(vm, activity, 8, &result);
    expect(rc == DX_OK && result.i == 1 && field_int(window, "_features", &features) && features == 321,
           "FEATURE_ACTION_BAR before content returns true");
    rc = request_feature(vm, activity, 1, &result);
    expect(rc == DX_OK && result.i == 1 && field_int(window, "_features", &features) && features == 67,
           "NO_TITLE clears ACTION_BAR and stores FEATURE_NO_TITLE");
    agr_dex_game_destroy(conflict);

    custom = open_game(dex, dex_size);
    expect(custom != NULL, "third activity for the custom-title conflict");
    if (!custom) return 1;
    vm = agr_dex_game_vm(custom);
    activity = vm->activity_instance;
    window = field_obj(activity, "_window");
    rc = request_feature(vm, activity, 7, &result);
    expect(rc == DX_OK && result.i == 1 && field_int(window, "_features", &features) && features == 193,
           "FEATURE_CUSTOM_TITLE from the default set returns true");
    rc = request_feature(vm, activity, 1, &result);
    expect(rc == DX_ERR_EXCEPTION &&
           strcmp(exception_name(vm), "Landroid/util/AndroidRuntimeException;") == 0 &&
           strcmp(exception_message(vm),
                  "You cannot combine custom titles with other title features") == 0 &&
           field_int(window, "_features", &features) && features == 193,
           "NO_TITLE combined with CUSTOM_TITLE throws and does not set the bit");
    clear_exception(vm);
    agr_dex_game_destroy(custom);

    free(dex);
    if (g_failures) {
        fprintf(stderr, "%d requestWindowFeature checks failed\n", g_failures);
        return 1;
    }
    printf("requestWindowFeature contract: PASS\n");
    return 0;
}
