#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MAXSIZE 100
int Check[MAXSIZE], data1[MAXSIZE], data2[MAXSIZE];
int Flag=0;
int N = 10;
void Swap(ElementType *a, ElementType *b);
int CompareArray(ElementType A[], int N);
int Insertion_Sort(ElementType A[], int N, ElementType Check[]);
int Merge_Sort(ElementType A[], int N);
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd);
int Merge_pass(ElementType A[], ElementType TmpA[], int N, int length, ElementType Check[]);

int main()
{
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
		Merge_Sort(data2, N);
	return 0;
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
		flag = CompareArray(A, N);
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

int CompareArray(ElementType A[], int N)
{
	for (int i=0; i<N; i++) {
		if(A[i] != Check[i]) return 0;
	}
	return 1;
}

int Merge_Sort(ElementType A[], int N)
{
	ElementType *TmpA;
	TmpA = malloc(N * sizeof(ElementType));
	int length = 1, flag=0;
	while (length < N) {
		if(flag) {
			Merge_pass(A, TmpA, N, length, Check);
			for(int j=0; j<N; j++)
			j == N-1 ? printf("%d", A[j]) : printf("%d ", A[j]);
			free(TmpA);
			return 1;
		}
		Merge_pass(A, TmpA, N, length, Check);
		length *= 2;
		flag = CompareArray(A, N);
		if(flag) printf("Merge Sort\n");
		// Merge_pass(TmpA, A, N, length);
		// length *= 2;
	}
	free(TmpA);
	return 0;
}

int Merge_pass(ElementType A[], ElementType TmpA[], int N, int length, ElementType Check[])
{
	int i, flag = 0;
	for (i=0; i<=N-2*length; i += 2*length){
		Merge(A, TmpA, i, i+length, i+2*length-1);
	}
	if (i+length < N){
		Merge(A, TmpA, i, i+length, N-1);
	}
	else{
		for (int j=i; j<N; j++)
			TmpA[j] = A[j];
	}
	return 0;
}

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
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
