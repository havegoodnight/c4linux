#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    if (fork()) {
        printf("Parent start sleep\n");
        sleep(0x04);
        printf("Parent end sleep\n");
        printf("Parent wait child ends\n");
        /**
         * If the parent process does not call wait() to wait for the end of the child process
         * The child process will become orphan process
         * Then the child process will be adopted by init process
         * NOTICE:
         *  It seems that systemd will adopt the orphan process instead init
         */
        // wait(NULL);
        printf("Child ends\n");
        exit(0);
    } else {
        int times = 0x10;
        while (times-- > 0) {
            int pid = getppid();
            printf("PPID: %d\n", pid);
            sleep(0x01);
        }
    }
}
