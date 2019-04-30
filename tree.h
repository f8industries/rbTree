#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct node
{
    struct node *left, *right, *parent;
    bool isRed;
    //void *data;
    int key;
}Node;

void insertValue(Node **n, int val, Node *par);

void removeNodes(Node **n);

void fixViolations(Node **n, Node *par);

void listNodes(Node *root);

bool haveRedUncle(Node *n);

void colorFlip(Node **n);

void rotateRight(Node **n);

void rotateLeft(Node **n);

//void removeNode
//void findNode


#endif // TREE_H

