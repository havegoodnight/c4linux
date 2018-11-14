#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    char root_line[] = "I am root.";
    char nonroot_line[] = "I am not root.";
    FILE *file;
    // Save all uid
    int ruid, euid, suid;
    getresuid(&ruid, &euid, &suid);
    printf("Real uid: %d\n", ruid);
    printf("Effective uid: %d\n", euid);
    printf("Saved set uid: %d\n", suid);

    // Do something which need privillege
    printf("Setting uid to root(0)\n");
    setuid(0);
    printf("Writting %ld bytes (%s) into root file.\n", sizeof(root_line), root_line);
    file = fopen("root", "a");
    if (file != NULL) {
        fwrite(root_line, sizeof(root_line), 1, file);
        fwrite("\n", 1, 1, file);
        fclose(file);
    } else {
        printf("Open root file failed");
    }

    // Restore privillege
    printf("Restoring uid\n");
    setuid(ruid);

    // Retry
    printf("Writting %ld bytes (%s) into root file.\n", sizeof(nonroot_line), nonroot_line);
    file = fopen("root", "a");
    if(file != NULL) {
        fwrite(nonroot_line, sizeof(nonroot_line), 1, file);
        fwrite("\n", 1, 1, file);
        fclose(file);
    } else {
        printf("Open root file failed");
    }
}
