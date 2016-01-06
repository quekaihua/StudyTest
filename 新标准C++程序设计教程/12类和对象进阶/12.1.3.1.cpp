#include <iostream>
using namespace std;
class Complex{
	public:
		double real,imag;
		Complex(double r,double i){
			real = r; imag = i;
		}
}; 
int main(){
	Complex c1(1,2);
	Complex c2(c1);
	cout << c2.real << "," << c2.imag;
	return 0;
}
