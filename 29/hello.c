#include <stdio.h>

int main(){
	int a = 2;
	int *p = &a;
	int *q = &a;
	printf("%d %d\n", *p++, *(q++)); // 自增运算符如果在变量名之后 , 则先使用值 , 然后自增 , 否则 , 先自增 , 然后使用值
	// 这里先使用值 , 然后自增
	p = &a;
	q = &a;
	printf("%d %d\n", *p, (*q)++); // 括号改变了运算的优先级
	return 0;
}
