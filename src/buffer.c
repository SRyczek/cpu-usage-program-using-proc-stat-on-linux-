
#include "../include/lib.h"

cbuff_t* cbuff_new(int size) {
  cbuff_t * cb = (cbuff_t*)malloc(sizeof(cbuff_t));
  memset(cb, 0, sizeof(cbuff_t));
  cb->size = size;
  cb->buff = (kernel_statistics_t*)malloc(sizeof(kernel_statistics_t)*size);
  
  return cb;
}

void cbuff_add(cbuff_t * cb, kernel_statistics_t elem) {
  pthread_mutex_lock(&mutex);
  int end = cb->end;
  while(cb->count && (end % cb->size) == cb->start) pthread_cond_wait(&loggerEnd, &mutex);

  //printf("Added Elem[%d] = %d\n",cb->end, elem);
  //printf("Added element\n");
  cb->buff[cb->end] = elem;
  cb->end = (cb->end+1) % cb->size;
  cb->count++;

  //printf("From Add Counter: %d, End %d, Start %d\n", cb->count, cb->end, cb->start);
  pthread_cond_signal(&loggerStart); 
  pthread_mutex_unlock(&mutex);
}

kernel_statistics_t cbuff_remove(cbuff_t * cb) {
  pthread_mutex_lock(&mutex);
  int start = cb->start;
  kernel_statistics_t ret;
  while(cb->count <= 0) pthread_cond_wait(&loggerStart, &mutex);

  if(cb->count || (start % cb->size) != cb->end) {
    //printf("Removed Elem[%d] = %d\n",cb->start, cb->buff[cb->start]);
    //printf("Removed element\n");
    //printf("From Remove Counter: %d, End %d, Start %d\n", cb->count, cb->end, cb->start);
    ret = cb->buff[cb->start];
    cb->start = (cb->start + 1 ) % cb->size;
    cb->count--;
  } else {
    printf("Something goes wrong with remove\n");
  }
  pthread_cond_signal(&loggerEnd); 
  pthread_mutex_unlock(&mutex);

  return ret;
}

void cbuff_delete(cbuff_t * cb)
{
  free(cb->buff);
  free(cb);
}
