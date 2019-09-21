/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
	*returnSize =  ASize;
	int **ret = (int **)malloc(*returnSize * sizeof(int *));
	returnColumnSizes = malloc(sizeof(int) * (*returnSize));
	//Invert
	for (int i=0; i<ASize; i++) {
		ret[i] = malloc(sizeof(int) * (AColSize[i]));
		returnColumnSizes[i] = AColSize[i];
		for(int j=0; j<AColSize[i]; j++) {
			ret[i][j] = A[i][j] == 0 ? 1 : 0;
		}
	}

	//flip
	for (int i=0; i<ASize; i++) {
		int left = 0, right = AColSize[i]-1, temp;
		while(left < right) {
			temp = ret[i][left];
			ret[i][left] = ret[i][right];
			ret[i][right] = temp;
			left++;
			right--;
		}
	}

	return ret;
}

int main()
{
	int A[][3] = {{0,1,1}, {1,1,1}, {0,0,1}};
	int * returnSize;
	int **returnColumnSizes;
	int AColSize[] = {3,3,3};
	flipAndInvertImage(A, 3, AColSize, &returnSize, returnColumnSizes);
}