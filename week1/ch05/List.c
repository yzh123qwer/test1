//这篇代码来自于CSDN，目的在于学习链表的编写过程（书上的有点看不懂）
#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int nValue;
	struct list *pNext;
}List;
/*申明一个全局的结构体变量，其中包含一个整型，和一个指向该结构体的指针变量
使得该全局变量在各个函数中都能使用
如链表中一个单元应该包含数据本身和指向下一个数据的地址*/
List *CreateList()
{
	int num;//num为链表中数据的个数
	int value;//数据本身，可多次利用
	List *pHead = NULL;
	/*定义表头，当输入num为0时，不执行while语句，表头为NULL常量，是一个空链表*/
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
/*这里的while语句目的在于数据录入，和数据之间地址录入
理解困难在于指向运算符“->”和mallco函数*/
	return pHead;
/*这里的返回值仅为表头的地址，其原因在于开始时申明的是全局变量，在while语句中，
链表中间各个数据的关系已经被建立，因此仅需返回一个表头地址，即可依次向后访问全
部数据*/
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
