#include <iostream>
using namespace std;

class CCar
{
	private:
		int price;
		friend class CDriver;
};

class CDriver
{
	public:
		CCar myCar;
		void ModifyCar()
		{
			myCar.price += 1000;
		}
};