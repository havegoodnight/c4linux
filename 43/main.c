#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int pid;

	printf("Father pid = %d\n", getpid());

	pid = fork();
	if (pid < 0) { // fork 函数失败的时候返回就是负数 , 具体参考 man 手册
		puts("Failed to fork!");
		exit(1);
	}else if (pid == 0) { // 这里用 pid 来区分当前是子进程还是父进程
		printf("I am the son process, now pid is %d, my ppid is %d, getpid() = %d\n", pid, getppid(), getpid());
	}else{
		printf("I am the parent process, now pid is %d, my ppid is %d, getpid() = %d", pid, getppid(), getpid()); // 这里输出的 pid 就是 fork 的返回值 , 当 fork 成功的时候返回就是 0
	}

	return 0;
}
