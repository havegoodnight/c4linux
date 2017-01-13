int printf(const char *format, ...);

int global_init_var = 666;
int global_uninit_var;

void printNumber(int i){
	printf("%d\n", i);
}

int main(void){
	static int static_var = 888;
	static int static_uninit_var;
	int a = 1;
	int b;
	printNumber(static_var + static_uninit_var + a + b);

	return a;
}
