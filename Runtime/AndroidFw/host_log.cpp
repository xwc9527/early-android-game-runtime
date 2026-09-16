#include <android/log.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" {
int __android_log_write(int, const char* tag, const char* text) {
    fprintf(stderr, "[%s] %s\n", tag ? tag : "androidfw", text ? text : "");
    return 0;
}

int __android_log_vprint(int, const char* tag, const char* format, va_list args) {
    fprintf(stderr, "[%s] ", tag ? tag : "androidfw");
    const int result = vfprintf(stderr, format, args);
    fputc('\n', stderr);
    return result;
}

int __android_log_print(int priority, const char* tag, const char* format, ...) {
    va_list args;
    va_start(args, format);
    const int result = __android_log_vprint(priority, tag, format, args);
    va_end(args);
    return result;
}

void __android_log_assert(const char* condition, const char* tag, const char* format, ...) {
    fprintf(stderr, "[%s] assertion failed: %s: ", tag ? tag : "androidfw",
                 condition ? condition : "");
    va_list args;
    va_start(args, format);
    if (format) vfprintf(stderr, format, args);
    va_end(args);
    fputc('\n', stderr);
    abort();
}
}
