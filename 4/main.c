#include <stdio.h>
#include "add.h"

int main(int argc, char** argv[]){
	int a = 1;
	int b = 2;
	int plus = add(a, b);
	printf("The result is : %d", plus);
	return 0;
}
