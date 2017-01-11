#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
	// 创建套接字
	int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// 绑定 IP / Port
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr)); // 每个字节都用 0 填充
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(1234);
	bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

	listen(server_socket, 20);

	struct sockaddr_in client_addr;
	socklen_t client_addr_size = sizeof(client_addr);
	int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);

	char content[] = "Hello world!";
	write(client_socket, content, sizeof(content));

	close(client_socket);
	close(server_socket);
	return 0;
}
