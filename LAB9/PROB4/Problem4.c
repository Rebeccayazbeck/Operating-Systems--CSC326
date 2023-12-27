#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ARRAY_SIZE 1000
#define NUM_THREADS 4
#define ELEMENTS_PER_THREAD 250

int array[ARRAY_SIZE];

void fillArrayRandomly() {
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = rand() % 100 + 1; // Generates random positive numbers between 1 and 100
    }
}

void displayArray() {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n\n\n");
}

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void *replacePrimesWithZeros(void *arg) {
    long threadID = (long)arg;
    int startIndex = threadID * ELEMENTS_PER_THREAD;
    int endIndex = startIndex + ELEMENTS_PER_THREAD;

    printf("I am thread number %ld. I will be working on the numbers from %d to %d.\n", threadID, startIndex, endIndex - 1);

    for (int i = startIndex; i < endIndex; ++i) {
        if (isPrime(array[i])) {
            array[i] = 0;
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Fill the array randomly with positive numbers
    fillArrayRandomly();

    // Display the original array
    printf("Original Array:\n");
    displayArray();

    // Create threads to replace primes with zeros
    for (long i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, replacePrimesWithZeros, (void *)i);
    }

    // Wait for all threads to finish
    for (long i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Print the modified array
    printf("\n\n\n\n");
    printf("Modified Array:\n");
    displayArray();

    return 0;
}
