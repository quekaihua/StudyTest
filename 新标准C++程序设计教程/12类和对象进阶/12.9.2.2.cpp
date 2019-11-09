#include <iostream>
using namespace std;

class Complex
{
	public:
		double real, imag;
		Complex(double r, double i): real(r), imag(i) {}
		Complex AddOne()
		{
			this->real++;
			return *this;
		}
};

int main()
{
	Complex c1(1, 1), c2(0, 0);
	c2 = c1.AddOne();
	cout << c2.real << "," << c2.imag << endl;
	return 0;
}