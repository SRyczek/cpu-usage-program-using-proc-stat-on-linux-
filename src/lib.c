
#include "../include/lib.h"

/* global variables */
kernel_statistics_t kS[BUFFER_LENGHT];
double *cpuPercentage;
pthread_mutex_t  mutex;
kernel_statistics_t *prevKS;

uint8_t writeIdx;
uint8_t readIdx;
/* The number of cores plus one is required because 
you have to take into account the sum of all the */
long numCoresPlusOne;

void initializer() {
    long numCores = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Num of cores: %ld\n", numCores);
    numCoresPlusOne = numCores + 1;
    /* allocate memory for previous kernel statistics array */
    prevKS = (kernel_statistics_t *)malloc(numCoresPlusOne * sizeof(kernel_statistics_t));
    cpuPercentage = (double *)malloc(numCoresPlusOne * sizeof(double));

}

void* reader() {
    FILE* file = fopen("/proc/stat", "r");
    if (file != NULL) {

        /*  ten warunek zostal stworzony aby sprawdzic czy
            indeks nie przekroczy czasem maksymalnej wielkosci tablicy
            dlatego jesli petla for ruszy to nie powinien przekroczyc takiej liczby jak w warunku */

        if(writeIdx > (BUFFER_LENGHT - numCoresPlusOne)) {
            writeIdx = 0;
        }
        
        printf("Write index: %d\n", writeIdx);
        for (int i = 0; i < numCoresPlusOne; i++) {
            fscanf(file, "%s %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
                        kS[writeIdx].cpuNum,
                        &kS[writeIdx].user,   &kS[writeIdx].nice, &kS[writeIdx].system,  &kS[writeIdx].idle, 
                        &kS[writeIdx].iowait, &kS[writeIdx].irq,  &kS[writeIdx].softirq, &kS[writeIdx].steal,
                        &kS[writeIdx].guest,  &kS[writeIdx].guest_nice);

            printf("%s %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", 
                        kS[writeIdx].cpuNum,
                        kS[writeIdx].user,   kS[writeIdx].nice, kS[writeIdx].system,  kS[writeIdx].idle, 
                        kS[writeIdx].iowait, kS[writeIdx].irq,  kS[writeIdx].softirq, kS[writeIdx].steal,
                        kS[writeIdx].guest,  kS[writeIdx].guest_nice);
            writeIdx++;
            
        }
        
    }
    fclose(file);

}


void* analyzer() {

    long long nonIdle[numCoresPlusOne];
    long long prevNonIdle[numCoresPlusOne];

    long long total[numCoresPlusOne];
    long long prevTotal[numCoresPlusOne];

    long long prevIdle[numCoresPlusOne];
    long long Idle[numCoresPlusOne];

    for (int i = 0; i < numCoresPlusOne; i++) {
        prevIdle[i] = prevKS[i].idle + prevKS[i].iowait;

        prevNonIdle[i] = prevKS[i].user + prevKS[i].nice + 
                        prevKS[i].system + prevKS[i].irq + prevKS[i].softirq + 
                        prevKS[i].steal;

        //pthread_mutex_lock(&mutex);

        Idle[i] = kS[i].idle + kS[i].iowait;

        nonIdle[i] =     kS[i].user + kS[i].nice + kS[i].system + kS[i].irq + 
                        kS[i].softirq + kS[i].steal;

        //pthread_mutex_unlock(&mutex);

        prevTotal[i] = prevNonIdle[i] + prevIdle[i];
        total[i] = nonIdle[i] + Idle[i];

        cpuPercentage[i] = (double)((total[i] - prevTotal[i]) - (Idle[i] - prevIdle[i])) / (total[i] - prevTotal[i]) * 100;

        printf("CPU perc %.2f\n", cpuPercentage[i]);

        /* assign previous values */
        prevKS[i] = kS[i];
    }

}



void* printer() {

    for (int i = 0; i < numCoresPlusOne; i++) {
        printf("CPU%d USAGE %.2f %%\n", i, cpuPercentage[i]);
    }
}

void* watchdog() {

}

void* logger() {

}

void helper() {

    for(int i = 0; i < BUFFER_LENGHT; i++) {


        printf("%d:   ", i);
        printf("%s %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", 
                    kS[i].cpuNum,
                    kS[i].user,   kS[i].nice, kS[i].system,  kS[i].idle, 
                    kS[i].iowait, kS[i].irq,  kS[i].softirq, kS[i].steal,
                    kS[i].guest,  kS[i].guest_nice);
    }
}