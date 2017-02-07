#include <stdio.h>
#include <string.h>

int main(){
	char *string[3] = {
		"Hello world!",
		"Hello China!",
		"Hello Harbin!"
	};
	char content[128];
	strcpy(content, string[0]); // strcpy(s, *(string + 0));
	strcpy(content, string[1]);
	strcpy(content, string[2]);
	printf("%s\n", content);
	return 0;
}
