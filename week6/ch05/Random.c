#include<stdio.h>

static unsigned long Seed = 99;
#define A 48271L
#define M 2147483647L

unsigned long Random(void);//产生长整型的随机数
unsigned long Random2(int a, int b);//产生a到b(a<b)范围里面的随机数
//这两个随机函数都依赖于初始值的输入
void Initialize(unsigned long InitVal);

void main(void)
{
	int initialize_val;
	printf("input Initialize Val:");
	scanf_s("%ld", &initialize_val);
	Initialize(initialize_val);
	int i;
	for (i = 1; i <= 10; i++)
		printf("Random_%d = %ld\n", i, Random());
	printf("1 to 100:\n");
	for (i = 1; i <= 10; i++)
		printf("Random_%d = %ld\n", i, Random2(1, 100));
	return;
}

unsigned long  Random(void)
{
	Seed = (A * Seed) % M;
	return Seed;
}

unsigned long Random2(int a, int b)
{
	if (a >= b)
	{
		printf("Error!!!");
		return 0;
	}
	Seed = Random();
	return (Seed % (b - a)) + a;
}

void Initialize(unsigned long InitVal)
{
	Seed = InitVal;
}
