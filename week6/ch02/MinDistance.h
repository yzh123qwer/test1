#ifndef MinDist_h
#define MinDist_h

#include<math.h>
#include<malloc.h>
#include<stdio.h>

struct Point
{
	double X;
	double Y;
};

double Dist(struct Point X1, struct Point X2);
static double Min(double a, double n);
double MinDist(struct Point Points[], int N);//假设输入N个不重复的点，并且已经被排序
void GetPoints(struct Point Points[], int N);//得到N个不重复的点，并将他们按照X坐标进行排序

double Dist(struct Point X1, struct Point X2)
{
	double a = (X1.X - X2.X) * (X1.X - X2.X);
	double b = (X1.Y - X2.Y) * (X1.Y - X2.Y);
	double c = sqrt(a + b);
	return c;
}

static double Min(double a, double b)
{
	if (a >= b)
		return b;
	else
		return a;
}

double MinDist(struct Point Points[], int N)
{
	if (N > 2)
	{
		double DisLeft = MinDist(Points, N / 2);
		double DisRight = MinDist(&Points[N / 2], N - N / 2);//输入的元素已经是被排序的，直接分开就一定会分成两边
		double Delta = Min(DisLeft, DisRight);
		double midX = 0.5 * (Points[N / 2].X + Points[N / 2 - 1].X);//分割线X坐标
		int i, j;
		int x_right, x_left;
		for (i = 0; i < N; i++)
			if (Points[i].X > midX - Delta)
			{
				x_right = i;
				break;
			}
		for(j = i; j < N; j++)
			if (Points[j].X > midX + Delta)
			{
				x_left = j;
				break;
			}
		for (i = x_right; i < x_left; i++)
			for (j = i + 1; j < x_left; j++)
				if (Dist(Points[i], Points[j]) < Delta)
					Delta = Dist(Points[i], Points[j]);//对双道带里面的元素进行逐一的计算
		return Delta;
	}
	else
	{
		if (N == 2)
			return Dist(Points[0], Points[1]);
		else//N=1，或N=0（可能出现）
			return 999999;//主要是为了防止，在迭代过程中，会产生1个点输入的情况，只要返回一个大于其他距离的值，就不会被误判
	}
}

void GetPoints(struct Point Points[], int N)
{
	int i, k;
	struct Point stack;
	for (i = 0; i < N; i++)
	{
		printf("input X:");
		scanf_s(" %lf", &Points[i].X);
		printf("input Y:");
		scanf_s(" %lf", &Points[i].Y);
		if (i > 0 && Points[i].X < Points[i - 1].X)
		{
			stack = Points[i];//类似插入排序的第二个for语句
			for (k = i; k > 0 && Points[k - 1].X > stack.X; k--)
				Points[k] = Points[k - 1];
			Points[k] = stack;
		}
	}
}

#endif
