#include <iostream>
#include <cstring>
using namespace std;

class CEmployee {
	private:
		char szName[30];
	public:
		int salary;
		void setName(char *name);
		void getName(char *name);
		void averageSalary(CEmployee e1, CEmployee e2);
};

void CEmployee::setName(char *name)
{
	strcpy(szName, name);
}

void CEmployee::getName(char *name)
{
	strcpy(name, szName);
}

void CEmployee::averageSalary(CEmployee e1, CEmployee e2)
{
	salary = (e1.salary + e2.salary) / 2;
}