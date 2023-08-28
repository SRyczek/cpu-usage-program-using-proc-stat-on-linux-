

#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
    unsigned long steal;
    unsigned long guest;
    unsigned long guest_nice;
    char cpuNum[8];
} kernel_statistics_t;

typedef struct cbuff_{
    kernel_statistics_t* buff;
    int start;
    int end;
    int count;
    int size;
} cbuff_t;

typedef struct log_cbuff_{
    int* buff;
    int start;
    int end;
    int count;
    int size;
} log_cbuff_t;

extern kernel_statistics_t *prevKS;
extern cbuff_t* cBuff;
extern log_cbuff_t* loggerCBuff;

/*buffor */
cbuff_t* cbuff_new(int size);
void cbuff_add(cbuff_t* cb, kernel_statistics_t elem);
kernel_statistics_t cbuff_remove(cbuff_t* cb);

log_cbuff_t* logger_cbuff_new(int size);
void logger_cbuff_add(log_cbuff_t* cb, int elem);
int logger_cbuff_remove(log_cbuff_t* cb);

void cbuff_delete(cbuff_t* cb, log_cbuff_t* logCb);

#endif
