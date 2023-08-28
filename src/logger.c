
#include "../include/global_variables.h"
#include "../include/buffer.h"
#include "../include/logger.h"
#include "../include/watchDog.h"

/*
The logger writes messages to a file that it receives from other threads. 
It utilizes a circular buffer for the writing process. 
Other threads add elements to the buffer, and the logger, during removal, 
retrieves the integral value present in the array. Each integral value corresponds 
to a specific message, which is described in the logMessageToFile[].
*/


const char* logMessageToFile[] = {
    "Program starts",                                                       /* Idx 0 */
    "Reader correctly open file",                                           /* Idx 1 */
    "Error opening file in reader",                                         /* Idx 2 */
    "Watchdog has detected that the analyzer is not working properly",      /* Idx 3 */    
    "Watchdog has detected that the reader is not working properly",        /* Idx 4 */
    "Watchdog has detected that the printer is not working properly",       /* Idx 5 */
    "In the analyzer was performed division by zero",                       /* Idx 6 */
    "WhichCpu function reports an error"                                    /* Idx 7 */
    "Watchdog has detected that the logger is not working properly"         /* Idx 8 */
};

void* logger() {

    time_t currentTime;
    struct tm *timeInfo;
    char timeString[30];

    while (programActivity == PROGRAM_RUNS) {

        pthread_mutex_lock(&mutex);
        while (loggerCBuff->count == 0) {
            pthread_cond_wait(&loggerStart, &mutex);
        }
        pthread_mutex_unlock(&mutex);


        int loggerMessage = logger_cbuff_remove(loggerCBuff);

        FILE *file1 = fopen("../log/log.txt", "a"); 

        if (file1 == NULL) {
            perror("Cannot open file\n");
            return 1;
        }
        /* calculate current time */
        time(&currentTime);
        timeInfo = localtime(&currentTime);
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeInfo);

        rewind(file1);
        fprintf(file1, "[%s] %s\n",timeString,logMessageToFile[loggerMessage]);
        fflush(file1);
        fclose(file1);

        atomic_store(&loggerFlag, THREAD_WORKS);

    }

    return 0;
}