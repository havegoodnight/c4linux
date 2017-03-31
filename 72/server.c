#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>


#define PORT 23333
#define MAX 5
int main(){
	int result = 0;
	char buffer[1024] = {0};

	/* socket() */
	int sockfd_server;
	int sockfd_client;
    sockfd_server = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd_server < 0){
		printf("[%d] create socket error!\n", sockfd_server);
		exit(1);
	}

	struct sockaddr_in addr_server;
                                         
	bzero(&addr_server, sizeof(struct sockaddr));   
	addr_server.sin_family = AF_INET;               
	addr_server.sin_port = htons(PORT);             
	addr_server.sin_addr.s_addr = htonl(INADDR_ANY);


	/* bind() */
	result = bind(sockfd_server, (struct sockaddr *)&addr_server, sizeof(struct sockaddr));
	if (result != 0){
		printf("[%d] bind error!\n", result);
		exit(2);
	}


	/* listen() */
	result = listen(sockfd_server, MAX);
	if (result != 0){
		printf("[%d] listen error!\n", result);
		exit(3);
	}

	// hacked
	char *content = "HTTP/1.1 200 OK\r\n\r\n<html><head></head><body>Hello!Hacker!</body></html>\r\n\r\n";

	/* accept() */
	struct sockaddr_in addr_client;
	socklen_t client_addr_size = sizeof(struct sockaddr_in);
	while(1){
		// accept
		sockfd_client = accept(sockfd_server, (struct sockaddr *)&addr_client, &client_addr_size);
		// handle error
		if (sockfd_client < 0){
			printf("[%d] accept error!\n", sockfd_client);
		}

		if (fork() == 0){ // Children 
			// close listening socket
			close(sockfd_server);	
			// handle
			printf("[+] client accepted! [%s:%d]\n", inet_ntoa(addr_client.sin_addr), addr_client.sin_port);
			memset(buffer, 0, sizeof(buffer));
			read(sockfd_client, buffer, 1024);
			write(1, buffer, 1024);
			write(sockfd_client, content, strlen(content));
			close(sockfd_client);
			break; // jump out of the loop
		}
	}

	/* close() */
	close(sockfd_server);
	
	return 0;
}
