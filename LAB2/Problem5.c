#include <stdio.h>
#include <math.h>

void MySuperFunc(int* num1, int* num2, int* num3);
int main(){
    int num1;
    int num2;
    int num3;
    printf("Enter three integers x,y and z: \n");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("From main, before ==> x = %d, y = %d and z = %d \n", num1 , num2, num3);
    MySuperFunc (&num1, &num2,& num3);
    printf("After calling the method MySuperFunc: \n");
    printf("From main, after ==> x = %d, y = %d and z = %d \n", num1 , num2, num3);

    return 0;
}

void MySuperFunc(int* num1, int* num2, int* num3){
    int n1 = *num1;
    int n2 = *num2;
    int n3 = *num3;

    *num1 = n1 + n2+ n3;
    *num2 = pow(n2,n1);
    *num3 = n1*n2*n3;


}
