#include <stdio.h>
#define ElementType int
#define MAXSIZE 100000

void Bubble_Sort(ElementType A[], int N);
void Swap(ElementType *a, ElementType *b);
void Insertion_Sort(ElementType A[], int N);

int main(){
	int N;
	scanf("%d", &N);
	int data[MAXSIZE];
	for(int i=0; i<N; i++)
		scanf("%d", &data[i]);
	// Bubble_Sort(data, N);
	Insertion_Sort(data, N);

	for(int i=0; i<N; i++)
		i==N-1 ? printf("%d", data[i]) : printf("%d ", data[i]);

	return 0;
}

void Bubble_Sort(ElementType A[], int N)
{
	int flag;
	for (int P = N-1; P>=0; P--) {
		flag = 0;
		for (int i=0; i<P; i++) {
			if (A[i] > A[i+1]) {
				Swap(&A[i], &A[i+1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

void Swap(ElementType *a, ElementType *b)
{
	ElementType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
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