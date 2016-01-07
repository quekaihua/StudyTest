#include <iostream>
using namespace std;
union Register{
	unsigned int word;
	struct{
	unsigned short L;
	unsigned short H;
	}data;
};
int main(){
	Register AX;
	AX.word = 0x12345678;
	AX.data.H = 0x9999;
	cout << hex << AX.word << "," << AX.data.L << "," << AX.data.H;
}
