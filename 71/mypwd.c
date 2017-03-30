#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int p = get_current_dir_name();
	printf("%s\n", (char *)p);
	return 0;
}
