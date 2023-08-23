
#include "../include/lib.h"

int main() {

    /* calculate num of cores in hardware */
    long numCores = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Num of cores: %ld\n", numCores);
    numCoresPlusOne = numCores + 1;

    /* allocate memory for previous kernel statistics array */
    prevKS = (kernel_statistics_t *)malloc(numCoresPlusOne * sizeof(kernel_statistics_t));
    cpuPercentage = (double *)malloc(numCoresPlusOne * sizeof(double));

    /* set prevKS name to use in analyzer */
    /* WARNING! 
        cpu index 0 is equal "cpu" 
        cpu index 1 is equal "cpu0" 
        cpu index 2 is equal "cpu1" 
        cpu index 3 is equal "cpu2" 
        ...
        */
    strcpy(prevKS[0].cpuNum, "cpu");
    for(int i = 1; i < numCoresPlusOne; i++) {
        sprintf(prevKS[i].cpuNum, "cpu%d", i - 1);
    }

    cBuff = cbuff_new(BUFFER_LENGHT);

    printf("Program starts\n\n");

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&readerThread, NULL, &reader, NULL);
    pthread_create(&analyzerThread, NULL, &analyzer, NULL);
    pthread_create(&printerThread, NULL, &printer, NULL);


    pthread_join(readerThread, NULL);
    pthread_join(analyzerThread, NULL);

    pthread_mutex_destroy(&mutex);
    free(prevKS);
    free(cpuPercentage);


    return 0;
}