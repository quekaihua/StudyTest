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
	auto_ptr<A>ptr1(new A(2));
	auto_ptr<A>ptr2(ptr1);
	auto_ptr<A>ptr3;
	ptr3 = ptr2;
	cout << ptr3->i << endl;
	A *p = ptr3.release();
	ptr1.reset(p);
	cout << ptr1->i << endl;
	ptr1.reset(new A(3));
	cout << "end" << endl;
	return 0;
}
