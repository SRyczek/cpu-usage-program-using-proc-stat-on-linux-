
#include "../include/lib.h"

void* logger() {

    while(1) {
        
        pthread_cond_wait(&loggerStart, &mutex);
        //zapisz do pliku
        printf("Test %s\n", readerLog);
        pthread_cond_broadcast(&loggerEnd);

    }

}