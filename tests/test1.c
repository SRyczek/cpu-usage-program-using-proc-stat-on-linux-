#include "../include/lib.h"
#include <assert.h>

int main() {

    cbuff_t* testCBuff;
    testCBuff = cbuff_new(BUFFER_LENGHT);

    assert(testCBuff->size == BUFFER_LENGHT);



    return 0;
}