#include <stdio.h>
typedef int ElementType;

#define MAXSIZE 51
int Count[MAXSIZE];
void Bucket_Sort(ElementType A[], int N);

int main()
{
	int N, year;
	scanf("%d", &N);
	for (int i=0; i<MAXSIZE; i++)
		Count[i] = 0;

	for (int i=0; i<N; i++) {
		scanf("%d", &year);
		Count[year]++;
	}

	for (int i=0; i<MAXSIZE; i++) {
		if(Count[i]){
			printf("%d:%d\n", i, Count[i]);
		}
	}
	return 0;
}