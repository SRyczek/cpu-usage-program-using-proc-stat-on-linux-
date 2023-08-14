
#include "../include/lib.h"

typedef struct {
    long long user;
    long long nice;
    long long system;
    long long idle;
    long long iowait;
    long long irq;
    long long softirq;
    long long steal;
    long long guest;
    long long guest_nice;
} kernelStatistics_t;

kernelStatistics_t kS[MAX_CPU_NUM], prevKS[MAX_CPU_NUM];

long long nonIdle[MAX_CPU_NUM];
long long prevNonIdle[MAX_CPU_NUM];

long long total[MAX_CPU_NUM];
long long prevTotal[MAX_CPU_NUM];

long long cpuPercentage[MAX_CPU_NUM];

uint8_t ksIndex = 0;

void *reader()
{
    char cpuNum[10];

    FILE *file = fopen("/proc/stat", "r");

    if (file != NULL) {   
        memset(cpuNum, 0, sizeof(cpuNum));
        fscanf(file, "%s", cpuNum);

        while (strncmp(cpuNum, "cpu", 3) == 0) {
            fscanf(file, "%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
                          &kS[ksIndex].user,   &kS[ksIndex].nice, &kS[ksIndex].system,  &kS[ksIndex].idle, 
                          &kS[ksIndex].iowait, &kS[ksIndex].irq,  &kS[ksIndex].softirq, &kS[ksIndex].steal,
                          &kS[ksIndex].guest,  &kS[ksIndex].guest_nice);
        
            ksIndex++;

            memset(cpuNum, 0, sizeof(cpuNum));
            fscanf(file, "%s", cpuNum);
        } 
    }
    fclose(file);
}

void *analyzer() {

    for(int i = 0; i < MAX_CPU_NUM; i++) {
        prevKS[i].idle += prevKS[i].iowait;
        kS[i].idle += kS[i].iowait;

        prevNonIdle[i] = prevKS[i].user + prevKS[i].nice + 
                         prevKS[i].system + prevKS[i].irq + prevKS[i].softirq + 
                         prevKS[i].steal;

        nonIdle[i] =     kS[i].user + kS[i].nice + kS[i].system + kS[i].irq + 
                         kS[i].softirq + kS[i].steal;

        prevTotal[i] = prevNonIdle[i] + prevKS[i].idle;
        total[i] = nonIdle[i] + kS[i].idle;

        cpuPercentage[i] = ((total[i] - prevTotal[i]) - (kS[i].idle - prevKS[i].idle)) / (total[i] - prevTotal[i]);

        /* assign previous values */
        prevKS[i].idle = kS[i].idle;
        prevNonIdle[i] = nonIdle[i];
        prevKS[i] = kS[i];
    }

}

void ksPrinter() {
    for (int i = 0; i < MAX_CPU_NUM; i++) {
        printf("%lld ", kS[i].user);
        printf("%lld ", kS[i].nice);
        printf("%lld ", kS[i].system);
        printf("%lld ", kS[i].idle);
        printf("%lld ", kS[i].iowait);
        printf("%lld ", kS[i].irq);
        printf("%lld ", kS[i].softirq);
        printf("%lld ", kS[i].steal);
        printf("%lld ", kS[i].guest);
        printf("%lld \n", kS[i].guest_nice);
    }
}