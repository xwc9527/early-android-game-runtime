__attribute__((noinline)) void A(void);
extern void B(void);
__attribute__((noinline)) void A(void) { B(); }
