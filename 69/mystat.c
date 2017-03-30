#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

/*                                                                              
struct stat {
    dev_t     st_dev;         // ID of device containing file
    ino_t     st_ino;         // inode number
    mode_t    st_mode;        // protection
    nlink_t   st_nlink;       // number of hard links
    uid_t     st_uid;         // user ID of owner
    gid_t     st_gid;         // group ID of owner
    dev_t     st_rdev;        // device ID (if special file)
    off_t     st_size;        // total size, in bytes
    blksize_t st_blksize;     // blocksize for filesystem I/O
    blkcnt_t  st_blocks;      // number of 512B blocks allocated

    struct timespec st_atim;  // time of last access
    struct timespec st_mtim;  // time of last modification
    struct timespec st_ctim;  // time of last status change

#define st_atime st_atim.tv_sec      // Backward compatibility
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec
};
*/ 
void printStat(struct stat * pstat){
	printf("[st_dev] -> [%ld]\n", pstat->st_dev);
	printf("[st_ino] -> [%ld]\n", pstat->st_ino);
	printf("[st_mode] -> [%x]\n", pstat->st_mode);
	printf("[st_nlink] -> [%ld]\n", pstat->st_nlink);
	printf("[st_uid] -> [%d]\n", pstat->st_uid);
	printf("[st_gid] -> [%d]\n", pstat->st_gid);
	printf("[st_rdev] -> [%ld]\n", pstat->st_rdev);
	printf("[st_size] -> [%ld]\n", pstat->st_size);
	printf("[st_blksize] -> [%ld]\n", pstat->st_blksize);
	printf("[st_blocks] -> [%ld]\n", pstat->st_blocks);
	printf("[st_atim] -> %s", ctime(&pstat->st_atime));
	printf("[st_mtim] -> %s", ctime(&pstat->st_mtime));
	printf("[st_ctim] -> %s", ctime(&pstat->st_ctime));
}

void printHelp(){
	printf("Usage : \n");
	printf("        mystat [FILE_PATH]\n");
}

int main(int argc, char *argv[]){
	if (argc != 2){
		printHelp();
		exit(1);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd < 0){
		printf("[%d] open file error!\n", fd);
	}
	struct stat *pstat = malloc(sizeof(struct stat));
	int result = fstat(fd, pstat);
	if (result < 0){
		printf("[%d] fstat error!\n", result);
		exit(3);
	}
	printStat(pstat);
	return 0;
}
