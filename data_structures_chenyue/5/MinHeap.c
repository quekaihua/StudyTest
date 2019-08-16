#include <stdio.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct HeapStruct *MaxHeap;
struct HeapStruct{
	ElementType *Elements;
	int Size;
	int Capacity;
};

MaxHeap create(int MaxSize);
bool IsFull(MaxHeap H);
void Insert(MaxHeap H, ElementType item);
bool IsEmpty(MaxHeap H);
ElementType DeleteMax(MaxHeap H);
void FindPathRoot(MaxHeap H, int index);

int main()
{
	int N, group, index;
	ElementType element;
	MaxHeap heap = create(1000);
	scanf("%d %d", &N, &group);
	for (int i=0; i<N; i++) {
		scanf("%d", &element);
		Insert(heap, element);
	}
	for (int i=0; i<group; i++) {
		scanf("%d", &index);
		FindPathRoot(heap, index);
	}
	return 0;
}

MaxHeap create(int MaxSize)
{
	MaxHeap heap   = malloc(sizeof(struct HeapStruct));
	heap->Elements = malloc(sizeof(ElementType) * MaxSize);
	heap->Size     = 0;
	heap->Capacity = MaxSize;
	heap->Elements[0] = -10001;
	return heap;
}

bool IsFull(MaxHeap H)
{
	return H->Size == H->Capacity;
}

bool IsEmpty(MaxHeap H)
{
	return H->Size == 0;
}

void Insert(MaxHeap H, ElementType item)
{
	int i;
	if(IsFull(H))
		exit(1);
	i = ++H->Size;
	for(; H->Elements[i/2] > item; i/=2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = item;
}

void FindPathRoot(MaxHeap H, int index)
{
	if(index > H->Size)
		exit(1);
	for(int i=index; i>0; i/=2){
		if(i == 1) printf("%d\n", H->Elements[i]);
		else printf("%d ", H->Elements[i]);
	}
}