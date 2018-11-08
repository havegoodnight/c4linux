#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]){
    // Redirection
    int fd = open("id.log", O_CREAT|O_RDWR|O_TRUNC);
    dup2(fd, 1);
    close(fd);
    // Execute new program
    char *child_argv[] = {
        "/usr/bin/id",
        NULL
    };
    char *child_envp[] = {
        "HOME=/",
        "PATH=/bin:/usr/bin",
        NULL
    };
    execve(child_argv[0], child_argv, child_envp);
	return 0;
}
