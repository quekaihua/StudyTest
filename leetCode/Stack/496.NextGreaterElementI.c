#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int* res = malloc(sizeof(int)*(nums1Size));
	*returnSize = nums1Size;
	int temp, flag, k=0;
	for (int i=0; i<nums1Size; i++) {
		temp = nums1[i];
		flag = 0;
		int j= 0;
		for (; j < nums2Size; j++) {
			if(temp == nums2[j]) break;
		}
		for (; j < nums2Size; j++) {
			if(temp < nums2[j]) {
				res[k++] = nums2[j];
				flag = 1;
				break;
			}
		}
		if(!flag) res[k++] = -1;
	}

	return res;
}

int main()
{
	int nums1[] = {2, 4};
	int nums2[] = {1, 2, 3, 4};
	int *res;
	int i = 2;
	res = nextGreaterElement(nums1, 2, nums2, 4, &i);
	for(int i=0; i<2;i++) printf("%d ", res[i]);
}