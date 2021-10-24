#ifndef LeftHeap_h
#define LeftHeap_h

struct TreeNode;
typedef struct TreeNode* PriorityQueue;

struct TreeNode
{
	int Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int Npl;//Null Path Length零路径长
};

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);
static void SwapChildren(PriorityQueue H);
PriorityQueue Insert(int X, PriorityQueue H);
PriorityQueue DeleteMin(PriorityQueue H);
static PriorityQueue Find(int X, PriorityQueue H);
PriorityQueue Delete(int X, PriorityQueue H);

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
	if (H1 == NULL)
		return H2;
	if (H2 == NULL)
		return H1;
	/*上述两个情况是合并时最简单的情况，
	* 当其中一个是空左式堆，则直接返回另一个堆
	*/
	if (H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge1(H2, H1);
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
	if (H1->Left == NULL)
		H1->Left = H2;
	/*由于左式堆的定义
	* 左式堆没有左儿子（左儿子是空节点，它的npl是-1），那么一定没有右儿子
	*/
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
			SwapChildren(H1);
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

static void SwapChildren(PriorityQueue H)
{
	PriorityQueue A = H->Left;
	H->Left = H->Right;
	H->Right = A;
}

PriorityQueue Insert(int X, PriorityQueue H)
{
	PriorityQueue SingleNode;
	SingleNode = (PriorityQueue)malloc(sizeof(struct TreeNode));
	if (SingleNode == NULL)
		printf("Out Of Space!!!");
	else
	{
		SingleNode->Element = X;
		SingleNode->Npl = 0;
		SingleNode->Left = SingleNode->Right = NULL;
		H = Merge(SingleNode, H);
	}
	return H;
}

PriorityQueue DeleteMin(PriorityQueue H)
{
	PriorityQueue LeftHeap, RightHeap;
	if (H == NULL)
	{
		printf("Priority queue is empty!!!");
		return H;//如果此时的优先队列是空的，则告诉用户是空的，然后什么不用做
	}
	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}

static PriorityQueue Find(int X, PriorityQueue H)
{
	if (H == NULL)
	{
		printf("Priority queue is empty!!!");
		return H;
	}
	if (X == H->Element)//目标元素在根节点处
		return H;
	else
	{
		if (X < H->Element || H->Left == NULL)//利用左式堆如果没有左儿子，则一定没有右儿子
		{
			printf("Priority queue don't have the element");
			return H;//找不到则返回原指针
		}
		if (X >= H->Left->Element && (H->Right == NULL || H->Right->Element))
			return Find(X, H->Left);//X可能在左子树中
		else if (X < H->Left->Element && X >= H->Right->Element)
			return Find(X, H->Right);//X可能在右子树中
		else if (X > H->Left->Element && X > H->Right->Element)
		{
			PriorityQueue Left_, Right_;
			Left_ = Find(X, H->Left);
			Right_ = Find(X, H->Right);
			if (X == Left_->Element)
				return Left_;
			else
				return Right_;
		}//X可能在左子树或者右子树中，此时最为复杂，
	}
}

PriorityQueue Delete(int X, PriorityQueue H)
{
	PriorityQueue TheElement;
	TheElement = Find(X, H);//假定一定能找到，如果不能找到只需对Find函数返回的指针稍加判断即可
	TheElement = DeleteMin(TheElement);
	return H;//主要是考虑删除的目标元素就是根时
}

#endif
