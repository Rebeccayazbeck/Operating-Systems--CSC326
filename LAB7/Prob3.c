#include<sys/types.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main()
{
  int fd[2];
  pipe(fd);
  
  pid_t pid= fork();
  
    if (pid<0)
    {
        // error in fork
        printf("Failed Fork pid1");
        perror("Failed Fork pid1");
        exit(1);
    }
    else
    {
         if (pid==0)
         {
        //Child
             close(1); //close sdout
             dup(fd[WRITE_END]); //redirect output to fd[1] of the pipe
             close(fd[READ_END]);
             close(fd[WRITE_END]);
             
             char * exp[]={"pwd", NULL};
             if (execvp("pwd", exp)<0)
             {
                 perror ("Execvp failed from child");
             }
             exit(EXIT_FAILURE);
         }
         else
         {
             //Parent
             wait(NULL);
             close(0); // close stdin
             dup(fd[READ_END]); //redirect input to fd[0] of the pipe
             close(fd[WRITE_END]);
        close(fd[READ_END]);
        
        char *exp[]={"wc","-c",NULL};
        if (execvp("wc", exp)<0)
             {
                 perror ("Execvp failed from parent");
             }
        exit(EXIT_FAILURE);
             
         }
         
         
    }
     
     close(fd[WRITE_END]);
     close(fd[READ_END]);
    
    return 0;
}







