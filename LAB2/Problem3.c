#include <stdio.h>
#include <math.h>

double computeAvg( int num1, int num2, int num3, int num4);
int min( int num1, int num2, int num3, int num4);
int max( int num1, int num2, int num3, int num4);
int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("ERROR!!\n");
        return 1;
    }

    int num1 = atoi(argv[0]);
    int num2 = atoi(argv[1]);
    int num3 = atoi(argv[2]);
    int num4 = atoi(argv[3]);

    double average = computeAvg(num1, num2, num3, num4);
    printf("The average of all the integers is: %.2lf\n", average);

    int Min = min(num1, num2,num3,num4);
    printf("The minimum of all the integers is: %d\n", Min);
    int Max = max(num1, num2,num3,num4);
    printf("The maximum of all the integers is: %d\n", Max);

    return 0;
}
double computeAvg( int num1, int num2, int num3, int num4){
    int sum = num1 + num2 + num3 + num4;
    double avg = sum/4;
    return avg;
}

int min(int num1, int num2, int num3, int num4){
    int min = num1;

    if (num2 < min) {
        min = num2;
    }
    if (num3 < min) {
        min = num3;
    }
    if (num4 < min) {
        min = num4;
    }
    return min;
}
int max( int num1, int num2, int num3, int num4){
    int max = num1;

    if (num2 > max) {
        max = num2;
    }
    if (num3 > max) {
        max = num3;
    }
    if (num4 > max) {
        max = num4;
    }
    return max;
}