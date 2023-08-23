
#include "../include/lib.h"

kernel_statistics_t kS;
double *cpuPercentage;
pthread_mutex_t mutex;
kernel_statistics_t *prevKS;
volatile uint8_t watchDogFlag;
uint8_t writeIdx;
uint8_t readIdx;
cbuff_t* cBuff;

/* threads */
pthread_cond_t loggerStart;
pthread_cond_t loggerEnd;
pthread_t readerThread, analyzerThread, printerThread, watchDogThread, loggerThread;
char readerLog[50];


/* The number of cores plus one is required because 
you have to take into account the sum of all the */
long numCoresPlusOne;
