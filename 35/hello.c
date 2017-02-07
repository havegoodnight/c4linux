#include <stdio.h>

int main(){
	char content[] = "Hello world!"; // 总共 12 个字符 , 加上结尾的 \0 , 长度为 13
	printf("sizeof(content) = %ld\n", sizeof(content));
	printf("sizeof(*content) = %ld\n", sizeof(*content));
	printf("sizeof(content[0]) = %ld\n", sizeof(content[0]));
	printf("sizeof(*(content + 1)) = %ld\n", sizeof(*(content + 1)));
	printf("sizeof(&content) = %ld\n", sizeof(&content));
	return 0;
}
