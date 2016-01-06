#include <iostream>
using namespace std;
class Complex{
	public:
		double real,imag;
		Complex(double r=0.0,double i=0.0):real(r),imag(i){
		}
		Complex operator-(const Complex &c);
};
Complex operator+(const Complex &a,const Complex &b){
	return Complex(a.real+b.real,a.imag+b.imag);
}
Complex Complex::operator-(const Complex &c){
	return Complex(real-c.real,imag-c.imag);
}
int main(){
	Complex a(4,4),b(1,1),c;
	c = a + b;
	cout << c.real << "," << c.imag << endl;
	cout << (a-b).real << "," << (a-b).imag << endl;
	return 0;
}
