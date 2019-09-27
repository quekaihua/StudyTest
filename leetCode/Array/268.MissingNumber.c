int missingNumber(int* nums, int numsSize){
	int total;
    int d = numsSize & 1;
	total = numsSize & 1 ? 
        ((numsSize+1)/2) * (0 + numsSize) :
        ((numsSize+2)/2) * (0 + numsSize) - (numsSize+1)/2;
	for(int i=0; i<numsSize; i++) total -= nums[i];
	return total;
}
