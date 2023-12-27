#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4


pthread_mutex_t lock;

float shared;


void *runner1(void* param)
{
    long id = (long) param;

    for(int i=0;i<5;i++)

    {
        pthread_mutex_lock(&lock);
        shared = shared*2;
        printf("Thread %d - Multiplying the shared variable by 2... %.1f \n", id, shared);
        pthread_mutex_unlock(&lock);

    }

}



void *runner2(void* param)
{
    long id = (long) param;

    for(int i=0;i<5;i++)

    {
        pthread_mutex_lock(&lock);
        shared =shared/2.0;
        printf("Thread %d - Dividing the shared variable by 2... %.1f \n", id, shared);
        pthread_mutex_unlock(&lock);

    }

}



int main()

{

    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);


    printf("Please enter the initial value of the shared variable \n");
    scanf("%f", &shared);
    printf("%.1f read \n",shared);
    long i, i2;

    for (i = 0; i < 2; i++) {
        pthread_create(&threads[i], &attr, runner1, (void*) i);
    }

   

    for (i2 = 2; i2 < NUM_THREADS; i2++) {

        pthread_create(&threads[i2], &attr, runner2, (void*) i2);

    }

    

    for (int i3 = 0; i3 < NUM_THREADS; i3++)
    {

        pthread_join(threads[i3], NULL);

    }



    printf("The final value of the shared variable is %.1f\n", shared);

    exit(EXIT_SUCCESS);

}






