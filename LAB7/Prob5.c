#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd1[2]; // Pipe to send choice from child to parent
    int fd2[2];  // Pipe to send capital from parent to child

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) { // Child process
        close(fd1[0]); // Close read end of the pipe to parent
        close(fd2[1]);  // Close write end of the pipe to child

        int choice;
        do {
            printf("Please enter the number of the country you want to learn about:\n");
            printf("1. Lebanon\n");
            printf("2. Egypt\n");
            printf("3. Tunis\n");
            printf("4. Morocco\n");
            printf("5. Jordan\n");
            printf("Enter the corresponding number: ");

            scanf("%d", &choice);
            if (choice < 1 || choice > 5) {
                printf("Invalid choice. Please try again.\n");
            }
        } while (choice < 1 || choice > 5);

        // Send the choice to the parent
        write(fd1[1], &choice, sizeof(int));

        // Read the response from the parent
        char response[100];
        read(fd2[0], response, sizeof(response));
        printf("Child: %s\n", response);

        close(fd1[1]);  // Close write end of the pipe to parent
        close(fd2[0]);   // Close read end of the pipe to child
    } else { // Parent process
        close(fd1[1]);  // Close write end of the pipe to parent
        close(fd2[0]);   // Close read end of the pipe to child

        int choice;
        read(fd1[0], &choice, sizeof(int));

        char *countries[] = {"Lebanon", "Egypt", "Tunis", "Morocco", "Jordan"};
        char *capitals[] = {"Beirut", "Cairo", "Tunis", "Rabat", "Amman"};

        char response[100];
        strcpy(response, "The capital of ");
        strcat(response, countries[choice - 1]);
        strcat(response, " is ");
        strcat(response, capitals[choice - 1]);
		
		//snprintf(response, sizeof(response), "The capital of %s is %s", countries[choice - 1], capitals[choice - 1]);
        

        // Send the response to the child
        write(fd2[1], response, strlen(response) + 1);

        close(fd1[0]);  // Close read end of the pipe to parent
        close(fd2[1]);   // Close write end of the pipe to child

        wait(NULL); // Wait for the child to complete
    }

    return 0;
}
