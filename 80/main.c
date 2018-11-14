#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int daemonize(){
    // Make child process adopted by init/systemd
    printf("Make child process adopted by init/systemd\n");
    if (fork()) {
        exit(0);
    }
    printf("Finished\n");

    // Become process group leader
    printf("Become process group leader\n");
    setsid();
    printf("Finished\n");

    // Make sure that this process won't acquire a new controlling tty
    printf("Make sure that this process won't acquire a new controlling tty\n");
    if (fork()) {
        exit(0);
    }
    printf("Finished\n");

    // Change working directory
    printf("Change working directory\n");
    chdir("/tmp");
    printf("Finished\n");

    // Change umask to 0 to allow open() creat()
    printf("Change umask to 0 to allow open() creat()\n");
    umask(0);
    printf("Finished\n");

    // Close all inherited files
    printf("Close all inherited files\n");
    fcloseall();
    printf("Finished\n");

    // Use dev null as stdin stdout and stderr
    printf("Use dev null as stdin stdout and stderr\n");
    int fd0 = open("/dev/null", O_RDWR);
    dup(fd0);
    dup(fd0);
    printf("Finished\n");
}

int ensure_running(char * log_path){
    char buffer[] = "Running\n";
    FILE * file = fopen(log_path, "a+");
    fwrite(buffer, sizeof(buffer), 1, file);
    fclose(file);
}

int main(int argc, char *argv[]){
    char * log_path = "daemon.log";
    daemonize();
    while(1) {
        ensure_running(log_path);
        sleep(0x10);
    }
	return 0;
}
