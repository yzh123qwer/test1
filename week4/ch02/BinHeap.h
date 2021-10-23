#ifndef BinHeap_h
#define BinHeap_h

struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;

struct HeapStruct
{
	int Capacity;
	int Size;
	int* Elements;
};

PriorityQueue Initialize(int MaxElements);
void Insert(int X, PriorityQueue H);
int IsFull(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int DeleteMin(PriorityQueue H);

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	if (MaxElements < 10)//10ΪMinPQSize
		printf("Priority queue is too small!!!");
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	if (H == NULL)
		printf("Out Of Space!!!");
	H->Elements = (int*)malloc(sizeof(int) * (MaxElements + 1));
	if (H->Elements == NULL)
		printf("Out Of Space!!!");
	H->Size = 0;
	H->Elements[0] = 0;//0MinData，此时假设插入元素全为正数
	/*注：初始化定义的最小元素是不会被Insert函数中上滤过程改变
	* 在利用堆的有序性计算过程中“0”的位置是特殊的
	* 即：如果插入了一个比初始定义中，最小元素还小的元素，就破坏了堆的有序性
	*/
	return H;
}

void Insert(int X, PriorityQueue H)
{
	int i;
	if (IsFull(H))
	{
		printf("Priority queue is full!!!");
		return;//插入失败，结束函数的调用
	}
	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)//当两个int型相除时，结果是向下取整（舍去小数部分）
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = X;
}
/*每执行一次Insert函数，一定会执行一次for语句，则Size变量增加1，
* Size变量相当与一个计数变量，Size表示此时优先队列中除去初始定义的最小元素之外，一共包含多少变量（用户插入了多少变量）
*/

int IsFull(PriorityQueue H)
{
	if (H->Size == 11)//11是优先队列的最大容量，这里简单写为11，与main函数初始化相同
		return 1;
	else
		return 0;
}//0代表假，1代表真

int IsEmpty(PriorityQueue H)
{
	if (H->Size == 0)
		return 1;//优先队列是空的则返回真
	else
		return 0;
}

int DeleteMin(PriorityQueue H)//被删除的元素一定是堆位置“1”的元素
{
	int i, Child;
	int MinElement, LastElement;
	if (IsEmpty(H))
	{
		printf("Priority queue is empty!!!");
		return H->Elements[0];//如果优先队列是空的，则返回初始化时定义的最小元素
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];
	for (i = 1; i * 2 <= H->Size; i = Child)
	{
		Child = i * 2;//child是i的左儿子
		if (Child != H->Size && H->Elements[Child + 1] < H->Elements[i])
			Child++;
		/*如果i的左儿子不是最后一个元素，并且i的左儿子大于右儿子
		* 则选中右儿子
		* 为了将较小的一个儿子向上移动
		*/
		if (LastElement > H->Elements[Child])
			H->Elements[i] = H->Elements[Child];
		/*如果最后一个元素是大于该儿子的，那么将儿子向上移动
		* 否则该元素就是最后一个元素
		*/
		else
			break;
	}
	H->Elements[i] = LastElement;
	return MinElement;
}

#endif
