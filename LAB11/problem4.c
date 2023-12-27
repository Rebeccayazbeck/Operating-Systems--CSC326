
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

void* philosopher(void*);
void get_fork(int);
void put_fork(int);
void think(int);
void eat(int);
int left(int);
int right(int);
void nap();

int number_philo;
sem_t *forks;

int main(int argc, char **argv) {

if (argc < 2) {
printf("Proper Usage: <%s> <Num of Philo>\n", argv[0]);
exit(1);     }

srand(time(NULL));
int i;
number_philo = atoi(argv[1]);
forks = (sem_t*) malloc(number_philo * sizeof(sem_t));
pthread_t *threads = (pthread_t*)malloc(number_philo * sizeof(pthread_t));

int *threads_id = (int*) malloc(number_philo * sizeof(int));

for (i =0; i<number_philo; i++) {
threads_id[0] = i;
pthread_create(&threads[i], NULL, philosopher, &i);
sem_init(&forks[i],0,1);     }

for (i =0; i<number_philo; i++)
pthread_join(threads[i], NULL);
return 0; }



void* philosopher(void *t) {
int id = *((int*)t);
while (1) {
think(id);
get_fork(id);
eat(id);
put_fork(id);
     }
return 0; }

void get_fork(int p) {
if (p %2==0) {
//if (p == 4) {
sem_wait(&forks[right(p)]);
sem_wait(&forks[left(p)]);     }
else {
sem_wait(&forks[left(p)]);
sem_wait(&forks[right(p)]);     } }

void put_fork(int p) {
sem_post(&forks[left(p)]);
sem_post(&forks[right(p)]); }

int left(int p) {
return p; }

int right(int p) {
return (p+1) % number_philo;
}
