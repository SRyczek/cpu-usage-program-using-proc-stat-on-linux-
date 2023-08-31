
#include "../include/global_variables.h"
#include "../include/analyzer.h"
#include "../include/watchDog.h"
#include "../include/buffer.h"
/*

Thread printer prints messages depending on the number of cores
every second.

*/
void* printer(void* arg);

void* printer(void* __attribute__((unused)) arg) {

    while (programActivity == PROGRAM_RUNS) {
        usleep(1000000);
        pthread_mutex_lock(&mutex);
        printf("cpu  USAGE %.2f %%\n", cpuPercentage[0]);
        for (size_t i = 1; i < numCoresPlusOne; i++) {
           printf("cpu%lu USAGE %.2f %%\n", i - 1, cpuPercentage[i]);
        }
        pthread_mutex_unlock(&mutex);
        printf("\n");
        atomic_store(&printerFlag, THREAD_WORKS);
    }

    return NULL;
}
