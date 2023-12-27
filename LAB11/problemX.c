#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
// Size of shared buffer
#define BUF_SIZE 100
int buffer[BUF_SIZE];
int add = 0;

int rem = 0;
int number = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
sem_t stopConsume;
sem_t stopProduce;

void *producer (void *param);
void *consumer (void *param);

int main(int argc, char *argv[]) {

  sem_init(&stopConsume, 0, 0);
  sem_init(&stopProduce, 0, BUF_SIZE);

  pthread_t tid, tid1;

      if (pthread_create(&tid, NULL, producer, NULL) != 0) {
      fprintf(stderr, "can't create producer thread\n");
       exit(1);     }

      if (pthread_create(&tid1, NULL, consumer, NULL) != 0) {
        fprintf(stderr, "can't create consumer thread\n");
        exit(1);     }
pthread_join(tid, NULL);
  pthread_join(tid1, NULL);
    printf("Parent quitting\n");
 return 0; }
 void *producer(void *param) {

    int i;
    for (i=1;;i++) {
           sem_wait(&stopProduce);
      pthread_mutex_lock(&m);

     buffer[add] = i;
      add = (add+1) % BUF_SIZE;
       number++;
     pthread_mutex_unlock(&m);

        sem_post(&stopConsume);
      printf ("producer: inserted %d\n", i);
      fflush (stdout);     }

    printf("producer quitting\n");
 fflush(stdout);
 return 0; }

 void *consumer(void *param) {
    int i;
    while (1) {
    sem_wait(&stopConsume);
    pthread_mutex_lock(&m);
    i = buffer[rem];
    rem = (rem+1) % BUF_SIZE;
    number--;

                pthread_mutex_unlock(&m);

        sem_post(&stopProduce);
    printf ("Consume value %d\n", i);
fflush(stdout);

    }     return 0; }
