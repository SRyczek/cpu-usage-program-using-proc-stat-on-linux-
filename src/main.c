

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

int main() {

    pthread_t readerThread, analyzerThread, printerThread, watchDogThread, loggerThread;

    /* set threads to RUN */
    programActivity = PROGRAM_RUNS;

    /* calculate num of cores in hardware */
    long numCores = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Num of cores: %ld\n", numCores);
    numCoresPlusOne = numCores + 1;
    uint8_t bufferLen = numCoresPlusOne * BUFFER_MULTIPLIER;

    initAnalyzer();
    initSigterm();

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&loggerStart, NULL);

    cBuff = cbuff_new(bufferLen);
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

void term() {
    /* free all memory, destroy mutex and stops all threads */
    programActivity = PROGRAM_STOP;
    pthread_mutex_destroy(&mutex);
    free(prevKS);
    free(cpuPercentage);
    cbuff_delete(cBuff);
    cbuff_delete(loggerCBuff);
    printf("Program stops\n");

    exit(0);
}

void initSigterm() {
    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_handler = term;
    sigaction(SIGTERM, &action, NULL);
}