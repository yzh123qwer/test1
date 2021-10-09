#ifndef _max_h
#define _max_h
/*如果没有编译_max.h则进行编译_max.h*/
int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
//头文件中包含一个简单的比较大小的函数
#endif
