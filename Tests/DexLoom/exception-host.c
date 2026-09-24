/* Phase 3C: throw, catch-all, move-exception, and JNI_OnLoad version. */
#include "dx_vm.h"
#include "dx_jni.h"
#include "dx_log.h"
#include <stdio.h>
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

static void fill_catch(uint8_t *image, uint16_t **insns) {
    uint16_t *code = (uint16_t *)image;
    code[0] = 0x0027;
    code[1] = 0x000e;
    code[2] = 0x000d;
    code[3] = 0x0011;
    image[8] = 0;
    image[9] = 0;
    image[10] = 0;
    image[11] = 0;
    image[12] = 1;
    image[13] = 0;
    image[14] = 0;
    image[15] = 0;
    image[16] = 0;
    image[17] = 2;
    *insns = code;
}

static jint onload_ok(JavaVM *vm, void *reserved) {
    void *env = NULL;
    (void)reserved;
    if (!vm || (*vm)->GetEnv(vm, &env, JNI_VERSION_1_6) != JNI_OK || !env) return 0;
    return JNI_VERSION_1_6;
}

static jint onload_bad(JavaVM *vm, void *reserved) {
    (void)vm;
    (void)reserved;
    return 0x00010001;
}

int main(void) {
    DxVM *vm;
    JNIEnv *env;
    JavaVM *java_vm = NULL;
    DxClass cls;
    DxMethod method;
    DxObject *exception;
    DxValue arg;
    DxValue result;
    uint8_t image[24];
    uint16_t *insns = NULL;
    alarm(20);
    dx_log_set_level(DX_LOG_ERROR);
    memset(&cls, 0, sizeof(cls));
    memset(&method, 0, sizeof(method));
    memset(image, 0, sizeof(image));
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK || dx_jni_init(vm) != DX_OK) return 1;
    env = dx_jni_get_env(vm);
    cls.descriptor = "LCatch;";
    cls.status = DX_CLASS_INITIALIZED;
    method.name = "run";
    method.shorty = "L";
    method.declaring_class = &cls;
    method.has_code = true;
    fill_catch(image, &insns);
    method.code.registers_size = 1;
    method.code.ins_size = 1;
    method.code.insns_size = 4;
    method.code.tries_size = 1;
    method.code.insns = insns;
    exception = dx_vm_create_exception(vm, "Ljava/lang/Exception;", "caught");
    arg = DX_OBJ_VALUE(exception);
    result = DX_NULL_VALUE;
    expect(dx_vm_execute_method(vm, &method, &arg, 1, &result) == DX_OK, "throw reaches the catch handler");
    expect(result.tag == DX_VAL_OBJ && result.obj == exception, "move-exception returns the thrown object");
    expect(dx_vm_current_exec(vm)->pending_exception == NULL, "a caught exception does not stay pending");
    method.code.tries_size = 0;
    result = DX_NULL_VALUE;
    expect(dx_vm_execute_method(vm, &method, &arg, 1, &result) == DX_ERR_EXCEPTION,
           "an uncaught throw leaves the caller");
    expect(dx_vm_current_exec(vm)->pending_exception == exception, "an uncaught throw is the pending exception");
    dx_vm_current_exec(vm)->pending_exception = NULL;
    (*env)->GetJavaVM(env, &java_vm);
    expect(dx_jni_call_onload(java_vm, NULL) == JNI_OK, "a library without JNI_OnLoad loads");
    expect(dx_jni_call_onload(java_vm, onload_ok) == JNI_OK, "JNI_OnLoad accepts JNI 1.6");
    expect(dx_jni_call_onload(java_vm, onload_bad) == JNI_EVERSION, "JNI_OnLoad rejects an unknown version");
    return g_failures ? 1 : 0;
}
