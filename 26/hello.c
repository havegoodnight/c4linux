#include <stdio.h>

#define LENGTH 16

int main(int argc, char *argv[]){
	int array[LENGTH];
	int *pointer;
	int i;

	/* 遍历数组赋值 */
	printf("数组赋值中...");
	for (i = 0; i < LENGTH; i++){
		array[i] = i;
	}

	/******************/
	printf("-----------------------\n");
	/******************/

	/* 遍历数组打印 */
	printf("利用数组下标来访问的传统方式 : \n");
	for (i = 0; i < LENGTH; i++){
		printf("array[%d] = %d\n", i, array[i]);
	}

	/******************/
	printf("-----------------------\n");
	/******************/

	/* 利用指针下标来遍历 */
	printf("利用指针下标来遍历数组 : \n");
	// 初始化指针
	pointer = array;
	// pointer = &array[0];
	for (i = 0; i < LENGTH; i++){
		printf("pointer[%d] = %d\n", i, pointer[i]);
	}

	/******************/
	printf("-----------------------\n");
	/******************/

	/* 利用纯指针来遍历数组 */
	printf("利用纯指针来遍历数组 : \n");
	int counter = 0;
	for (pointer = array; pointer != &array[LENGTH] ; pointer++){
		counter++;
		printf("Time : %d ,value = %d\n", counter, *pointer);
	}

	/******************/
	printf("-----------------------\n");
	/******************/

	/* 使用指针来访问数组之后内存 */
	printf("使用指针来访问数组之后的内存 : \n");
	pointer = array;
	printf("pointer[16] = %d\n", pointer[16]);

	/******************/
	printf("-----------------------\n");
	/******************/

	/* 使用数组名来访问数组之后内存 */
	printf("使用数组名来访问数组之后的内存 : \n");
	printf("array[16] = %d\n", array[16]);

	/******************/
	printf("-----------------------\n");
	/******************/


	/* 利用指针的 * 的语法来访问数组元素 */
	printf("利用指针的 * 的语法来访问数组 : \n");
	// 初始化指针
	pointer = &array[0];
	// pointer = array;
	for (i = 0; i < LENGTH; i++){
		printf("*(pointer + %d) = %d\n", i, *(pointer + i));
	}

	/******************/
	printf("-----------------------\n");
	/******************/

	/* 使用数组的名称以及 * 的语法来访问数组 */
	printf("使用数组的名称以及 * 的语法来访问数组 : \n");
	for (i = 0; i < LENGTH; i++){
		printf("*(array + %d) = %d\n", i, *(array + i));
	}

	/******************/
	printf("-----------------------\n");
	/******************/

	/* 奇怪的数组语法 */
	printf("奇怪的数组语法 : \n");
	printf("array[5] = %d\n", array[5]);
	printf("5[array] = %d\n", 5[array]);
	printf("两种写法其实是相同的 , 指的都是 *(array + 5) , 都表示的是地址 , 而加法具有交换律 , 所以等同\n");

	/******************/
	printf("-----------------------\n");
	/******************/

	/* 数组名是否和指针一样可以运算 ?  */
	printf("数组名是否和指针一样可以运算 : \n");
	printf("array = %p\n", array);
	printf("&array = %p\n", &array);
	printf("(array + 1) = %p\n", (array+1));
	// printf("(array++) = %p\n", (array++)); // 编译不通过
	printf("array = %p\n", array);
	printf("这样是不是可以理解为 : 数组名就是保存了一个地址的静态变量 , 这个值是不能变化的 , 这也是为什么不能进行自增运算只能取值的原因\n");
	printf("而指针是正常的变量 , 其中的值是可以改变的 , 因此可以进行进行自增运算 , 也可以取值\n");

	return 0;
}
