#include <stdio.h>
#include <pthread.h>
#include "../include/lib.h"

int main() {

    pthread_t readerThread, analyzerThread;
    //pthread_create(&readerThread, NULL, &reader, NULL);
    //pthread_create(&analyzerThread, NULL, &analyzer, NULL);
    reader();
    analyzer();
    sleep(4);
    printf("\n\n");
    reader();
    analyzer();
    sleep(4);
    printf("\n\n");
    reader();
    analyzer();
    //pthread_join(readerThread, NULL);
    //pthread_join(analyzerThread, NULL);


    return 0;
}