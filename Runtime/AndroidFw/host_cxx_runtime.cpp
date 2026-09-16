#include <stddef.h>
#include <stdlib.h>

#ifdef _WIN32
#undef _get_osfhandle
#include <io.h>
#include <windows.h>
#endif

void* operator new(size_t size) { return malloc(size ? size : 1); }
void* operator new[](size_t size) { return malloc(size ? size : 1); }
void operator delete(void* pointer) throw() { free(pointer); }
void operator delete[](void* pointer) throw() { free(pointer); }

extern "C" void __cxa_pure_virtual(void) { abort(); }

#ifdef _WIN32
extern "C" intptr_t agr_duplicate_osfhandle(int fd) {
    HANDLE original = reinterpret_cast<HANDLE>(_get_osfhandle(fd));
    HANDLE duplicate = INVALID_HANDLE_VALUE;
    if (original == INVALID_HANDLE_VALUE) return -1;
    if (!DuplicateHandle(GetCurrentProcess(), original, GetCurrentProcess(), &duplicate,
                         0, FALSE, DUPLICATE_SAME_ACCESS)) {
        return -1;
    }
    return reinterpret_cast<intptr_t>(duplicate);
}
#endif
