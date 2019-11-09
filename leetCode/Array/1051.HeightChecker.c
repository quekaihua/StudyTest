#include <stdlib.h>
int cmp(const void *a, const void *b)
{
	return *(int*) a - *(int*)b;
}

int heightChecker(int* heights, int heightsSize){
	int * heights2 = malloc(sizeof(int) * heightsSize);
	for (int i=0; i<heightsSize; i++) {
		heights2[i] = heights[i];
	}
	qsort(heights2, heightsSize, sizeof(int), cmp);

	int cnt=0;
	for (int i=0; i<heightsSize; i++) {
		if(heights[i] != heights2[i]) cnt++;
	}
	return cnt;
}

