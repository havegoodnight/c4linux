#ifndef __CLIENT_H__
#define __CLIENT_H__

/* 标准输入输出流 , 提供 printf 函数 */
#include <stdio.h>
/* 主要提供 memset 函数 , 将定义的结构体的内存地址全部填充为 0 */
#include <string.h>
/* 定义socket相关的一些常量 */
#include <netinet/in.h>


/**
 * 显示帮助信息
 */
void printUsage();

/**
 * 主入口
 */
int main(int argc, char *argv[]);


#endif
