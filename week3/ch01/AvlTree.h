#ifndef AvlTree_h
#define AvlTree_h

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
struct AvlNode
{
	int Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

AvlTree MakeEmpty(AvlTree T);
static int Height(Position P);
static int Max(int a, int b);//这里max函数仅能返回两个数中较大的数，只用于Insert函数中
AvlTree Insert(int X, AvlTree T);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);
void PrintTree(AvlTree T);

AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Right);
		MakeEmpty(T->Left);
		free(T);
	}
	return T;
}

static int Height(Position P)
//这里的static主要目的在于使Height函数只会在源文件中使用，服务于Insert函数和rotate
{
	if (P == NULL)
		return -1;//空指针为空节点的情况，习惯上将该节点的高度定义为-1
	else
		return P->Height;
}

static int Max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

AvlTree Insert(int X, AvlTree T)//直接输入Avl树的根节点的指针
{
	if (T == NULL)//根节点的指针为NULL时，此时树一个元素的没有
	{
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		if (T == NULL)
		{
			printf("OUT OF SPACE!!!");
		}
		else
		{
			T->Element = X;
			T->Height = 0;
			T->Right = T->Left = NULL;
		}
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}
	/*else X is in the tree alerdy;we'll do nothing*/
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	
	//在最底层的树叶的高度是零，这些树叶的左指针和右指针指向的空节点高度被定义为-1，
	/*插一个新的元素（该元素是导致某个节点不平衡的元素），由于函数的迭代使用，会在被判断出该节点不平衡之前，就使得节点的子树高度改变
	因此注意旋转函数中深度的定义*/
	return T;
}

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	K1 = K2->Left;//使得K1为K2（不平衡节点）的左儿子
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	return K1;/*new node*/
}

static Position SingleRotateWithRight(Position K2)
{
	Position K1;
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	return K1;
}//该情况与左边单次旋转应该是对称的（可以归类为一种），但是在设计程序中依然编辑两种方式

static Position DoubleRotateWithLeft(Position K3)
/*将K3定义为不平衡节点，该情况为双旋转的第一种，在K3的左儿子的右子树插入导致K3不平衡
将K3的左儿子定义为K1，左儿子的右子树的根节点定义为K2，
则只需首先对K1进行一次右单旋转，然后对K3进行一次左单旋转*/
{
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);
}

void PrintTree(AvlTree T)
{
	if (T != NULL)
	{
		PrintTree(T->Left);
		printf("%d\n", T->Element);
		PrintTree(T->Right);
	}
}
//输出元素一定是从小到大输出

#endif
