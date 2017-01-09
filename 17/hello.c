#include "hello.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
	int file;

	/* Check user input  */
	if (argc != 3){
		printf("Usage : \n\t%s [filename] [content]\n", argv[0]);
		exit(1);
	}

	char *filename = argv[1];
	char *content = argv[2];

	/* Print user input */
	printf("Filename : %s\n", filename);
	printf("Content : %s\n", content);
	
	/* Create or open file */
	file = open(filename, O_WRONLY|O_CREAT, 0600);
	
	/* Judge whether open file succeed */
	if (file == -1){
		printf("Open or create file failed.\n");
		exit(2);
	}

	/* Get size of content */
	int counter = 0;
	while(content[counter] != 0){
		counter++;
	}

	/* Write content to file */
	write(file, content, counter);

	/* Close file  */
	close(file);

	////////////////////////////////

	/* Create or open file */
	file = open(filename, O_RDONLY);

	/* Read file content */
	char buffer[BUFFER_SIZE];
	int read_size = read(file, buffer, counter - 1);

	/* Judge whether read file succeed */
	if (read_size == -1){
		printf("Read file failed.\n");
		exit(3);
	}

	/* Print content of file */
	printf("The conent of this file is : \n%s\n", buffer);

	/* Close file  */
	close(file);

	return 0;
}
