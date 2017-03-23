#include "main.h"

int main(int argc, char *argv[]){
	/* 由于单链表的特殊性 , 在作为栈使用的时候 , 栈顶只能指向链表的头 */
	struct LINKEDLIST *pLinkedStack = malloc(sizeof(struct LINKEDLIST));
	initLinkedStack(pLinkedStack)



	return 0;
}

void initLinkedStack(struct LINKEDLIST *pLinkedStack){
	pLinkedStack->length = 0;
	pLinkedStack->pFirstNode = NULL;
}

void push(struct LINKEDLIST *pLinkedStack){
	
}
