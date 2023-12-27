#include <stdio.h>
#include <math.h>

#define bool int
#define true 1
#define false 0

bool check(float num);
bool Armstrong(int num1, int num2, int num3);
int getNum(int num1, int num2, int num3);

int main(){
    int num1;
    printf("Enter num1: \n");
    scanf("%d",&num1);
    int num2;
    printf("Enter num2: \n");
    scanf("%d",&num2);
    int num3;
    printf("Enter num3: \n");
    scanf("%d",&num3);
    if(!check(num1)|| !check(num2)|| !check(num3)){
        printf("The integers should be single-digit and positive numbers\n");
        return 1;
    }
    int num = getNum(num1,num2,num3);
    if (Armstrong(num1,num2,num3)){
        printf("%d is an Armstrong number since %d ^3 + %d ^3 +%d ^3 is equal to %d  " , num,num1,num2,num3,num);
    }
    else{
        printf("%d is not an Armstrong number since %d ^3 + %d ^3 +%d ^3 is not equal to %d  " , num,num1,num2,num3,num);
    }
    return 0;

}
bool check(float num){
    if (num < 0 || num >9){
        return false;
    }
    return true;
}
bool Armstrong(int num1, int num2, int num3) {
    int sumOfCubes = pow(num1,3) + pow(num2,3) + pow(num3,3);
    return sumOfCubes == num1 * 100 + num2 * 10 + num3;
}
int getNum(int num1, int num2, int num3){
    return num1 * 100 + num2 * 10 + num3;
}
