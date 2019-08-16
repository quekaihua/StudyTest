#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

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

#endif