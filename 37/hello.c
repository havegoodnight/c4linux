#include <stdio.h>

struct cat{
	int age;
	char *name;
};

int main(){
	struct cat garfield = {3, "Garfield"};
	struct cat *p_cat = &garfield;
	int *p_int = (int *)&garfield;
	printf("garfield.age = %d\ngarfield.name = %s\n", garfield.age, garfield.name);
	printf("p_cat->age = %d\np_cat.name = %s\n", p_cat->age, p_cat->name);
	printf("(*p_int) = %d\n(*(p_int + 1)) = %d\n", (*p_int), (*(p_int + 1))); // 这里将字符数组的前四个字节(一个字符一个字节)作为整型读出
	return 0;
}
