#include "main.h"

/*
 * 树的每一个节点的数据域
 */
struct TREEDATA{
	char ch;
};

/*
 * 树 的叶子节点的特殊属性
 * 比如说 : 
 *		如果把一本英语词典用 树 这种结构来存储
 *		那么 叶子节点 的属性这个数据结构中就可以存储单词的词性等数据
 */
struct ATTRIBUTE{
	int length; // 暂时只写一个长度 , 保存了从根节点追溯到该叶子节点的跳数 , 也就是 枝 的个数
};

/*
 * 树 的叶子节点
 */
struct LEAFNODE{
	struct TREEDATA *pData;
	struct ATTRIBUTE *pAttribute;
	/*
	 * 叶子节点不需要保存兄弟节点或者儿子节点
	 */
};

/*
 * 树 的普通节点
 */
struct TREENODE{
	struct TREEDATA *pData;
	struct TREEDATA *pNext;
	struct TREENODE *pSon;
};

struct TREE{
	int depth; // 深度
	struct TREENODE *pRoot;	// 用 ROOT 这种数据结构来指向 树 的根节点 , 这个数据结构还可以保存 树 的其他信息
	/*
	 * 可以类比于 链表 的 LINKEDLIST 这个数据结构中 保存了链表的长度
	 * 那么 这里也可以相似地保存 树 的一些基本信息
	 * 比如说深度
	 */
};

int main(int argc, char *argv[]){

	return 0;
}

void initTree(struct TREE *pTree){

}

void clearTree(struct TREE *pTree){

}
