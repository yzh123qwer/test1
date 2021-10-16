#include<stdio.h>
#include<string.h>
typedef unsigned int Index;
Index Hash_1(const char* Key, int TableSize);
Index Hash_2(const char* Key, int TableSize);
Index Hash_3(const char* Key, int TableSize);

Index Hash_1(const char* Key, int TableSize)
{
	unsigned int HashVal = 0;
	while (*Key != '\0')
		HashVal += *Key++;
	return HashVal % TableSize;
}
/*这是一个简单的散列函数，能够将输入的关键字（字符串）进行ascall码的求和，然后对TableSize进行求余
这样就能使得所用的关键词映射得到的散列值都在TableSize中，但是缺点为如果TableSize太大时，映射得到会相对集中分布在一个区域（假设关键字长度相差不大时）*/

Index Hash_2(const char* Key, int TableSize)
{
	return (Key[0] + 27 * Key[1] + 729 * Key[2]);
}
/*这依然是一个不太好的散列函数，它假设关键字最少有2个字符（此时第三个字符为‘\0’，它在ASCLL码中的值为0），
并且它只能够根据前三个字母来得出散列值的大小*/

Index Hash_3(const char* Key, int TableSize)
{
	unsigned int HashVal = 0;
	while (*Key != '\0')
		HashVal = HashVal * 32 + (*Key++);//乘以32相当于二进制移动5位
	return HashVal;
}
/*这是一个比较好的散列函数，它涉及关键词中的所有字符，并且分布的很好*/

int main(void)
{
	int TableSize = 10007;
	Index hello_1 = Hash_1("hello", TableSize);
	Index hello_2 = Hash_2("hello", TableSize);
	Index hello_3 = Hash_3("hello", TableSize);
	printf("Hashing_1 = %d\n", hello_1);
	printf("Hashing_2 = %d\n", hello_2);
	printf("Hashing_3 = %d\n", hello_3);
}
