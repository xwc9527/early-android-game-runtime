#include "../../Runtime/GuestRuntime/agr_jni_methods.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define CHECK(expr) do { if (!(expr)) { fprintf(stderr,"FAIL %s:%d: %s\n",__FILE__,__LINE__,#expr); return 1; } } while (0)

int main(void) {
    agr_jni_method_table table={0};
    uint32_t image=0, repeat=0, sound=0, other_class=0;
    CHECK(agr_jni_method_id(&table,0x64000001u,"loadImage","(Ljava/lang/String;)I",&image)==0);
    for (unsigned i=0;i<1000000;i++) {
        CHECK(agr_jni_method_id(&table,0x64000001u,"loadImage","(Ljava/lang/String;)I",&repeat)==0);
        CHECK(repeat==image);
    }
    CHECK(table.count==1);
    CHECK(agr_jni_method_id(&table,0x64000001u,"playSound","(Ljava/lang/String;F)I",&sound)==0);
    CHECK(sound!=image);
    CHECK(agr_jni_method_id(&table,0x64000002u,"loadImage","(Ljava/lang/String;)I",&other_class)==0);
    CHECK(other_class!=image);
    CHECK(table.count==3);
    CHECK(agr_jni_method_bind(&table,0x64000001u,"nativeStep","(I)I",0x12345679u)==0);
    CHECK(agr_jni_method_native_address(&table,0x64000001u,"nativeStep","(I)I")==0x12345679u);
    CHECK(agr_jni_method_native_address(&table,0x64000002u,"nativeStep","(I)I")==0);

    for (unsigned i=0;i<100000;i++) {
        char name[48];
        snprintf(name,sizeof(name),"method_%u",i);
        uint32_t handle=0;
        CHECK(agr_jni_method_id(&table,0x64000001u,name,"()V",&handle)==0);
        const agr_jni_method *method=agr_jni_method_lookup(&table,handle);
        CHECK(method && !strcmp(method->name,name) && !strcmp(method->signature,"()V"));
    }
    CHECK(table.count==100004 && table.capacity>=table.count);
    CHECK(agr_jni_method_lookup(&table,image)!=NULL);
    CHECK(agr_jni_method_lookup(&table,0x65000001u)==NULL);
    CHECK(agr_jni_method_lookup(&table,0)==NULL);
    for (unsigned i=0;i<100000;i+=971) {
        char name[48];
        snprintf(name,sizeof(name),"method_%u",i);
        uint32_t handle=0;
        CHECK(agr_jni_method_id(&table,0x64000001u,name,"()V",&handle)==0);
        CHECK(handle==0x65000000u+(i+4u)*4u);
    }
    CHECK(table.count==100004);
    printf("PASS 1M repeated GetMethodID, 100k distinct methods, stable class-aware IDs; entries=%zu\n",table.count);
    agr_jni_method_table_destroy(&table);
    CHECK(table.count==0 && !table.entries && !table.buckets);
    return 0;
}
