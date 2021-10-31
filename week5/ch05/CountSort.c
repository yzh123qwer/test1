#include<stdio.h>

void CountSort(int A[], int N);
int* MakeCount(void);

int main(void)
{
	int abc[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("input:");
		scanf_s(" %d", &abc[i]);
	}
	CountSort(abc, 10);
	for (i = 0; i < 10; i++)
		printf("%d <", abc[i]);
}

void CountSort(int A[], int N)
{
	int* Count = MakeCount();
	int i, j;
	for (i = 0; i < N; i++)
	{
		if (A[i] <= 99 && A[i] >= 0)
			Count[A[i]]++;
		else
			printf("%d is not in Count!!!", A[i]);
	}
	for (i = 0, j = 0; i < 100; i++)
	{
		if (Count[i] != 0)
		{
			Count[i] -= 1;
			A[j++] = i--;
		}
	}
}

int* MakeCount(void)//假定输入的数字是0-99的整数
{
	int A[100] = {0};
	return A;
}
