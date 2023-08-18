
#include "../include/lib.h"

int main()
{

    printf("Program starts\n\n");

    pthread_t readerThread, analyzerThread, printerThread;
    pthread_mutex_t mutex;

    initializer();

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&readerThread, NULL, &reader, NULL);
    sleep(1);
    pthread_create(&analyzerThread, NULL, &analyzer, NULL);
    pthread_create(&printerThread, NULL, &printer, NULL);

    pthread_join(readerThread, NULL);
    pthread_join(analyzerThread, NULL);
    pthread_join(printerThread, NULL);


    pthread_mutex_destroy(&mutex);

    free(prevKS);
    free(cpuPercentage);


    return 0;
}