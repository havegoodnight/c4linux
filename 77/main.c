#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc){
    FILE *file = fopen("data", "a");
    char buffer0[0x10] = "1";
    char buffer1[0x10] = "2";
    int times = 0x1000;
    while(times-- > 0){
        usleep(500);
        int n = 0;
        if (argc > 1) {
            n = fwrite(buffer0, strlen(buffer0), 1, file);
        } else {
            n = fwrite(buffer1, strlen(buffer1), 1, file);
        }
        fflush(file);
        printf("%d bytes written\n", n);
    }
    fclose(file);
}



