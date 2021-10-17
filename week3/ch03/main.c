#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"HashSep.h"
int main(void)
{
	HashTable hash_table = InitializeTable(100);//初始化一个散列表
	Insert("hello", hash_table);
	Insert("abandon", hash_table);
	Insert("you", hash_table);
	Position pos = Find("hello", hash_table);
	printf("%s", pos->Key);
}
