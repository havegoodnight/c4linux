#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int pid = fork();
    if (pid > 0) {
        printf("Child process (%d) created\n", pid);
        int times = 0x10;
        while (times-- > 0) {
            printf("I am parent process, I have nothing to do even my child dead\n");
            sleep(0x01);
        }
    } else if (pid == 0) {
        printf("I am child process\n");
        printf("I am going to die\n");
        printf("If my parent do not reap me, I will become a zombie process\n");
        exit(0);
    } else {
        printf("Fork failed\n");
    }
	return 0;
}
