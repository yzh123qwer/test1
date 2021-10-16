#include<stdio.h>
#include<malloc.h>
#include"AvlTree.h"

int main(void)
{
	AvlTree root = NULL;
	int numbers,i,stack;
	printf("please input numbers of AvlTree:");
	scanf_s(" %d", &numbers);
	for (i = 0; i < numbers; i++)
	{
		printf("\nplease input element:");
		scanf_s(" %d", &stack);
		root = Insert(stack, root);
	}
	PrintTree(root);
}                           
