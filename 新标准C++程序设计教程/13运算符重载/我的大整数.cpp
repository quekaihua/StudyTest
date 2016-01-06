#include <iostream>
#include <string>
using namespace std;
class BigInt{
	string str;
	int len;
	
	public:
		BigInt(string str_){
			str = str_;
			len = str_.size();
		}
		string GetNum(){
			return str;
		}
		string operator +(BigInt &c){
			if(str[0]=='-'){
				if(c.str[0]=='-'){
					str = +c
				}else{
					
				}
			}else{
				if(c.str[0]=='-'){
					
				}else{
					
				}
			}
		}
}; 
int main(){
	string a,res;
	cin >> a;
	BigInt A(a);
	res = A.GetNum();
	for(int i=0;i<res.size();++i){
		cout << res[i] ;
	}
	return 0;
}
