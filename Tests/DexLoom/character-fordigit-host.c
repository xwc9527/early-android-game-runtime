/* API19 java.lang.Character.forDigit host contract.
   Static CII. Invalid digit or radix returns 0. */
#include "dx_vm.h"
#include "dx_log.h"
#include <stdio.h>
#include <unistd.h>

static int g_failures = 0;

static void expect_char(int32_t actual, int32_t expected, const char *message) {
    if (actual == expected) {
        printf("PASS %s (%d)\n", message, actual);
        return;
    }
    printf("FAIL %s actual=%d expected=%d\n", message, actual, expected);
    g_failures++;
}

static int32_t call_fordigit(DxVM *vm, DxMethod *method, int32_t digit, int32_t radix) {
    DxValue args[2];
    DxValue result;
    args[0] = DX_INT_VALUE(digit);
    args[1] = DX_INT_VALUE(radix);
    result = DX_NULL_VALUE;
    if (dx_vm_execute_method(vm, method, args, 2, &result) != DX_OK) return -1;
    if (result.tag != DX_VAL_INT) return -2;
    return result.i;
}

int main(void) {
    DxVM *vm;
    DxClass *character;
    DxMethod *method;
    alarm(20);
    dx_log_set_level(DX_LOG_WARN);
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK) return 1;
    character = dx_vm_find_class(vm, "Ljava/lang/Character;");
    method = character ? dx_vm_find_method(character, "forDigit", "CII") : NULL;
    if (!method || !(method->access_flags & DX_ACC_STATIC) || !method->is_native) {
        fprintf(stderr, "Character.forDigit CII is not registered\n");
        return 1;
    }

    expect_char(call_fordigit(vm, method, 0, 10), '0', "forDigit(0, 10)");
    expect_char(call_fordigit(vm, method, 9, 10), '9', "forDigit(9, 10)");
    expect_char(call_fordigit(vm, method, 10, 10), 0, "digit == radix");
    expect_char(call_fordigit(vm, method, -1, 10), 0, "negative digit");
    expect_char(call_fordigit(vm, method, 0, 2), '0', "forDigit(0, 2)");
    expect_char(call_fordigit(vm, method, 1, 2), '1', "forDigit(1, 2)");
    expect_char(call_fordigit(vm, method, 10, 16), 'a', "forDigit(10, 16)");
    expect_char(call_fordigit(vm, method, 15, 16), 'f', "forDigit(15, 16)");
    expect_char(call_fordigit(vm, method, 35, 36), 'z', "forDigit(35, 36)");
    expect_char(call_fordigit(vm, method, 36, 36), 0, "digit == MAX_RADIX boundary");
    expect_char(call_fordigit(vm, method, 1, 1), 0, "radix below MIN_RADIX");
    expect_char(call_fordigit(vm, method, 1, 37), 0, "radix above MAX_RADIX");
    expect_char(call_fordigit(vm, method, 0, 36), '0', "forDigit(0, 36)");

    if (g_failures) {
        fprintf(stderr, "%d forDigit checks failed\n", g_failures);
        return 1;
    }
    printf("character-fordigit-host PASS\n");
    return 0;
}
