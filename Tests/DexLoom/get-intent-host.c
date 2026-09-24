/* API19 Activity.getIntent returns the Activity's current Intent identity. */
#include "game_dex_runner.h"
#include "dx_vm.h"
#include "dx_log.h"
#include <GLES2/gl2.h>
#include <pthread.h>
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

static DxObject *g_worker_activity = NULL;
static DxObject *g_worker_launch = NULL;
static volatile uint32_t g_worker_exec = 0xffffffffu;
static volatile int g_worker_done = 0;
static volatile int g_worker_identity_ok = 0;

static DxResult worker_get_intent_run(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    DxExecutionContext *exec = dx_vm_current_exec(vm);
    DxValue result = DX_NULL_VALUE;
    DxResult rc;
    (void)frame;
    (void)args;
    (void)count;
    __atomic_store_n(&g_worker_exec, exec ? exec->id : 0xffffffffu, __ATOMIC_RELEASE);
    rc = call_get_intent(vm, g_worker_activity, &result);
    __atomic_store_n(&g_worker_identity_ok,
                     rc == DX_OK && result.tag == DX_VAL_OBJ && result.obj == g_worker_launch,
                     __ATOMIC_RELEASE);
    __atomic_store_n(&g_worker_done, 1, __ATOMIC_RELEASE);
    return DX_OK;
}

static int intent_has_exec(const agr_dex_runtime_snapshot *snapshot, uint32_t exec_id) {
    char needle[32];
    uint32_t i;
    snprintf(needle, sizeof(needle), " e=%u ", exec_id);
    if (!snapshot) return 0;
    for (i = 0; i < snapshot->intent_event_count; i++) {
        if (strstr(snapshot->intent_events[i], needle)) return 1;
    }
    return 0;
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

    {
        agr_dex_runtime_snapshot snap = {0};
        DxExecutionContext *root_exec = dx_vm_current_exec(vm);
        agr_dex_game_runtime_snapshot(game, &snap);
        expect(root_exec && root_exec->id == 0, "the host caller is execution context 0");
        expect(intent_has_exec(&snap, 0), "root getIntent records e=0");
        if (!intent_has_exec(&snap, 0)) {
            uint32_t i;
            for (i = 0; i < snap.intent_event_count; i++)
                fprintf(stderr, "root intent: %s\n", snap.intent_events[i]);
        }
    }

    {
        agr_dex_game *worker_game = agr_dex_game_create_for_launch(
            dex, dex_size, "Ltest/TestActivity;", "Ltest/TestApplication;", "test.activity.launch");
        DxVM *worker_vm = worker_game ? agr_dex_game_vm(worker_game) : NULL;
        DxClass *thread_cls = worker_vm ? dx_vm_find_class(worker_vm, "Ljava/lang/Thread;") : NULL;
        DxMethod *run = thread_cls ? dx_vm_find_method(thread_cls, "run", "V") : NULL;
        DxMethod *start = thread_cls ? dx_vm_find_method(thread_cls, "start", "V") : NULL;
        DxMethod *join = thread_cls ? dx_vm_find_method(thread_cls, "join", "V") : NULL;
        DxObject *thread = NULL;
        DxValue args[1];
        agr_dex_runtime_snapshot snap = {0};
        uint32_t worker_exec;
        int i;
        expect(worker_game && agr_dex_game_start_activity(worker_game) == 0,
               "worker fixture starts an activity");
        g_worker_activity = worker_vm ? worker_vm->activity_instance : NULL;
        g_worker_launch = field_obj(g_worker_activity, "_intent");
        expect(run && start && join && run->is_native && g_worker_launch,
               "synthetic worker can call getIntent");
        if (run && start && join && g_worker_activity && g_worker_launch) {
            run->native_fn = worker_get_intent_run;
            thread = dx_vm_alloc_object(worker_vm, thread_cls);
            args[0] = DX_OBJ_VALUE(thread);
            expect(thread && dx_vm_execute_method(worker_vm, start, args, 1, NULL) == DX_OK,
                   "start synthetic getIntent worker");
            for (i = 0; i < 2000 && __atomic_load_n(&g_worker_done, __ATOMIC_ACQUIRE) == 0; i++)
                usleep(1000);
            expect(dx_vm_execute_method(worker_vm, join, args, 1, NULL) == DX_OK,
                   "join synthetic getIntent worker");
        }
        worker_exec = __atomic_load_n(&g_worker_exec, __ATOMIC_ACQUIRE);
        expect(g_worker_done == 1 && worker_exec != 0 && worker_exec != 0xffffffffu,
               "synthetic worker runs on its own execution context");
        expect(g_worker_identity_ok == 1, "worker getIntent returns the same Intent identity");
        if (worker_game) agr_dex_game_runtime_snapshot(worker_game, &snap);
        expect(intent_has_exec(&snap, worker_exec), "worker getIntent records its execution context id");
        if (!intent_has_exec(&snap, worker_exec)) {
            uint32_t event;
            fprintf(stderr, "worker exec %u\n", worker_exec);
            for (event = 0; event < snap.intent_event_count; event++)
                fprintf(stderr, "worker intent: %s\n", snap.intent_events[event]);
        }
        if (worker_game) agr_dex_game_destroy(worker_game);
    }

    agr_dex_game_destroy(game);
    free(dex);
    if (g_failures) {
        fprintf(stderr, "%d getIntent checks failed\n", g_failures);
        return 1;
    }
    printf("getIntent contract: PASS\n");
    return 0;
}
