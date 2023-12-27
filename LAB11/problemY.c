#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

void* read(void* t);
void* write(void* t);
int nap();

sem_t sem_rw, mutex;
int reader_count;

int main(int argc, char* argv[]) {
if (argc != 3) {
printf("Number of readers and writer %s \n", argv[0]);
exit(1);
}
int i;
int readers = atoi(argv[1]);
int writers  = atoi(argv[2]);

sem_init(&sem_rw, 0, 1);
sem_init(&mutex, 0, 1);
reader_count = 0;

srand(time(NULL));

pthread_t *reader = (pthread_t*) malloc(readers * sizeof(pthread_t));
pthread_t *writer = (pthread_t*) malloc(writers * sizeof(pthread_t));

for (i =0; i<readers; i++)
pthread_create(&reader[i], NULL, read, (void*)i);

for (i=0; i<writers; i++)
pthread_create(&writer[i], NULL, write, (void*)i);

for (i =0; i<readers; i++)
pthread_join(reader[i], NULL);

for (i =0; i<writers; i++)
pthread_join(writer[i], NULL);
return 0;

}
void* read(void* t) {
int id = (int) t;

 nap();

 printf("About to read %d  \n", id);
 do {
 sem_wait(&mutex);
 reader_count++;
 if (reader_count == 1)
 sem_wait(&sem_rw);
 sem_post(&mutex);

printf("Reader %d is reading \n", id);
nap();

sem_wait(&mutex);
reader_count--;
if (reader_count == 0)
sem_post(&sem_rw);
sem_post(&mutex); }
while (1);
return 0; }
void* write(void* t) {

int id = (int) t;
nap();
printf("Writer %d is about to write \n", id);
do {
sem_wait(&sem_rw);

printf("Writer %d is writing \n", id);
nap();
sem_post(&sem_rw);
printf("Writer %d is done writing \n", id); }
while (1);
return 0; }
int nap () {
struct  timespec tim;
int sec = rand() %3;
int nanosec = rand() %999999999;
tim.tv_sec = sec;
tim.tv_nsec = nanosec;
nanosleep(&tim, NULL); }
