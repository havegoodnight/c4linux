#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void printDir(struct dirent *pdirent){
	printf("%s\t\t", pdirent->d_name);
	printf("%ld\t", pdirent->d_ino);
	printf("%ld\t", pdirent->d_off);
	printf("%d\t", pdirent->d_reclen);
	printf("%x\t\n", pdirent->d_type);
}


void printHelp(){
	printf("Usage : \n");
	printf("        myls [FILE_PATH]\n");
}

void printTableHead(){
	printf("[name]\t\t[inode]\t[offset]\t[length]\t[type]\n");

}

int main(int argc, char *argv[]){

	if (argc != 2){
		printHelp();
		exit(1);
	}

	DIR *pdir = opendir(argv[1]);

	if (pdir == NULL){
		printf("[-] opendir error!\n");
		exit(2);
	}

	printTableHead();

	struct dirent *pdirent;// = malloc(sizeof(struct dirent));
	
	while( (pdirent = readdir(pdir)) != NULL){
		printDir(pdirent);
	}

	return 0;
}
