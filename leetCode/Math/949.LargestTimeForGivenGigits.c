#include <stdlib.h>
#include <stdio.h>

int used[4] = {0};

int getMaxLessN(int* A, int ASize, int N) {
	int max = -1;
	int max_index = -1;
	for(int i=0; i<ASize; i++) {
		if(used[i]) continue;
		if(max < A[i] && A[i] <= N) {
			max = A[i];
			max_index = i;
		}
	}
	return max_index;
}

char * largestTimeFromDigits(int* A, int ASize){
	char * res = calloc(6, sizeof(char));
	int first, second, third, forth;
	first = getMaxLessN(A, ASize, 2);
	if (first == -1) {
		return res;
	} 
	used[first] = 1;
	
	second = A[first] == 2 ? getMaxLessN(A, ASize, 3) : getMaxLessN(A, ASize, 9);
	if(second == -1) {
		return res;
	}
	used[second] = 1;

	third = getMaxLessN(A, ASize, 5);
	if(third == -1) {
		for(int i=0; i<ASize; i++) {
			used[i] = 0;
		}
		first = getMaxLessN(A, ASize, 1);
		if (first == -1) {
			return res;
		}
		used[first] = 1;
		second = getMaxLessN(A, ASize, 9);
		if(second == -1) {
			return res;
		}
		used[second] = 1;
		third = getMaxLessN(A, ASize, 5);
		if(third == -1) {
			return res;
		}
		used[third] = 1;
	}
    used[third] = 1;

	forth = getMaxLessN(A, ASize, 9);
	if(forth == -1) {
		return res;
	}
	
	res[0] = A[first] + 48;
	res[1] = A[second] + 48;
	res[2] = ':';
	res[3] = A[third] + 48;
	res[4] = A[forth] + 48;
	res[5] = '\0';
	return res;
}

int main() {
	int a[4] = {0,0,0,0};
	char *res = largestTimeFromDigits(a, 4);
	printf("%s", res);
}

