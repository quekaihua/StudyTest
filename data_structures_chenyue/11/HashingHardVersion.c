#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXSIZE 1000
int Table[MAXSIZE];
// int Table[11] = {33, 1, 13, 12, 34, 38, 27, 22, 32, -1, 21};
int Indegree[MAXSIZE] = {0};
int Graph[MAXSIZE][MAXSIZE];

typedef int ElementType;
typedef struct HeapStruct *MinHeap;
struct HeapStruct{
	ElementType *Elements;
	int Size;
	int Capacity;
};
typedef int Position, ElementType;
int N, M=0;

Position Find(ElementType Key, int TableSize);
void TopSort(int N);
void InitialGraph(int N);
void BuildGraph();
int compare ( const void *a , const void *b);
ElementType DeleteMin(MinHeap H);
void BuildMinHeap(MinHeap H);
void Insert(MinHeap H, ElementType node);
int IsEmpty(MinHeap H);
int HeapIsFull(MinHeap H);
MinHeap CreateHeap();

int main()
{
	scanf("%d", &N);
	N = 11;
	for(int i=0; i<N; i++){
		Table[i] = -1;
	}
	for (int i=0; i<N; i++) {
		scanf("%d", &Table[i]);
		if(Table[i] != -1) M++;
	}

	InitialGraph(N);
	BuildGraph(N);
	TopSort(N);

	return 0;
}

void BuildGraph(int N)
{
	for(int i=0; i<N; i++) {
		Position p = Table[i] % N;
		if ( Table[p] != Table[i] && Table[i] != -1) { //如果这个位置已被占有
			for (int j = p; j != i; j = ( j + 1 ) % N ) {
				Graph[j][i] = 1;
				Indegree[i]++; 	//位置j到i的元素都在i之前进入哈希表
			}
		}
	}
}

void TopSort(int N)
{
	int V;
	MinHeap H = CreateHeap();
	for (int i=0; i<N; i++)
		if(Table[i] != -1 && Indegree[i] == 0) {  //度为0的入队
			Insert(H, Table[i]);
		}
		BuildMinHeap(H);
		// for(int i=0; i<H->Size; i++) 
		// printf("Ele[%d]=%d ", i, H->Elements[i]);
		// printf("\n");
	int data;
	int cnt = 0;
	while( !IsEmpty(H) ) {
		data = DeleteMin(H);
		printf("%d", data);
		cnt++;
		if (cnt != M) printf(" ");
		int k;
		for(k=0; k<N; k++) {
			if (Table[k]==data) break;
		}
		for (int j=0; j<N; j++) {
			if(Graph[k][j] != 0) {
				if (--Indegree[j] == 0) {  //度为0的入队
					Insert(H, Table[j]);
					BuildMinHeap(H);
				}
			}
		}
	}
}

void InitialGraph(int N)
{
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++){
			Graph[i][j] = 0;
		}
}

int compare ( const void *a , const void *b)
{
	return *(int *)b - *(int *)a;
}

MinHeap CreateHeap()
{
	MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
	H->Size   = 0;
	H->Capacity = MAXSIZE;
	H->Elements = malloc(MAXSIZE * sizeof(int));
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
		for (int Child=i; 2*Child+1<H->Size; Child = Child) {
			LeftChild = 2 * i + 1;
			if(LeftChild < H->Size-1 && 
			H->Elements[LeftChild] > H->Elements[LeftChild+1])
				Child = ++LeftChild;
			else 
				Child = LeftChild;
			if(H->Elements[Child] < H->Elements[i]) {
				temp = H->Elements[i];
				H->Elements[i] = H->Elements[Child];
				H->Elements[Child] = temp;
			} else break;
		}
	}
}

ElementType DeleteMin(MinHeap H)
{
	int Parent, Child;
	ElementType MinItem, temp;
	if(IsEmpty(H)) {
		printf("MinHeap is empty.\n");
		return -1;
	}
	MinItem = H->Elements[0];
	temp = H->Elements[H->Size-1];
	for (Parent=0; Parent*2+1 < H->Size; Parent=Child) {
		Child = Parent * 2 + 1;
		if ((Child < H->Size-1) &&
			H->Elements[Child] > H->Elements[Child+1])
			Child++;
		if(temp < H->Elements[Child]) break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	H->Size--;
	return MinItem;
}



