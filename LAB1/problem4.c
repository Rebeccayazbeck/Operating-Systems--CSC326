#include <stdio.h>
#include <math.h>

#define bool int
#define true 1
#define false 0
bool Check(int x1, int y1, int x2, int y2, double D);

int main(){
    int x1 = 1;
    int y1 = 1;
    int x2 = 10;
    int y2 = 15;
    float D = 10;

    if (Check(x1,y1,x2,y2,D)){
        printf("Yes, the Manhattan distance between O and A is greater than D =%.2f ", D);
    }
    else{
        printf("No, the Manhattan distance between O and A is not greater than D =%.2f ", D);
    }

}

bool Check(int x1, int y1, int x2, int y2, double D){
    double distance = fabs(x1-x2) + fabs(y1-y2);
    if (distance > D){
        return true;
    }
    else{
        return false;
    }
}