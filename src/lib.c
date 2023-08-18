
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

void* reader() {

    while(1) {

        if (writeIdx > (BUFFER_LENGHT - numCoresPlusOne)) {
            writeIdx = 0;
            printf("Buffor reset\n");
        }

        if (kS[writeIdx + numCoresPlusOne].user != 0) {
            //printf("Reader reads data too fast\n");

        } else {

            FILE* file = fopen("/proc/stat", "r");
            if (file != NULL) {

                /*  ten warunek zostal stworzony aby sprawdzic czy
                    indeks nie przekroczy czasem maksymalnej wielkosci tablicy
                    dlatego jesli petla for ruszy to nie powinien przekroczyc takiej liczby jak w warunku */

                
                printf("Write index: %d\n", writeIdx);
                pthread_mutex_lock(&mutex);
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
                pthread_mutex_unlock(&mutex);
            }
            fclose(file);
            
        }
        sleep(13);


    }

}

void* analyzer() {

    while(1) {

        long long nonIdle, prevNonIdle;
        long long total, prevTotal;
        long long prevIdle, Idle;
        uint8_t prevIdx;

        if (readIdx == writeIdx) {

            //printf("ReadIdx is equal writeIdx\n");
        } else {

            /* go readIdx to start */
            if (readIdx >= BUFFER_LENGHT) {
                readIdx = 0;
            }
            pthread_mutex_lock(&mutex);
            prevIdx = whichCpu(kS[readIdx].cpuNum);
            pthread_mutex_unlock(&mutex);
            prevIdle = prevKS[prevIdx].idle + prevKS[prevIdx].iowait;

            prevNonIdle = prevKS[prevIdx].user + prevKS[prevIdx].nice + 
                            prevKS[prevIdx].system + prevKS[prevIdx].irq + prevKS[prevIdx].softirq + 
                            prevKS[prevIdx].steal;


            pthread_mutex_lock(&mutex);
            Idle = kS[readIdx].idle + kS[readIdx].iowait;

            nonIdle =     kS[readIdx].user + kS[readIdx].nice + kS[readIdx].system + kS[readIdx].irq + 
                            kS[readIdx].softirq + kS[readIdx].steal;
            pthread_mutex_unlock(&mutex);


            prevTotal = prevNonIdle + prevIdle;
            total = nonIdle + Idle;

            cpuPercentage[prevIdx] = (double)((total - prevTotal) - (Idle - prevIdle)) / (total - prevTotal) * 100;

            printf("CPU perc %.2f %%\n", cpuPercentage[prevIdx]);

            pthread_mutex_lock(&mutex);
            /* assign previous values */
            memcpy(&prevKS[prevIdx], &kS[readIdx], sizeof(&kS[readIdx]));

            /* reset struct */
            memset(&kS[readIdx], 0, sizeof(kS[readIdx]));
            pthread_mutex_unlock(&mutex);
            readIdx++;

            
        }
        sleep(1);
    }


}



void* printer() {

    while (1) {

        for (int i = 0; i < numCoresPlusOne; i++) {
            pthread_mutex_lock(&mutex);
            printf("cpu%d USAGE %.2f %%\n", i, cpuPercentage[i]);
            pthread_mutex_unlock(&mutex);
        }
        printf("\n");
        sleep(1);
    }
}

void* watchdog() {

}

void* logger() {

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