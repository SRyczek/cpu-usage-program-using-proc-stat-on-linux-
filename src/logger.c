
#include "../include/lib.h"

void* logger() {

    while(programActivity == PROGRAM_RUNS) {
        
        pthread_cond_wait(&loggerStart, &mutex);
        //zapisz do pliku
        printf("Test %s\n", readerLog);
        pthread_cond_broadcast(&loggerEnd);

    }
    //return 0;
}