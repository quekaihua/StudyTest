#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MAXSIZE 100
int Check[MAXSIZE], N, Flag;

void Swap(ElementType *a, ElementType *b);
int CompareArray(ElementType A[], int N);
int Insertion_Sort(ElementType A[], int N);
void Merge_Sort(ElementType A[], int N);
void MSort(ElementType A[], ElementType TmpA[], int L, int RightEnd);
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd);

int main()
{
	N;
	scanf("%d", &N);
	int data1[MAXSIZE], data2[MAXSIZE];
	for(int i=0; i<N; i++){
		scanf("%d", &data1[i]);
		data2[i] = data1[i];
	}
	for(int i=0; i<N; i++)
		scanf("%d", &Check[i]);

	int flag1;
	Flag = 0;
	// flag1 = Insertion_Sort(data1, N);
	if(!flag1)
		Merge_Sort(data2, N);
	return 0;
}

int Insertion_Sort(ElementType A[], int N)
{
	int P, i;
	ElementType Tmp;
	for (P = 1; P<N; P++) {
		Tmp = A[P];
		for (i=P; i>0 && A[i-1]>Tmp; i--)
			A[i] = A[i-1];
		A[i] = Tmp;
		Flag = CompareArray(A, N);
		if (Flag) {
			printf("Insertion Sort\n");
			break;
		}
	}
	if(Flag){
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

int CompareArray(ElementType A[], int N)
{
	printf("A[]:\n");
	for(int j=0; j<N; j++)
			j == N-1 ? printf("%d", A[j]) : printf("%d ", A[j]);
	printf("\n");

	printf("Check[]:\n");
	for(int j=0; j<N; j++)
			j == N-1 ? printf("%d", Check[j]) : printf("%d ", Check[j]);
	printf("\n");
	for (int i=0; i<N; i++) {
		if(A[i] != Check[i]) return 0;
	}
	printf("\n");
	return 1;
}

void Merge_Sort(ElementType A[], int N)
{
	ElementType *TmpA;
	TmpA = malloc(N * sizeof(ElementType));
	if(TmpA != NULL) {
		MSort(A, TmpA, 0, N-1);
		free(TmpA);
	}
}

void MSort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
	int Center;
	if (L < RightEnd) {
		Center = (L + RightEnd) / 2;
		MSort(A, TmpA, L, Center);
		MSort(A, TmpA, Center+1, RightEnd);
		Merge(A, TmpA, L, Center+1, RightEnd);
	}
	// printf("%d", Flag);
	// if (Flag) {
	// 	printf("Merge Sort\n");
	// 	for(int j=0; j<10; j++)
	// 		j == 9 ? printf("%d", A[j]) : printf("%d ", A[j]);
	// 	Flag = 0;
	// }
	// printf("\n");
}

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	printf("L=%d,R=%d\n", L, R);
	Flag = CompareArray(A, N);
	int LeftEnd = R - 1;
	int Tmp = L;
	int NumElements = RightEnd - L + 1;
	while(L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R]) TmpA[Tmp++] = A[L++];
		else	TmpA[Tmp++] = A[R++];
	}
	while(L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while(R <= RightEnd)
		TmpA[Tmp++] = A[R++];
	for (int i=0; i<NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}
