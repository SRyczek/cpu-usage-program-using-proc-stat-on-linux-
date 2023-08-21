
#include "../include/lib.h"


void initializer() {
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

    writeIdx = 0;
    readIdx = 0;
}


void* logger() {

}
