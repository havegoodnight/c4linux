#ifndef __SERVER_H__
#define __SERVER_H__

/* 标准输入输出 */
#include <stdio.h>
/* 主要提供 msmset 函数 , 用于初始化服务器端监听的地址和端口号 */
#include <string.h>
/* 提供 socket 函数 , 用于创建 socket 函数 */
#include <sys/socket.h>
/* 提供 socket 相关的一些常量 , 以及地址的数据结构 */
#include <netinet/in.h>

/**
 * 打印帮助信息
 */
void printUsage();
/**
 * 主入口
 */
int main(int argc, char *argv[]);

#endif
