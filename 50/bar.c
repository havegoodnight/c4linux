void foo_function(char *ptr, int length);

void bar_function(int arg1, int arg2){
	if (arg1 > arg2) {
		foo_function("arg1 > arg2", 11);
	} else if (arg1 == arg2) {
		foo_function("arg1 = arg2", 11);
	} else {
		foo_function("arg1 < arg2", 11);
	}
}
