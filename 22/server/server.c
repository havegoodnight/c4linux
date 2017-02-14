#include "server.h"

void printUsage(){
	printf("Usage : \n\tserver [PORT]\n");
}

int get_socket(int port){
	/* 创建套接字 */
	int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	/* 构造地址结构体 */
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr)); // 每个字节都用 0 填充
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY; // 参数表示自动获取可用的本机IP地址 (为了防止某些主机存在两个网卡的情况)
	server_addr.sin_port = htons(port);
	
	/* 将套接字和IP/端口进行绑定 */
	int bind_result = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
	
	if (bind_result == 0){
		return server_socket;
	}else{
		printf("Bind failed ! Error code : %d\n", bind_result);
		exit(1);
	}
}

void say_hello(int client_socket, char *content){
	write(client_socket, content, strlen(content));
}

int main(int argc, char *argv[]){
	/* 判断用户输入是否合法 */
	if (argc != 2){
		printUsage();
		return 1;
	}
	
	int port = atoi(argv[1]);

	/* 获取套接字 */
	int server_socket = get_socket(port);
	
	/* 开始监听端口 */
	listen(server_socket, 8); // 第二个参数表示能处理的最大连接数
	
	/* 定义客户端的地址结构体 */
	struct sockaddr_in client_addr;
	socklen_t client_addr_size = sizeof(client_addr);
	int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);

	say_hello(client_socket, "Hello, client!\n");
	
	/* 向套接字中写入数据 */
	char buffer_receive[BUFFER_SIZE] = {0};
	char buffer_send[BUFFER_SIZE] = {0};
	while (1){
		/* 读取用户输入 , 准备发送给 client */
		puts("\nServer : ");
		memset(buffer_send, 0, BUFFER_SIZE);
		read(0, buffer_send, BUFFER_SIZE);
		if(!strcmp(buffer_send, "exit\n")){ // 服务器端需要关闭连接
			printf("Connection is closed by server.");
			break;
		}else{
			printf("%s", buffer_send);
			write(client_socket, buffer_send, strlen(buffer_send));
		}
		/* 接收客户端发送来的数据 */
		memset(buffer_receive, 0, BUFFER_SIZE);
		read(client_socket, buffer_receive, BUFFER_SIZE);
		if(!strcmp(buffer_receive, "exit\n")){ // 服务器端需要关闭连接
			printf("Connection is closed by client.");
			break;
		}else{
			printf("\nClient : %s", buffer_receive);
		}
	}
	
	/* 关闭套接字 */
	close(client_socket);
	close(server_socket);
	
	/* 结束程序 */
	return 0;
}
