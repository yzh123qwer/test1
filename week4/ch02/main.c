#include<stdio.h>
#include<stdio.h>
#include"BinHeap.h"
int main(void)
{
	PriorityQueue priority_queue;
	priority_queue = Initialize(11);
	int i;
	for (i = 0; i < 12; i++)
		Insert(i * 2 + 1, priority_queue);//多插入了一次，在Insert函数考虑了元素已满的情况
	printf("\n");
	for (i = 1; i < 12; i++)
		printf("%d\n", priority_queue->Elements[i]);
	DeleteMin(priority_queue);
	printf("delete is completed!!\n");
	for (i = 1; i < 12; i++)
		printf("%d\n", priority_queue->Elements[i]);//delete函数中只是将堆的size-1，而不是将元素删除，所以还是可以访问得到原来的最后一个元素
	return 0;
}
