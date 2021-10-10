#ifndef _Tree_H
#define _Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
struct TreeNode
{
	int Element;
	SearchTree Right;
	SearchTree Left;
};

SearchTree MakeEmpty(SearchTree T);
Position Find(int x,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X,SearchTree T);
SearchTree Delete(int x,SearchTree T);

SearchTree MakeEmpty(SearchTree T)
{
	if(T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);//free函数在malloc.h库下
	}
	return NULL;
}

Position Find(int X,SearchTree T)
{
	if(T == NULL)
		return NULL;
	if(X < T->Element)
		return Find(X,T->Left);
	else
	{
		if(X > T->Element)
			return Find(X,T->Right);
		else
			return T;
	}
}

Position FindMin(SearchTree T)
{
	if(T == NULL)
		return NULL;
	else
	{
		if(T->Left == NULL)
			return T;
		else
			return FindMin(T->Left);
	}
}

Position FindMax(SearchTree T)
{
	if(T != NULL)
	{	while (T->Right !=NULL)
			T = T->Right;
	}
	return T;
}

SearchTree Insert(int X,SearchTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct TreeNode));
		if(T == NULL)
			printf("Out of space!!!");
		else
		{
			T->Element = X;
			T->Right = NULL;
			T->Left = NULL;
		}
	}
	else if(X < T->Element)
		T->Left = Insert(X,T->Left);
	else if(X > T->Element)
		T->Right = Insert(X,T->Right);
	/*else X is in the tree,we'll do nothing!*/
	return T;
}

SearchTree Delete(int X,SearchTree T)
{
	Position TmpCell;
	
	if(T == NULL)
		printf("Error:Element is not found!!");
	else if(X < T->Element)
		T->Left = Delete(X,T->Left);
	else if(X > T->Element)
		T->Right = Delete(X,T->Left);
	else if(T->Left && T->Right)//X与跟中元素相同的情况下，判断条件非0/NULL即真
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element,T->Right);//该语句为了删除右边最小元素
	}
	/*当所需删除的元素就是二叉查找树的根时，需要将元素删去，并找到一个元素的位置来代替这个根
	由于查找树是对数据排列有要求的，即当元素全为数字时（目的在于可以简单的用判断大小来进行排
	序），大小越靠中间的元素应该越在二叉树的上方，此时删去一个元素，顶替的元素必定是右边的最
	小元素（它是被删除元素的右边，所以大于全部的被删除元素的左边，而它又是右边的最小元素），
	但是语句仅仅将该值顶替了被删除元素，但是右边的最小元素还存在二叉树中，
	*/
	else
	{
		TmpCell = T;
		if(T->Left == NULL)
			T = T->Right;
		else if(T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}
#endif
