#ifndef __SERVER_H__
#define __SERVER_H__

#define BUFFER_SIZE 0xFF

/* 系统标准库 , 提供exit函数 */
#include <stdlib.h>
/* 标准输入输出 */
#include <stdio.h>
/* 主要提供 msmset 函数 , 用于初始化服务器端监听的地址和端口号 */
#include <string.h>
/* 主要提供 read , close 等函数 */
#include <unistd.h>
/* 提供 socket 函数 , 用于创建 socket 函数 */
#include <sys/socket.h>
/* 提供 socket 相关的一些常量 , 以及地址的数据结构 */
#include <netinet/in.h>
/* 多线程编程(主要用于支持服务器多客户端) */
#include <pthread.h>
/* 提供 unix 时间戳 */
#include <time.h>

/**
 * 打印帮助信息
 */
void printUsage();
/**
 * 主入口
 */
int main(int argc, char *argv[]);

#endif
