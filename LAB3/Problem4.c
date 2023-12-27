#include <stdio.h>

typedef struct{
    int ID;
    char* name;
    float GPA;
} Student;

int main(){
    Student student[5];
    student[0].ID = 1;
    student[0].name = "Rebecca";
    student[0].GPA = 3.2;

    student[1].ID = 2;
    student[1].name = "Renee";
    student[1].GPA = 3.1;

    student[2].ID = 3;
    student[2].name = "Eliecharles";
    student[2].GPA = 4;

    student[3].ID = 4;
    student[3].name = "Rim";
    student[3].GPA = 3.7;

    student[4].ID = 5;
    student[4].name = "Mariam";
    student[4].GPA = 3.9;

    float avgGPA = 0;
    char* NamehighestGPA;
    float highestGPA = 0;
    for (int i = 0; i < 5; i++){
        avgGPA += student[i].GPA;
        if (student[i].GPA > highestGPA){
            highestGPA = student[i].GPA;
            NamehighestGPA = student[i].name;
        }
    }
    avgGPA /=5;
    printf("The average GPA is: %.2f\n", avgGPA);
    printf("The student with the highest GPA is: %s\n",NamehighestGPA );


}