#include <stdio.h>

int main(int argc, char *argv[]){
	int hoge; // 没有初始化的整型变量
	int *hoge_p; // 没有初始化的指向整型的指针变量

	int foo = 10; // 初始化的整型变量
	int *foo_p = &foo; // 初始化的指向整型的指针变量

	void *void_p = NULL; //指向空的空类型的指针变量
	
	printf("hoge = %d\n", hoge);
	printf("&hoge = %p\n", &hoge);
	printf("hoge_p = %p\n", hoge_p);
	printf("&hoge_p = %p\n", &hoge_p);
	// printf("*hoge_p  %d\n", *hoge_p); // 没有初始化的指针
	
	printf("foo = %d\n", foo);
	printf("&foo = %p\n", &foo);
	printf("foo_p = %p\n", foo_p);
	printf("&foo_p = %p\n", &foo_p);
	printf("*foo_p = %d\n", *foo_p);

	printf("void_p = %p\n", void_p);
	printf("&void_p = %p\n", &void_p);
	// printf("*void_p = %d\n", *void_p);

	void_p = &foo; // 将空类型的指针变量进行赋值

	printf("void_p = %p\n", void_p);
	printf("&void_p = %p\n", &void_p);
	printf("*void_p = %d\n", * (int *) void_p); // 这里必须将空类型的指针的类型强制转换为指向整型的指针类型 . 否则会有 error
	// 上一行中的 (int *) , 可以将 (int *) 理解为一个类型

	double temp = 3.14159; // 定义一个 double 变量 , 验证 void* 类型的指针可以指向任意的类型

	printf("temp = %f\n", temp);
	printf("&temp = %p\n", &temp);
	
	void_p = &temp;

	printf("void_p = %p\n", void_p);
	printf("&void_p = %p\n", &void_p);
	printf("*void_p = %d\n", * (int *) void_p);	// 这里将内存中的数据按照整型来读取 , 因此就会出现乱的数字
	printf("*void_p = %f\n", * (double *) void_p);

	return 0;
}
