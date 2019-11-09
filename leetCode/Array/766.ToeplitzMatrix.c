
#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
	int col = matrixColSize[0];
	for(int i=0; i<matrixSize-1; i++) {
		for(int j=0; j<col-1; j++) {
			if(matrix[i][j] != matrix[i+1][j+1]) return false;
		}
	}
	return true;
}

int main()
{
	int matrix[3][4] = {{1,2,3,4}, 
					    {5,1,2,3},
					    {9,5,1,2}};
	int matrixSize = 3;
	int matrixColSize[] = {4,4,4};
	isToeplitzMatrix(matrix, matrixSize, matrixColSize);

	return 0;
}

