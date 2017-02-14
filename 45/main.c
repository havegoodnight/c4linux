#include <stdio.h>

/* 冒泡排序 */
int main(int argc, char *argv[]){
	int data[16] = {12, 23, 54, 36, 56,26, 763, 636, 432, 653, 246, 674, 9734, 4361, 434, 245};
	int i;
	int j;
	for (i = 15; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (data[j] > data[j+1]){
				int temp;
				temp = data[j+1];
				data[j+1] = data[j];
				data[j] = temp;
			}
		}
	}
	int counter = 0;
	for (counter = 0; counter < 16; counter++) {
		printf("data[%d] = %d\n", counter, data[counter]);
	}
	return 0;
}
