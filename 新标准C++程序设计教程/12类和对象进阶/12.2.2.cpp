#include <iostream>
using namespace std;
class CDemo{
	public:
		~CDemo(){
			cout << "Destructor called" << endl;
		}
};
void Func(CDemo obj){
	cout << "func" << endl;
} 
CDemo dl;
CDemo Test(){
	cout << "test" << endl;
	return dl;
}
int main(){
	CDemo d2;
	Func(d2);
	Test();
	cout << "after test" << endl;
	return 0;
}
