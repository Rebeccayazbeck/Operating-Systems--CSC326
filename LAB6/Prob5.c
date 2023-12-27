#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    char date[20];
    float rating;
} Movie;

int main() {
    // Create a shared memory segment to hold an array of movies
    Movie *movieArray = mmap(NULL, 5 * sizeof(Movie), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (movieArray == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Parent process: Fill the movie array by prompting the user
    printf("Enter details for 5 movies:\n");
    for (int i = 0; i < 5; i++) {
        printf("Movie %d\n", i + 1);

        // Movie ID
        printf("ID: ");
        scanf("%d", &movieArray[i].id);

        // Movie Name
        printf("Name: ");
        scanf("%s", movieArray[i].name);

        // Movie Date
        printf("Date: ");
        scanf("%s", movieArray[i].date);

        // Movie Rating
        printf("Rating: ");
        scanf("%f", &movieArray[i].rating);

        printf("\n");
    }

    // Fork a child process
    int pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process: Find the movie with the highest rating
        float maxRating = -1.0;
        int maxRatingMovieIndex = -1;

        for (int i = 0; i < 5; i++) {
            if (movieArray[i].rating > maxRating) {
                maxRating = movieArray[i].rating;
                maxRatingMovieIndex = i;
            }
        }

        if (maxRatingMovieIndex != -1) {
            printf("Movie with highest rating:\n");
            printf("ID: %d\n", movieArray[maxRatingMovieIndex].id);
            printf("Name: %s\n", movieArray[maxRatingMovieIndex].name);
            printf("Date: %s\n", movieArray[maxRatingMovieIndex].date);
            printf("Rating: %.1f\n", movieArray[maxRatingMovieIndex].rating);
        } else {
            printf("No movies found.\n");
        }

        exit(0);
    } else {
        // Parent process: Wait for the child to finish
        wait(NULL);
    }

    // Unmap the shared memory
    if (munmap(movieArray, 5 * sizeof(Movie)) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    return 0;
}
