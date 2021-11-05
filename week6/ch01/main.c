#include"Huffman.h"
void main(void)
{
	Queue chars = NULL;
	chars = GetChars(chars, 5);
	chars = Huffman(chars, 5);
	printf("After Huffman:\n");
	PrintHuffman(chars);
	return;
}
