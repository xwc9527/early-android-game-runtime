#include <stddef.h>
#include <stdlib.h>

void* operator new(size_t size) { return malloc(size ? size : 1); }
void* operator new[](size_t size) { return malloc(size ? size : 1); }
void operator delete(void* pointer) throw() { free(pointer); }
void operator delete[](void* pointer) throw() { free(pointer); }
extern "C" void __cxa_pure_virtual(void) { abort(); }
