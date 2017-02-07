#include <stdio.h>

int add(int x, int y);
int sub(int x, int y);
int (*p_function)(int x, int y); // 声明一个可以指向函数的指针变量(参数和返回值相同)

int main(){
	int x = 10;
	int y = 20;
	p_function = add; // 将函数指针指向 add 函数
	int add_result = p_function(x, y); // x + y = 10 + 20 = 30;
	p_function = sub; // 将函数指针指向 sub 函数
	int sub_result = p_function(x, y); // x - y = 10 - 20 = -10;
	printf("x + y = %d\nx - y = %d\n", add_result, sub_result);
	return 0;
}

int add(int x, int y){
	return (x + y);
}

int sub(int x, int y){
	return (x - y);
}

