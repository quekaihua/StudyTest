int maxProfit(int* prices, int pricesSize){
	int min, profit, max=0;
	for(int i=0; i<pricesSize-1; i++) {
		if(i==0) min=prices[i];
		profit = prices[i] - min;
		
		if (profit < 0) min = prices[i];
		else if (prices[i] < prices[i+1]) {
			max += profit; 
			min=prices[i+1];
		}
	}
	return max;
}

int main()
{
	int a[] = {7, 1, 5, 3, 6, 4};
	maxProfit(a, 6);
	return 0;
}