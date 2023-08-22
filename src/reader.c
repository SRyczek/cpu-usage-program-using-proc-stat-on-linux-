
#include "../include/lib.h"

void* reader() {

    while(1) {

        if (writeIdx > (BUFFER_LENGHT - numCoresPlusOne)) {

            writeIdx = 0;
            printf("Buffor reset\n");
            // strcpy(readerLog, "Buffor reset\n");
            // pthread_cond_signal(&loggerStart);
            // pthread_mutex_lock(&mutex);
            // pthread_cond_wait(&loggerEnd, &mutex);
            // pthread_mutex_unlock(&mutex);

        }

        if (kS[writeIdx + numCoresPlusOne].flag == 1) {
            
            //printf("Reader reads data too fast\n");

        } else {

            FILE* file = fopen("/proc/stat", "r");
            if (file != NULL) {

                /*  ten warunek zostal stworzony aby sprawdzic czy
                    indeks nie przekroczy czasem maksymalnej wielkosci tablicy
                    dlatego jesli petla for ruszy to nie powinien przekroczyc takiej liczby jak w warunku */

                //printf("Writeidx: %d\n", writeIdx);
                            
                pthread_mutex_lock(&mutex);
                for (int i = 0; i < numCoresPlusOne; i++) {
                    fscanf(file, "%s %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
                                kS[writeIdx].cpuNum,
                                &kS[writeIdx].user,   &kS[writeIdx].nice, &kS[writeIdx].system,  &kS[writeIdx].idle, 
                                &kS[writeIdx].iowait, &kS[writeIdx].irq,  &kS[writeIdx].softirq, &kS[writeIdx].steal,
                                &kS[writeIdx].guest,  &kS[writeIdx].guest_nice);

                    kS[writeIdx].flag = 1;

                    // printf("%s %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", 
                    //             kS[writeIdx].cpuNum,
                    //             kS[writeIdx].user,   kS[writeIdx].nice, kS[writeIdx].system,  kS[writeIdx].idle, 
                    //             kS[writeIdx].iowait, kS[writeIdx].irq,  kS[writeIdx].softirq, kS[writeIdx].steal,
                    //             kS[writeIdx].guest,  kS[writeIdx].guest_nice);
                    writeIdx++;
                    
                }
                pthread_mutex_unlock(&mutex);
                fclose(file);
            } else {
                perror("Error opening file\n");
            }
            
            
        }
        sleep(1);

        pthread_mutex_lock(&mutex);
        watchDogFlag = 1;
        pthread_mutex_unlock(&mutex);
    }

}