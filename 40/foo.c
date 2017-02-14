#include "foo.h"

int main(int argc, char *argv[]){
	char *buffer;
	buffer = (char *)malloc(BUFFER_SIZE);
	if (buffer == NULL){
		puts("Failed to get or allocate the memery!\n");
		exit(1);
	}else{
		strcpy(buffer, "Hello world!");
		printf("The buffer is : %s\n", buffer);
		free(buffer); /* 非常重要 , 在使用完成 malloc 申请的内存之后一定要将其 free 掉 , 否则会造成内存泄漏的问题 */
	}
	return 0;
}
