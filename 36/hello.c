#include <stdio.h>

int main(){
	int (*p)[16]; // 声明一个可以指向具有16个元素的数组的指针
	int *q[16]; // 声明一个具有16个元素的数组 , 每一个元素都是一个可以指向整型的指针
	printf("sizeof(int (*p)[16]) = %d\t(64 位程序的指针长度为 8 字节)\n", sizeof(p));
	printf("sizeof(int *q[16]) = %d\t(这样测量出来的是整个数组的长度 , 也就是单个元素的长度( 8 )乘元素个数(16))\n", sizeof(q));
	return 0;
}
