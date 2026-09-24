/* Phase 3B: virtual, interface, super, static, and direct dispatch. */
#include "dx_vm.h"
#include "dx_jni.h"
#include "dx_log.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int g_failures = 0;
static int g_which = 0;

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

static DxResult native_parent(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)frame; (void)args; (void)arg_count;
    g_which = 1;
    return DX_OK;
}

static DxResult native_child(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)frame; (void)args; (void)arg_count;
    g_which = 2;
    return DX_OK;
}

static DxResult native_clinit_throw(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)frame; (void)args; (void)arg_count;
    dx_vm_current_exec(vm)->pending_exception =
        dx_vm_create_exception(vm, "Ljava/lang/Exception;", "clinit");
    return DX_OK;
}

int main(void) {
    DxVM *vm;
    JNIEnv *env;
    DxClass parent, child, iface;
    DxMethod parent_method, child_method, static_method, abstract_method, iface_method, clinit;
    DxMethod *parent_vtable[1];
    DxMethod *child_vtable[1];
    DxMethod *iface_slots[1];
    DxObject receiver;
    const char *names[1];
    const char *types[1];
    jfieldID field;
    alarm(20);
    dx_log_set_level(DX_LOG_ERROR);
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK || dx_jni_init(vm) != DX_OK) return 1;
    env = dx_jni_get_env(vm);
    memset(&parent, 0, sizeof(parent));
    memset(&child, 0, sizeof(child));
    memset(&iface, 0, sizeof(iface));
    memset(&parent_method, 0, sizeof(parent_method));
    memset(&child_method, 0, sizeof(child_method));
    memset(&static_method, 0, sizeof(static_method));
    memset(&abstract_method, 0, sizeof(abstract_method));
    memset(&iface_method, 0, sizeof(iface_method));
    memset(&clinit, 0, sizeof(clinit));
    memset(&receiver, 0, sizeof(receiver));
    parent.descriptor = "LParent;";
    parent.status = DX_CLASS_INITIALIZED;
    child.descriptor = "LChild;";
    child.super_class = &parent;
    child.status = DX_CLASS_INITIALIZED;
    iface.descriptor = "LIface;";
    iface.status = DX_CLASS_INITIALIZED;
    parent_method.name = "m";
    parent_method.shorty = "I";
    parent_method.declaring_class = &parent;
    parent_method.vtable_idx = 0;
    parent_method.is_native = true;
    parent_method.native_fn = native_parent;
    parent_method.access_flags = DX_ACC_PUBLIC;
    child_method = parent_method;
    child_method.declaring_class = &child;
    child_method.native_fn = native_child;
    static_method = parent_method;
    static_method.access_flags = DX_ACC_PUBLIC | DX_ACC_STATIC;
    static_method.vtable_idx = -1;
    static_method.native_fn = native_parent;
    abstract_method = parent_method;
    abstract_method.access_flags = DX_ACC_PUBLIC | DX_ACC_ABSTRACT;
    abstract_method.is_native = false;
    abstract_method.native_fn = NULL;
    iface_method = parent_method;
    iface_method.declaring_class = &iface;
    iface_method.native_fn = native_parent;
    parent.virtual_methods = &parent_method;
    parent.virtual_method_count = 1;
    parent_vtable[0] = &parent_method;
    parent.vtable = parent_vtable;
    parent.vtable_size = 1;
    child.virtual_methods = &child_method;
    child.virtual_method_count = 1;
    child_vtable[0] = &child_method;
    child.vtable = child_vtable;
    child.vtable_size = 1;
    iface.virtual_methods = &iface_method;
    iface.virtual_method_count = 1;
    receiver.klass = &child;
    expect(dx_vm_select_invoke(vm, 0x6e, &parent_method, &receiver, &child) == &child_method,
           "virtual dispatch uses the receiver vtable");
    expect(dx_vm_select_invoke(vm, 0x6f, &child_method, &receiver, &child) == &parent_method,
           "super dispatch starts at the caller superclass");
    expect(dx_vm_select_invoke(vm, 0x70, &parent_method, &receiver, &child) == &parent_method,
           "direct dispatch keeps the resolved method");
    expect(dx_vm_select_invoke(vm, 0x71, &static_method, &receiver, &child) == &static_method,
           "static dispatch ignores the receiver");
    child.virtual_methods = NULL;
    child.virtual_method_count = 0;
    parent.virtual_methods = NULL;
    parent.virtual_method_count = 0;
    dx_vm_class_hash_insert(vm, &iface);
    iface_slots[0] = &child_method;
    child.itable = &(typeof(*child.itable)){0};
    child.itable[0].interface_desc = "LIface;";
    child.itable[0].methods = iface_slots;
    child.itable[0].method_count = 1;
    child.itable_count = 1;
    expect(dx_vm_select_invoke(vm, 0x72, &iface_method, &receiver, &child) == &child_method,
           "interface dispatch uses the receiver itable");
    child_vtable[0] = &abstract_method;
    expect(dx_vm_select_invoke(vm, 0x6e, &abstract_method, &receiver, &child) == NULL,
           "abstract method without a body fails dispatch");
    names[0] = "COUNT";
    types[0] = "I";
    parent.static_field_count = 1;
    parent.static_field_names = names;
    parent.static_field_types = types;
    field = (*env)->GetStaticFieldID(env, dx_jni_wrap_class(&parent), "COUNT", "I");
    expect(field && ((DxFieldId *)field)->declaring == &parent && ((DxFieldId *)field)->index == 0,
           "static field id uses name and type");
    expect((*env)->GetStaticFieldID(env, dx_jni_wrap_class(&parent), "COUNT", "J") == NULL,
           "static field id rejects the wrong type");
    clinit.declaring_class = &child;
    clinit.name = "<clinit>";
    clinit.shorty = "V";
    clinit.is_native = true;
    clinit.native_fn = native_clinit_throw;
    child.direct_methods = &clinit;
    child.direct_method_count = 1;
    child.status = DX_CLASS_LOADED;
    expect(dx_vm_init_class(vm, &child) == DX_ERR_CLASS_NOT_FOUND, "clinit exception fails the class");
    expect(child.status == DX_CLASS_ERROR, "failed clinit leaves the class in ERROR");
    expect(dx_vm_init_class(vm, &child) == DX_ERR_CLASS_NOT_FOUND, "later access keeps the failed class");
    return g_failures ? 1 : 0;
}
