#include<sys/types.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/mman.h>

void print_array(int *array, int N)
{
    for(int i=0;i<N; i++)
    {
        printf("%d ",*(array+i));
        //printf("%d ",array[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{

    //printf("%d\n", argc);
    
        int N;
        if (argc==2)
        {
            N= atoi(argv[1]);
            printf("Length N=%d\n", N);
        }

    int * shared_array= (int*) mmap(NULL, sizeof(int) *N, PROT_READ |PROT_WRITE, MAP_SHARED |MAP_ANONYMOUS, -1,0);
    
    
    if (shared_array== MAP_FAILED)
    {
        perror ("Failed: mmap");
        exit(EXIT_FAILURE);
    }
                
                
    pid_t pidFork= fork();
    
    if (pidFork<0)
    {
        printf("ERROR\n");
        // error
        //perror("Fork Failed");
       exit(EXIT_FAILURE);
        
    }
    else
    {
        if(pidFork==0)
        {
            //Child
            printf("From Child, please enter %d integers: \n",N);
            
            for (int i=0; i<N; i++)
            scanf("%d", &shared_array[i]);

            print_array(shared_array,N); // or foop loop her, without a function
        }
        else
        {
            //Parent
            wait(NULL);
            printf("From Parent, ");
            printf("please enter a: \n");
            int a;
            scanf("%d", &a);
            for (int i=0; i<N; i++)
            {
                shared_array[i]=shared_array[i]*a;
            }
            
            
            
            print_array(shared_array,N); // or foop loop her, without a function

        }
    }
    
    munmap(shared_array, sizeof(int) *N);
 
    
    return 0;
}






