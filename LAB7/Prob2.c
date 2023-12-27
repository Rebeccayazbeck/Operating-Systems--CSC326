#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

#define MAX_SIZE 100

int main(int argc, char const *argv[])
{
  pid_t pid ;
  int fd[2]; //from child to parent
  pipe(fd);
  
  int fd2[2];//from parent to child
  pipe(fd2);
  
  pid = fork();

  
  if(pid == 0) {
    // close fd[0] and write
    close(fd[0]);
    close(fd2[1]);
    int n = 0;
    char input[MAX_SIZE];

    printf("Enter a string\n");
    
    if(fgets(input, sizeof(input), stdin) == NULL) { // scan a string from the user
      printf("%s\n", "Error while reading input from user");
    }
    else {

      strtok(input, "\n"); // remove trailing new line

      n = write(fd[1], input, strlen(input)); // returns the number of bytes read
            
      if(n < 0) {
    perror("Error in writing");
      }
      printf("%s %s\n", "Child wrote", input);
      printf("Child wrote %d bytes\n", n);
    }
    close(fd[1]);
    
    int aReceived;
    read(fd2[0], &aReceived, sizeof(int));
    close(fd2[0]);
    
    printf("Child: Bytes received from parent=%d \n", aReceived);
    printf("Child: Number of characters received=%d \n", strlen(input));
    
    if (strlen(input)==aReceived)
    {
        printf("Child ==>Message successfully received!!");
    }
    else
    printf("Child ==>Message Transmission Failed!!");
    
    
    exit(EXIT_FAILURE);
  }

  else if(pid > 0) {
    // close fd[1] and read
    //wait(NULL);
    close (fd[1]);
    close(fd2[0]);
    char buff[100];
    int n = 0;

    n = read(fd[0], buff, sizeof(buff));

    if(n < 0) {
      perror("Error in reading");
    }
    else {
      buff[n] = '\0'; // discard any gibberish chars
      printf("Parent reads %s\n", buff);
      printf("Parent reads %d bytes\n", n);
    }
    close(fd[0]);
    
    int a=strlen(buff);
    write(fd2[1], &a, sizeof(int));
    printf("Parent: Bytes received=%d \n", a);
    close(fd2[1]);
  }

  else {
    printf("Error in forking");
    exit(EXIT_FAILURE);
  }

  close(fd[0]);
  close(fd[1]);

  return 0;
}




