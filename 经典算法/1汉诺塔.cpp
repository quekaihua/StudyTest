#include <iostream>
using namespace std;

void move(char A, int n, char C){
	cout << "Move sheet " << n << " from " << A << " to " << C << endl;
} 

void hanoi(int n,char A,char B,char C){
	if(n == 1){
		move(A,1,C); 
	}else{
		hanoi(n-1,A,C,B);
		move(A,n,C);
		hanoi(n-1,B,A,C);
	}
}
int main(){
	int n;
	cout << "ÇëÊäÈëÅÌ×ÓÊý£º" << endl;
	cin >> n;
	hanoi(n,'A','B','C');
	return 0;
}
