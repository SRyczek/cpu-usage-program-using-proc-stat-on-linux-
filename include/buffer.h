

#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>

typedef struct {
    char cpuNum[10];
    long long user;
    long long nice;
    long long system;
    long long idle;
    long long iowait;
    long long irq;
    long long softirq;
    long long steal;
    long long guest;
    long long guest_nice;
    uint8_t flag;
} kernel_statistics_t;

typedef struct cbuff_{
    kernel_statistics_t* buff;
    int start;
    int end;
    int size;
    int count;
} cbuff_t;

typedef struct log_cbuff_{
    int* buff;
    int start;
    int end;
    int size;
    int count;
} log_cbuff_t;

extern kernel_statistics_t *prevKS;
extern cbuff_t* cBuff;
extern log_cbuff_t* loggerCBuff;

/*buffor */
cbuff_t* cbuff_new(int size);
void cbuff_add(cbuff_t * cb, kernel_statistics_t elem);
kernel_statistics_t cbuff_remove(cbuff_t * cb);
void cbuff_delete(cbuff_t * cb);

log_cbuff_t* logger_cbuff_new(int size);
void logger_cbuff_add(log_cbuff_t * cb, int elem);
int logger_cbuff_remove(log_cbuff_t * cb);

#endif