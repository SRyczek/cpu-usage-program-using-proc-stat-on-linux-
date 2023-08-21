
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_LENGHT 12 * 7

typedef struct {
    char cpuNum[10];
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
    uint8_t flag;
} kernel_statistics_t;

extern kernel_statistics_t kS[BUFFER_LENGHT];
extern double *cpuPercentage;
extern pthread_mutex_t mutex;
extern kernel_statistics_t *prevKS;
extern volatile uint8_t watchDogFlag;
extern uint8_t writeIdx;
extern uint8_t readIdx;

/* The number of cores plus one is required because 
you have to take into account the sum of all the */
extern long numCoresPlusOne;

/* function */
void initializer();
void helper();
double calculateCpuPercentage(long long* inPrevNonIdle, 
                              long long* inPrevIdle, 
                              long long* inNonIdle, 
                              long long* inIdle);
uint8_t whichCpu(char* n);




/* threads */
void* reader();
void* analyzer();
void* printer();
void* watchdog();
void* logger();