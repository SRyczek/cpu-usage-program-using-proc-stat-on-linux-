
#include "../include/global_variables.h"
#include "../include/buffer.h"
#include "../include/analyzer.h"
#include "../include/watchDog.h"

/*
initAnalyzer() dynamically allocates memory for arrays
for prevKS(previous krenel statistic) and cpuPercentage.

The number of elements is equal to the number of 
processor cores plus one reserved for their sum.

Additionally initAnalyzer() assigns the names of cores to specific array elements.

analyzer() retrieves one element from the buffer and 
checks by name which core it is. Next performs calculations
for it using the previous values.

*/

kernel_statistics_t *prevKS;
double *cpuPercentage = NULL;

void initAnalyzer(void);
uint8_t whichCpu(char* n);

void* analyzer(void* __attribute__((unused)) arg) {

    unsigned long nonIdle, prevNonIdle, prevIdle, Idle, prevTotal,
                total, totalLd, idled;

    uint8_t prevIdx;
    kernel_statistics_t inputKs;

    while (programActivity == PROGRAM_RUNS) {

        prevIdx = 254;

        inputKs = cbuff_remove(cBuff);

        /* choose cpy by name */
        prevIdx = whichCpu(inputKs.cpuNum);

        /* calculate cpu usege in percentage */
        prevIdle = prevKS[prevIdx].idle + prevKS[prevIdx].iowait;
        prevNonIdle = prevKS[prevIdx].user + prevKS[prevIdx].nice + 
                        prevKS[prevIdx].system + prevKS[prevIdx].irq + prevKS[prevIdx].softirq + 
                        prevKS[prevIdx].steal;
        Idle = inputKs.idle + inputKs.iowait;
        nonIdle =     inputKs.user + inputKs.nice + inputKs.system + inputKs.irq + 
                        inputKs.softirq + inputKs.steal;

        prevTotal = prevNonIdle + prevIdle;
        total = nonIdle + Idle;

        totalLd = total - prevTotal;
        idled = Idle - prevIdle;

        if (totalLd != 0) {

            pthread_mutex_lock(&mutex);
            cpuPercentage[prevIdx] = ((double)(totalLd - (double)idled) / (double)totalLd) * 100;

            pthread_mutex_unlock(&mutex);
            /* assign previous values */
            memcpy(&prevKS[prevIdx], &inputKs, sizeof(inputKs));
            
        } else {
            /* numerator is less or equal 0 */
            /* DO NOTHING */
            logger_cbuff_add(loggerCBuff, 6);

        }

        atomic_store(&analyzerFlag, THREAD_WORKS);

    }
    return NULL;

}

uint8_t whichCpu(char* n) {

    for (uint8_t i = 0; i < (uint8_t)numCoresPlusOne; i++) {
        if (strcmp(n, prevKS[i].cpuNum) == 0) {
            return i;
        } 
    }
    logger_cbuff_add(loggerCBuff, 7);
    return 0;

}

void initAnalyzer() {

    /* allocate memory for previous kernel statistics array */
    //prevKS = (kernel_statistics_t*)malloc(numCoresPlusOne * sizeof(kernel_statistics_t));
    prevKS = (kernel_statistics_t*)calloc(numCoresPlusOne, sizeof(kernel_statistics_t));
    cpuPercentage = (double*)calloc(numCoresPlusOne, sizeof(double));

    /* set prevKS name to use in analyzer */
    /* WARNING!
        cpu index 0 is equal "cpu"
        cpu index 1 is equal "cpu0"
        cpu index 2 is equal "cpu1"
        cpu index 3 is equal "cpu2"
        ...
    */

    strcpy(prevKS[0].cpuNum, "cpu");
    for (uint8_t i = 1; i < (uint8_t)numCoresPlusOne; i++) {
        sprintf(prevKS[i].cpuNum, "cpu%d", i - 1);
    }

}
