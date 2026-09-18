extern "C" void agr_eh2_event(int);
extern "C" void agr_eh2_C_throw(void);

struct Cleanup {
    ~Cleanup() { agr_eh2_event(12); }
};

extern "C" __attribute__((noinline)) void agr_eh2_B_call(void) {
    Cleanup cleanup;
    agr_eh2_C_throw();
}

