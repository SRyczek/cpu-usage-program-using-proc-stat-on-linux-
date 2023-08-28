
#ifndef WATCHDOG_H
#define WATCHDOG_H

#include <stdatomic.h>

/* watchDogFlag */
extern volatile _Atomic int analyzerFlag;
extern volatile _Atomic int readerFlag;
extern volatile _Atomic int printerFlag;
extern volatile _Atomic int loggerFlag;

void* watchDog(void* arg);

#endif
