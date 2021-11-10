#ifndef List_h
#define List_h
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node* PtrNode;
typedef PtrNode List;
typedef PtrNode Position;
struct Node
{
	int Element;
	Position Next;
};

int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X, List L);
Position FindPrevious(int X, List L);
void Delete(int X, List L);
void Insert(int X, List L, Position P);
void DeleteList(List L);

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find(int X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;//如果没有找到放回的P是NULL
	return P;
}

Position FindPrevious(int X, List L)
/*如果存在X则返回X的前驱元
* 否则返回最后一个链表
*/
{
	Position P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}

void Delete(int X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X, L);//如果存在X，则P是X的前驱元
	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void Insert(int X, List L, Position P)
{
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("Out Of Space!!");
	if (P != NULL)
	{
		TmpCell->Element = X;
		TmpCell->Next = P->Next;
		P->Next = TmpCell;
	}
}

void DeleteList(List L)
{
	Position P, Tmp;
	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}

#endif
