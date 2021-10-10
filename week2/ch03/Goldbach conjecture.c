#include<stdio.h>
/*哥德巴赫猜想
任何一个大于6的偶数均可以表示为
两个奇素数之和*/ 
int ssh(int a);
int main (void)
{
	int a;
	scanf("%d",&a);
	if (ssh(a)==0)
	printf("%d不是素数。\n",a);
	else
	printf("%d是素数。\n",a);
	int x,y,i;
	scanf(" %d",&a);
	if(a<=6||a%2!=0)
	{
		printf("input error!\n");
	}
	else
	{
		x = a/2+1;
		y = a-x;
		for(i=0;i<(a/2);i++)
		{
			if(ssh(x)!=0&&ssh(y)!=0)
			break;
			x = x+1;
			y = a-x;
		}
		printf("%d=%d+%d",a,x,y);
	}
	return 0;
}
int ssh(int a)
{
	int i;
	for (i=1;i<a;i++)
	{
		if(i==1)
		{
			continue;
		}
		if(a%i==0)
		{
			return 0;
			break;
		}
	}
}
