#include <stdio.h>
#include <math.h>

double MyAverage(int a, int b, int c, int d);
int MyM(int a, int b, int c, int d);

int k = 22;
int l = 33;
int m = 12;
int n = 6;

int main(){
    double avg = MyAverage(k,l,m,n);
    printf("The average is %.2lf\n" , avg);
    int min = MyM(k,l,m,n);
    printf("The minimum is %d" , min);
    return 0;
}
double MyAverage(int a, int b, int c, int d){
    double avg = (a+b+c+d) / 4.0;
    return avg;
}

int MyM(int a, int b, int c, int d){
    int min = a;
    int Numb[] = {a,b,c,d};
    for (int i =1; i< 4; i++){
        if (Numb[i] < min){
            min = Numb[i];
        }
    }
    return min;
}