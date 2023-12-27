#include<sys/types.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>



int main()
{
    printf("Main Process PID= %d, PPID=%d\n", getpid(), getppid());
    
    
    pid_t child=fork();
    
    if (child<0)
    {
        // error in fork
        //printf("Failed Fork");
        perror("Failed Fork");
        exit(1);
    }
    else
    {
        if(child==0)
        {
            //Child
            sleep(5);
            printf("Child Process PID= %d, PPID=%d\n", getpid(), getppid());
            printf("Ready to kill my parent!\n");
            kill(getppid(), SIGINT);
            printf("I am an orphan now\n");
            exit(0);
        }
        else
        {
            //Parent
            wait(NULL);
            printf("I am the parent, I will not be executed");
     
        }
    
    }
    

    
    
    return 0;
}


