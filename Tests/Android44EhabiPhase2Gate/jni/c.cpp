extern "C" void agr_eh2_event(int);

extern "C" __attribute__((noinline)) void agr_eh2_C_throw(void) {
    agr_eh2_event(11);
    throw 23;
}

