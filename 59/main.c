#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 128

typedef struct{
	int id;
}ElementType;

typedef struct{
	ElementType data[MAXSIZE];
	int top_little;
	int top_big;
}Stack;

void createStack(Stack *pstack);
void push_little(Stack *pstack, int item);
void push_big(Stack *pstack, int item);
int pop_little(Stack *pstack);
int pop_big(Stack *pstack);

int main(int argc, char *argv[]){
	Stack *pstack = malloc(sizeof(Stack));
	createStack(pstack);
	int i;
	for(i = 0; i < 64; i++){
		push_little(pstack, i);
	}
	for(i = 0; i < 64; i++){
		push_big(pstack, i);
	}
	/* 打印整个栈 */
	for(i = 0; i < MAXSIZE; i++){
		printf("pstack->data[%d] = %d\n", i, pstack->data[i].id);
	}
	return 0;
}

// 初始化栈
void createStack(Stack *pstack){
	memset(pstack, 0, MAXSIZE);
	pstack->top_little = -1;
	pstack->top_big = MAXSIZE;
}

// 压栈
void push_little(Stack *pstack, int item){
	if (pstack->top_little + 1 == pstack->top_big){
		printf("栈已满\n");
		exit(2);
	}else{
		pstack->top_little++;
		pstack->data[pstack->top_little].id = item;
		return;
	}
}

// 压栈
void push_big(Stack *pstack, int item){
	if (pstack->top_little + 1 == pstack->top_big){
		printf("栈已满\n");
		exit(2);
	}else{
		pstack->top_big--;
		pstack->data[pstack->top_big].id = item;
		return;
	}
}

// 弹栈(注意这里顺序和压栈刚好相反)
int pop_little(Stack *pstack){
	if(pstack->top_little < 0){ // 栈空
		printf("小栈已空\n");
		exit(1);
	}else{
		int result = pstack->data[pstack->top_little].id;
		pstack->top_little--;
		return result;
	}
}

// 弹栈(注意这里顺序和压栈刚好相反)
int pop_big(Stack *pstack){
	if(pstack->top_big > 127){ // 栈空
		printf("大栈已空\n");
		exit(1);
	}else{
		int result = pstack->data[pstack->top_big].id;
		pstack->top_big++;
		return result;
	}
}
