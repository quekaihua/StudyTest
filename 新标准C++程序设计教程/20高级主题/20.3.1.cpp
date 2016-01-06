#include <iostream>
#include <memory>
using namespace std;
class A{
	public:
		int i;
		A(int n):i(n){};
		~A(){
			cout << i << " " << "destructed" << endl;
		}
};
int main(){
	auto_ptr<A> ptr(new A(2));
	cout << ptr->i << endl;
	ptr->i = 100;
	A a(*ptr);
	cout << a.i << endl;
	a.i = 20;
	return 0;
}
