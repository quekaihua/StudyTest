
int abs(int a) {
	return a > 0 ? a : 0-a;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
	int *res = malloc(sizeof(int) * ASize);
    *returnSize = ASize;
	int P, i, temp;
	for(P=1; P<ASize; P++) {
		temp = A[P];
		for(i=P; i>0 && (abs(A[i-1]) > abs(temp)); i--)
			A[i] = A[i-1];
		A[i] = temp;
	}
    for(int i=0; i<ASize; i++)
        res[i] = A[i] * A[i];
	return res;
}





