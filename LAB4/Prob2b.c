
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
            
            pid_t child2= fork();
            
            if (child2<0)
            {
                printf("Failed Fork Child2");
                exit(1);
            }
            else
            {
                if (child2==0)
                    printf("Child2 Process PID= %d, PPID=%d\n", getpid(), getppid());
                else
                {
                    wait(NULL);
                    
                    printf("Parent Process PID= %d, PPID=%d\n", getpid(), getppid());
                        
                }
            }
                
        }
    
    }
    
    
    return 0;
}



