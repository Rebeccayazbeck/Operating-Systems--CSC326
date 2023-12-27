#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
  int    fd[2];
  pipe(fd);
  pid_t  childId = fork();

if (childId<0)
{
    perror("Fork failed");
    exit(1);
}
else
{
  if (childId == 0) {
    int nChars = 0;

    // close the output end of pipe
    close(fd[1]);

    // Receive characters from parent process via pipe
    // one at a time, and count them
    char a;
    char array[100];
    while ( read(fd[0], &a, 1) == 1 && a!='*')
      {
              array[nChars]= a;
               nChars++;
               
       //printf("Char=%c \t Count = %d\n", a,nChars);
               
      }

    printf("Child: Read = %d\n", nChars);
    
    
    char c;
    int CounterC=0;
    read(fd[0], &c, 1);
    for(int i=0; i< nChars;i++)
    {
        if(array[i]==c)
        CounterC++;
    }
    
    return CounterC; //exit(nChars)
  }
  else {
    int nChars = 0;
    int size = 0;
    //printf("Parent\n");

    // close the input side of the pipe
    close(fd[0]);

    // Send characters from command line arguments starting with
    // argv[1] one at a time through pipe to child process.
    int i, z;
    
    for (i = 1; i < argc; i++) {
      size = strlen(argv[i]);
      //printf("size=%d\n", size);
      for (z = 0; z < size; z++) {
        write(fd[1], &argv[i][z], 1);
        //printf("Char=%c\n", argv[i][z]);
      }
    }
    int star='*';
    write(fd[1], &star, 1);
    printf("Parent: Sending the characters and then * to end\n");
    char c;
   printf("Parent: Please enter character c:\n");
   scanf("%c",&c);
   write(fd[1], &c, 1);
    close(fd[1]);

    /* Wait for child process to return and
       Receive number of characters counted via the parent */

    int status;
    wait(&status);

    int return_value = WEXITSTATUS(status);
    printf("Parent ==> Occurrence of letter '%c' received from Child = %d \n", c,return_value);
    return 0;
  }

  close(fd[0]);
  close(fd[1]);
}
  return 0;
}


