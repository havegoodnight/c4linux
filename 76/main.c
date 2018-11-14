#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    struct stat statbuf = {0};
    stat("./no_such_file", &statbuf);
    printf("Link number: %d\n", statbuf.st_nlink);
}
