#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "tree.h"

int main()
{
    Node *tree;
    char inputC = 0;
    while(inputC!= 'q')
    {	
	printf("\n\nChoose an option: node(a)dd, (r)emove, dump(l)istOfNodes or (q)uit \n"); 
	scanf(" %c", &inputC);
	switch(inputC)
	{
	    case 'a':
		printf("adding\n");
		break;

	    case 'r':
		printf("removing\n");
		break;
	
	    case 'l':
		printf("listing\n");
		break;
	    default:
		printf("choose another");
	}
    }
  return 0;
}
