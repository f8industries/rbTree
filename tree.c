#include "stdio.h"
#include "tree.h"

void insertNode(Node *root, Node *n)
{
    printf("insert: %p\n", (void *)n);
}

void removeNode(Node *n)
{
    printf("remove: %p\n", (void *)n);
}

void initializeTree(Node *root)
{
    printf("tree init \n");
}

void listTree(Node *root)
{
    printf("List : %p\n", (void *)root);
}

static void rotate(Node *n)
{
    printf("rotate: %p\n", (void *)n);
}

static void colorFlip(Node *n)
{
    printf("colorFlip: %p\n", (void *) n);
}

