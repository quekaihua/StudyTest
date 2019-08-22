#include <stdio.h>

#define MAXSIZE 10
typedef int ElementType;

void Swap(ElementType *a, ElementType *b);

int main()
{
	int N, cnt=0, Arr[MAXSIZE];
	scanf("%d", &N);
	for (int i=0; i<MAXSIZE; i++)
		scanf("%d", &Arr[i]);
	
	for (int i=1; i<N; i++) {
		if (Arr[i] == i) continue;
		while(Arr[0] != 0) {
			Swap(&Arr[0], &Arr[Arr[0]]);
			cnt++;
		}

		if (Arr[i] != i) {
			Swap(&Arr[0], &Arr[i]);
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}

void Swap(ElementType *a, ElementType *b)
{
	ElementType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}



