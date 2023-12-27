
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <pthread.h>


#define PORT 8055
void* ThreadFunction(void *);
int main(int argc,char* argv[])
{
  int sock1, sock2, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  // int buffer[1024] = {0};
  // char buff[] = "Hello from server";

  // Creating socket file descriptor
  if ((sock1 = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Forcefully attaching socket to the port 8080
  if (bind(sock1, (struct sockaddr *)&address,
           sizeof(address)) < 0)
  {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
while (1)
  {
    if (listen(sock1, 3) < 0)
    {
      perror("Listen Failed");
      exit(EXIT_FAILURE);
    }
    if ((sock2 = accept(sock1, (struct sockaddr *)&address,
         (socklen_t *)&addrlen)) < 0)
    {
      perror("accept");
      exit(EXIT_FAILURE);
    }
    char message[100] = {0};
    char message3[100] ="Hello Client";
    char message2[20];
    recv(sock2, message, sizeof(message),0);
    printf("Received: %s\n", message);
    send(sock2,message3,strlen(message3),0);
    printf("Waiting for client to send the string s and character c");
    int n = recv(sock2,message2,20,0);
    printf("\nNumber of bytes read = %d\n",n);
    printf("String Received: %s\n", message2);

    
    char CR;
    int Count=0;
    int y=recv(sock2,&CR,1,0);
    printf("Character Received: %c\n", CR);
    //printf("\nFinished reading\ncomputing occurrence\n") ;
    for(int k=0;k<20;k++)
    {
      if(message2[k]==CR)
          Count++;
    }
    printf("\n Count: %d\n", Count);
    send(sock2,&Count,sizeof(int),0);
    printf("Finished sending Count");

    close(sock2);

  }
close(sock1);
  
  return 0;
}

