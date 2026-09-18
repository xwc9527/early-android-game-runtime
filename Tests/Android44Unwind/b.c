__attribute__((noinline)) void B(void);
extern void C(void);
__attribute__((noinline)) void B(void) { C(); }
