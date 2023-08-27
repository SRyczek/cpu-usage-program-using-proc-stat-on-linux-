
#include <stdio.h>

int main() {

    FILE *file1 = fopen("log.txt", "w");

    //fprintf(file1, "dadas");

    fclose(file1);


    printf("test\n");
    return 0;
}