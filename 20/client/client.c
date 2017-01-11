#include "client.h"

void printUsage(){
	printf("Usage : \n\tclient [IP_ADDRESS] [PORT]\n");
}

int connect_socket(const char* address, int port){
	/* 定义 socket 结构体 */
	int socket_client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	/* 定义地址结构体 */
	struct sockaddr_in client_addr;
	memset(&client_addr, 0, sizeof(client_addr)); // 将申请到的用于保存目标地址信息的内存全部使用 0 进行填充
	client_addr.sin_family = AF_INET; // 设置使用 IPv4 进行目标地址的表示
	client_addr.sin_addr.s_addr = inet_addr(address); // 设置目标主机 IP 地址
	client_addr.sin_port = htons(port); // 设置目标主机端口
	
	/* 与远程主机的端口建立连接 */
	int connect_result = connect(socket_client, (struct sockaddr*)&client_addr, sizeof(client_addr)); // 需要提供 socket , 目标地址 , 目标地址长度

	/* 判断连接状态 */
	if (connect_result == 0){
		/* 返回套接字描述符 */
		return socket_client;
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
	int socket_descriptor; // 套接字描述符	
	
	/* 建立连接 */
	socket_descriptor = connect_socket(address, port);
	
	/* 读取远程主机发送的数据 */
	char buffer[16];
	read(socket_descriptor, buffer, sizeof(buffer) - 1);
	
	/* 显示数据 */
	printf("Server : %s\n", buffer);
	
	/* 通信结束 , 断开连接 */
	close(socket_descriptor);
	return 0;
}
