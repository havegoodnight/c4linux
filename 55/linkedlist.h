#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>

/*
 * 定义节点数据域数据类型
 */
struct DATA{
	int number;
};

/*
 * 定义节点数据类型
 */
struct NODE{
	struct DATA *pData;
	struct NODE *pNext;
};

/*
 * 定义链表数据类型(一个含有 指向链表第一个节点的指针 和 链表长度 的数据结构)
 */
struct LINKEDLIST{
	int length;
	struct NODE *pFirstNode;
};


void initLinkedList(struct LINKEDLIST *pLinkedList);
void clearLinkedList(struct LINKEDLIST *pLinkedList);
int printLinkedList(struct LINKEDLIST *pLinkedList);
int insertNode(struct LINKEDLIST *pLinkedList, struct NODE *pNewNode, int index);
int insertNodeTail(struct LINKEDLIST *pLinkedList, struct NODE *pNewNode);
void deleteNode(struct LINKEDLIST *pLinkedList, int index);
void deleteNodeTail(struct LINKEDLIST *pLinkedList);
void updateNode(struct LINKEDLIST *pLinkedList, struct DATA *data, int index);
struct NODE *selectNode(struct LINKEDLIST *pLinkedList, int index);
struct NODE *selectNodeTail(struct LINKEDLIST *pLinkedList);


#endif
