#ifndef HashQuad_h
#define HashQuad_h

typedef unsigned int Index;
typedef Index Position;
struct HashTbl;
typedef struct HashTbl* HashTable;
enum KindOfEntry {Legitimate,Empty,Dleted};//申明一个变量名称为KindOfEntry的枚举型变量
/*这里可以理解为定义3种状态，它们在计算机中存储为3个数字，emun函数赋值会默认从0开始，依次加1*/

struct HashEntry
{
	int Element;//该散列表的散列元素为整型数字（int）
	enum KindOfEntry Info;
};
struct HashTbl
{
	int TableSize;
	struct HashEntry* TheCells;
};

int NextPrime(int a);
int Hash(int a, int TableSize);
HashTable InitializeTable(int TableSize);
Position Find(int Key, HashTable H);
void Insert(int Key, HashTable H);

int NextPrime(int a)
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

int Hash(int a, int TableSize)//这是一个简单的散列函数（散列元素为int型）
{
	if (TableSize >= 10)
	{
		a = a * a;
		a = a % 10;
		return a;
	}
	else
	{
		a = a * a;
		a = a % TableSize;
		return a;
	}
}

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	if (TableSize < 100)//100为MinTableSize
	{
		printf("Table size is too small!");
		return NULL;
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
		printf("Out Of Space!!!");
	H->TableSize = NextPrime(TableSize);
	H->TheCells = (struct HashEntry*)malloc(sizeof(struct HashEntry) * H->TableSize);
	if (H == NULL)
		printf("Put Of Space!!!");
	for (i = 0; i < H->TableSize; i++)
		H->TheCells[i].Info = Empty;
	return H;
}

Position Find(int Key, HashTable H)
{
	Position CurrentPos;
	int CollisionNum;
	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
	{
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize)
			CurrentPos -= H->TableSize;
	}//这里需要一定数学上的证明，可以结合平方探测法来理解目的
	return CurrentPos;
}
/*
* Find函数将返回Key在散列表中的位置，如果Key不出现，那么Key将返回最后的单元。（该单元就是当需要时，Key将被插入的地方。）
* 这同样需要数学上的证明
*/

void Insert(int Key, HashTable H)
{
	Position Pos;
	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate)//如果Find返回的地址是已经有元素的，则已经插入，否则Find函数返回的地址就是该元素该被插入的地方
	{
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}
}

#endif
