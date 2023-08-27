
#include "../include/global.h"
#include "../include/buffer.h"
#include "../include/logger.h"

const char* logMessageToFile[] = {
    "printer works correctly",
    "printer2 works correctly",
};


void* logger() {


    time_t currentTime;
    struct tm *timeInfo;
    char timeString[30];
    
    while(programActivity == PROGRAM_RUNS) {

        pthread_mutex_lock(&mutex);
        while(loggerCBuff->count == 0) {
            pthread_cond_wait(&loggerStart, &mutex);
        }
        pthread_mutex_unlock(&mutex);


        int loggerMessage = logger_cbuff_remove(loggerCBuff);

        FILE *file1 = fopen("log.txt", "a"); 

        if (file1 == NULL) {
            perror("Cannot open file\n");
            return 1;
        }

        time(&currentTime);
        timeInfo = localtime(&currentTime);
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeInfo);

        rewind(file1);
        fprintf(file1, "[%s] %s\n",timeString,logMessageToFile[loggerMessage]);
        fflush(file1);
        fclose(file1);

    }

    return 0;
}