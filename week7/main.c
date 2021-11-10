#include"List.h"
void main(void)
{
	List abc = (List)malloc(sizeof(struct Node));
	Position tmp1 = NULL;
	int i, tmp;
	for (i = 0; i < 5; i++)
	{
		printf("input:");
		scanf_s(" %d", &tmp);
		Insert(tmp, abc, abc);
	}
	for (i = 0, tmp1 = abc->Next; i < 5; i++)
	{
		printf("%d ", tmp1->Element);
		tmp1 = tmp1->Next;
	}
	Delete(1, abc);
}
