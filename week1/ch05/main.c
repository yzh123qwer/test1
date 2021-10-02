//这篇代码以模仿为主
#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int nValue;
	struct list *pNext;
}List;
List *CreateList()
{
	int num;
	int value;
	List *pHead = NULL;
	List *pTemp = NULL;
	List *pTail = NULL;
	printf("请输入节点个数\n");
	scanf("%d",&num);
	while(num!=0)
	{
		printf("请输入节点值\n");
		scanf("%d",&value);
		pTemp = (List*)malloc(sizeof(List));
		pTemp->nValue = value;
		pTemp->pNext = NULL;
		if(pHead == NULL)
		{
			pHead = pTemp;
		}
		else
		{
			pTail->pNext = pTemp;

		}
		pTail = pTemp;
		num--;
	}
	return pHead;
}
void PrintList(List *pHead)
{
	if(pHead)
	{
		printf("链表如下\n");
		while(pHead != NULL)
		{
			printf("%d\n",pHead->nValue);
			pHead = pHead->pNext;
		}
	}

}
int main()
{
	List *pHead = CreateList();
	PrintList(pHead);
	return 0;
}
