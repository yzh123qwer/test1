#include<stdio.h>
void InsertSort(int Element[], int N);
void ShellSort(int Element[], int N);

int main(void)
{
	int abc[13];
	int i,h;
	for (i = 0; i < 13; i++)
	{
		printf("input:");
		scanf_s(" %d", &abc[i]);
	}
	ShellSort(abc, 13);
	for (i = 0; i < 13; i++)
		printf("%d< ", abc[i]);
}

void InsertSort(int Element[], int N)
{
	int j, p,i;
	int tmp;
	for (p = 1; p < N; p++)
	{
		tmp = Element[p];
		for (j = p; j > 0 && Element[j - 1] > tmp; j--)
			Element[j] = Element[j - 1];
		Element[j] = tmp;
	}
}

void ShellSort(int Element[], int N)
{
	int i, j, increment, tmp;
	for (increment = N / 2; increment != 0; increment /= 2)
	{
		for (i = increment; i < N; i++)
		{
			tmp = Element[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (tmp < Element[j - increment])
					Element[j] = Element[j - increment];
				else
					break;
			}
			Element[j] = tmp;
		}
	}
}
