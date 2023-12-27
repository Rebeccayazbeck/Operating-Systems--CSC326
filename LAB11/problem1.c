#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t lock;


void* print(void *);


int main(int argc, char const *argv[]) {
     sem_init(&lock,0,0);
     printf("Main started\n");
     // create a thread
     pthread_t thread;
     pthread_attr_t attr;
     pthread_attr_init(&attr);
     pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
     pthread_create(&thread, NULL, (void *) print, NULL);
     // decrement sem's count if greater than 0 and return otherwise wait
     sem_wait(&lock);
     printf("%s\n", "Thread Finished");

    return 0; }

void* print(void * args) {

    sem_post(&lock);
    pthread_exit(NULL); }
