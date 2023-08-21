
#include "../include/lib.h"

void* printer() {

    while(1) {
        pthread_mutex_lock(&mutex);
        printf("cpu  USAGE %.2f %%\n", cpuPercentage[0]);
        for (int i = 1; i < numCoresPlusOne; i++) {
            printf("cpu%d USAGE %.2f %%\n", i - 1, cpuPercentage[i]);
        }
        pthread_mutex_unlock(&mutex);
        printf("\n");
        sleep(1);

        pthread_mutex_lock(&mutex);
        watchDogFlag = 1;
        pthread_mutex_unlock(&mutex);
    }
}