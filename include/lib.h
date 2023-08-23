
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdatomic.h>


#define BUFFER_LENGHT 12 * 7
#define THREAD_WORKS 1
#define THREAD_NOT_WORKING 0


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

typedef struct cbuff_{
    kernel_statistics_t * buff;
    int start;
    int end;
    int size;
    int count;
} cbuff_t;



extern kernel_statistics_t kS;
extern double *cpuPercentage;
extern pthread_mutex_t mutex;
extern kernel_statistics_t *prevKS;
extern pthread_cond_t loggerStart;
extern pthread_cond_t loggerEnd;
extern pthread_t readerThread;
extern pthread_t analyzerThread; 
extern pthread_t printerThread;
extern pthread_t watchDogThread;
extern pthread_t oggerThread;
extern cbuff_t* cBuff;

/* watchDogFlag */
extern volatile _Atomic int analyzerFlag;
extern volatile _Atomic int readerFlag;
extern volatile _Atomic int printerFlag;


extern char readerLog[50];
extern char analyzerLog[50];
extern char watchDogLog[50];
extern char printerLog[50];

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
void* watchDog();
void* logger();

/*buffor */
cbuff_t* cbuff_new(int size);
void cbuff_add(cbuff_t * cb, kernel_statistics_t elem);
kernel_statistics_t cbuff_remove(cbuff_t * cb);