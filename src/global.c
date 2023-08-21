
#include "../include/lib.h"

kernel_statistics_t kS[BUFFER_LENGHT];
double *cpuPercentage;
pthread_mutex_t mutex;
kernel_statistics_t *prevKS;
volatile uint8_t watchDogFlag;
uint8_t writeIdx;
uint8_t readIdx;

/* The number of cores plus one is required because 
you have to take into account the sum of all the */
long numCoresPlusOne;
