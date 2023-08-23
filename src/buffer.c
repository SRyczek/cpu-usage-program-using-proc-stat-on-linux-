
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
  printf("Added element\n");
  cb->buff[cb->end] = elem;
  cb->end = (cb->end+1) % cb->size;
  cb->count++;

  //printf("Counter: %d, End %d, Start %d\n", cb->count, cb->end, cb->start);
  pthread_cond_signal (&loggerStart); 
  pthread_mutex_unlock(&mutex);
}

kernel_statistics_t cbuff_remove(cbuff_t * cb) {
  pthread_mutex_lock(&mutex);
  int start = cb->start;
  kernel_statistics_t ret;
  printf("cbuf remove work\n");
  while(cb->count <= 0 || (cb->count || (start % cb->size) == cb->end)) pthread_cond_wait(&loggerStart, &mutex);

  if(cb->count || (start % cb->size) != cb->end) {
    //printf("Removed Elem[%d] = %d\n",cb->start, cb->buff[cb->start]);
    printf("Removed element\n");
    ret = cb->buff[cb->start];
    cb->start = (cb->start + 1 ) % cb->size;
    cb->count--;
  } else {
    printf("Something goes wrong with remove\n");
  }
  pthread_cond_signal (&loggerEnd); 
  pthread_mutex_unlock(&mutex);

  return ret;
}


void cbuff_print(cbuff_t * cb)
{
  int start = cb->start ;
  int end = cb->end ;
  int i, count = 0;
  for(i = start; count < cb->count; i = (i + 1)%cb->size){
    printf("Elem[%d] = %d\n", i, cb->buff[i]);
    count++;
    if(i == (end - 1)) {
      break;
    }
  }
}


void cbuff_delete(cbuff_t * cb)
{
  free(cb->buff);
  free(cb);
}



/*
  if(cb->count && (end % cb->size) == cb->start) {
    //printf("Overflow Elem[%d] %d lost\n", cb->start, cb->buff[cb->start]);
    printf("Overflow element\n");
    cb->start = (cb->start + 1 ) %cb->size;
    cb->count--;

*/