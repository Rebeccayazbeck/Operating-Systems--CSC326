#include <stdio.h>
#include <math.h>

#define bool int
#define true 1
#define false 0
bool check(float num);
float computeBMI( float w, float h);
int checkBMI( float BMI);

int main(){
    float w;
    printf("Enter the weight in Kg: \n");
    scanf("%f", &w);
    float h;
    printf("Enter the height in cm: \n");
    scanf("%f", &h);

    if (!check(w) || !check(h)){
        printf(" the weight and height should not be negative or equal to 0");
        return 1;
    } 

    float BMI = computeBMI (w,h);
    printf ("BMI = %.2f  ", BMI);
    int checkBmi = checkBMI(BMI);
  
    if (checkBmi == -1){
        printf("underweight");
        
    }
    if (checkBmi == 0){
        printf("normal weight");
    }
    if (checkBmi == 1){
        printf("overweight");
    }
    return 0;


}
bool check(float num){
    if (num <= 0){
        return false;
    }
    return true;
}

float computeBMI( float w, float h){
    float BMI = w*1000 / (h*h);
    return BMI;
}
int checkBMI( float BMI){
    if (BMI < 18.5){
        return -1;
    }
    if ( 18.8 <=  BMI && BMI <= 24.9){
        return 0;
    }
    if ( BMI > 24.9){
        return 1;
    }
  
}
