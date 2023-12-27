#include <stdio.h>
#include <math.h>

#define bool int
#define true 1
#define false 0

bool Check(float x1, float y1, float x2, float y2, double D);
double Mdist(float x1, float y1, float x2, float y2 );

int main(){
    float x1;
    float y1; 
    printf("Please enter the coordinates of O:\n");
    scanf("%f %f",&x1,&y1);
    float x2;
    float y2;
    printf("Please enter the coordinates of A:\n");
    scanf("%f",&x2,&y2);

    float D;
    printf("Please enter the target distance:\n");
    scanf("%f",&D);

    double result = Mdist(x1,y1,x2,y2);
    printf("The Manhattan distance between O and A = %.2lf\n", result);

    if (Check(x1,y1,x2,y2,D)){
        printf("Yes, the Manhattan distance between O and A is greater than D =%.2f \n", D);
    }
    else{
        printf("No, the Manhattan distance between O and A is not greater than D =%.2f \n", D);
    }

    return 0;

}

double Mdist(float x1, float y1, float x2, float y2 ){
    double distance = fabs(x1-x2) + fabs(y1-y2); 
    return distance;
}

bool Check(float x1, float y1, float x2, float y2, double D){
    double distance = Mdist(x1,y1,x2,y2);
    if (distance > D){
        return true;
    }
    else{
        return false;
    }
}