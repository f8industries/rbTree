// 1.)Perform standard BST insertion and make the color of newly inserted nodes as RED.
// 2.)If x is root, change color of x as BLACK (Black height of complete tree increases by 1).
// 3.)Black uncle -> rotate
// 4.)Red uncle -> colorflip

#include "stdio.h"
#include <stdlib.h>
#include "tree.h"

void insertValue(Node **n, int val, Node *par)
{
    Node *temp;
    if(NULL== *n)// node is empty
    {
        temp = (Node *)malloc(sizeof(Node));

        temp->left = NULL;
        temp->right = NULL;
        temp->key = val;
        temp->isRed = true;
        temp->parent = par;

        if(temp){
            printf("Created obj : %p with value = %d\n", (void *)temp, val);
        }else {
            printf(("Node isnt created"));
        }

        *n = temp;

    }else {
        if(val >= (*n)->key)// equals to the right
        {
            printf("insert %d on the right of %d\n\n", val, (*n)->key);
            insertValue(&(*n)->right, val, *n);
        }else {
            printf("insert %d on the left of %d\n", val, (*n)->key);
            insertValue(&(*n)->left, val, *n);
        };
    };

    fixViolations(n, par);

}

void listNodes(Node *root)
{
    if(NULL == root){
        printf("List is empty\n");
        return;
    }

    if(NULL != root->left)
        listNodes(root->left);

    printf("%s node: %d addr:%p with parent %p\n", root->isRed ? "Red  " : "Black", root->key, (void*)root, (void*)root->parent);

    if(NULL != root->right)
        listNodes(root->right);
}

void removeNodes(Node **n)
{
    if(NULL == (*n)){
        printf("List is empty\n");
        return;
    }
    if(NULL != (*n)->left)
        removeNodes(&(*n)->left);

    if(NULL != (*n)->right)
        removeNodes(&(*n)->right);

    printf("removing: %p\n", (void *)(*n));
    free(*n);
    (*n) = NULL;
}

void colorFlip(Node **n)
{
    printf("colorFlip: %d\n", (*n)->key);
    (*n)->parent->parent->isRed = true;
    (*n)->parent->parent->left->isRed = false;
    (*n)->parent->parent->right->isRed = false;
}


bool haveRedUncle(Node *n)
{
    Node *grandpa = n->parent->parent;
    Node *uncle = NULL;
    if(n->parent == grandpa->right){// uncle is on left
        uncle = grandpa->left;}
    else{                              // uncle is on right
        uncle = grandpa->right;
    }
    if(NULL != uncle)
    {
        return uncle->isRed;
    };
    return false; // uncle is black or NULL;
}

void fixViolations(Node **n, Node *par)
{
    if(NULL == par)// If x is root, change color of x as BLACK
    {
        printf("Make root black again\n");
        (*n)->isRed = false;
    }

    if((*n)->parent && (*n)->parent->parent && (*n)->isRed && (*n)->parent->isRed) // got parent && got grandpa && itself is red & parent is red
    {
        printf("have 2 consecutive red nodes\n");
        if(haveRedUncle(*n))
        {
            printf("node have red uncle\n");// 4.)Red uncle -> colorflip
            colorFlip(n);
        }else {
            printf("node %d have black uncle\n", (*n)->key);// 3.)Black uncle -> rotate
            if((*n) == par->left && (*n)->parent->parent->right == par)
            {
                printf("node is left child, parent is right child\n");
                rotateRight(&(*n)->parent);
            };
//            if((*n) == par->right && (*n)->parent->parent->left == par)
//            {
//                printf("node is right child, parent is left child\n");
//                rotateLeft(n);
//            };
//            if((*n) == par->right)
//            {
//                printf("node is right child\n");
//                rotateLeft(n);
//            }else {
//                printf("node is left child\n");
//                rotateRight(n);
//            }
        }
    };
}

void rotateRight(Node **n)//from Maybes
{
    Node *p = (*n)->parent;
    Node *nl = (*n)->left;//c
    //Node *nr = (*n)->right;

    if(nl->right != NULL)
    {
        printf("repin right child of left parent upper");
        nl->right->parent = (*n);
    };

    (*n)->left = nl->right;//
    (*n)->parent = nl;
    nl->right = (*n);
    nl->parent = p;

    if(NULL !=p) // pin parent to grandchild
    {
        if(p->right == (*n))
            p->right = nl;
        else
            p->left = nl;
    }
    printf("rotation right around %d\n", (*n)->key);
}

void rotateLeft(Node **n)
{

}

