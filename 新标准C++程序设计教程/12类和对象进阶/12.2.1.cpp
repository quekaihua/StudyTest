#include <iostream>
using namespace std;
class CDemo{
	public:
		~CDemo(){
			cout << "Destructor called" << endl;
		}
};
int main(){
	CDemo array[2];
	CDemo *pTest = new CDemo;
	delete pTest;
	cout << "----------------------------" << endl;
	pTest = new CDemo[2];
	delete [] pTest;
	cout << "Main ends." << endl;
	return 0;
}
