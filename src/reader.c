
#include "../include/lib.h"

void* reader() {
    while(1) {
        FILE* file = fopen("/proc/stat", "r");
        if (file != NULL) {

            for (int i = 0; i < numCoresPlusOne; i++) {
                fscanf(file, "%s %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
                            kS.cpuNum,
                            &kS.user,   &kS.nice, &kS.system,  &kS.idle, 
                            &kS.iowait, &kS.irq,  &kS.softirq, &kS.steal,
                            &kS.guest,  &kS.guest_nice);

                /* add data to buffor */
                cbuff_add(cBuff, kS);
            }

            fclose(file);
        } else {
            perror("Error opening file\n");
        }
            
        usleep(1000000);

        atomic_store(&readerFlag, THREAD_WORKS);

    }

}