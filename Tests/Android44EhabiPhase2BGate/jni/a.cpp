#include "types.hpp"
extern "C" void agr_eh2b_reset(void);
extern "C" void agr_eh2b_event(int);
extern "C" void agr_eh2b_set(int, int);
extern "C" void agr_eh2b_B_call(void);
extern "C" __attribute__((noinline)) int agr_eh2b_cross(void) {
    agr_eh2b_reset(); agr_eh2b_event(810);
    try { agr_eh2b_B_call(); }
    catch (Base& value) {
        Derived *derived = dynamic_cast<Derived*>(&value);
        agr_eh2b_event(813); agr_eh2b_set(10, value.base);
        agr_eh2b_set(11, derived ? derived->derived : -1);
        return value.base == 71 && derived && derived->derived == 74 ? 1 : 0;
    }
    return 0;
}
