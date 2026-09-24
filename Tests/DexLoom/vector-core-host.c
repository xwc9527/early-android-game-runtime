/* API19 java.util.Vector core. Guest element identity is preserved. */
#include "dx_vm.h"
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

static DxObject *make_object(DxVM *vm) {
    DxClass *object_cls = dx_vm_find_class(vm, "Ljava/lang/Object;");
    return dx_vm_alloc_object(vm, object_cls);
}

static DxMethod *find_vector(DxVM *vm, const char *name, const char *shorty) {
    DxClass *vector = dx_vm_find_class(vm, "Ljava/util/Vector;");
    return vector ? dx_vm_find_method(vector, name, shorty) : NULL;
}

static void clear_exception(DxVM *vm) {
    if (dx_vm_current_exec(vm)) dx_vm_current_exec(vm)->pending_exception = NULL;
}

static const char *exception_name(DxVM *vm) {
    DxObject *exception = dx_vm_current_exec(vm) ? dx_vm_current_exec(vm)->pending_exception : NULL;
    if (!exception || !exception->klass || !exception->klass->descriptor) return "";
    return exception->klass->descriptor;
}

int main(void) {
    DxVM *vm;
    DxClass *vector_cls;
    DxObject *vector;
    DxObject *a;
    DxObject *b;
    DxObject *c;
    DxObject *extra[12];
    DxMethod *init;
    DxMethod *size_m;
    DxMethod *add;
    DxMethod *at;
    DxMethod *remove;
    DxValue args[3];
    DxValue result;
    DxResult rc;
    int i;
    alarm(20);
    dx_log_set_level(DX_LOG_WARN);
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK) return 1;
    vector_cls = dx_vm_find_class(vm, "Ljava/util/Vector;");
    init = find_vector(vm, "<init>", "V");
    size_m = find_vector(vm, "size", "I");
    add = find_vector(vm, "addElement", "VL");
    at = find_vector(vm, "elementAt", "LI");
    remove = find_vector(vm, "removeElement", "ZL");
    expect(vector_cls && init && size_m && add && at && remove, "Vector core methods are registered");
    if (g_failures) return 1;
    vector = dx_vm_alloc_object(vm, vector_cls);
    a = make_object(vm);
    b = make_object(vm);
    c = make_object(vm);
    expect(vector && a && b && c, "allocate Vector and elements");
    args[0] = DX_OBJ_VALUE(vector);
    rc = dx_vm_execute_method(vm, init, args, 1, &result);
    expect(rc == DX_OK, "Vector()");
    rc = dx_vm_execute_method(vm, size_m, args, 1, &result);
    expect(rc == DX_OK && result.tag == DX_VAL_INT && result.i == 0, "empty size is 0");

    args[1] = DX_OBJ_VALUE(a);
    rc = dx_vm_execute_method(vm, add, args, 2, &result);
    expect(rc == DX_OK, "addElement A");
    rc = dx_vm_execute_method(vm, size_m, args, 1, &result);
    expect(rc == DX_OK && result.i == 1, "size is 1 after one append");
    args[1] = DX_INT_VALUE(0);
    rc = dx_vm_execute_method(vm, at, args, 2, &result);
    expect(rc == DX_OK && result.tag == DX_VAL_OBJ && result.obj == a, "elementAt(0) is A");

    args[1] = DX_OBJ_VALUE(b);
    rc = dx_vm_execute_method(vm, add, args, 2, &result);
    expect(rc == DX_OK, "addElement B");
    args[1] = DX_OBJ_VALUE(c);
    rc = dx_vm_execute_method(vm, add, args, 2, &result);
    expect(rc == DX_OK, "addElement C");
    rc = dx_vm_execute_method(vm, size_m, args, 1, &result);
    expect(rc == DX_OK && result.i == 3, "size is 3");
    args[1] = DX_INT_VALUE(1);
    rc = dx_vm_execute_method(vm, at, args, 2, &result);
    expect(rc == DX_OK && result.obj == b, "elementAt(1) is B");
    args[1] = DX_INT_VALUE(2);
    rc = dx_vm_execute_method(vm, at, args, 2, &result);
    expect(rc == DX_OK && result.obj == c, "elementAt(2) is C");

    args[1] = DX_INT_VALUE(3);
    rc = dx_vm_execute_method(vm, at, args, 2, &result);
    expect(rc == DX_ERR_EXCEPTION &&
           strcmp(exception_name(vm), "Ljava/lang/ArrayIndexOutOfBoundsException;") == 0,
           "elementAt(size) throws ArrayIndexOutOfBoundsException");
    clear_exception(vm);
    rc = dx_vm_execute_method(vm, size_m, args, 1, &result);
    expect(rc == DX_OK && result.i == 3, "failed elementAt leaves size unchanged");
    args[1] = DX_INT_VALUE(-1);
    rc = dx_vm_execute_method(vm, at, args, 2, &result);
    expect(rc == DX_ERR_EXCEPTION &&
           strcmp(exception_name(vm), "Ljava/lang/ArrayIndexOutOfBoundsException;") == 0,
           "elementAt(-1) throws ArrayIndexOutOfBoundsException");
    clear_exception(vm);

    args[1] = DX_OBJ_VALUE(b);
    rc = dx_vm_execute_method(vm, remove, args, 2, &result);
    expect(rc == DX_OK && result.tag == DX_VAL_INT && result.i == 1, "removeElement B returns true");
    rc = dx_vm_execute_method(vm, size_m, args, 1, &result);
    expect(rc == DX_OK && result.i == 2, "size is 2 after remove");
    args[1] = DX_INT_VALUE(0);
    rc = dx_vm_execute_method(vm, at, args, 2, &result);
    expect(rc == DX_OK && result.obj == a, "elementAt(0) is still A");
    args[1] = DX_INT_VALUE(1);
    rc = dx_vm_execute_method(vm, at, args, 2, &result);
    expect(rc == DX_OK && result.obj == c, "elementAt(1) shifted to C");
    args[1] = DX_OBJ_VALUE(b);
    rc = dx_vm_execute_method(vm, remove, args, 2, &result);
    expect(rc == DX_OK && result.i == 0, "removeElement of a missing object returns false");

    args[1] = DX_NULL_VALUE;
    rc = dx_vm_execute_method(vm, add, args, 2, &result);
    expect(rc == DX_OK, "addElement null");
    rc = dx_vm_execute_method(vm, size_m, args, 1, &result);
    expect(rc == DX_OK && result.i == 3, "size includes null");
    args[1] = DX_INT_VALUE(2);
    rc = dx_vm_execute_method(vm, at, args, 2, &result);
    expect(rc == DX_OK && result.tag == DX_VAL_OBJ && result.obj == NULL, "elementAt returns the stored null");
    args[1] = DX_NULL_VALUE;
    rc = dx_vm_execute_method(vm, remove, args, 2, &result);
    expect(rc == DX_OK && result.i == 1, "removeElement null returns true");

    for (i = 0; i < 12; i++) {
        extra[i] = make_object(vm);
        args[1] = DX_OBJ_VALUE(extra[i]);
        rc = dx_vm_execute_method(vm, add, args, 2, &result);
        if (rc != DX_OK) break;
    }
    expect(i == 12 && rc == DX_OK, "grow past the default capacity of 10");
    rc = dx_vm_execute_method(vm, size_m, args, 1, &result);
    expect(rc == DX_OK && result.i == 14, "size is 14 after growth");
    args[1] = DX_INT_VALUE(13);
    rc = dx_vm_execute_method(vm, at, args, 2, &result);
    expect(rc == DX_OK && result.obj == extra[11], "elementAt after growth keeps the same object");

    if (g_failures) {
        fprintf(stderr, "%d Vector checks failed\n", g_failures);
        return 1;
    }
    printf("vector core contract: PASS\n");
    return 0;
}
