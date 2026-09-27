/* Test-only JSON for the Dalvik.JNINativeBinding RegisterNatives differential.
   Both fixtures emit this shape. It is an observation, not a governance record. */
#ifndef JNI_NATIVE_BINDING_REPORT_H
#define JNI_NATIVE_BINDING_REPORT_H

#include <stdio.h>

typedef struct JniBindCase {
    const char *name;
    int register_return;
    const char *pending; /* NULL when ExceptionOccurred is null */
    int has_call;
    int call_result;
} JniBindCase;

static void jni_bind_json_string(FILE *fp, const char *text) {
    const unsigned char *cursor = (const unsigned char *)text;
    fputc('"', fp);
    for (; *cursor; cursor++) {
        if (*cursor == '"' || *cursor == '\\') {
            fputc('\\', fp);
            fputc((int)*cursor, fp);
        } else if (*cursor < 0x20) {
            fprintf(fp, "\\u%04x", *cursor);
        } else {
            fputc((int)*cursor, fp);
        }
    }
    fputc('"', fp);
}

static void jni_bind_print_json(FILE *fp, const JniBindCase *cases, int count) {
    int index;
    fputs("{\"cases\":[", fp);
    for (index = 0; index < count; index++) {
        if (index) fputc(',', fp);
        fputs("{\"call_result\":", fp);
        if (cases[index].has_call) fprintf(fp, "%d", cases[index].call_result);
        else fputs("null", fp);
        fputs(",\"case\":", fp);
        jni_bind_json_string(fp, cases[index].name ? cases[index].name : "");
        fputs(",\"pending_exception\":", fp);
        if (cases[index].pending && cases[index].pending[0])
            jni_bind_json_string(fp, cases[index].pending);
        else
            fputs("null", fp);
        fprintf(fp, ",\"register_return\":%d}", cases[index].register_return);
    }
    fputs("]}\n", fp);
}

#endif
