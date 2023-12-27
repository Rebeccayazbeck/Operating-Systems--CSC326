#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main() {
    int num;
    int numbers[100];
    int count = 0;

    printf("Please enter integers or enter -1 to exit:\n");

    while (true) {
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        numbers[count] = num;
        count++;
    }

    bool areEqual = true;

    for (int i = 1; i < count; i++) {
        if (numbers[i] != numbers[0]) {
            areEqual = false; 
            break;
        }
    }

    if (areEqual) {
        printf("All the integers are equal? YES\n");
    } else {
        printf("All the integers are equal? NO\n");
    }

    return 0;
}
