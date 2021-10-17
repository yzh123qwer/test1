#ifndef HashSep_h
#define HashSep_h

struct ListNode;
typedef struct ListNode *Position;
typedef Position List;
struct HashTal;
typedef struct HashTbl *HashTable;
typedef unsigned int Index;

struct ListNode
{
	char Key[10];//假设需要被散射的元素是字符串（且字符数在9个以内，包含9个）
	Position Next;
};
struct HashTbl
{
	int TableSize;
	List *TheLists;
};

HashTable InitializeTable(int TableSize);
int NextPrime(int a);
Position Find(const char* Key, HashTable H);
Index Hash(const char* Key, int TableSize);
void Insert(const char* Key, HashTable H);
void Copy(char str1[], const char *str2);

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	if (TableSize < 13)//这里应该写TableSize<MinTableSize，MinTableSize应该根据具体问题具体得出，13仅为参考
	{
		printf("Table size is too small!!");
		return NULL;
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
		printf("Out Of Space!!!");
	H->TableSize = NextPrime(TableSize);//当TableSize为素数的时候，能从一定程度避免散列冲突
	
	H->TheLists = (List *)malloc((sizeof(List)) * H->TableSize);
	if (H->TheLists == NULL)
		printf("Out of Space!!!");
	for (i = 0; i < H->TableSize; i++)
	{
		H->TheLists[i] = (Position)malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
			printf("Out of Space!!!");
		else
			H->TheLists[i]->Next = NULL;
	}
	return H;
}

int NextPrime(int a)//寻找大于等于a的一个素数，并返回
{
	if (a % 2 == 0)//a为偶数
		a = NextPrime(a + 1);
	else
	{
		int i;
		for (i = 3; i < a; i++)
		{
			if (a % i == 0)
			{
				a = NextPrime(a + 1);
				break;
			}
		}
	}
	return a;
}

Position Find(const char *Key, HashTable H)
{
	Position P;
	List L;
	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P != NULL && (strcmp(Key, P->Key) != 0))//strcmo函数能判断两个字符串是否相同，相同则返回0（部分功能）
		P = P->Next;
	return P;
}//如果没有找到散列元素返回的指针是空指针NULL

Index Hash(const char* Key, int TableSize)
{
	unsigned int HashVal = 0;
	while (*Key != '\0')
		HashVal = *Key++;
	return HashVal % TableSize;
}//这是以个简单的（不太好的）散列函数

void Insert(const char* Key, HashTable H)
{
	Position Pos, NewCell;
	List L;
	Pos = Find(Key, H);
	if (Pos == NULL)
	{
		NewCell = malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
			printf("Out Of Space!!!");
		else
		{
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Next = L->Next;
			Copy(NewCell->Key, Key);//Copy函数将第二个参数的字符串赋值给第一个字符串
			L->Next = NewCell;
		}
	}
}//注：结合Find函数Insert函数，两函数都默认了散列表中第一个链表节点是不包含散列元素（可以认为这是链表的表头）

void Copy(char str1[], const char *str2)
{
	int i;
	for (i = 0; ; i++)
	{
		str1[i] = str2[i];
		if (str2[i] == '\0')
			break;
	}
}

#endif
