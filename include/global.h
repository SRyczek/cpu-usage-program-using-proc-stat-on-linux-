
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdatomic.h>

#define BUFFER_MULTIPLIER 12
#define THREAD_WORKS 1
#define THREAD_NOT_WORKING 0

#define PROGRAM_RUNS 1
#define PROGRAM_STOP 0

extern pthread_mutex_t mutex;
extern pthread_cond_t loggerStart;
extern pthread_cond_t loggerEnd;

extern volatile _Atomic int programActivity;

extern char readerLog[50];
extern char analyzerLog[50];
extern char watchDogLog[50];
extern char printerLog[50];

/* The number of cores plus one is required because 
you have to take into account the sum of all the */
extern long numCoresPlusOne;

void initSigterm();
void term();


