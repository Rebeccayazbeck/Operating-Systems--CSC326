#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2;

    // Create child 1
    pid1 = fork();

    if (pid1 == 0) {
        // Child 1
        
        // Create child 2
        pid2 = fork();

        if (pid2 == 0) {
            // Child 2
            for (int i = 1; i <= 10; i++)
                printf("Child 2: PID = %d, PPID = %d, Number = %d\n", getpid(), getppid(), i);
            exit(0);
        }
        
        else if(pid2>0)
        {
        //child1
        wait(NULL);
        for (int i = 11; i <= 20; i++)
            printf("Child 1: PID = %d, PPID = %d, Number = %d\n", getpid(), getppid(), i);
        exit(0);
        }
    }

    // Parent
    else if(pid1>0)
    {
    // Wait for child 1 to finish
    wait(NULL);
    for (int i = 21; i <= 30; i++)
        printf("Parent: PID = %d, PPID = %d, Number = %d\n", getpid(), getppid(), i);


    return 0;
    }
}
