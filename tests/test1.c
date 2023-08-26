
#include "../include/global.h"
#include "../include/buffer.h"
#include <assert.h>

int main() {

    /* verify cbuff_new */

    cbuff_t* testCBuff = NULL;
    int len = 12;
    testCBuff = cbuff_new(len);

    assert(testCBuff->size == len);
    assert(&testCBuff != NULL);

    return 0;
}