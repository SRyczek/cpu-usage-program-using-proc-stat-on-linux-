
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
} kernel_statistics_t;

extern double *cpuPercentage;
extern pthread_mutex_t mutex;
extern kernel_statistics_t *prevKS;

void initializer();
void* reader();
void* analyzer();
void* printer();
