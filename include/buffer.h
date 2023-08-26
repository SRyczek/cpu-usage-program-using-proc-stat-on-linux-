

#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>
#include "../include/global.h"

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
    kernel_statistics_t * buff;
    int start;
    int end;
    int size;
    int count;
} cbuff_t;

extern kernel_statistics_t *prevKS;
extern cbuff_t* cBuff;

/*buffor */
cbuff_t* cbuff_new(int size);
void cbuff_add(cbuff_t * cb, kernel_statistics_t elem);
kernel_statistics_t cbuff_remove(cbuff_t * cb);
void cbuff_delete(cbuff_t * cb);

#endif