

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
	int **res = malloc(sizeof(int*) * numRows);
	*returnSize = numRows;
	*returnColumnSizes = (int *) malloc (sizeof(int) * numRows);
	for (int i = 0; i < numRows; i++) 
		(*returnColumnSizes)[i] = i + 1;
		
	for (int row=0; row<numRows; row++) {
		int* temp = malloc(sizeof(int) * (row+1));
		for(int col=0; col<(row+1); col++) {
			if(col==0) temp[col] = 1; continue;
			if(col==row) temp[col] = 1; continue;
			if (row > 1) {
				temp[col] = res[row-1][col-1] + res[row-1][col];
			}
		}
		res[row] = temp;
	}

	return res;
}
