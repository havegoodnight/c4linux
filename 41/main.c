#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]){
	/* 测试标志位 , 这里其实都是 2 的 n 次方 , 因此可以通过按位或来设置文件的打开模式
	printf("%d\n", O_APPEND);
	printf("%d\n", O_ASYNC);
	printf("%d\n", O_CLOEXEC);
	printf("%d\n", O_CREAT);
	printf("%d\n", O_DIRECTORY);
	printf("%d\n", O_EXCL);
	*/
	int fd;
	fd = open("./data.txt", O_CREAT | O_WRONLY, 0600);
	if (fd == -1){
		puts("Failed to open file.\n");
		exit(1);
	}

	/*
	char buffer[] = "Hello world!";
	write(fd, buffer, sizeof(buffer));
	*/
	
	char *buffer = "Hello world!";
	write(fd, buffer, strlen(buffer)); // 只有当 sizeof 的参数是数组的时候 , 返回值才是数组的真正长度 , 否则就是数据类型的长度

	close(fd);

	return 0;
}
