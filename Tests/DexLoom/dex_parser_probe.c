#include "dx_dex.h"
#include "dx_log.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static uint8_t *read_file(const char *path,uint32_t *size) {
    FILE *file=fopen(path,"rb"); long length; uint8_t *bytes;
    if(!file||fseek(file,0,SEEK_END)||((length=ftell(file))<0)||
       length>0xffffffffL||fseek(file,0,SEEK_SET)) { if(file)fclose(file); return NULL; }
    bytes=(uint8_t *)malloc((size_t)length);
    if(!bytes||(length&&fread(bytes,1,(size_t)length,file)!=(size_t)length)) {
        free(bytes);fclose(file);return NULL;
    }
    fclose(file);*size=(uint32_t)length;return bytes;
}

int main(int argc,char **argv) {
    if(argc!=2) { fprintf(stderr,"usage: dex_parser_probe classes.dex\n");return 2; }
    uint32_t size=0;uint8_t *bytes=read_file(argv[1],&size);DxDexFile *dex=NULL;
    if(!bytes) { fprintf(stderr,"read failed: %s\n",argv[1]);return 2; }
    dx_log_init();DxResult result=dx_dex_parse(bytes,size,&dex);
    printf("{\"result\":\"%s\",\"code\":%d,\"size\":%u",dx_result_string(result),(int)result,size);
    if(dex)printf(",\"strings\":%u,\"types\":%u,\"protos\":%u,\"fields\":%u,\"methods\":%u,\"classes\":%u",
        dex->string_count,dex->type_count,dex->proto_count,dex->field_count,dex->method_count,dex->class_count);
    puts("}");dx_dex_free(dex);free(bytes);return result==DX_OK?0:1;
}
