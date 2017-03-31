#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>



/*
 * reset=0，balck=30，red=31，green=32，yellow=33，blue=34，magenta=35，cyan=36，white=37
 */
void printColor(char *content, int number){
	printf("\e[1;%dm", number);
	printf("%s", content);
	printf("\e[0m");
}



/* File types for `d_type'.  */
/*
enum
  {
    DT_UNKNOWN = 0,
    DT_FIFO = 1,
    DT_CHR = 2,
    DT_DIR = 4,
    DT_BLK = 6,
    DT_REG = 8,
    DT_LNK = 10,
    DT_SOCK = 12,
    DT_WHT = 14
  };
*/
/*	
printf("%ld\t", pdirent->d_ino);
printf("%ld\t", pdirent->d_off);
printf("%x", pdirent->d_type);
printf("%d\t", pdirent->d_reclen);
*/

void printDirNormal(struct dirent *pdirent){
	if (pdirent->d_type == DT_DIR){
		printColor(pdirent->d_name, 34); // blue
        printf("  ");
	}else{
		printColor(pdirent->d_name, 37); // white
        printf("  ");
    }
}

void printDirWithInode(struct dirent *pdirent){
	if (pdirent->d_type == DT_DIR){
		printColor(pdirent->d_name, 34); // blue
        printf("\n");
	}else{
		printColor(pdirent->d_name, 37); // white
        printf("\n");
    }
}


void printDirOnlyFolder(struct dirent *pdirent){
    if(pdirent->d_type == DT_DIR){
	    printf("%s  ", pdirent->d_name);
    }
}


void printHelp(){
	printf("Usage : \n");
	printf("        myls [OPTIONS] [FILE_PATH]\n");
	printf("Options : \n");
	// printf("        -l    show the details.\n");
	// printf("        -i    show the inodes of the files.\n");
	// printf("        -d    only show the folders.\n");
}

int main(int argc, char *argv[]){

	if (argc != 2){
		printHelp();
		exit(1);
	}

	DIR *pdir = opendir(argv[1]);

	if (pdir == NULL){
		printf("myls: cannot access '%s': No such file or directory\n", argv[1]);
		exit(2);
	}

	struct dirent *pdirent;
	
	while( (pdirent = readdir(pdir)) != NULL){
		// printDirNormal(pdirent);
		printDirWithInode(pdirent);
	}
	
	printf("\n");

	return 0;
}
