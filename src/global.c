
#include "../include/lib.h"

kernel_statistics_t kS;
double *cpuPercentage;
pthread_mutex_t mutex;
kernel_statistics_t *prevKS;
volatile _Atomic int analyzerFlag;
volatile _Atomic int readerFlag;
volatile _Atomic int printerFlag;

volatile _Atomic int programActivity;

cbuff_t* cBuff;

/* threads */
pthread_cond_t loggerStart;
pthread_cond_t loggerEnd;
pthread_t readerThread, analyzerThread, printerThread, watchDogThread, loggerThread;
char readerLog[50];


/* The number of cores plus one is required because 
you have to take into account the sum of all the */
long numCoresPlusOne;
