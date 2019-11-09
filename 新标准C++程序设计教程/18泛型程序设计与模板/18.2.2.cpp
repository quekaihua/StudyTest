#include <iostream>
using namespace std;

template<class T>
class A
{
	public:
		template<class T2>
		void Func(T2 t) {cout << t;}
};

int main()
{
	A<int> a;
	a.Func('K');
	return 0;
}