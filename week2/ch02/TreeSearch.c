#include<stdio.h>
#include<malloc.h>
#include"_Tree.h"
int main (void)
{
	struct TreeNode treenode[100];//定义100个还没有关联的节点
	SearchTree root = &treenode[0];
	int numbers,i;
	int tmp_element;
	printf("please input Element Numbers(<=100):");
	scanf("%d",&numbers);
	printf("\n");
	for (i=0;i<numbers;i++)
	{
		if(i = 0)//第一个元素需要进行初始化定义
		{
			MakeEmpty(treenode);
			printf("please input element:");
			scanf("%d",&treenode[0].Element);//默认节点数组中第0个是根
		}
		printf("please input element:");
		scanf("%d",&tmp_element);
		root = Insert(tmp_element,root);
	}
	return 0;
  //将数据录入以后即可对二叉查找树进行编辑了！
}
