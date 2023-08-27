
#include "../include/global.h"

void* logger() {

    while(programActivity == PROGRAM_RUNS) {
        
        pthread_cond_wait(&loggerStart, &mutex);
        //zapisz do pliku
        
        pthread_cond_broadcast(&loggerEnd);

    }
    return 0;
}