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


#define PORT 8080
void* ThreadRun(void *);

int main(int argc,char* argv[])
{
  int sock1, clientSocket, valread;
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
    if ((clientSocket = accept(sock1, (struct sockaddr *)&address,
         (socklen_t *)&addrlen)) < 0)
    {
      perror("accept");
      exit(EXIT_FAILURE);
    }
    
    
        pthread_t th;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);


    pthread_create(&th,&attr,ThreadRun,&clientSocket);
    

  }
close(sock1);
  
  return 0;
}

void * ThreadRun(void * socket)
{
     int sock2=*((int*)socket);
        
    char message[1024] = {0};
        char message3[1024] ="Hello client";
    int message2[1024]={0};
    int temp[100];
    int j;
    int sum=0;
    int k;
    recv(sock2, message, sizeof(message),0);
    printf("Received: %s\n", message);
    send(sock2,message3,strlen(message3),0);

printf("Waiting for client to send array");
    int n = recv(sock2,message2,1024*sizeof(int),0);
    printf("\nNumber of bytes read = %d; thus %d is the size of the array\n",n,n/sizeof(int));

    for(j=0;j<n/sizeof(int);j++){
      printf("%d ",message2[j]);
    }
    printf("\nfinished reading\ncomputing sum") ;
    for(k=0;k<n/sizeof(int);k++){
      sum+=message2[k];
    }
    printf("\nSum : %d\n", sum);
    send(sock2,&sum,sizeof(int),0);
    printf("Finished sending sum");
}

