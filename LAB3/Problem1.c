#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char  c;
    char string[1000]; 

    printf("Enter a String: \n");
    fgets(string,sizeof(string),stdin);

    printf("Enter a character:\n");
    scanf("%c",&c);

    int specialChar = 0;
    int letter = 0;
    int digit = 0;
    int totalChar = strlen(string);
    int occurrences[256];

    for(int i = 0; i<totalChar; i++){
        if (isdigit(string[i])){
            digit++;
        }
        else if (isalpha(string[i])){
            letter++;
        }
        else if(!isspace(string[i])){
            specialChar++;
        }
        
        occurrences[(int)string[i]]++;
    }

    printf("the Character %c occurred %d times\n", c, occurrences[(int)c]);

    for(int i =0 ; i<256 ; i++){
        if (occurrences[i]>0){
            printf("Character = %c --> Occurrence: %d\n", (char)i, occurrences[i]);
        }
    }

}