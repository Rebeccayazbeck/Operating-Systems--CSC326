#include <stdio.h>
#include <math.h>

int w = 13;
int l = 7;
int h = 2;
double R = 5.5;

int main(){
    float VolumeCuboid = w*l*h;
    printf("The volume of the cuboid is %.2f\n",VolumeCuboid );
    double VolumeSphere = (4.0 / 3.0) * M_PI * pow(R, 3);
    printf("The volume of the sphere is %.2lf", VolumeSphere);
    return 0;

}
