#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
    float width;
    float length;
}Rectangle;

void ScaleRectangle (int a, Rectangle *r);
double ComputeArea(Rectangle r);
double ComputePerimeter(Rectangle r);
bool isSquare(Rectangle r);
bool withinRectangle (Rectangle r, double a, double b);
void MoveRectangle (double a ,double b, Rectangle *r);

int main(){
    Rectangle r;
    r.x = 1;
    r.y = 1;
    r.length = 5.50;
    r.width = 5.50;
    printf("Rectangle 1: w= %.2lf , l=%.2lf, a(%.2lf,%.2lf)\n",r.width,r.length,r.x,r.y);
    ScaleRectangle(2,&r);
    printf("Rectangle 1 scaled: w= %.2lf , l=%.2lf\n",r.width,r.length);
    printf("Rectangle r1 area = %.2lf\n", ComputeArea(r));
    printf("Rectangle 1 perimeter = %.2lf\n", ComputePerimeter(r));
    if(isSquare(r)){
        printf("Rectangel 1 is a square\n");
    }
    else{
        printf("Rectangel 1 is not a square\n");
    }
    printf("Please enter the coordinated of the point P");
    double xp ;
    double yp;
    scanf("%lf %lf", &xp,&yp);
    if (withinRectangle(r,xp,yp)){
        printf("P(x= %.2lf, y= %.2lf) is located inside the rectangle\n",xp,yp);
    }
    else{
        printf("P(x= %.2lf, y= %.2lf) is not located inside the rectangle\n",xp,yp);
    }
    printf("Move the rectangle by (3.3, 10.10):\n");
    MoveRectangle(3.3,10.10,&r);
    printf("Rectangle R1 Updated: w= %.2lf ,l= %.2lf, A(%.2lf,%.2lf)\n",r.width,r.length,r.x,r.y);
}
void ScaleRectangle (int a, Rectangle *r){
    r->length= r->length * a;
    r->width= r->width *a;
}

double ComputeArea(Rectangle r){
    double area =  r.length * r.width;
    return area;
}

double ComputePerimeter(Rectangle r){
    double perimeter = 2 * (r.length + r.width);
    return perimeter;
}

bool isSquare(Rectangle r){
    return r.length == r.width;
}

bool withinRectangle (Rectangle r, double a, double b){
    return abs(r.x - a)<= r.length && abs(r.y - b) <= r.width; 
}
void MoveRectangle (double a ,double b, Rectangle *r){
    r->x = r->x + a;
    r->y = r->y + b;
}