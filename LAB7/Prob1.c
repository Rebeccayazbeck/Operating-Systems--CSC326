#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
  int    fd[2];
  int fd2[2];

  pipe(fd);
  pipe(fd2);
  
  int N;
  
  pid_t  childId = fork();

if (childId<0)
{
    perror("Fork failed");
    exit(1);
}
else
{
  if (childId == 0) {
    close(fd[0]);
    close(fd2[1]);
  
    int Nreceived;
    read(fd2[0], &Nreceived, 4);
    
    int array[Nreceived];
    printf("Child ==> Enter %d integers:\n",Nreceived);
    for(int i=0; i<Nreceived;i++)
    {
        int temp;
        scanf("%d", &temp);
        array[i]=temp;
    }
    
    for(int i=0; i<Nreceived;i++)
    {
        
        int temp= array[i];
        write(fd[1], &temp, 4);
    }
    
    int countReceived;
    read(fd2[0], &countReceived, 4);
    printf("\nChild ==> The number of positive integers is %d ", countReceived);
    
    close(fd2[0]);
    close(fd[1]);
  }
  else {
  
  //printf("Parent\n");
    close(fd[1]);
    close(fd2[0]);
  
   printf("Parent ==> Enter N the number of integers in the list:\n");
   scanf("%d",&N);
  
   printf("\nParent ==> sending N=%d \n", N);
   write(fd2[1], &N,4);
    
    int CountPos= 0;
    
    
    int temp;
    printf("The parent received:");
    for (int i = 0; i < N; i++)
    {
     read(fd[0], &temp,4);
     printf("%d ", temp);
     if (temp>0)
         CountPos++;
    }
    printf("\nParent ==> the number of positive integers is %d ", CountPos);
    write(fd2[1], &CountPos,4);

    close(fd[0]);
    close(fd2[1]);
  }

  close(fd[0]);
  close(fd[1]);
}
  return 0;
}



