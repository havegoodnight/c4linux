#include <stdio.h>
#include <stdlib.h>

int add(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
int divid(int x, int y);
int	computer(int x, int y, int (*p_function)(int x, int y));


int main(){
	int x = 10;
	int y = 20;
	int (*p_handle)(int x, int y);
	p_handle = (add); // 也可以写成 (&add) 或者 (*add)
	printf("Result : %d\n", computer(x, y, p_handle));
	p_handle = (sub);
	printf("Result : %d\n", computer(x, y, p_handle));
	p_handle = (mult);
	printf("Result : %d\n", computer(x, y, p_handle));
	p_handle = (divid);
	printf("Result : %d\n", computer(x, y, p_handle));

	/* 将一个整型变量转换为函数指针 */
	int temp = &add;
	int result = ((int (*)(int x, int y))(temp))(10, 10);
	printf("%d\n", result);
	// 这里说明一个整型变量通过强制类型转换是可以作为函数指针来使用的
	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(int*) = %d\n", sizeof(int*));
	printf("整型在低地址区域可以当作函数指针来用 , 但是整型变量只有 4 字节 , 所以一旦指针的值大于 4 字节能表示的最大范围就会溢出 , 因此不建议这样用 , 反过来想 , 函数指针为代码段 , 地址都很低 , 大概用的时候也不太可能出错 , 但是如果用作指向栈内存的变量的时候就很容易出错\n");
	
	return 0;
}

int add(int x, int y){
	return (x + y);
}

int sub(int x, int y){
	return (x - y);
}

int mult(int x, int y){
	return (x * y);
}

int divid(int x, int y){
	/* 处理除数为 0 的情况 */
	if (!y){
		exit(1);
	}
	return (x / y);
}

int	computer(int x, int y, int (*p_function)(int x, int y)){
	return p_function(x, y); // 或者 (*p_function)(x, y);
}

