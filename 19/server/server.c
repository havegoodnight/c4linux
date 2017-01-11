#include "server.h"

void printUsage(){
	printf("Usage : \n\tserver [PORT]");
}

int main(int argc, char *argv[]){
	/* 判断用户输入是否合法 */
	if (argc != 2){
		printUsage();
		return 1;
	}
	/* 创建套接字 */
	int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	/* 构造地址结构体 */
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr)); // 每个字节都用 0 填充
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int port = atoi(argv[1]);
	server_addr.sin_port = htons(port);
	
	/* 将套接字和IP/端口进行绑定 */
	bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
	
	/* 开始监听端口 */
	listen(server_socket, 1); // 第二个参数表示能处理的最大连接数
	
	/* 定义客户端的地址结构体 */
	struct sockaddr_in client_addr;
	socklen_t client_addr_size = sizeof(client_addr);
	int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
	
	/* 向套接字中写入数据 */
	char content[] = "Hello world!";
	write(client_socket, content, sizeof(content));
	
	/* 关闭套接字 */
	close(client_socket);
	close(server_socket);
	
	/* 结束程序 */
	return 0;
}
