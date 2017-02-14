#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p1, const void *p2){
	int a = *(int *)p1;
	int b = *(int *)p2;
	return (a>b);
}

int main(int argc, char *argv[]){
	int data[] = {312, 34, 432, 543, 342, 32, 234, 434, 342, 432, 54, 5, 4, 2, 243, 321};
	int i;

	/* 排序之前输出一下数组所有元素 */
	puts("Before qsort : ");
	for (i = 0; i < 0x10; i++){
		printf("%d ", data[i]);
	}
	printf("\n");

	/* 排序 */
	qsort(data, 0x10, sizeof(int), compare);


	/* 排序之后输出一下数组所有元素 */
	puts("After qsort : ");
	for (i = 0; i < 0x10; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
	return 0;
}
