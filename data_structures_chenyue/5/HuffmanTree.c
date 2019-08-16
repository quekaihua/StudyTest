
typedef int ElementType;

typedef struct TreeNode *HuffmanTree;
struct TreeNode {
	int Weight;
	HuffmanTree Left, Right;
};

typedef struct HeapStruct *MinHeap;
struct HeapStruct{
	ElementType *Elements;
	int Size;
	int Capacity;
};

HuffmanTree Huffman(MinHeap H)
{
	
}