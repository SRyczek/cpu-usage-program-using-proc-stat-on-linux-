
#include "../include/lib.h"

void* analyzer() {

    while(1) {

        long long nonIdle, prevNonIdle;
        long long prevIdle, Idle;
        long long prevTotal, total;

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

        prevTotal = prevNonIdle + prevIdle;
        total = nonIdle + Idle;

        long long totalLd = total - prevTotal;
        long long idled = Idle - prevIdle;

        cpuPercentage[prevIdx] = ((double)(totalLd - (double)idled) / (double)totalLd) * 100;

        /* assign previous values */
        memcpy(&prevKS[prevIdx], &inputKs, sizeof(inputKs));

        atomic_store(&analyzerFlag, THREAD_WORKS);

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
