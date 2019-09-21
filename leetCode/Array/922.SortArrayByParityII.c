/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
	int odd=1, even=0;
	int *ret = malloc(sizeof(int) * ASize);
	for (int i=0; i<ASize; i++) {
		if(A[i] & 1) {
			ret[odd] = A[i];
            odd += 2;
		} else {
			ret[even] = A[i];
            even += 2;
		}
	}
    *returnSize = ASize;
	return ret;
}