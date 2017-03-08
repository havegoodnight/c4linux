#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 128

struct Stack{
	int data[MAXSIZE];
	int top;
};

void createStack(struct Stack *pstack);
void push(struct Stack *pstack, int item);
int pop(struct Stack *pstack);

int main(int argc, char *argv[]){
	struct Stack *pstack = malloc(sizeof(struct Stack));
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
void createStack(struct Stack *pstack){
	memset(pstack, 0, MAXSIZE);
	pstack->top = MAXSIZE;
}

// 压栈
void push(struct Stack *pstack, int item){
	pstack->top--;
	pstack->data[pstack->top] = item;
}

// 弹栈(注意这里顺序和压栈刚好相反)
int pop(struct Stack *pstack){
	int result = pstack->data[pstack->top];
	pstack->top++;
	return result;
}
