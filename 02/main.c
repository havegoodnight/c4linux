#include <stdio.h>

int add(int a, int b){
	return a + b;
}

int main(){
	int a = 1;
	int b = 2;
	int plus = add(a, b);
	printf("The result is : %d", plus);
	return 0;
}

