#include <stdio.h>

int main(int argc, char* argv[]){
	printf("参数个数为 : %d\r\n", argc);
	int counter;
	for (counter = 0; counter < argc; counter++){
		printf("第%d个参数是%s\r\n", (counter + 1), argv[counter]);
	}
	return 0;
}
