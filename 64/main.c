#include <stdio.h>
#include <stdlib.h>

int main(){

	int *a;
	a = malloc(sizeof(int));
	*a = 1234;
	printf("%d\n", *a);
	free(a);
	printf("%d\n", *a);
}
