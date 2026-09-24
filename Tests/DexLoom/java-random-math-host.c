/* Android 4.4.4 libcore Random and java.lang.Math focused contracts. */
#include "dx_vm.h"
#include "dx_log.h"
#include <math.h>
#include <stdio.h>

static int failures;

static void check(int ok, const char *name) {
    printf("%s %s\n", ok ? "PASS" : "FAIL", name);
    if (!ok) failures++;
}

static DxResult invoke(DxVM *vm, DxClass *cls, const char *name,
                       const char *shorty, DxValue *args, uint32_t count,
                       DxValue *result) {
    DxMethod *method = dx_vm_find_method(cls, name, shorty);
    if (!method) return DX_ERR_INVALID_FORMAT;
    return dx_vm_execute_method(vm, method, args, count, result);
}

int main(void) {
    DxVM *vm = dx_vm_create(NULL);
    DxClass *random_class, *math_class;
    DxObject *random;
    DxValue args[2], result = DX_NULL_VALUE;
    const int32_t expected[] = {-1155484576, -723955400, 1033096058};
    dx_log_set_level(DX_LOG_WARN);
    check(vm && dx_register_java_lang(vm) == DX_OK, "register API19 core classes");
    if (!vm || failures) return 1;
    random_class = dx_vm_find_class(vm, "Ljava/util/Random;");
    math_class = dx_vm_find_class(vm, "Ljava/lang/Math;");
    check(random_class && math_class, "Random and Math registered");
    if (!random_class || !math_class) return 1;
    random = dx_vm_alloc_object(vm, random_class);
    check(random != NULL, "Random instance allocated in DEX heap");
    if (!random) return 1;
    args[0] = DX_OBJ_VALUE(random);
    args[1] = (DxValue){.tag=DX_VAL_LONG,.l=0};
    check(invoke(vm, random_class, "<init>", "VJ", args, 2, NULL) == DX_OK,
          "Random(0) seed initialization");
    for (unsigned i = 0; i < sizeof(expected)/sizeof(expected[0]); i++) {
        result = DX_NULL_VALUE;
        check(invoke(vm, random_class, "nextInt", "I", args, 1, &result) == DX_OK &&
              result.tag == DX_VAL_INT && result.i == expected[i],
              "Random(0) nextInt API19 reference sequence");
    }
    check(invoke(vm, random_class, "setSeed", "VJ", args, 2, NULL) == DX_OK,
          "Random.setSeed(0)");
    args[1] = DX_INT_VALUE(8);
    result = DX_NULL_VALUE;
    check(invoke(vm, random_class, "nextInt", "II", args, 2, &result) == DX_OK &&
          result.tag == DX_VAL_INT && result.i == 5,
          "Random(0).nextInt(8) API19 power-of-two bound");
    args[0] = (DxValue){.tag=DX_VAL_DOUBLE,.d=1.5707963267948966};
    result = DX_NULL_VALUE;
    check(invoke(vm, math_class, "sin", "DD", args, 1, &result) == DX_OK &&
          result.tag == DX_VAL_DOUBLE && fabs(result.d - 1.0) < 1e-15,
          "Math.sin API19 native libm mapping");
    args[0].d = 3.141592653589793;
    result = DX_NULL_VALUE;
    check(invoke(vm, math_class, "cos", "DD", args, 1, &result) == DX_OK &&
          result.tag == DX_VAL_DOUBLE && fabs(result.d + 1.0) < 1e-15,
          "Math.cos API19 native libm mapping");
    dx_vm_destroy(vm);
    return failures ? 1 : 0;
}
