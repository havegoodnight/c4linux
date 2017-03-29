#include <stdio.h>

int main(){
	int num = 0x12345678;
	void *p = &num;
	int i;
	FILE * file = fopen("temp.dat", "w");
	// size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
	fwrite(p, sizeof(int), 1, file);
	fclose(file);
	return 0;
}
