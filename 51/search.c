#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int count_string(char *father, char *son);

int main(int argc, char *argv[]) {

	if (argc != 3){
		printf("Usage : \n\t%s [filename] [string]\n", argv[0]);
		exit(1);
	}

	FILE *fd;
	char buffer[1024] = {0};
	char *filename = argv[1];
	char *son = argv[2];
	int counter = 0;

	fd = fopen(filename, "r");

	if (fd == NULL) {
		write(2, "Failed to open file.\n", 20);
		exit(1);
	}

	while (!feof(fd)) {
		memset(buffer, 0, sizeof(buffer));
		fgets(buffer, sizeof(buffer) - 1, fd);
		int temp = count_string(buffer, son);
		if (temp > 0) {
			counter += temp;
		}
	}

	fclose(fd);

	printf("[ %d ] times of [ %s ] found in the file : [ %s ].\n", counter, son, filename);

	return 0;
}

int count_string(char *father, char *son){
	int counter = 0;
	int pointer = 0; // 指针
	int length = strlen(son);
	// printf("length of son is : %d\n", length);
	// printf("Comparing : [%s] and [%s]\n", father, son);
	while(pointer < 1024){
		int i = 0;
		int flag = 1;
		for (i = 0; i < length; i++){
			// printf("Comparing : [ %c ] and [ %c ]\n", *(father+pointer+i), *(son+i));
			if((*(father + pointer + i)) != (*(son + i))){
				flag = 0;
				break;
			}
		}
		if (flag) {
			counter++;
			pointer++;
		} else {
			pointer += (i+1);
			// printf("Now pointer is [%d]\n", pointer);
		}
	}
	return counter; 
}
