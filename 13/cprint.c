// #include "print.h"
#include "cprint.h"

void cprint_blue(char *content){
	printf("\033[34m");
	print(content);
	printf("\033[0m");
}

void cprint_red(char *content){
	printf("\033[31m");
	print(content);
	printf("\033[0m");
}

void cprint_pink(char *content){
	printf("\033[35m");
	print(content);
	printf("\033[0m");
}

void cprint_green(char *content){
	printf("\033[32m");
	print(content);
	printf("\033[0m");
}

void cprint_yellow(char *content){
	printf("\033[33m");
	print(content);
	printf("\033[0m");
}

void cprint_black(char *content){
	printf("\033[30m");
	print(content);
	printf("\033[0m");
}

