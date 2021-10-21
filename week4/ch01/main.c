#include<stdio.h>
#include<malloc.h>
#include"HashQuad.h"
int main(void)
{
	HashTable hash_table;
	hash_table = InitializeTable(101);
	Insert(5, hash_table);
	Position pos = Find(5, hash_table);
	printf("%d", (hash_table->TheCells[pos].Element));
}
