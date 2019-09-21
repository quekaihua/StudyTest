

int heightChecker(int* heights, int heightsSize){
	int cnt=0;
	for (int i=0; i<heightsSize-1; i++) {
		if(heights[i] < heights[i+1]) cnt++;
	}
	return cnt > 0 ? cnt+1 : cnt;
}

