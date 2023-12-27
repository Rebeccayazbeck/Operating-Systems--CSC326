#include <stdio.h>
#include <stdlib.h>

int isRectangular(int a);
void Rectangular(int a);

int main(){
    int num = 0;
    while(num>=0){
        printf("Enter a positive integer or a negative integer to exit:\n");
        scanf("%d", &num);
        if(num<0){
            break;
        }
        if (isRectangular(num)==1){
            printf("%d is a rectangular number.\n", num);
        }
        else{
            printf("%d is not a rectangular number.\n", num);
        }
    }
    printf("Enter a number n to print all rectangular numbers from 1 to n:\n");
    scanf("%d", &num);
    Rectangular(num);
    return 0;

}

int isRectangular(int a){
    int i;
    for(i = 1; i <= a/2; i++){
        if(i*(i+1) == a){
            return 1;
        }
    }
    return 0;
}

void Rectangular(int a){
    int i;
    for(i = 1; i <= a; i++){
        if(isRectangular(i)==1){
            printf("%d\n", i);
        }
    }
}
