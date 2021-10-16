#include<stdio.h>
#include<malloc.h>
#include"_Tree.h"
void print_tree(SearchTree T);

int main (void)
{
	SearchTree root = NULL;
	int numbers,i,stack;
	printf("please input Element Numbers:");
	scanf_s("%d",&numbers);
	printf("\n");
	for(i = 0;i < numbers;i++)
	{
		printf("please input Element:");
		scanf_s("%d",&stack);
		root = Insert(stack,root);
	}
	printf("tree elements:");
	print_tree(root);
	return 0;
}

void print_tree(SearchTree T)
{
	if(T == NULL)
		printf("");
	if(T != NULL)
	{
		printf("%d\n",T->Element);
		print_tree(T->Left);
		print_tree(T->Right);
	}
}
//打印出二叉查找树中所有的元素，优先打印左边
