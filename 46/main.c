#include <stdio.h>

int main(int argc, char *argv[]){
	fork();
	// fork() && fork() || fork();
	/* 以下这段 if 语句和上句代码等同 */
	if (fork()) {
		if (!fork()) {
			fork();
		}
	} else {
		fork();
	}
	fork();
	/*
	 * 研究方法 : 
	 *		已知 fork() 函数是拷贝当前进程的内存状态 , 然后产生一个新的进程 (子进程)
	 *		可以将代码打印出来 , 然后用纸和笔模拟内存中程序的变化 , 可以用 : (main_0_3) 来表示 第 0 号进程目前执行状态为 03 行
	 */
	printf("+\n");
	return 0;
}
