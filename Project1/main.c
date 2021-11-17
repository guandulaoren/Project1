#include <stdio.h>
#include <stdlib.h>

#define NODE_COUNT 15
#define MAX_SIZE 20

typedef struct Node {
	int data;
	struct Node* lChild, * rChild;
} Node;

Node* create() {
	int data[] = { -1,1,2,3,0,5,10,0,0,0,9,0,14,7,0,0 };
	//int data[] = { -1,1,2,3,4,5,6,7 };
	Node* nodes[NODE_COUNT + 1];

	for (int i = 1; i <= NODE_COUNT; i++) {
		Node* node = (Node*)malloc(sizeof(Node));
		(*node).data = data[i];
		(*node).lChild = NULL;
		(*node).rChild = NULL;
		nodes[i] = node;
	}

	for (int i = 1; i <= NODE_COUNT; i++) {
		int lChildNo = 2 * i;
		int rChildNo = lChildNo + 1;
		if (!(lChildNo > NODE_COUNT)) {
			if ((*nodes[lChildNo]).data != 0) {
				(*nodes[i]).lChild = nodes[lChildNo];
			}
		}
		if (!(rChildNo > NODE_COUNT)) {
			if ((*nodes[rChildNo]).data != 0) {
				(*nodes[i]).rChild = nodes[rChildNo];
			}
		}
	}

	return nodes[1];
}

void firstFind(Node* tree) {
	int stack[MAX_SIZE];
	int top = -1;
	stack[++top] = tree;
	while (top != -1) {
		Node* p = stack[top--];
		if ((*p).rChild != NULL) {
			stack[++top] = (*p).rChild;
		}
		if ((*p).lChild != NULL) {
			stack[++top] = (*p).lChild;
		}
		printf("%d\n", (*p).data);
	}
}

void middleFind(Node* tree) {
	int stack[MAX_SIZE];
	int top = -1;
	Node* p = tree;
	while (top != -1 || p != NULL) {
		while (p != NULL) {
			stack[++top] = p;
			p = (*p).lChild;
		}
		if (top != -1) {
			Node* node = stack[top--];
			printf("%d\n", (*node).data);
			p = (*node).rChild;
		}
	}
}

void lastFind(Node* tree) {
	int stack[MAX_SIZE];
	int top = -1;
	// 当前要遍历的树
	Node* p = tree;
	// 上一个已遍历过的树
	Node* prep = NULL;
	while (top != -1 || p != NULL) {
		while (p != NULL) {
			stack[++top] = p;
			p = (*p).lChild;
		}
		if (top != -1) {
			Node* node = stack[top];
			Node* rp = (*node).rChild;
			if (rp == NULL || rp == prep) {
				Node* node = stack[top--];
				printf("%d\n", (*node).data);
				prep = node;
			} else {
				p = rp;
			}
		}
	}
}

void middleFind2(Node* tree) {
	int stack[MAX_SIZE];
	int top = -1;
	stack[++top] = tree;
	Node* p = (*tree).lChild;
	while (top != -1) {
		if (p != NULL) {
			stack[++top] = p;
			p = (*p).lChild;
		} else {
			Node* node = stack[top--];
			printf("%d\n", (*node).data);
			Node* rp = (*node).rChild;
			if (rp != NULL) {
				stack[++top] = rp;
				p = (*rp).lChild;
			}
		}
	}
}

void lastFind2(Node* tree) {
	int stack[MAX_SIZE];
	int top = -1;
	stack[++top] = tree;
	// 当前要遍历的树
	Node* p = (*tree).lChild;
	// 上一个已遍历过的树
	Node* prep = NULL;
	while (top != -1) {
		if (p != NULL) {
			stack[++top] = p;
			p = (*p).lChild;
		} else {
			Node* node = stack[top];
			Node* rp = (*node).rChild;
			if (rp == NULL || rp == prep) {
				Node* node = stack[top--];
				printf("%d\n", (*node).data);
				prep = node;
			} else {
				stack[++top] = rp;
				p = (*rp).lChild;
			}
		}
	}
}

int main() {
	Node* tree = create();
	//firstFind(tree);
	middleFind2(tree);
	//lastFind2(tree);
	return 0;
}
