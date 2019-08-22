#include <stdio.h>
#define ElementType int
#define MAXSIZE 100

// int Check[MAXSIZE] ={6,4,5,1,0,3,2,7,8,9};
// int data1[MAXSIZE] = {3,1,2,8,7,5,9,4,6,0}, data2[MAXSIZE]={3,1,2,8,7,5,9,4,6,0};
int Check[MAXSIZE], data1[MAXSIZE], data2[MAXSIZE];
int Insertion_Sort(ElementType A[], int N, ElementType Check[]);
void Heap_Sort(ElementType A[], int N);
void PercDown(ElementType A[], int i, int N);
int CompareArray(ElementType A[], int N, ElementType Check[]);
void Swap(ElementType *a, ElementType *b);

int main() {
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &data1[i]);
		data2[i] = data1[i];
	}
	for(int i=0; i<N; i++)
		scanf("%d", &Check[i]);
		int flag1, flag2;
	flag1 = Insertion_Sort(data1, N, Check);
	if(!flag1)
		Heap_Sort(data2, N);
}

int Insertion_Sort(ElementType A[], int N, ElementType Check[])
{
	int P, i, flag;
	ElementType Tmp;
	for (P = 1; P<N; P++) {
		Tmp = A[P];
		for (i=P; i>0 && A[i-1]>Tmp; i--)
			A[i] = A[i-1];
		A[i] = Tmp;
		flag = CompareArray(A, N, Check);
		if (flag) {
			printf("Insertion Sort\n");
			break;
		}
	}
	if(flag){
		P++;
		Tmp = A[P];
		for (i=P; i>0 && A[i-1]>Tmp; i--)
			A[i] = A[i-1];
		A[i] = Tmp;
		for(int j=0; j<N; j++)
			j == N-1 ? printf("%d", A[j]) : printf("%d ", A[j]);
		return 1;
	}
	return 0;
}

void Swap(ElementType *a, ElementType *b)
{
	ElementType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int CompareArray(ElementType A[], int N, ElementType Check[])
{
	for (int i=0; i<N; i++) {
		if(A[i] != Check[i]) return 0;
	}
	return 1;
}

void Heap_Sort ( ElementType A[], int N )
{ 
	int i, flag=0;
	for ( i=N/2-1; i>=0; i-- )/* BuildHeap */
		PercDown( A, i, N );
	
	for ( i=N-1; i>0; i-- ) {
		if (flag) {
			Swap( &A[0], &A[i] ); /* DeleteMax */
			PercDown( A, 0, i );
			for(int j=0; j<N; j++)
				j == N-1 ? printf("%d", A[j]) : printf("%d ", A[j]);
			printf("\n");
			break;
		}
		Swap( &A[0], &A[i] ); /* DeleteMax */
		PercDown( A, 0, i );
		flag = CompareArray(A, N, Check);
		if (flag) {
			printf("Heap Sort\n");
		}
	}
}

void PercDown(ElementType A[], int i, int N)
{
	ElementType item;
	int child, LeftChild, RightChild;
	for(item=A[i]; 2*i+1 < N; i=child) {
		LeftChild = 2*i+1;
		RightChild = 2*i+2;
		if(RightChild < N && A[LeftChild] < A[RightChild])
			child = RightChild;
		else child = LeftChild;
		if(A[child] > A[i]){
			Swap(&A[i], &A[child]);
		} else break;
	}
}