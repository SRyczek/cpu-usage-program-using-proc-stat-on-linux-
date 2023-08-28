
#include "../include/global_variables.h"
#include "../include/buffer.h"

volatile _Atomic int programActivity;

/* threads */
pthread_cond_t loggerStart;
log_cbuff_t* loggerCBuff;
pthread_mutex_t mutex;

/* The number of cores plus one is required because 
you have to take into account the sum of all the */
size_t numCoresPlusOne;
