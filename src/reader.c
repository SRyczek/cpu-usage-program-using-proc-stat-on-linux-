
#include "../include/global_variables.h"
#include "../include/buffer.h"
#include "../include/watchDog.h"

/*

Reader thread opens the /proc/stat file using the fopen function.
Reads data via foben function and writes to kS, which is type of kernel_statistics_t.
After saving the data, it adds it to the buffer and close the file.

The delay in this thread was introduced due to the length of 
the measurement of calculations taken from /proc/stat.

*/


void* reader() {

    kernel_statistics_t kS;
    
    while (programActivity == PROGRAM_RUNS) {
        FILE* file = fopen("/proc/stat", "r");
        if (file != NULL) {
            logger_cbuff_add(loggerCBuff, 1);
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
            logger_cbuff_add(loggerCBuff, 2);
        }
            
        usleep(1000000);

        atomic_store(&readerFlag, THREAD_WORKS);
    }

    return 0;

}