#include <stdio.h>

int main(){
	// int a = 10;
	int b = 20;
	int c = 20;
	int d = 20;
	// int p = (a++) + (a++) + (a++);
	int q = (++b) + (++b) + (++b);
	int m = (++c) + (++c);
	int n = (++d) + (++d) + (++d) + (++d);
	// printf("a = %d\n", a);
	printf("b = %d\n", b);
	// printf("p = %d\n", p);
	printf("q = %d\n", q);
	printf("m = %d\n", m);
	printf("n = %d\n", n);
	return 0;
}
