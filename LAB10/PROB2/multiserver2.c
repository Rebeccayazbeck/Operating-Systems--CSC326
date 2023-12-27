#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <pthread.h>

#define PORT 5100 
void* ThreadRun(void *);

int main(int argc, char const *argv[]) 
{ 
        int server_fd, new_socket, valread; 
        struct sockaddr_in address; 
        int opt = 1; 
        int addrlen = sizeof(address); 
        //char buffer[1024] = {0}; 
        

        // Creating socket file descriptor 
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
        { 
                perror("socket failed"); 
                exit(EXIT_FAILURE); 
        } 

        // Forcefully attaching socket to the port 5100 
        if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))) 
        { 
                perror("setsockopt"); 
                exit(EXIT_FAILURE); 
        } 
        address.sin_family = AF_INET; 
        address.sin_addr.s_addr = INADDR_ANY; 
        address.sin_port = htons( PORT ); 

        // Forcefully attaching socket to the port 5100 
        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
        { 
                perror("bind failed"); 
                exit(EXIT_FAILURE); 
        } 
        while(1){
        if (listen(server_fd, 3) < 0) 
        { 
                perror("listen"); 
                exit(EXIT_FAILURE); 
        } 
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                                        (socklen_t*)&addrlen))<0) 
        { 
                perror("accept"); 
                exit(EXIT_FAILURE); 
        } 
	pthread_t th;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&th,&attr,ThreadRun,&new_socket);
        //pthread_join(th, NULL);	
	}
	close(server_fd);
        return 0; 
} 
int fib(int n) 
{ 
   if (n <= 1) 
      return n; 
   return fib(n-1)+fib(n-2); 
} 

void* ThreadRun (void * socket){
        int *sock=(int*)socket;
        int s=*sock;
char helloc[255];
char usrmsg[255];
char* hi="hi from server";

read(s,helloc,sizeof(helloc));
printf("received from client: %s\n", helloc);
send(s , hi , strlen(hi) , 0 ); 

int readint;
read(s,(int*)&readint,sizeof(readint));
int a = fib(readint);
printf("%d\n", a);
        //send(s , (int*)&a, 1, 0 ); 
        //printf("fib value sent from server thread\n"); 

close(s);

}
