#include <stdio.h>

int main(argc, argv, envp)
int argc;
char *argv[];
char *envp[];
{
	int i;
	for (i = 0; argv[i] != NULL; i++){
		printf("argv[%d] = [%s]\n", i, argv[i]);
	}
	for (i = 0; envp[i] != NULL; i++){
		printf("envp[%d] = [%s]\n", i, envp[i]);
	}
	return 0;
}
