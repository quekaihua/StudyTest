#include <iostream>
using namespace std;
class A{
	public:
		A(){
		};
		A(A &a){
			cout << "Copy constructor called" << endl;
		}
};
void Func(A a){
}

int main(){
	A a;
	Func(a);
	return 0;
}
