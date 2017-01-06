#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char *ptr;
	ptr = malloc(24);
	strcpy(ptr, "Hello world!");
	printf("The ptr is : %s\n", ptr);
	free(ptr);	
	return 0;
}
