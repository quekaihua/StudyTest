#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream inFile("c:\\tmp\\test.txt",ios::in);
	if(inFile)
		inFile.close();
	else
		cout << "test.txt doesn't exist" << endl;
	ofstream oFile("test.txt",ios::out);
	if(!oFile)
		cout << "error1" << endl;
	else
		oFile.close();
	fstream oFile2("tmp\\test2.txt",ios::out|ios::in);
	if(!oFile2)
		cout << "error2";
	else
		oFile2.close();
	return 0;
}
