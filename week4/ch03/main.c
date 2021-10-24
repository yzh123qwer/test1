#include<stdio.h>
#include<malloc.h>
#include"LeftHeap.h"
int main(void)
{
	PriorityQueue heap1, heap2, heap3;
	heap1 = heap2 = heap3 = NULL;
	heap1 = Insert(10, heap1);
	heap1 = Insert(21, heap1);
	heap2 = Insert(14, heap2);
	heap2 = Insert(23, heap2);
	heap1 = Merge(heap1, heap2);
	heap1 = Insert(3, heap1);
	heap3 = Insert(26, heap3);
	heap3 = Insert(17, heap3);
	heap3 = Insert(8, heap3);
	heap1 = Merge(heap1, heap3);
	/*目的在于构建一个特别的左式堆（课本P153页-6-21(左))
	* 只有通过多个左式堆合并，
	*/
	printf("%d", Find(14, heap1)->Element);
}
