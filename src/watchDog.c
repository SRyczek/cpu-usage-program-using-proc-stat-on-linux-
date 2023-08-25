
#include "../include/lib.h"


void* watchDog() {
    while(programActivity == PROGRAM_RUNS) {

        atomic_store(&analyzerFlag, THREAD_NOT_WORKING);
        atomic_store(&readerFlag, THREAD_NOT_WORKING);
        atomic_store(&printerFlag, THREAD_NOT_WORKING);
        
        sleep(2);

        if(atomic_load(&analyzerFlag) == THREAD_NOT_WORKING) {
            printf("Analyzer is not working\n");
            sleep(3);
            exit(0);
        } else if (atomic_load(&readerFlag) == THREAD_NOT_WORKING){
            printf("Reader is not working\n");
            sleep(3);
            exit(0);
        } else if (atomic_load(&printerFlag) == THREAD_NOT_WORKING) {
            printf("Printer is not working\n");
            sleep(3);
            exit(0); 
        }

    }
}