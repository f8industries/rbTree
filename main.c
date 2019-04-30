#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "tree.h"

int main()
{
    Node *tree = NULL;
    char inputC = 0;
    int n = 0;

    while(inputC!= 'q')
    {
    printf("\n\nChoose an option: node(a)dd, (r)emove tree, (l)istOfNodes or (q)uit \n");
    scanf(" %c", &inputC);
    switch(inputC)
    {
    case 'a':
        printf("Adding. Enter value\n");
        scanf("%d",&n); getchar(); fflush(stdin);
        insertValue(&tree, n, NULL);
        break;

    case 'r':
        printf("Remove all\n");
        removeNodes(&tree);
        break;

    case 'l':
        printf("listing\n");
        listNodes(tree);
        break;

    default:
        printf("choose another");
    }
    }
  return 0;
}

