#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR *dir;
	dir = opendir("./");
	if (dir == NULL) {
		puts("Failed to open dir.");
		exit(1);
	}

	struct dirent *m_dirent; // Linux 的文件系统中 , 一个文件夹中的所有文件应该是通过类似于链表的形式储存的 , 这样就可以通过 readdir 函数来一个一个读取所有的文件 (不知道这样的理解对不对 , 不是应该是以树的形式存储的吗 ? )

	while((m_dirent = readdir(dir)) != NULL){
		puts("============================================\n");
		printf("m_dirent->d_ino = %ld\n", m_dirent->d_ino);
		printf("m_dirent->d_off = %ld\n", m_dirent->d_off);
		printf("m_dirent->d_reclen = %d\n", m_dirent->d_reclen);
		printf("m_dirent->d_type = %c\n", m_dirent->d_type);
		printf("m_dirent->d_name = %s\n", m_dirent->d_name);
	}


	closedir(dir);

	return 0;
}
