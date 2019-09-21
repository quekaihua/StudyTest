

int fib(int N){
	int sum;
	if(N==0) sum=0;
	else if(N==1) sum=1;
	else sum = fib(N-1) + fib(N-2);
	return sum;
}

