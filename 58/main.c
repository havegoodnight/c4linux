#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 128
#define ERROR 0

typedef struct{
	int id;
}ElementType;

typedef struct{
	ElementType data[MAXSIZE];
	int top;
}Stack;

void createStack(Stack *pstack);
void push(Stack *pstack, int item);
int pop(Stack *pstack);

int main(int argc, char *argv[]){
	Stack *pstack = malloc(sizeof(Stack));
	createStack(pstack);
	int i;
	for(i = 0; i < 10; i++){
		printf("push->[%d]|", i);
		push(pstack, i);
		printf("top->[%d]\n", pstack->top);
	}
	for(i = 0; i < 10; i++){
		printf("pop->[%d]|", pop(pstack));
		printf("top->[%d]\n", pstack->top);
	}
	return 0;
}

// 初始化栈
void createStack(Stack *pstack){
	memset(pstack, 0, MAXSIZE);
	pstack->top = MAXSIZE;
}

// 压栈
void push(Stack *pstack, int item){
	if (pstack->top == 0){
		printf("栈已满\n");
		return;
	}else{
		pstack->top--;
		pstack->data[pstack->top].id = item;
		return;
	}
}

// 弹栈(注意这里顺序和压栈刚好相反)
int pop(Stack *pstack){
	if(pstack->top >= 128){ // 栈空
		printf("栈已空\n");
		return ERROR; // ERROR 是一个特殊值 , 表示栈已空
	}else{
		int result = pstack->data[pstack->top].id;
		pstack->top++;
		return result;
	}
}
