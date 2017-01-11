#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
	if (argc != 3){
		printf("Usage : \n\t%s [IP_ADDRESS] [PORT]", argv[0]);
	}
	int socket_client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in client_addr;
	memset(&client_addr, 0, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = inet_addr(argv[1]);
	client_addr.sin_port = htons(1234);
	connect(socket_client, (struct sockaddr*)&client_addr, sizeof(client_addr));
	
	char buffer[32];
	read(socket_client, buffer, sizeof(buffer) - 1);
	printf("Server : %s", buffer);

	close(socket_client);
	return 0;
}
