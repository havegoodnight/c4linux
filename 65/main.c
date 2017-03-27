#include <stdio.h>
#include <stdlib.h>

struct NODE{
	int i;
	char j;
	double k;
	double l;
	void *p;
};

int main(int argc, char *argv[]){
	struct NODE * node;
	node = malloc(sizeof(struct NODE));
	printf("[node] -> [%p]\n", &node);
	printf("[*node] -> [%p]\n", node);
	printf("[node.i] (int) -> [%p]\n", &(node->i));
	printf("[node.j] (char) -> [%p]\n", &(node->j));
	printf("[node.k] (double) -> [%p]\n", &(node->k));
	printf("[node.l] (double) -> [%p]\n", &(node->l));
	printf("[node.p] (void *) -> [%p]\n", &(node->p));

	return 0;
}
