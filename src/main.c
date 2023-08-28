

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../include/global_variables.h"
#include "../include/buffer.h"
#include "../include/analyzer.h"
#include "../include/printer.h"
#include "../include/reader.h"
#include "../include/watchDog.h"
#include "../include/logger.h"

__attribute__((noreturn)) void term(void);
void initSigterm(void);

int main() {

    pthread_t readerThread, analyzerThread, printerThread, watchDogThread, loggerThread;
    size_t numCores, bufferLen;
    /* set threads to RUN */
    programActivity = PROGRAM_RUNS;

    /* calculate num of cores in hardware */
    numCores = (size_t)sysconf(_SC_NPROCESSORS_ONLN);
    printf("Num of cores: %ld\n", numCores);
    numCoresPlusOne = numCores + 1;
    bufferLen = numCoresPlusOne * BUFFER_MULTIPLIER;

    initAnalyzer();
    initSigterm();

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&loggerStart, NULL);

    cBuff = cbuff_new((int)bufferLen);
    loggerCBuff = logger_cbuff_new(LOGGER_LENGTH);

    printf("Program starts\n\n");
    printf("ID procesu (PID): %d\n", getpid());

    logger_cbuff_add(loggerCBuff, 0);

    pthread_create(&readerThread, NULL, &reader, NULL);
    pthread_create(&analyzerThread, NULL, &analyzer, NULL);
    pthread_create(&watchDogThread, NULL, &watchDog, NULL);
    usleep(500000);
    pthread_create(&printerThread, NULL, &printer, NULL);
    pthread_create(&loggerThread, NULL, &logger, NULL);


    pthread_join(readerThread, NULL);
    pthread_join(analyzerThread, NULL);
    pthread_join(watchDogThread, NULL);
    pthread_join(printerThread, NULL);
    pthread_join(loggerThread, NULL);

    return 0;
}



void initSigterm() {
    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_handler = term;
    sigaction(SIGTERM, &action, NULL);
}

void term() {
    /* free all memory, destroy mutex and stops all threads */
    programActivity = PROGRAM_STOP;
    usleep(2000000);
    pthread_mutex_destroy(&mutex);
    free(prevKS);
    free(cpuPercentage);
    cbuff_delete(cBuff, NULL);
    cbuff_delete(NULL, loggerCBuff);
    printf("Program stops\n");
    exit(0);
}
