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
	// 因此上述操作是危险的 , 并不建议这样做
	// 还有编译器在编译的时候 , 结构体中的变量在内存中的排放可能不是连续的
	// 因此上一行代码并没有将字符数组的前四个字节全部打印出来 , 只是打印了部分字节 , 说明在 int age; 之后编译器还填充了一些空字节
	// 因此如果直接通过地址来读取结构体中的数据是非常容易出错也是非常危险的
	printf("((struct cat*)p_int)->age = %d\n", ((struct cat*)p_int)->age);
	// 但是在使用的时候只要将其强制转换为结构体类型 , 就可以根据结构体在内存中的排布来访问其中的变量
	return 0;
}
