#include "../include/lib.h"

int main()
{


    pthread_t readerThread, analyzerThread, printerThread;
    pthread_mutex_t mutex;

    initializer();

    //pthread_mutex_init(&mutex, NULL);

    // pthread_create(&readerThread, NULL, &reader, NULL);
    // pthread_create(&analyzerThread, NULL, &analyzer, NULL);

    for(int i = 0; i < 13; i++) {
        reader();
    }

    helper();
    


    // pthread_join(readerThread, NULL);
    // pthread_join(analyzerThread, NULL);

    //pthread_mutex_destroy(&mutex);

    free(prevKS);
    free(cpuPercentage);


    return 0;
}