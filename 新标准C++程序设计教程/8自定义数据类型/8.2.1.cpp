#include <iostream>
#include <cstring>
using namespace std;
union UTest{
	int a;
	short b;
	char s[16];
	char c;
};
int main(){
	UTest u;
	cout << sizeof(u) << endl;
	memset(&u,0,sizeof(u));
	u.a = 0x61626364;
	cout << hex << u.a << "," << u.b << "," << u.c << "," << u.s;
}
