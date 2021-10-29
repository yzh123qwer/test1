#include<stdio.h>
#include<malloc.h>
#define LeftChild(i) (2 * (i) + 1)//注意，这里的堆从位置0开始，所以左儿子是2i+1

void PercDown(int A[], int i, int N);
void HeapSort(int A[], int N);
void Swap(int* a, int* b);

int main(void)
{
	int abc[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("input:");
		scanf_s(" %d", &abc[i]);
	}
	for (i = 0; i < 10; i++)
		printf("%d ", abc[i]);
	printf("\n");
	HeapSort(abc, 10);
	for (i = 0; i < 10; i++)
		printf("%d ", abc[i]);
}

void PercDown(int A[], int i, int N)
{
	int child, tmp;
	for (tmp = A[i]; LeftChild(i) < N; i = child)
	{
		child = LeftChild(i);
		if (child < N - 1 && A[child] < A[child + 1])//如果存在右儿子，并且右儿子大于左儿子
			child++;
		if (tmp < A[child])
			A[i] = A[child];
		else
			break;
	}
	A[i] = tmp;
}

void HeapSort(int A[], int N)
{
	int i, tmp, j;
	for (i = N / 2; i >= 0; i--)
		PercDown(A, i, N);
	for (i = N - 1; i > 0; i--)
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}

void Swap(int* a, int* b)
{
	//int* tmp = (int*)malloc(sizeof(int));
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
