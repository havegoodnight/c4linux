#include <stdio.h>

int main(int argc, char *argv[]){
	char content[] = "Hello world!"; // 字符数组 , 每个元素都是字符类型 , 一个字节
	int *pointer = (int *)content; // 强制类型转换并不会影响变量的类型
	printf("%s\n", pointer);
	pointer++; // 由于 pointer 指向了一个整型变量 , 因此自增运算会移动四个字节(sizeof(int)) , 所以再打印就是从 content[4] 开始了
	printf("pointer -> %s\n", pointer);
	printf("content[4] -> %s\n", &content[4]);
	return 0;
}
