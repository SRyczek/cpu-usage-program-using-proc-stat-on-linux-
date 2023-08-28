
#include "../include/global_variables.h"
#include "../include/watchDog.h"
#include "../include/logger.h"
#include "../include/buffer.h"
/*

WatchDog thread checks that other threads are still running.
For verification, it uses variables dedicated to each thread, 
which are of type volatile _Atomic int.

Thread writes the value THREAD_NOT_WORKING into the flags waits 2 seconds 
and if the threads do not change this value the program ends.

*/

volatile _Atomic int analyzerFlag;
volatile _Atomic int readerFlag;
volatile _Atomic int printerFlag;
volatile _Atomic int loggerFlag;

void* watchDog() {
    while (programActivity == PROGRAM_RUNS) {

        atomic_store(&analyzerFlag, THREAD_NOT_WORKING);
        atomic_store(&readerFlag, THREAD_NOT_WORKING);
        atomic_store(&printerFlag, THREAD_NOT_WORKING);
        atomic_store(&loggerFlag, THREAD_NOT_WORKING);

        sleep(2);

        if (atomic_load(&analyzerFlag) == THREAD_NOT_WORKING) {
            logger_cbuff_add(loggerCBuff, 3);
            sleep(3);
            exit(0);
        } else if (atomic_load(&readerFlag) == THREAD_NOT_WORKING){
            logger_cbuff_add(loggerCBuff, 4);
            sleep(3);
            exit(0);
        } else if (atomic_load(&printerFlag) == THREAD_NOT_WORKING) {
            logger_cbuff_add(loggerCBuff, 5);
            sleep(3);
            exit(0); 
        } else if(atomic_load(&loggerFlag) == THREAD_NOT_WORKING) {
            logger_cbuff_add(loggerCBuff, 8);
            sleep(3);
            exit(0);
        }

    }
    return 0;
}