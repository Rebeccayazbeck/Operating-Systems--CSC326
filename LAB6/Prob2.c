#include<sys/types.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include <string.h>


#define ARRAY_SIZE 4
#define STRING_SIZE 20

int main()
{
    /* allocate shared memory for the whole array */
    char ** shared_array= (char **) mmap(NULL, sizeof(char*) *ARRAY_SIZE, PROT_READ |PROT_WRITE, MAP_SHARED |MAP_ANONYMOUS, -1,0);
    
    
    if (shared_array== MAP_FAILED)
    {
        perror ("Failed: mmap");
        exit(EXIT_FAILURE);
    }
    
    /* allocate shared memory for each element in the array */
    for (int i=0; i<ARRAY_SIZE;i++)
    {
        shared_array[i]= (char *) mmap(NULL, STRING_SIZE, PROT_READ |PROT_WRITE, MAP_SHARED |MAP_ANONYMOUS, -1,0);
    
    }
                
    pid_t pidFork= fork();
    
    if (pidFork<0)
    {
        // error
        perror("Fork Failed");
        exit(EXIT_FAILURE);
 
        
    }
    else
    {
        if(pidFork==0)
        {
            //Child
            printf("From child: \n");
            for (int i=0; i<ARRAY_SIZE;i++)
            {
                printf("Please enter a string %d:", i+1);
                fgets(shared_array[i], STRING_SIZE, stdin);
            }
        }
        else
        {
            //Parent
            wait(NULL);
            printf("\nFrom Parent: ");
            
            for (int i=0; i<ARRAY_SIZE; i++)
            {
                printf("\n\n*** String %d ***\n",i+1);
                printf("%s", shared_array[i]);
                printf("Length = %d\n", strlen(shared_array[i])-1);
 
                 char text[50];
                 strcpy (text, shared_array[i]);
                 int countUpper=0;
                 int countLower=0;
                 int countLetters=0;
                 int countIntegers=0;
            int countSpecialChars=0;
            
            
            for (int i=0;i<strlen(text)-1;i++)
            {
            
                if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
                {
                    countLetters++;
                    //printf("Char = %c \n",text[i]);
                  if(text[i] >= 'a' && text[i] <= 'z')
                    {
                        countLower++;
                       
                    }
                       
                    if(text[i] >= 'A' && text[i] <= 'Z')
                    {
                        countUpper++;
                    }
            
                }
                    else
                {
               
                   if(text[i] >= '0' && text[i] <= '9')
                {
                    countIntegers++;
                
                }
                else
                {
                    countSpecialChars++;
                }
               }
                   
                   
             }
                
             printf("The number of letters is: %d\n",countLetters);
             printf("The number of uppercase letters is: %d\n",countUpper);
             printf("The number of lowercase letters is: %d\n",countLower);
             printf("The number of integers is: %d\n",countIntegers);
             printf("The number of special characters is: %d\n",countSpecialChars);
                
                printf("Transform to upper case:\n");
           for (int i=0;i<strlen(text)-1;i++)
        {
            
            if(text[i] >= 'a' && text[i] <= 'z')
            {
                printf("%c",text[i]+'A'-'a');
            
            }
                
                else
                {
                printf("%c",text[i]);
                }
                   
                   
             }
                 
            }
            
        }
    }
    
    for (int i =0; i<ARRAY_SIZE; i++)
         munmap(shared_array[i], STRING_SIZE);
 
 
     munmap(shared_array, ARRAY_SIZE * sizeof(char*));

    
    return 0;
}







