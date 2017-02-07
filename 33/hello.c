#include <stdio.h>

int add(int x, int y);
int (*p_function)(int x, int y);

int main(){
	int x = 10;
	int y = 20;

	/****************************/

	/* 直接调用函数 */
	printf("add(x, y) = %d\n", add(x, y));
	printf("(*add)(x, y) = %d\n", (*add)(x, y)); // 函数可以通过 (*FUNC_NAME) 来调用

	/****************************/

	p_function = add; // 直接赋值

	/* 通过函数指针调用函数 */
	printf("p_function(x, y) = %d\n", p_function(x, y));
	printf("(*p_function)(x, y) = %d\n", (*p_function)(x, y));

	p_function = &add; // 通过地址赋值

	/* 通过函数指针调用函数 */
	printf("p_function(x, y) = %d\n", p_function(x, y));
	printf("(*p_function)(x, y) = %d\n", (*p_function)(x, y));

	/****************************/

	/* 通过函数地址直接调用函数 */
	printf("(&add)(x, y) = %d\n", (&add)(x, y));
	/*
	int add_address = (&add);
	printf("add_address = %p\n", add_address);
	printf("(add_address)(x, y)", (add_address)(x, y));
	printf("(*add_address)(x, y)", (*add_address)(x, y));
	printf("(*((int (*)(int x, int y))add_address))(x, y) = %d", (*((int (*)(int x, int y))add_address))(x, y));
	*/
	// 上述代码由于C中整型不能转为函数指针 , 因此出现错误
	void *p = NULL;
	p = (add);
	printf("p = %p\n", p);
	printf("((int (*)(int x, int y))p)(x, y) = %d\n", ((int (*)(int x, int y))p)(x, y));
	// 对函数指针进行强制类型转换
	// p = (int (*)(int x, int y))p; // 这在 C 中是被禁止的
	// 由于 (*p) 和 (&p) 只能做为右值 , 因此强转是没有意义的
	// printf("(&p)(x, y) = %d\n", (((int (*)(int x, int y))(&p)))(x, y));
	// printf("(*p)(x, y) = %d\n", ((int (*)(int x, int y))(*p))(x, y));

	/****************************/

	/* 打印函数指针地址进行分析 */
	printf("add -> %p\n", add);
	printf("(*add) -> %p (函数指针指向的地址的值还是一个地址 ? )\n", (*add));
	printf("(&add) -> %p\n", (&add));
	printf("p_function -> %p\n", p_function);
	printf("(*p_function) -> %p\n", (*p_function));
	printf("(&p_function) -> %p\n", (&p_function));

	return 0;
}

int add(int x, int y){
	return (x + y);
}
