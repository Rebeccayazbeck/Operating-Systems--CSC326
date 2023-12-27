#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 8


pthread_mutex_t lock;

float shared_V;
int a,b,c,d;


void *runnerAdd(void* param)
{
    long id = (long) param;

    for(int i=0;i<3;i++)

    {
        pthread_mutex_lock(&lock);
        shared_V = shared_V+a;
        printf("Thread %d - Adding %d... V=%.1f \n", id, a, shared_V);
        pthread_mutex_unlock(&lock);

    }

}

void *runnerSub(void* param)
{
    long id = (long) param;

    for(int i=0;i<3;i++)

    {
        pthread_mutex_lock(&lock);
        shared_V = shared_V-b;
        printf("Thread %d - Subtracting %d... V=%.1f \n", id, b, shared_V);
        pthread_mutex_unlock(&lock);

    }

}



void *runnerMult(void* param)
{
    long id = (long) param;

    for(int i=0;i<3;i++)

    {
        pthread_mutex_lock(&lock);
         shared_V = shared_V*c;
       printf("Thread %d - Multiplying by %d... V=%.1f \n", id, c, shared_V);
        pthread_mutex_unlock(&lock);

    }

}

void *runnerDiv(void* param)
{
    long id = (long) param;

    for(int i=0;i<3;i++)

    {
        pthread_mutex_lock(&lock);
         shared_V = (double)shared_V/d/1.0;
       printf("Thread %d - Dividing by %d... V=%.1f \n", id, d, shared_V);
        pthread_mutex_unlock(&lock);

    }

}


int main()

{

    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);


    printf("Please enter the initial value of the shared variable \n");
    scanf("%f", &shared_V);
    
     printf("Please enter the values for a, b, c and d \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    printf("\nRead V=%.1f - a=%d - b=%d - c=%d - d=%d\n \n",shared_V,a,b,c,d);
    
    
    long i=0;
    for (i = 0; i < 4; i++) {
    
        if (i==0 || i==1)
            pthread_create(&threads[i], &attr, runnerAdd, (void*) i);
         
        if (i==2 || i==3)
            pthread_create(&threads[i], &attr, runnerSub, (void*) i);

    }
    
    for (int i3 = 0; i3 < 4; i3++)
    {

        pthread_join(threads[i3], NULL);

    }
    
    
    for (i = 4; i < NUM_THREADS; i++) {
        
        if (i==4 || i==5)
            pthread_create(&threads[i], &attr, runnerMult, (void*) i);
            
        if (i==6 || i==7)
            pthread_create(&threads[i], &attr, runnerDiv, (void*) i);
    

    }
    
        for (int i3 = 4; i3 < NUM_THREADS; i3++)
    {

        pthread_join(threads[i3], NULL);

    }



    printf("The final value of the shared variable is %.1f\n", shared_V);

    exit(EXIT_SUCCESS);

}








