#include<stdio.h>
#include<malloc.h>

void MSort(int A[], int TmpArray[], int Left, int Right);
void Merge(int A[], int TamArray[], int Lpos, int Rpos, int RightEnd);
void Mergesort(int A[], int N);

int main(void)
{
	int abc[10], i;
	for (i = 0; i < 10; i++)
	{
		printf("input:");
		scanf_s(" %d", &abc[i]);
	}
	Mergesort(abc, 10);
	for (i = 0; i < 10; i++)
		printf("%d < ", abc[i]);
}

void MSort(int A[], int TmpArray, int Left, int Right)
{
	int Center;
	if (Left < Right)
	{
		Center = (Left + Right) / 2;
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center + 1, Right);
		/*这里的两个MSort语句已经包含了递归的基准型
		* 即当分裂到只有1个数或者0个数的时候，在判断if语句时，不会在继续执行MSort函数，就是基准型
		* 并且此时，在基准型的上一层中执行Merge函数一定是合并只有长度为1的数组
		*/
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}

void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;
	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if (A[Lpos] <= A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];
	}
	while (Lpos <= LeftEnd)
		TmpArray[TmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];
	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpArray[RightEnd];//注意考虑归并数组在原数组中间的情况
}

void Mergesort(int A[], int N)
{
	int* TmpArray;
	TmpArray = (int*)malloc(N * sizeof(int));
	if (TmpArray != NULL)
	{
		MSort(A, TmpArray, 0, N - 1);
		free(TmpArray);
	}
	else
		printf("Out Of Space!!!");//与大部分练习情况一样，运用malloc函数在大存储机器上通常不会出现空间不足（返回NULL）的情况
}
