
#define _GNU_SOURCE

#include<sys/types.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#include<sys/mman.h>
#include <string.h>


void print_array(int *array, int N)
{
    for(int i=0;i<N; i++)
    {
        printf("%d ",*(array+i));
        //printf("%d ",array[i]);
    }
    printf("\n");
}

int main()
{
  
      int N;
      printf("Please enter the size of the array:\n");
      scanf("%d",&N);
    
    int * shared_array= (int *) mmap(NULL, sizeof(int) *N, PROT_READ |PROT_WRITE, MAP_SHARED |MAP_ANONYMOUS, -1,0);
    
    
    if (shared_array== MAP_FAILED)
    {
        perror ("Failed: mmap");
        exit(EXIT_FAILURE);
    }

                
    pid_t child1=fork();
    
    if (child1<0)
    {
        // error in fork
        //printf("Failed Fork Child1");
        perror("Failed Fork Child1");
        exit(1);
    }
    else
    {
        if(child1==0)
        {
            //Child
            pid_t child3= fork();
            
            if (child3<0)
            {
                printf("Failed Fork Child3");
                perror("Failed Fork Child3");
                exit(1);
            }
            else
            {
                if (child3==0)
                    {
                        printf("*** From Child 3: ***\n");
                printf("Please enter %d integers: \n", N);
                for (int i=0; i<N; i++)
                    scanf("%d", &shared_array[i]);
                
                print_array(shared_array,N);
                printf("\n");
                    }
                else
                {
                    wait(NULL);
                    printf("*** From Child 1: ***\n");
                    for (int i=0; i<N; i++)
                    shared_array[i]=shared_array[i]*10;
                
                    print_array(shared_array,N);
                    printf("\n");
                }
            }
            
            
        }
        else
        {
            //Parent
            wait(NULL);
            
            pid_t child2= fork();
            
            if (child2<0)
            {
                printf("Failed Fork Child2");
                perror("Failed Fork Child2");
                exit(1);
            }
            else
            {
                if (child2==0)
                {
                    printf("*** From Child 2: ***\n");
                    for (int i=0; i<N; i++)
                    shared_array[i]=shared_array[i]-2;
                
                    print_array(shared_array,N);
                    printf("\n");
                    
                }
                else
                {
                    //Parent
                    wait(NULL);
                    printf("*** From Parent: ***\n");
                            
                            
                        
                  
                    shared_array= mremap(shared_array,N* sizeof(int), (N+1)* sizeof(int),0);
                            
                            
                            
                    int sum=0;
                    for (int i=0; i<N; i++)
                        sum=sum+shared_array[i];
                            
                    N=N+1;
                    shared_array[N-1]=sum;
                    print_array(shared_array,N);
                    printf("\n");
                }
            }
                
        }
    
    }
    
    
     munmap(shared_array, sizeof(int) *N);

    
    return 0;
}






