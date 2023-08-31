
#include "../include/buffer.h"
#include "../include/global_variables.h"
/*
In this file buffer implementation is included.

cbuff_new() creates structure cbuff_t which 
includes counters, buffer size and space for elements.

cbuff_add() adds the item to the buffer.If buffor is full
function call pthread_cond_wait() until some element is removed.

cbuff_remove() removes element from buffor and returns it in place of
the function call. If buffer is empty function call pthread_cond_wait() until some element 
is added.

cbuff_delete() deletes buffer and frees memory.

*/
static pthread_cond_t bufforFull;
static pthread_cond_t bufforEmpty;

static pthread_cond_t logBufforFull;
static pthread_cond_t logBufforEmpty;

cbuff_t* cBuff;

/* kernel statistic buffor ***********************************************************/

cbuff_t* cbuff_new(int size) {
  cbuff_t *cb = (cbuff_t*)calloc(1, sizeof(cbuff_t));
  cb->size = size;
  cb->buff = (kernel_statistics_t*)calloc((size_t)size, sizeof(kernel_statistics_t));
  return cb;
}

void cbuff_add(cbuff_t* cb, kernel_statistics_t elem) {
  int end;
  pthread_mutex_lock(&mutex);
  end = cb->end;
  while (cb->count && (end % cb->size) == cb->start) pthread_cond_wait(&bufforFull, &mutex);

  cb->buff[cb->end] = elem;
  cb->end = (cb->end+1) % cb->size;
  cb->count++;

  pthread_cond_signal(&bufforEmpty); 
  pthread_mutex_unlock(&mutex);
}

kernel_statistics_t cbuff_remove(cbuff_t * cb) {
  int start;
  kernel_statistics_t ret;
  memset(&ret, 0, sizeof(ret));
  pthread_mutex_lock(&mutex);
  start = cb->start;
  while(cb->count <= 0) pthread_cond_wait(&bufforEmpty, &mutex);

  if (cb->count || (start % cb->size) != cb->end) {

    ret = cb->buff[cb->start];
    cb->start = (cb->start + 1 ) % cb->size;
    cb->count--;
  } 

  pthread_cond_signal(&bufforFull); 
  pthread_mutex_unlock(&mutex);

  return ret;
}

/* logger buffor ************************************************************************/

log_cbuff_t* logger_cbuff_new(int size) {
  log_cbuff_t *cb = (log_cbuff_t*)calloc(1, sizeof(log_cbuff_t));
  cb->size = size;
  cb->buff = (int*)calloc((size_t)size, sizeof(int));
  
  return cb;
}

void logger_cbuff_add(log_cbuff_t* cb, int elem) {
  int end;
  pthread_mutex_lock(&mutex);
  end = cb->end;
  while (cb->count && (end % cb->size) == cb->start) pthread_cond_wait(&logBufforFull, &mutex);

  cb->buff[cb->end] = elem;
  cb->end = (cb->end+1) % cb->size;
  cb->count++;

  pthread_cond_signal(&logBufforEmpty); 
  
  pthread_mutex_unlock(&mutex);
  pthread_cond_signal(&loggerStart); 

}

int logger_cbuff_remove(log_cbuff_t * cb) {
  int start;
  int ret = 0;
  pthread_mutex_lock(&mutex);
  start = cb->start;
  while (cb->count <= 0) pthread_cond_wait(&logBufforEmpty, &mutex);

  if (cb->count || (start % cb->size) != cb->end) {
    ret = cb->buff[cb->start];
    cb->start = (cb->start + 1 ) % cb->size;
    cb->count--;
  } else {
    printf("Something goes wrong with remove\n");
  }
  pthread_cond_signal(&logBufforFull); 
  pthread_mutex_unlock(&mutex);
  return ret;
}


/* delete buffers **************************************************************************/

void cbuff_delete(cbuff_t* cb, log_cbuff_t* logCb) {
  if (cb != NULL && logCb == NULL) {
    free(cb->buff);
    free(cb);
  } else if (cb == NULL && logCb != NULL) {
    free(logCb->buff);
    free(logCb);   
  } else {
    /* something goes wrong */
    perror("Buffers free error\n");

  }

}

