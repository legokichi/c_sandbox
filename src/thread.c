#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void thtest(void * arg){
  int i;
  int * thread_id = (int * )malloc(sizeof(int));
  *thread_id = pthread_self();
  printf("arg = %s\n", (char * )arg);
  sleep(5);
  pthread_exit((void *) thread_id);
}

void thr_ad(){
  pthread_t th1;
  void * rval;

  if(pthread_create(&th1, NULL, thtest, (void *)"hello, th1") != 0){
    perror("Thead creation failed.\n");
    exit(EXIT_FAILURE);
  }
  if(pthread_join(th1, &rval)!=0){
    perror("Failed to join with th1.\n");
  }
  printf("th1: %d... fin.\n", *((int *)rval));
}
