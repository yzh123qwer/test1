#include<stdio.h>
int Fib(int N);//最简单的方式，但是是低效的
int Fibonacci(int N);//线性算法
//注意这里的斐波那契数列从第0项开始，即第0项和第1项是1

void main(void)
{
	printf("Fib(10) = %d\n", Fib(10));
	printf("Fibonacci(10) = %d", Fibonacci(10));
	return;
}

int Fib(int N)
{
	if (N <= 1)
		return 1;
	else
		return Fib(N - 1) + Fib(N - 2);
}

int Fibonacci(int N)
{
	if (N <= 1)
		return 1;
	int i, Last, NextToLast, Answer;
	Last = NextToLast = 1;
	for (i = 2; i <= N; i++)
	{
		Answer = Last + NextToLast;
		NextToLast = Last;
		Last = Answer;
	}
	return Answer;
}
