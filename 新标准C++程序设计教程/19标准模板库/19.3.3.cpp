#include <iostream>
#include <algorithm>
using namespace std;
template<class T>
void PrintInterval(T first,T last){
	for(;first!=last;++first){
		cout << *first << " ";
	}
	cout << endl;
}
class A{
	public:
		int v;
		A(int n):v(n){}
};
bool operator <(const A &a1,const A &a2){
	return a1.v < a2.v;
}
bool GreaterA(const A &a1,const A &a2){
	return a1.v > a2.v;
}
struct LessA{
	bool operator()(const A &a1,const A &a2){
		return (a1.v % 10) < (a2.v % 10);
	}
};
ostream & operator <<(ostream &o,const A &a){
	o << a.v;
	return o;
}
int main(){
	int a1[4] = {5,2,4,1};
	A a2[5] = {13,12,9,8,16};
	sort(a1,a1+4);
	cout << "1)";PrintInterval(a1,a1+4);
	sort(a2,a2+5);
	cout << "2)";PrintInterval(a2,a2+5);
	sort(a2,a2+5,GreaterA);
	cout << "3)";PrintInterval(a2,a2+5);
	sort(a2,a2+5,LessA());
	cout << "4)";PrintInterval(a2,a2+5);
	return 0;
}
