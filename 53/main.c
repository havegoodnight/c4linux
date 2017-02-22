#include <stdio.h>
#include <stdlib.h>

/* 链表
 * 应该有的功能有 : 
 * 1. 初始化节点(创建一个空链表)
 * 2. 清空链表
 * 3. 获取链表长度
 * 1. 插入指定位置
 * 2. 获取指定位置的节点
 * 4. 删除指定位置节点
 * 5. 修改指定节点数据
 */

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

	/*
	if(index < 0 || !index){ // 非法索引 , 但是由于函数没有返回 , 则将其插在头部
		if(pLinkedList->pFirstNode == NULL){ // 链表为空的时候 , 直接插入
			pLinkedList->pFirstNode = pNewNode;
			pLinkedList->length = 1;
		}else{ // 非空的时候需要先找到头结点 , 然后找准位置插入
			pNewNode->pNext = pLinkedList->pFirstNode->pNext;
			pLinkedList->pFirstNode = pNewNode;
			pLinkedList->length++;	
		}
		return 0;
	}else{
		if (index >= pLinkedList->length){
			// 当 index 大于长度的时候默认就是往链表尾部插入
			struct NODE *pNode = selectNode(pLinkedList, index - 1); // 找到需要插入的地方的上一个节点
			// pNewNode->pNext = pNode->pNext; // 这个时候 pNode->pNext 就是空的了 , 因此就不需要了
			pNewNode->pNext = NULL;
			pNode->pNext = pNewNode;
			pLinkedList->length++;
			return pLinkedList->length;
		}else{
			struct NODE *pNode = selectNode(pLinkedList, index - 1); // 找到需要插入的地方的上一个节点
			pNewNode->pNext = pNode->pNext;
			pNode->pNext = pNewNode;
			pLinkedList->length++;
			return pLinkedList->length;
		}
	}
	*/
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
	/*
	struct NODE *pNode = selectNodeTail(pHead); // 选中需要删除的节点的父节点
	free(pTempNode->pData);
	free(pTempNode);
	*/
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
/*	struct NODE *pNode = pHead;
	while(1){
		if(pNode->pNext == NULL){
			return pNode;
		}else{
			pNode = pNode->pNext;
		}
	}
	// return NULL; // 不知道有没有用 , 理论上是执行不到这里的
*/
	return selectNode(pLinkedList, pLinkedList->length - 1);
}
