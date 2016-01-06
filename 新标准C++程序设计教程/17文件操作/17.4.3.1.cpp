#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class CStudent{
	public:
		char szName[20];
		int age;
};
int main(){
	CStudent s;
	fstream ioFile("sudent.dat",ios::in|ios::out);
	if(!ioFile){
		cout << "error";
		return 0;
	}
	ioFile.seekg(0,ios::end);
	int L = 0,R;
	R = ioFile.tellg() / sizeof(CStudent)-1;
	do{
		int mid = (L + R) / 2;
		ioFile.seekg(mid * sizeof(CStudent),ios::beg);
		ioFile.read((char*)&s,sizeof(s));
		int tmp = strcmp(s.szName,"Jack");
		if(tmp == 0){
			s.age = 20;
			ioFile.seekp(mid * sizeof(CStudent),ios::beg);
			ioFile.write((char *)&s,sizeof(s));
			break;
		}else if(tmp > 0)
			R = mid - 1;
		else
			L = mid + 1;
	}while(L <= R);
	ioFile.close();
	return 0;
}
