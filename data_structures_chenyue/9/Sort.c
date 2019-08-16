#include <stdio.h>
#define ElementType int

void Bubble_Sort(ElementType A[], int N);
void Swap(ElementType *a, ElementType *b);

int main(){

	return 0;
}

void Bubble_Sort(ElementType A[], int N)
{
	int flag;
	for (int P = N-1; P>=0; P--) {
		flag = 0;
		for (int i=0; i<P; i++) {
			if (A[i] > A[i+1]) {
				Swap(A[i], A[i+1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

void Insertion_Sort(ElementType A[], int N)
{
	for (int P = 1; P<N; P++) {
		ElementType Tmp = A[P];
		int i;
		for (i=P; i>0 && A[i-1]>Tmp; i--)
			A[i] = A[i-1];
		A[i] = Tmp;
	}
}

void Shell_sort(ElementType A[], int N)
{
	int D, P, i;
	ElementType Tmp;
	for (D=N/2; D>0; D/=2) {
		for (P=D; P<N; P++) {
			Tmp = A[P];
			for (i=P; i>=D && A[i-D]>Tmp; i-=D)
				A[i] = A[i-D];
			A[i] = Tmp;
		}
	}
}

void Selection_Sort(ElementType A[], int N)
{
	int i, MinPosition;
	for(i=0; i<N; i++) {
		MinPosition = ScanForMin(A, i, N-1);
		Swap(A[i], A[MinPosition]);
	}
}

void Heap_Sort(ElementType A[], int N)
{
	BuildHeap(A);
	ElementType TmpA[N];
	for (int i=0; i<N; i++)
		TmpA[i] = DeleteMin(A);
	for (int i=0; i<N; i++)
		A[i] = TmpA[i];
}

void Swap(ElementType *a, ElementType *b)
{
	ElementType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int ScanForMin(ElementType A[], int start, int end)
{
	int min = start;
	for(int i=start+1; i<=end; i++)
		if(A[min] > A[i])
			min = i;
	return min;
}