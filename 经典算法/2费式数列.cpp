#include <iostream>
using namespace std;
#define N 1000
int Fib[N] = {0};
int Fibo(int n){
	int temp;
	if(n==0)
		temp = 0;
	else if(n==1)
		temp = 1;
	else
		temp = Fibo(n-1)+Fibo(n-2);
	return temp; 
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		Fib[i] = Fibo(i);
	}
	for(int i=0;i<n;i++){
		cout << Fib[i] << " ";
	}
	cout << endl;
	
	return 0;
}

