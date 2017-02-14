#include "client.h"

void printUsage(){
	printf("Usage : \n\tclient [IP_ADDRESS] [PORT]\n");
}

int connect_socket(const char* address, int port){
	/* 定义 socket 结构体 */
	int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	/* 定义地址结构体 */
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr)); // 将申请到的用于保存目标地址信息的内存全部使用 0 进行填充
	server_addr.sin_family = AF_INET; // 设置使用 IPv4 进行目标地址的表示
	server_addr.sin_addr.s_addr = inet_addr(address); // 设置目标主机 IP 地址
	server_addr.sin_port = htons(port); // 设置目标主机端口
	
	/* 与远程主机的端口建立连接 */
	int connect_result = connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)); // 需要提供 socket , 目标地址 , 目标地址长度

	/* 判断连接状态 */
	if (connect_result == 0){
		/* 返回套接字描述符 */
		return server_socket;
	}else{
		/* 连接失败 */
		printf("Connect failed! Error code : %d\n", connect_result);
		exit(1);
	}
}

int main(int argc, char *argv[]){
	/* 判断参数合法性 , 如果不合法则打印使用帮助 */
	if (argc != 3){
		printUsage();
		return 1;
	}
	
	char *address = argv[1]; // IP 地址
	int port = atoi(argv[2]); // 端口号
	int server_socket; // 套接字描述符	
	
	/* 建立连接 */
	server_socket = connect_socket(address, port);

	/* 循环读取远程主机发送的数据 */
	char buffer_receive[BUFFER_SIZE] = {0};
	char buffer_send[BUFFER_SIZE] = {0};
	while(1){
		/* 接收服务器发送的数据 */
		memset(buffer_receive, 0, BUFFER_SIZE);
		read(server_socket, buffer_receive, BUFFER_SIZE); 
		if(!strcmp(buffer_receive, "exit\n")){
			printf("Connection is closed by server.\n");
		}else{
			/* 显示数据 */
			printf("\nServer : %s", buffer_receive);
		}

		/* 读取客户端输入 */
		printf("\nClient : ");
		memset(buffer_send, 0, BUFFER_SIZE);
		read(0, buffer_send, BUFFER_SIZE);
		/* 判断客户端是否想要退出 */
		if(!strcmp(buffer_send, "exit\n")){
			printf("Connection is closed by client.\n");
			break;
		}else{
			printf("%s", buffer_send);
			write(server_socket, buffer_send, strlen(buffer_send));
		}
	}
	
	/* 通信结束 , 断开连接 */
	close(server_socket);
	return 0;
}
