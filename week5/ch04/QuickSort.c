#include<stdio.h>

#define Cutoff (3)//这里的常量同时规定了快速排序进行分割的最少元素，但它少于最少元素时，对该数组进行插入排序
void Quicksort(int A[], int N);
void Swap(int* A, int* B);
int Median3(int A[], int Left, int Right);
void Qsort(int A[], int Left, int Right);
void InsertionSort(int Element[], int N);

int main(void)
{
	int abc[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("input:");
		scanf_s(" %d", &abc[i]);
	}
	Quicksort(abc, 10);
	for (i = 0; i < 10; i++)
		printf("%d <", abc[i]);
}

void Quicksort(int A[], int N)
{
	Qsort(A, 0, N - 1);
}

void Swap(int* A, int* B)
{
	int tmp = *A;
	*A = *B;
	*B = tmp;
}

int Median3(int A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);//将其中较小的一个放在A[Left]，则此时A[Left]是前面两个较小的一个
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);//此时A[Left]是三个中最小的一个
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);//此时三个数按大小排列
	Swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}

void Qsort(int A[], int Left, int Right)
{
	int i, j, Pivot;
	if (Left + Cutoff <= Right)//同样包含对基准型的判断
	{
		Pivot = Median3(A, Left, Right);
		i = Left;
		j = Right - 1;
		for (; ; )
		{
			while (A[++i] < Pivot) {}
			while (A[--j] > Pivot) {}
			if (i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		Swap(&A[i], &A[Right - 1]);
		//此时A[i]的位置的元素，已经将左边和右边的元素进行分割（左边的元素<A[i]<右边的元素），不需要对A[i]在进行排序
		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else
		InsertionSort(A + Left, Right - Left + 1);
}

void InsertionSort(int Element[], int N)
{
	int j, p, i;
	int tmp;
	for (p = 1; p < N; p++)
	{
		tmp = Element[p];
		for (j = p; j > 0 && Element[j - 1] > tmp; j--)
			Element[j] = Element[j - 1];
		Element[j] = tmp;
	}
}
