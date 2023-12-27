#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 5100

int main(int argc, char const *argv[])
{
        int sock = 0, valread;
        struct sockaddr_in serv_addr;
        char *hello = "Hello from client!";
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
                printf("\n Socket creation error \n");
                return -1;
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);

        // Convert IPv4 and IPv6 addresses from text to binary form
        if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
        {
                printf("\nInvalid address/ Address not supported \n");
                return -1;
        }

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
                printf("\nConnection Failed \n");
                return -1;
        }
        char hellos[100];
        send(sock, hello, strlen(hello),0);
        printf("hello msg sent to server\n");
    read(sock,hellos,sizeof(hellos));
    printf("received from server: %s\n", hellos);

    int a;
    printf("Enter the first int: \n");
    scanf("%d", &a);
    send(sock, (int*)&a, 1,0);
    
    printf("Enter the second int: \n");
    scanf("%d", &a);
    send(sock, (int*)&a, 1,0);

int sumRead=0;
valread = read( sock , (int*)&sumRead, sizeof(sumRead));
printf("Received from server, sum= %d\n",sumRead );
    close(sock);
    return 0;
}


