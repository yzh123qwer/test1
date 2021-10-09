#include<stdio.h>
#include"_max.h"
//包含一个自己编写的头文件，习惯上使用“""”
int main (void)
{
	int a,b;
	printf("please input a and b\neg:5and8.\n");
	scanf("%d and %d",&a,&b);
	int c = max(a,b);
	printf("max is %d",c);
	return 0;
}
