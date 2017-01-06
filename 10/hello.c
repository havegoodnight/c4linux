#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char *ptr;
	ptr = (char *)malloc(24);
	if (ptr == NULL){
		printf("malloc error!");
		exit(1); // or return 1;
	}
	strcpy(ptr, "Hello world!");
	printf("The ptr is : %s\n", ptr);
	free(ptr);	
	return 0;
}
