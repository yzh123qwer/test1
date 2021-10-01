//学生成绩管理
#include<stdio.h>
#include<string.h>
void chj(int a[],int n);
void xh(char a[][11],int n);
int sum(int a[],int n);
void mismax(int a[],int n);
int min(int a[],int n);
int max(int a[],int n);
int main (void)
{
	int a[65];
	char b[65][11];
	printf("请输入学生人数。\n");
	int n;
	scanf("%d",&n);
	printf("请按照一定顺序输入成绩。\n");
	chj(a,n);
	printf("请按照相同顺序输入学号。\n");
	int i;
	char c=0;
	for(i=0;i>=0;i++)
	{
		scanf("%c",&c);
		if(c==10)
		break;	
	}
	xh(b,n);
	printf("学生成绩录入如下：\n");
	for (i=0;i<n;i++)
	{
		printf("成绩：%d	学号：",a[i]);
		puts(b[i]);
	}
	float pj;
	pj = (float)sum(a,n)/n;
	int pjs = 0;
	for (i=0;i<n;i++)
	{
		if(a[i]>=pj)
		{
			pjs = pjs+1;
		}
	}
	printf("平均成绩为%.2f。平均分以上的人数为%d。\n",pj,pjs);
	int gch1[65],gch2[65];
	for (i=0;i<n;i++)
	{
		gch1[i] = a[i];
	}
	for (i=0;i<n;i++)
	{
		gch2[i] = max(gch1,n);
		mismax(gch1,n);
	}
	for(i=0;i<n;i++)
	{
		printf("第%d名	%d\n",i+1,gch2[i]);
	}
	char hm[11];
	printf("输入学生学号获取对应成绩。\n");
	gets(hm);
	for(i=0;i<n;i++)
	{
		if(strcmp(hm,b[i])==0)
		{
			printf("该学生成绩为%d。\n",a[i]);
			break;
		}
	}
	return 0;
}
void chj(int a[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}
}
void xh(char a[][11],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		gets(a[i]);
	}
}
int sum(int a[],int n)
{
	int i;
	int ab = 0;
	for(i=0;i<n;i++)
	{
		ab = ab+a[i];
	}
	return ab;
}
int max(int a[],int n)
{
	int i = 0;
	int max = a[0];
	while(i<n-1)
	{
		if(max<a[i+1])
		{
			max = a[i+1];
			i = i+1;
			continue;
		}
		i = i+1;
	}
	return max;
}
int min(int a[],int n)
{
	int i = 0;
	int min = a[0];
	while(i<n-1)
	{
		if(min>a[i+1])
		{
			min = a[i+1];
			i = i+1;
			continue;
		}
		i = i+1;
	}
	return min;
}
void mismax(int a[],int n)
{
	int i = 0;
	int max1 = max(a,n);
	int min1 = min(a,n);
	while(i<n)
	{
		if(a[i]==max1)
		{
			a[i] = min1;
			break;
		}
		i = i+1;
	}
}
