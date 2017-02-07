#include <stdio.h>

int main(){
	char content[] = "When_can_I_see_you_again?";
	int *pointer = content;
	char **p = &pointer; // p 这个指针指向的变量的类型是 (char *) , 也就是指向的变量也是一个指针 , 这个指针可以指向一个字符变量

	printf("%s\n", content); // 这个 %s 就是需要传入首地址 , 然后会逐字符输出 , 直到遇到 \0 , 也就是字符串的结尾
	printf("%s\n", &content[0]);
	printf("%s\n", pointer);

	printf("%p\n", pointer); // 这就是 content 这个字符数组的首元素的首地址

	printf("%p\n", &pointer); // 打印指向 content 这个字符数组的首元素的首地址的指针变量的地址
	printf("%p\n", p); // 打印指向上述指针的字符数组的首地址
	
	printf("%p\n", *p);

	printf("%c\n", **p);
	printf("%p\n", p); // 打印自增前指针的值
	printf("%p\n", *p);
	p++;
	printf("%p\n", *p);
	printf("%p\n", p); // 打印自增后指针的值
	printf("%d\n", sizeof(char *)); // 打印指针指向的变量占用内存的大小
	printf("%c\n", **p); // 由于自增运算是将指针变量的值加上 sizeof(指针指向的变量的类型的长度) , 这里 p 指向的也是一个指针 , 也就是增加 8 个字节
	// 8 字节也就是 64 位
	
	/*
		p 这个指针指向的是 char * , 也就是指向了一个指针 , 这个指针在 64 位机里面用 8 字节来表示
		p++ 表示将 p 这个变量的值增加 sizeof(char *) , 也就是 8
		在这个程序中也就是 (&pointer + 8)
		也就是 pointer 这个指针的地址 (注意是地址而不是值) 再加上 8
		而这个地址是在栈内存中的
		这个时候如果再去用 **p 来访问内存的话 
		由于 *p 已经指向了一个野地址 , 因此就会出现随机值或者直接崩溃
	*/

	return 0;
}
