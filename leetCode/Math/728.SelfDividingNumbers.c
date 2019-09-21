

int selfDividing(int i)
{
    if(i == 0) return 0;
	int num = i, d;
	while(num > 0) {
		d = num%10;
        if(d == 0) return 0;
		if(i % d != 0) return 0;
		num /= 10;
	}
	return 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
	int *res = malloc(sizeof(int)*10000);
	int k=0;
	for(int i=left; i<=right; i++) {
		if(selfDividing(i)) res[k++] = i;
	}
	*returnSize = k;
	return res;
}