#include <stdio.h>
#include "mathfunc.h"

int main(int argc, char *argv[]){
	int x = 666;
	int y = 888;
	printf("The max number is : %d\n", getMax(x, y));
	printf("The min number is : %d\n", getMin(x, y));
	printf("%d + %d = %d\n", x, y, add(x, y));
	printf("%d - %d = %d\n", x, y, sub(x, y));
	return 0;
}
