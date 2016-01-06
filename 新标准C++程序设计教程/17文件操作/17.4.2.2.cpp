#include <iostream>
#include <fstream>
using namespace std;
class CStudent{
	public:
		char szName[20];
		int age;
};
int main(){
	CStudent s;
	ifstream inFile("sudent.dat",ios::in|ios::binary);
	if(!inFile){
		cout << "error" << endl;
		return 0;
	}
	while(inFile.read((char *)&s,sizeof(s))){
		int readedBytes = inFile.gcount();
		cout << s.szName << " " << s.age << endl;
	}
	inFile.close();
	return 0;
	
}
