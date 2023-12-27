#include <stdio.h>

int main(){
    int a = 5;
    int b =2;
    int *ptr1 = &a;
    int *ptr2 = &b;
    printf("Before Swap\n a = %d\n b = %d\n",a,b);
    
    *ptr1= *ptr1 + *ptr2;
    *ptr2= *ptr1 - *ptr2 ;
    *ptr1 = *ptr1- *ptr2;
    printf("After Swap\n a = %d\n b = %d\n",a,b);

}