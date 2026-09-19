#include "types.hpp"
extern "C" void agr_eh2b_event(int);
extern "C" __attribute__((noinline)) void agr_eh2b_C_throw(void) {
    agr_eh2b_event(811); throw Derived(70);
}
