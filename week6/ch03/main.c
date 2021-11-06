#include"DisjSet.h"
void main(void)
{
	DisjSet abc;
	Initilialize(abc);
	SetUnion(abc, 5, 6);
	SetUnion(abc, 7, 8);
	SetUnion(abc, 5, 7);
	int i;
	for (i = 1; i < 8 + 1; i++)
		printf("%d ", abc[i]);
	printf("\n8's root is %d", Find(8, abc));
}
