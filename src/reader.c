
#include "../include/reader.h"

void* reader(void){

    printf("test\n");

    FILE *file = fopen("/proc/stat", "r");

    char buffer[256];

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        printf("%s", buffer);
    }

    fclose(file);
}