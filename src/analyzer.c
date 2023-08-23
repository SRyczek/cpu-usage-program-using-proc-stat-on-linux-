
#include "../include/lib.h"

void* analyzer() {

    while(1) {

        long long nonIdle, prevNonIdle;
        long long prevIdle, Idle;
        uint8_t prevIdx;

        kernel_statistics_t inputKs = cbuff_remove(cBuff);

        /* choose cpy by name */
        prevIdx = whichCpu(inputKs.cpuNum);

        
        prevIdle = prevKS[prevIdx].idle + prevKS[prevIdx].iowait;
        prevNonIdle = prevKS[prevIdx].user + prevKS[prevIdx].nice + 
                        prevKS[prevIdx].system + prevKS[prevIdx].irq + prevKS[prevIdx].softirq + 
                        prevKS[prevIdx].steal;
        Idle = inputKs.idle + inputKs.iowait;
        nonIdle =     inputKs.user + inputKs.nice + inputKs.system + inputKs.irq + 
                        inputKs.softirq + inputKs.steal;

        cpuPercentage[prevIdx] = calculateCpuPercentage(&prevNonIdle, &prevIdle, &nonIdle, &Idle);

        /* assign previous values */
        memcpy(&prevKS[prevIdx], &inputKs, sizeof(inputKs));

        readIdx++;

        pthread_mutex_lock(&mutex);
        watchDogFlag = 1;
        pthread_mutex_unlock(&mutex);
        //sleep(1);
    }

}

uint8_t whichCpu(char* n) {

    for(int i = 0; i < numCoresPlusOne; i++) {
        if(strcmp(n, prevKS[i].cpuNum) == 0) {
            return i;
        } 
    }

    printf("whichCpu error\n");
    return 0;

}

double calculateCpuPercentage(long long* inPrevNonIdle, 
                              long long* inPrevIdle, 
                              long long* inNonIdle, 
                              long long* inIdle) {

    long long prevTotal, total;

    prevTotal = *inPrevNonIdle + *inPrevIdle;
    total = *inNonIdle + *inIdle;

    return (double)((total - prevTotal) - (*inIdle - *inPrevIdle)) / (total - prevTotal) * 100;

}