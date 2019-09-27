int maxProfit(int* prices, int pricesSize){
	int min, profit, max=0;
	for(int i=0; i<pricesSize; i++) {
		if(i==0) min=prices[i];
		profit = prices[i] - min;
		if(profit < 0) min = prices[i];
		if(max < profit) max = profit;
	}
	return max;
}