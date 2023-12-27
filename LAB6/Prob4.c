#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int calculate_factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * calculate_factorial(n - 1);
}

int main() {
    int *shared_memory;
    int pid;
    int number;

    // Create a shared memory segment
    shared_memory = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Prompt the user for a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Check for valid input
    if (number < 0) {
        printf("Error: The integer should be positive!\n");
        return 1;
    }

    // Write the number to shared memory
    *shared_memory = number;

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        int n = *shared_memory;

        // Calculate the factorial
        int factorial = calculate_factorial(n);

        // Write the factorial to shared memory
        *shared_memory = factorial;

        // Exit the child process
        exit(0);
    } else {
        // Parent process
        // Wait for the child to finish
        wait(NULL);

        // Read the factorial result from shared memory
        int result = *shared_memory;
        printf("Factorial of %d is: %d\n", number, result);
    }

    // Unmap the shared memory
    if (munmap(shared_memory, sizeof(int)) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    return 0;
}
