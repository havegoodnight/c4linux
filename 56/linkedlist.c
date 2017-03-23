#include "linkedlist.h"

void initLinkedList(struct LINKEDLIST *pLinkedList){
	pLinkedList->length = 0;
	pLinkedList->pFirstNode = NULL;
}

void clearLinkedList(struct LINKEDLIST *pLinkedList){
	/*
	 * free 掉所有占用的内存
	 */
	if (pLinkedList->pFirstNode == NULL){ // 已经空了
		return;
	}
	struct NODE *pNode = pLinkedList->pFirstNode;
	while((pNode = pNode->pNext) != NULL){
		free(pNode->pData);
		free(pNode);
	}
	initLinkedList(pLinkedList);
}

int printLinkedList(struct LINKEDLIST *pLinkedList){
	if (pLinkedList->pFirstNode == NULL){
		return 0; // 当链表中没有数据的时候就直接返回链表长度 0
	}
	int i = 0;
	struct NODE *pNode = pLinkedList->pFirstNode;
	do {
		printf("[ %d ] -> [ %d ]\n", i++, pNode->pData->number); // 这里由于 pNode 直接就是第一个节点 , 所以要先打印然后再指向下一个节点
	}while((pNode = pNode->pNext)!=NULL);
	return i;
}

int insertNode(struct LINKEDLIST *pLinkedList, struct NODE *pNewNode, int index){
	/* 处理范围溢出的问题 */
	if (index < 0){
		index = 0;
	}else if (index > pLinkedList->length){
		index = pLinkedList->length;
	}
	/* 处理链表为空的情况 */
	if(pLinkedList->pFirstNode == NULL){
		pLinkedList->pFirstNode = pNewNode;
		pNewNode->pNext = NULL;
		pLinkedList->length++;
		return 0; // 返回插入的位置
	}else{
		if (index == 0){
			pNewNode->pNext = pLinkedList->pFirstNode;
			pLinkedList->pFirstNode = pNewNode;
			pNewNode->pNext = NULL;
			pLinkedList->length++;
		}else if(index == pLinkedList->length){
			struct NODE *pNode = selectNode(pLinkedList, index - 1); // if 分支已经保证了 index 不会为 0 , 而且肯定是大于 0 的 , 并且不会大于链表的长度
			pNode->pNext = pNewNode;
			pNewNode->pNext = NULL;
			pLinkedList->length++;
		}else{
			struct NODE *pNode = selectNode(pLinkedList, index - 1); // if 分支已经保证了 index 不会为 0 , 而且肯定是大于 0 的 , 并且不会大于链表的长度
			pNewNode->pNext = pNode->pNext;
			pNode->pNext = pNewNode;
			pLinkedList->length++;	
		}
		return index; // 返回插入的位置
	}
}

int insertNodeTail(struct LINKEDLIST *pLinkedList, struct NODE *pNewNode){
	insertNode(pLinkedList, pNewNode, pLinkedList->length); // 插入到尾部 , 即 索引为 length
}

void deleteNode(struct LINKEDLIST *pLinkedList, int index){
	struct NODE *pNode = selectNode(pLinkedList, index - 1); // 选中需要删除的节点的父节点
	struct NODE *pTempNode = pNode->pNext; // 保存需要删除的节点的地址 (需要用它找到它的下一个节点 , 而且还要 free 掉它自己)
	pNode->pNext = pTempNode->pNext; // 将父节点的指针域指向孙子节点 (也就是越过了需要删除的节点)
	free(pTempNode->pData);
	free(pTempNode);
	pLinkedList->length--;
}

void deleteNodeTail(struct LINKEDLIST *pLinkedList){
	deleteNode(pLinkedList, pLinkedList->length - 1);
}

void updateNode(struct LINKEDLIST *pLinkedList, struct DATA *data, int index){
	struct NODE *pNode = selectNode(pLinkedList, index);
	free(pNode->pData); // free 之前节点的数据域的结构体在内存中占用的空间
	pNode->pData = data;
}

struct NODE *selectNode(struct LINKEDLIST *pLinkedList, int index){
	if (index < 0 || index >= pLinkedList->length){
		return NULL;
	}
	if (pLinkedList->length == 0){
		return NULL;
	}
	if (!index){ // 当 index == 0 , 则说明要取第一个元素 , 也就是直接通过 pLinkedList 返回 pFirstNode 即可
		return pLinkedList->pFirstNode;
	}else{ // 当 index != 0 , 则先要找到第一个元素 , 然后通过第一个元素找到下面的元素
		struct NODE *pNode = pLinkedList->pFirstNode;
		while((index--)>0){
			pNode = pNode->pNext;
		}
		return pNode;
	}
}

struct NODE *selectNodeTail(struct LINKEDLIST *pLinkedList){
	return selectNode(pLinkedList, pLinkedList->length - 1);
}

