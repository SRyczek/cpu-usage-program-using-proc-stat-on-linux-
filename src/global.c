
#include "../include/global.h"
#include "../include/buffer.h"

volatile _Atomic int programActivity;

/* threads */
pthread_cond_t loggerStart;
pthread_cond_t loggerEnd;

pthread_mutex_t mutex;


