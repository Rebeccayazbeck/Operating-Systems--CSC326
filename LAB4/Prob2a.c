
#include<sys/types.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int main()
{
    pid_t child1=fork();
    
    if (child1<0)
    {
        // error in fork
        //printf("Failed Fork");
        perror("Failed Fork");
        exit(1);
    }
    else
    {
        if(child1==0)
        {
            //Child
            printf("Child1 Process PID= %d, PPID=%d\n", getpid(), getppid());
            
        }
        else
        {
            //Parent
            wait(NULL);
            printf("Parent Process PID= %d, PPID=%d\n", getpid(), getppid());

                
        }
    
    }
    
    
    return 0;
}



