int trap(int* height, int heightSize){
	int begin=0, end, water=0;
	for(int i=0; i<heightSize; i++) {
		if (height[begin] <= height[i]) {
			end = i;
			//calcul water
			for(int j=begin+1; j<end; j++) {
				water = water + (height[begin] - height[j]);
			}
			begin = end;
		}
	}

	begin = heightSize - 1;
	for(int i=begin; i>=0; i--) {
		if (height[begin] < height[i]) {
			end = i;
			//calcul water
			for(int j=begin-1; j>end; j--) {
				water = water + (height[begin] - height[j]);
			}
			begin = end;
		}
	}
	return water;
}

int main()
{
	int height[] = {0,1,0,2,1,0,1,3,2,1,2,1,3,5,6,2,3,3,4,5,6};
	int heightSize = 21;
	trap(height, heightSize);
}