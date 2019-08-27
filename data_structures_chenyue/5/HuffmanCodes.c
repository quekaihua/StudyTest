#include <stdio.h>

typedef struct TreeNode* ElementType;
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

int main()
{
	int N, M;
	scanf("%d", &N);
	
}

HuffmanTree Huffman(MinHeap H)
{
	int i; HuffmanTree T;
	BuildMinHeap(H);
	for(i=1; i< H->Size; i++) {
		T = malloc(sizeof(struct TreeNode));
		T->Left = DeleteMin(H);
		T->Right = DeleteMin(H);
		T->Weight = T->Left->Weight + T->Right->Weight;
		Insert(H, T);
	}
	T = DeleteMin(H);
	return T;
}

ElementType DeleteMin(MinHeap H)
{
	int Parent, Child;
	ElementType MinItem, temp;
	if(IsEmpty(H)) {
		printf("MinHeap is empty.\n");
		return;
	}
	MinItem = H->Elements[1];
	temp = H->Elements[H->Size--];
	for (Parent=1; Parent*2<=H->Size; Parent=Child) {
		Child = Parent * 2;
		if ((Child != H->Size) &&
			H->Elements[Child]->Weight > H->Elements[Child+1]->Weight)
			Child++;
		if(temp <= H->Elements[Child]) break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MinItem;
}

