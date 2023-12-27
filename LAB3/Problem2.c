#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* LowerToUpper(char string[]);
char* UpperToLower(char string[]);
int main(){
    char string[1000];
    printf("Enter a String:\n");
    fgets(string, sizeof(string),stdin);
    printf("After LowerToYpper: \n");
    printf(LowerToUpper(string) ,"\n");

    printf("After UpperToLower: \n");
    printf(UpperToLower(string) ,"\n");    



}

char* LowerToUpper(char string[]){
    for (int i =0; i< strlen(string); i++){
        if (isalpha(string[i]) && !isupper(string[i])){
            int asciiUpper = (int) string[i] -32;
            string[i]= (char) asciiUpper;
        }

    }
    return string;
}
char* UpperToLower(char string[]){
    for (int i =0; i< strlen(string); i++){
        if (isalpha(string[i]) && isupper(string[i])){
            int asciiLower = (int) string[i] +32;
            string[i]= (char) asciiLower;
        }

    }
    return string;
}
