#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char command[100];

    printf("Enter a command to execute: ");
    scanf("%s", command);

    // Fork a child process
    int child_pid = fork();

    if (child_pid == 0) {
        // Child process
        execlp("sh", "sh", "-c", command, NULL);

        // Print an error message if execlp fails
        perror("execlp");
        exit(-1);
    } else if (child_pid < 0) {
        perror("fork");
        exit(-2);
    } else {
        // Parent process
        printf("Parent process: Created child process with PID %d\n", child_pid);
        wait(NULL);  // Wait for the child process to finish
        printf("Parent process: Child process completed.\n");
    }

    return 0;
}
