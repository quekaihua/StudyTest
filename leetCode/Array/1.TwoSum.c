/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	*returnSize = 2;
	int *res = malloc(sizeof(int) * (*returnSize));
	int flag = 0;
	for(int i=0; i<numsSize; i++) {
		for(int j=0; j<numsSize; j++){
			if(i==j) continue;
			if(nums[i] + nums[j] == target) {
				flag = 1;
				res[0] = i;
				res[1] = j;
                break;
			}
		}
        if(flag) break;
	}

	return res;
}