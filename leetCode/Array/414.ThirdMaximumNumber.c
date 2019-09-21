int thirdMax(int* nums, int numsSize){
	int top[3];
	int size=0;
	for (int i=0; i<numsSize; i++) {
		if(size>0){
			int j=size-1;
			for(int j=size-1; j>0; j--){
				if(top[j] < nums[i]) {
					top[j+1] = top[j];
				}
			}
			top[j] = nums[i];
			size++;
		} else {
			top[0] = nums[i];
			size++;
		}
	}
	return size > 2 ? top[2] : top[0];
}