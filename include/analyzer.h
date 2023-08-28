
#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdint.h>

extern double *cpuPercentage;

void* analyzer(void* arg);
void initAnalyzer(void);
uint8_t whichCpu(char* n);

#endif
