#include "server.h"

static int client_counter = 0;

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

void handle_every_client(int *client_socket){
	client_counter++;
	printf("Function client socket : %d\n", *client_socket);
	time_t now_time;
	struct tm *timeinfo;
	time(&now_time); // 返回 unix 时间戳
	timeinfo = localtime(&now_time);
	printf ( "\007The current date/time is: %s", asctime (timeinfo) );
	int size = write(*client_socket, asctime(timeinfo), BUFFER_SIZE);
	printf("Size : %d\n", size);
	char counter_buffer[16] = {0};
	sprintf(counter_buffer, "%d", client_counter);
	size = write(*client_socket, counter_buffer, BUFFER_SIZE);
	printf("Size : %d\n", size);
	/* 向套接字中写入数据 */
	//char buffer_receive[BUFFER_SIZE] = {0};
	//char buffer_send[BUFFER_SIZE] = {0};
	//while (1){
	//	/* 读取用户输入 , 准备发送给 client */
	//	puts("\nServer : ");
	//	memset(buffer_send, 0, BUFFER_SIZE);
	//	read(0, buffer_send, BUFFER_SIZE);
	//	if(!strcmp(buffer_send, "exit\n")){ // 服务器端需要关闭连接
	//		printf("Connection is closed by server.");
	//		break;
	//	}else{
	//		printf("%s", buffer_send);
	//		write(client_socket, buffer_send, strlen(buffer_send));
	//	}
	//	/* 接收客户端发送来的数据 */
	//	memset(buffer_receive, 0, BUFFER_SIZE);
	//	read(client_socket, buffer_receive, BUFFER_SIZE);
	//	if(!strcmp(buffer_receive, "exit\n")){ // 服务器端需要关闭连接
	//		printf("Connection is closed by client.");
	//		break;
	//	}else{
	//		printf("\nClient : %s", buffer_receive);
	//	}
	//}
	/* 关闭套接字 */
	close(*client_socket);
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
	
	while (1){
		/* 定义客户端的地址结构体 */
		struct sockaddr_in client_addr;
		socklen_t client_addr_size = sizeof(client_addr);
		/* 取得一个新的链接 */
		int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
		/* 开启一个新的线程去处理 */
		pthread_t tid; // 定义线程描述符
		/* 尝试开启线程 */
		printf("New client socket : %d\n", client_socket);
		if(!pthread_create(&tid, NULL, (void*)handle_every_client, &client_socket)){
			// printf("Connected by : %s\n", client_addr.sin_addr.s_addr);
			printf("Connected!\n");
		}else{
			printf("Create thread error!\n");
			continue;
		}
		printf("Keep listening...");
	}

	/* 关闭服务器的监听 */
	close(server_socket);
	
	/* 结束程序 */
	return 0;
}
