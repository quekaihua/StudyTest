/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
	int left=0, right = ASize-1, temp;
	int * ret = malloc(sizeof(int) * ASize);
	for (int i=0; i<ASize; i++) {
		if(A[i] & 1) {
			ret[right--] = A[i];
		} else {
			ret[left++] = A[i];
		}
	}
    *returnSize = ASize;
	return ret;
}