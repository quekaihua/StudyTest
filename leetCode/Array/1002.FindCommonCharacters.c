

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** A, int ASize, int* returnSize){
	char** ans = sizeof(char*) * 100; 
	char* string = A[0];
	int j=0, flag=0, k=0;
	while (string[j] != '\0') {
		flag=0;
		for(int i=1; i<ASize; i++) {
			if(A[i][j] == string[j]) {
				A[i][j] == '-';
				flag = 1;
				continue;
			}
		}
		if(flag) {
			ans[k++] = malloc(2);
			ans[k][0] = string[j];
			ans[k][1] = '\0';
		}
		j++;
	}
	returnSize = k;

	return ans;
}

