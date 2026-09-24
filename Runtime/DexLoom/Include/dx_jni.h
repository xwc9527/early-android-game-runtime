#ifndef DX_JNI_H
#define DX_JNI_H

#include "dx_types.h"
#include "jni.h"

// DexLoom JNI bridge
// Provides a fake JNIEnv that maps JNI calls to DexLoom's VM operations.
// This allows DEX bytecode that calls native methods via JNI to partially work.

// Initialize the JNI environment for a VM instance
DxResult dx_jni_init(DxVM *vm);
/* Call JNI_OnLoad. A missing function is success. A version other than 1.4 or 1.6 fails. */
jint dx_jni_call_onload(JavaVM *vm, jint (*onload)(JavaVM *vm, void *reserved));

// Get the JNIEnv pointer (for passing to JNI_OnLoad, native methods, etc.)
JNIEnv *dx_jni_get_env(DxVM *vm);

// Clean up JNI resources
void dx_jni_destroy(DxVM *vm);

// Convert between JNI jobject and DxObject
jobject  dx_jni_wrap_object(DxObject *obj);
DxObject *dx_jni_unwrap_object(jobject ref);

// Convert between JNI jclass and DxClass
jclass   dx_jni_wrap_class(DxClass *cls);
DxClass  *dx_jni_unwrap_class(jclass ref);

#endif // DX_JNI_H
