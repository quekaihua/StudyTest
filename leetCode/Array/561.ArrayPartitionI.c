#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int arrayPairSum(int* nums, int numsSize){
	qsort(nums, numsSize, sizeof(int), cmpfunc);

	int sum=0;
	for(int i=0; i<numsSize; i+=2) {
		sum += nums[i];
	}
	return sum;
}

// int arrayPairSum(int* nums, int numsSize){
// 	int flag;
// 	for(int i=numsSize-1; i>=0; i--) {
// 		flag = 0;
// 		for(int j=0; j<i; j++) {
// 			if(nums[j] > nums[j+1]) {
// 				swap(&nums[j], &nums[j+1]);
// 				flag = 1;
// 			}
// 		}
// 		if(!flag) break;
// 	}
// 	int sum=0;
// 	for(int i=0; i<numsSize; i+=2) {
// 		sum += nums[i];
// 	}
// 	return sum;
// }

