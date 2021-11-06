#ifndef DisjSet_h
#define DisjSet_h

#include<stdio.h>

typedef int DisjSet[8 + 1];//8是NumSets
typedef int SetType;
typedef int ElementType;

void Initilialize(DisjSet S);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElementType X, DisjSet S);

void Initilialize(DisjSet S)//默认不使用第0个位置
{
	int i;
	for (i = 8; i > 0; i--)
		S[i] = 0;
}

void SetUnion(DisjSet S, SetType Root1, SetType Root2)//比较简单的，不太好的。
{
	S[Root2] = Root1;
	/*这里没有根据Find函数的结果来判断是否执行Union
	* 如果Root1和Root2的值相同（具有同样的父亲节点），则Union不会进行任何操作
	* 即Find(Root1)和Find(Root2)返回两个相同的值
	* 如果Root1和Root2的值不相同，Union会将Root1的值（Root1的父亲）赋值给Root2
	*/
}

SetType Find(ElementType X, DisjSet S)
{
	if (X[S] <= 0)
		return X;
	else
		return Find(S[X], S);
}

#endif
