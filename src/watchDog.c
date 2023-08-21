
#include "../include/lib.h"

void* watchdog() {
    while(1) {
        pthread_mutex_lock(&mutex);
        watchDogFlag = 0;
        pthread_mutex_unlock(&mutex);
        sleep(2);
        if(watchDogFlag == 0) {

            printf("Watchdog Error\n");
            sleep(3);
            exit(0);
        }
    }
}