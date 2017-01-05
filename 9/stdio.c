#include <stdio.h>
/*
 * stdin
 * stdout
 * stderr
 */
int main(int argc, char* argv[]){
	// pringf();
	fprintf(stdout, "Hello world!\r\n");

	int a;
	// scanf();
	fscanf(stdin, "%d", &a);
	printf("a = %d", a);
	return 0;
}
