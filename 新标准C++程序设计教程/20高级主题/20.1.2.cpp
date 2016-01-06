#include <iostream>
using namespace std;
class A{
	public:
		int i;
		int j;
		A(int n):i(n),j(n){}
};
int main(){
	A a(100);
	int &r = reinterpret_cast<int &>(a);
	r = 200;
	cout << a.i << "," << a.j << endl;
	int n = 300;
	A *pa = reinterpret_cast<A *>(& n);
	pa->i = 400;
	pa->j = 500;
	cout << n << endl;
	long long la = 0x12345678abcdLL;
	pa = reinterpret_cast<A *>(& n);
//	unsigned int u = reinterpret_cast<unsigned int>(pa);
//	cout << hex << u << endl;
	typedef void (*PF1)(int);
	typedef int (*PF2)(int,char *);
	PF1 pf1;PF2 pf2;
	pf2 = reinterpret_cast<PF2>(pf1);
}
