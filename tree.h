#include <stdbool.h>

typedef struct node
{
	struct Node *root, *left, *right;
	bool isRed;
	void *data;
}Node;

void insertNode(Node *root, Node *n);
void removeNode(Node *n);

void initializeTree(Node *root);

void listTree(Node *root);

