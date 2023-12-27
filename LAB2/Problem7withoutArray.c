#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main() {
    int num;
    int prevNum = -1; 
    bool areEqual = true;

    printf("Please enter integers or enter -1 to exit:\n");

    while (true) {
        scanf("%d", &num);
       
        if (num == -1) {
            break; 
        }

        if (prevNum != -1 && prevNum != num) {
            areEqual = false;
        }

        prevNum = num;
    }

    if (areEqual) {
        printf("All the integers are equal? YES\n");
    } else {
        printf("All the integers are equal? NO\n");
    }

    return 0;
}
