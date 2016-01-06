#include <iostream>
using namespace std;
class A{
	public:
		operator int(){
			return 1;
		}
		operator char * (){
			return NULL;
		}
};
int main(){
	A a;
	int n;char *p = "New Dragon Inn";
	n = static_cast<int>(3.14);
	cout << "n=" << n << endl; 
	n = static_cast<int>(a);
	cout << "n=" << n << endl; 
	p = static_cast<char *>(a);
	return 0;
}
