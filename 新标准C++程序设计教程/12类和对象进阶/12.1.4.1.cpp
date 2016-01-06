#include <iostream>
using namespace std;
class Complex{
	public:
		double real,imag;
		Complex(int i){
			cout << "IntConstructor called" << endl;
			real = i; imag = 0;
		}
		Complex(double r,double i){
			real = r; imag = i;
		}
		Complex(const Complex &c){
			real = c.real; imag = c.imag;
			cout << "Copy Constructor called" << endl;
		}
};
int main(){
	Complex c1(7,8);
	Complex c2 = 12;
	c1 = 9;
	cout << c1.real << "," << c1.imag << endl;
	return 0;
}
