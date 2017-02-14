#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	char buffer[1024] = {0};
	while (1){
		memset(buffer, 0, 1024);
		read(0, buffer, 1024);
		write(1, buffer, 1024);
	}
	return 0;
}
