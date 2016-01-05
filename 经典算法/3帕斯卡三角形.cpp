#include <iostream>
#include <iomanip>
using namespace std;
#define R 13
int arr[R][R+10] = {0};
int main(){
	for(int i=0;i<R;i++){
		for(int j=0;j<=R+1;j++){
			if(j==0){
			arr[i][j] = 1;
			}else{
				arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
			}	
		}
	}
	for(int i=0;i<R;i++){
		for(int k=0;k<R-i;k++)
			cout << " ";
		for(int j=0;j<=i;j++){
			cout << setw(3) << setiosflags(ios::right) << arr[i][j] << " ";
		}
		cout << endl;
	}
}
