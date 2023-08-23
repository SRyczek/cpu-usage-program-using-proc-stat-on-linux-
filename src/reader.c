
#include "../include/lib.h"

void* reader() {
    while(1) {
        FILE* file = fopen("/proc/stat", "r");
        if (file != NULL) {

            /*  ten warunek zostal stworzony aby sprawdzic czy
                indeks nie przekroczy czasem maksymalnej wielkosci tablicy
                dlatego jesli petla for ruszy to nie powinien przekroczyc takiej liczby jak w warunku */

            for (int i = 0; i < numCoresPlusOne; i++) {
                fscanf(file, "%s %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
                            kS.cpuNum,
                            &kS.user,   &kS.nice, &kS.system,  &kS.idle, 
                            &kS.iowait, &kS.irq,  &kS.softirq, &kS.steal,
                            &kS.guest,  &kS.guest_nice);

                /* add data to buffor */
                cbuff_add(cBuff, kS);
            }
            printf("\n");
            fclose(file);
        } else {
            perror("Error opening file\n");
        }
            
        // pthread_mutex_lock(&mutex);
        // watchDogFlag = 1;
        // pthread_mutex_unlock(&mutex);

        //sleep(1);
    }

}