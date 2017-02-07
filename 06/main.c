#include <stdio.h>
#include "max.h"
#include "min.h"

int main(int argc, char** argv[]){
	int a = 11;
	int b = 54;
	int maxNum = max(a, b);
	int minNum = min(a, b);
	printf("Max : %d\nMin : %d\n", maxNum, minNum);
	return 0;
}
