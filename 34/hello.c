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

