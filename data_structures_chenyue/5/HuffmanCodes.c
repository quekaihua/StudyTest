#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAXSIZE 65
// ElementType Codes[MAXSIZE];
int f[MAXSIZE];

typedef struct TreeNode *ElementType;
typedef struct TreeNode *HuffmanTree;
struct TreeNode {
	char code;
	int  Weight;
	HuffmanTree Left, Right;
};

typedef struct HeapStruct *MinHeap;
struct HeapStruct{
	ElementType *Elements;
	int Size;
	int Capacity;
};

ElementType CreateNode();
MinHeap CreateHeap();
int HeapIsFull(MinHeap H);
int IsEmpty(MinHeap H);
void Insert(MinHeap H, ElementType node);
ElementType DeleteMin(MinHeap H);
HuffmanTree Huffman(MinHeap H, int N);
int TreeWeight(HuffmanTree T, int depth);
int GetCodeLength(char code[][MAXSIZE], int N);
int BuildHuffman(char code[][MAXSIZE], int N);

int main()
{
	int N, M;
	scanf("%d ", &N);
	ElementType node;
	MinHeap H = CreateHeap();

	//输入code
	for(int i=0; i<N; i++) {
		node = CreateNode();
		scanf("%c %d ", &node->code, &node->Weight);
		f[i] = node->Weight;
		Insert(H, node);
	}

	// for(int i=0; i<H->Size; i++) {
	// 	printf("%c %d\n", H->Elements[i]->code, H->Elements[i]->Weight);
	// }

	HuffmanTree T = Huffman(H, N);
	int TotalWeight = TreeWeight(T, 0);

	scanf("%d ", &M);
	char c, code[MAXSIZE][MAXSIZE];
	int flag, length;
	//输入学生提交
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++) {
			scanf("%c %s ", &c, code[j]);
		}
		// for(int j=0; j<N; j++) {
		// 	printf("%c %s\n", c, code[j]);
		// }
		length = GetCodeLength(code, N);
		if(length != TotalWeight) {
			printf("No\n");
		} else {
			flag = BuildHuffman(code, N);
			flag == 1 ? printf("Yes\n") : printf("No\n");
		}
	}
}

int GetCodeLength(char code[][MAXSIZE], int N)
{
	int length = 0;
	for(int i=0; i<N; i++) {
		length += strlen(code[i]) * f[i];
	}
	return length;
}

int BuildHuffman(char code[][MAXSIZE], int N)
{
	HuffmanTree T, Current, temp;
	T = CreateNode();
	for(int i=0; i<N; i++) {
		Current = T;
		for(int j=0; code[i][j] != '\0'; j++) {
			if (code[i][j] == '0') {
				if(Current->Left == NULL) Current->Left = CreateNode();
				else {
					if(Current->Left->code == '1') return 0;
				}
				Current = Current->Left;
			} else if(code[i][j] == '1'){
				if(Current->Right == NULL) Current->Right = CreateNode();
				else {
					if(Current->Right->code == '1') return 0;
				}
				Current = Current->Right;
			}
		}
		Current->code = '1';
		if(Current->Left != NULL || Current->Right != NULL) return 0;
	}
	return 1;
}

ElementType CreateNode()
{
	ElementType node = (ElementType)malloc(sizeof(struct TreeNode));
	node->Left = node->Right = NULL;
	return node;
}

MinHeap CreateHeap()
{
	MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
	H->Size   = 0;
	H->Capacity = MAXSIZE;
	H->Elements = malloc(MAXSIZE * sizeof(struct TreeNode));
	return H;
}

int HeapIsFull(MinHeap H)
{
	return H->Size+1 == H->Capacity ? 1 : 0;
}

int IsEmpty(MinHeap H)
{
	return H->Size == 0 ? 1 : 0;
}

void Insert(MinHeap H, ElementType node)
{
	if (HeapIsFull(H)) return;
	H->Elements[H->Size++] = node;
}

void BuildMinHeap(MinHeap H)
{
	int parent, Child, LeftChild;
	ElementType temp;
	for (int i=H->Size/2-1; i>=0; i-- ) {
		// for(int i=0; i<H->Size; i++) {
		// 	printf("%c %d ", H->Elements[i]->code, H->Elements[i]->Weight);
		// }
		// printf("\n");
		for (int Child=i; 2*Child+1<H->Size; Child = Child) {
			LeftChild = 2 * i + 1;
			if(LeftChild < H->Size-1 && 
			H->Elements[LeftChild]->Weight > H->Elements[LeftChild+1]->Weight)
				Child = ++LeftChild;
			else 
				Child = LeftChild;
			if(H->Elements[Child]->Weight < H->Elements[i]->Weight) {
				temp = H->Elements[i];
				H->Elements[i] = H->Elements[Child];
				H->Elements[Child] = temp;
			} else break;
		}
		// for(int i=0; i<H->Size; i++) {
		// 	printf("%c %d ", H->Elements[i]->code, H->Elements[i]->Weight);
		// }
		// printf("\n");
		// printf("paixu yici\n");
	}
}

ElementType DeleteMin(MinHeap H)
{
	int Parent, Child;
	ElementType MinItem, temp;
	if(IsEmpty(H)) {
		printf("MinHeap is empty.\n");
		return NULL;
	}
	MinItem = H->Elements[0];
	temp = H->Elements[H->Size-1];
	for (Parent=0; Parent*2+1 < H->Size; Parent=Child) {
		Child = Parent * 2 + 1;
		if ((Child < H->Size-1) &&
			H->Elements[Child]->Weight > H->Elements[Child+1]->Weight)
			Child++;
		if(temp->Weight < H->Elements[Child]->Weight) break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	H->Size--;
	return MinItem;
}

HuffmanTree Huffman(MinHeap H, int N)
{
	BuildMinHeap(H);
	int i; HuffmanTree T;
	ElementType node;
	for(i=1; i<N; i++) {
		node = CreateNode();
		node->Left = DeleteMin(H);
		node->Right = DeleteMin(H);
		node->Weight = node->Left->Weight + node->Right->Weight;
		Insert(H, node);
		BuildMinHeap(H);
	}
	T = DeleteMin(H);
	return T;
}

int TreeWeight(HuffmanTree T, int depth)
{
	if	(T->Left == NULL && T->Right == NULL) {
		// printf("weight=%d code=%c depth=%d weight*depth=%d\n", T->Weight, T->code, depth, T->Weight*depth);
		return T->Weight * depth;
	}
	return (TreeWeight(T->Left, depth+1) + TreeWeight(T->Right, depth+1));
}


