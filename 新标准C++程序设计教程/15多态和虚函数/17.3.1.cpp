#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream inFile;
	inFile.open("c:\\tmp\\test.txt",ios::in);
	if(inFile)
		inFile.close();
	else
		cout << "test.txt doesn't exist" << endl;
	ofstream oFile;
	oFile.open("test1.txt",ios::out);
	if(!oFile)
		cout << "error1" << endl;
	oFile.open("tmp\\test.txt",ios::out|ios::in);
	if(oFile)
		oFile.close();
	else
		cout << "error2" << endl;
	fstream ioFile;
	ioFile.open("..\\test.3.txt",ios::out|ios::in|ios::trunc);
	if(!ioFile)
		cout << "error3" << endl;
	else
		ioFile.close();
	
	
	return 0;
}
