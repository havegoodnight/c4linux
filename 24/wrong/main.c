#include <stdio.h>

void swap(int a, int b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main(){
	int a = 10;
	int b = 1;
	swap(a, b);
	printf("a = %d;\t b = %d\n", a, b);
}
