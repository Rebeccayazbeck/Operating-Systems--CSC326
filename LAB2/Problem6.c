#include <stdio.h>

int main() {
    int N;
    printf("Please enter an integer N: \n");
    scanf("%d", &N);

    printf("The right triangles having sides ranging between 1 and %d are:\n", N);

    for (int a = 1; a < N; a++) {
        for (int b = a; b < N; b++) {
            for (int c = b; c < N; c++) {
                if (a * a + b * b == c * c) {
                    printf("(%d, %d, %d)\n", a, b, c);
                }
            }
        }
    }

    return 0;
}

