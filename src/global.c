
#include "../include/global.h"
#include "../include/buffer.h"

volatile _Atomic int programActivity;

/* threads */
pthread_cond_t loggerStart;
pthread_cond_t loggerEnd;

pthread_mutex_t mutex;

/* The number of cores plus one is required because 
you have to take into account the sum of all the */
long numCoresPlusOne;

cbuff_t* cBuff;