#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, char *argv[])
{
	int a = 1;
	int b = 2;
	swap(&a, &b);
	printf("Number a : %d\nNumber b : %d\n", a, b);
	return 0;
}
