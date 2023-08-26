
#ifndef ANALYZER_H
#define ANALYZER_H

extern double *cpuPercentage;

void* analyzer();
void initAnalyzer();
uint8_t whichCpu(char* n);

#endif