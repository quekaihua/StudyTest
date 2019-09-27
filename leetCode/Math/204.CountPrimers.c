int isPrimes(int n) {
	// if(!(n & 1)) return 0;
	if(n == 2) return 1;
	if(!(n & 1)) return 0;
	int root = sqrt(n);
	for (int i=3; i<= root; i+=2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int countPrimes(int n){
	int count = 0;
	for(int i=2; i<n; i++) {
		if(isPrimes(i)) count++;
	}
	return count;
}