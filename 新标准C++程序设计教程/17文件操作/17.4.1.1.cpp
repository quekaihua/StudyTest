#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
const int MAX_NUM = 1000;
int a[MAX_NUM];
int MyCompare(const void *e1,const void *e2){
	return *((int*)e1) - *((int*)e2);
} 
int main(){
	int total = 0;
	ifstream srcFile("in.txt",ios::in);
	if(!srcFile){
		cout << "error opening source file." << endl;
		return 0;
	}
	ofstream destFile("out.txt",ios::out);
	if(!destFile){
		srcFile.close();
		cout << "error opening destination file." << endl;
		return 0;
	}
	int x;
	while(srcFile >> x)
		a[total++] = x;
	qsort(a,total,sizeof(int),MyCompare);
	for(int i=0;i<total;++i)
		destFile << a[i] << " ";
	destFile.close();
	srcFile.close();
	return 0;
}	
