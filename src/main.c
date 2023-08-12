#include <stdio.h>
#include <pthread.h>
#include "../include/reader.h"


int main() {

    pthread_t readerThread;
    pthread_create(&readerThread, NULL, &reader, NULL);

    pthread_join(readerThread, NULL);
    return 0;
}