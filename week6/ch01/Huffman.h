/*课本上使用优先队列的目的在于能够快速的选出，最少频率的字符，并且能将新产生二叉树快速插入到所对应的位置
* 但是是过于复杂的
* 这里采用插入排序的方式来完成（原因：字符数少），所需排序元素少
*/
#ifndef Huffman_h
#define Huffman_h
#include<stdio.h>
#include<malloc.h>

struct CharNode
{
	int Frequency;
	struct CharNode* Right;
	struct CharNode* Left;
	char Element;
};
typedef struct CharNode* Queue;
typedef struct CharNode* TreeNode;

Queue GetChars(Queue H, int MaxChars);
static void Sort(Queue H, int MaxChars);
TreeNode Merge(struct CharNode* A, struct CharNode* B);
TreeNode Huffman(Queue H, int MaxChars);
void PrintHuffman(TreeNode H);

Queue GetChars(Queue H, int MaxChars)
{
	H = (Queue)malloc(sizeof(struct CharNode) * MaxChars);
	if (H == NULL)
		printf("Out Of Space!!");
	int i, sum_frequency = 0;
	for (i = 0; i < MaxChars; i++)
	{
		printf("input char:");
		scanf_s(" %c", &H[i].Element);
		printf("input frequency:");
		scanf_s(" %d", &H[i].Frequency);
		H[i].Left = H[i].Right = NULL;
	}
	for (i = 0; i < MaxChars; i++)
		sum_frequency += H[i].Frequency;
	for (i = 1; ; )
	{
		if (MaxChars / (2 * i) != 0)
			i += 1;
		else
		{
			printf("Indicates that these chars require at least %d bits.(Before Huffman)\n", i);
			printf("Indicates that these sentences require at least %d bits.(Before Huffman)\n", sum_frequency * i);
			break;
		}
	}
	Sort(H, MaxChars);//将输入的字符按频率大小排列整齐，在后序操作只要不破坏其顺序即可
	return H;
}
static void Sort(Queue H, int MaxChars)//假定没有重复频率的字符
{
	int* insert_sort;
	insert_sort = (int*)malloc(sizeof(int) * MaxChars);
	int i, j, tmp, k;
	for (i = 0; i < MaxChars; i++)
		insert_sort[i] = H[i].Frequency;
	for (i = 1; i < MaxChars; i++)
	{
		tmp = insert_sort[i];
		for (j = i; j > 0 && insert_sort[j - 1] > tmp; j--)
			insert_sort[j] = insert_sort[j - 1];
		insert_sort[j] = tmp;
	}
	struct CharNode stack;
	stack.Left = stack.Right = NULL;
	for (i = 0; i < MaxChars; i++)
	{
		stack = H[i];
		for (j = 0; j < MaxChars; j++)
		{
			if (stack.Frequency == insert_sort[j])//这里对于CharNode节点的交换，过程是繁琐的，可优化的
			{
				H[i] = H[j];
				H[j] = stack;
				break;
			}
		}
	}
	return;
}

TreeNode Merge(struct CharNode* A, struct CharNode* B)
{
	TreeNode the_tree = (TreeNode)malloc(sizeof(struct CharNode));
	the_tree->Left = A;
	the_tree->Right = B;
	the_tree->Frequency = A->Frequency + B->Frequency;
	return the_tree;
}

TreeNode Huffman(Queue H, int MaxChars)
{
	TreeNode node = (TreeNode)malloc(sizeof(struct CharNode) * (MaxChars - 1));//Huffman算法产生MaxChars-1个节点
	struct CharNode stack;
	int i, j, k;
	for (i = 0; i < MaxChars - 1; i++)//共进行MaxChars-1次合并
	{
		node[i] = *Merge(&H[0], &H[1]);//总是将前两个节点合并
		for (j = 2; j < MaxChars - i; j++)
			H[j - 2] = H[j];//从第三个元素后，每个向前面推两个位置
		for (j = 0; j < MaxChars - i - 2; j++)//将合并后的节点放入其位置，并保持顺序性
		{
			if (node[i].Frequency <= H[j].Frequency)
			{
				for (k = MaxChars - i - 3; k >= j; k--)
					H[k + 1] = H[k];
				H[j] = node[i];
				break;
			}
			if (j == MaxChars - i - 1)
				H[j] = node[i];
		}
	}
	return &node[MaxChars - 2];
}

void PrintHuffman(TreeNode H)
{
	if (H->Right == NULL && H->Left == NULL)
		printf(" = %c\n", H->Element);
	else
	{
		printf("0");
		PrintHuffman(H->Left);
		printf("1");
		PrintHuffman(H->Right);
	}
}

#endif
