#include "main.h"

int main(int argc, char *argv[]){
	struct LINKEDLIST *pLinkedList = malloc(sizeof(struct LINKEDLIST));
	printf("初始化链表...\n");
	initLinkedList(pLinkedList);

	int i;
	for(i = 0; i < 10; i++){
		struct DATA *pData = malloc(sizeof(struct DATA));
		pData->number = i;
		struct NODE *pNode = malloc(sizeof(struct NODE));
		pNode->pData = pData;
		pNode->pNext = NULL;
		insertNodeTail(pLinkedList, pNode);
	}
	printf("打印当前链表 : \n");
	printLinkedList(pLinkedList);

	printf("添加节点 (321) 到 index = 4 : \n");
	struct DATA *pData = malloc(sizeof(struct DATA));
	pData->number = 321;
	struct NODE *pNode = malloc(sizeof(struct NODE));
	pNode->pData = pData;
	pNode->pNext = NULL;
	insertNode(pLinkedList, pNode, 4);

	printf("打印当前链表 : \n");
	printLinkedList(pLinkedList);
	printf("删除尾部节点...\n");
	deleteNodeTail(pLinkedList);
	printf("清空链表...\n");
	clearLinkedList(pLinkedList);
	printf("打印当前链表 : \n");
	printLinkedList(pLinkedList);
	printf("添加到尾部\n");
	printf("添加节点 (321) 到 index = 4 : (由于这个时候链表已经空了 , 因此再往 4 的位置插入就会插到尾部)\n");
	struct DATA *pDataTemp = malloc(sizeof(struct DATA));
	pDataTemp->number = 321;
	struct NODE *pNodeTemp = malloc(sizeof(struct NODE));
	pNodeTemp->pData = pDataTemp;
	pNodeTemp->pNext = NULL;
	insertNode(pLinkedList, pNodeTemp, 4);
	printf("打印当前链表 : \n");
	printLinkedList(pLinkedList);

	free(pLinkedList);
	return 0;
}
