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

#define arraylength 5
#define PORT 8055

int main(int argc, char const *argv[])
{
 int sock = 0, valread;
  struct sockaddr_in serv_addr;
  int buffer[1024] = {78};
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("\n Socket creation error \n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
  {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    printf("\nConnection Failed \n");
    return -1;
  }
  
   char message[]="Hello Server\n";
   char message2[1024]={0};
  
  int temp1;
  send(sock,message,strlen(message),0);
  recv(sock,message2,sizeof(message2),0);
  printf("\nReceived: %s\n",message2);
  int i;
char s[100];
printf("Please enter a string s:\n");
scanf("%s",&s);
send(sock,s,strlen(s),0);
char c;
printf("Please enter a character c:\n");
//scanf("%c",&c);
c=getchar();
c=getchar();
printf("Character c:%c\n",c);


send(sock,&c,1,0);



 recv(sock,&temp1,sizeof(int),0);
printf("Number of occurrence = %d",temp1);
  close(sock);

  


}


