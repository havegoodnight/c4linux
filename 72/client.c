#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
	int PORT = -1;
	char *IP;

	if (argc != 3){
		printf("Usage : \n");
		printf("        client [IP] [PORT]\n");
		exit(1);
	}

	IP = argv[1];
	PORT = atoi(argv[2]);

	int sockfd;
	struct sockaddr_in addr;

	/* 填充struct sockaddr_in */
	bzero(&addr, sizeof(struct sockaddr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(IP);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0){
		printf("[%d] open socket error!\n", sockfd);
		exit(2);
	}

	/* 强制转换成struct sockaddr */
	int result = connect(sockfd, (struct sockaddr *) &addr, sizeof(struct sockaddr));

	if (result < 0){
		printf("[%d] connect error!\n", result);
		exit(3);
	}

	// char buffer[16] = {0};
	// read(sockfd, buffer, 16);
	// printf("[Server] : [%s]", buffer);

	char *content = "Hello world!\n";
	write(sockfd, content, strlen(content));
	char buffer[1024] = {0};
	read(sockfd, buffer, 1024);
	write(1, buffer, 1024);
	close(sockfd);

	return 0;
}
