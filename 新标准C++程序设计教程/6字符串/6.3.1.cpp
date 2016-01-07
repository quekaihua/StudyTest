#include <iostream>
#include <cstring>
using namespace std;

void PrintSmall(char s1[],char s2[]){
	if(strcmp(s1,s2)<=0)
		cout << s1;
	else
		cout << s2;
}

int main(){
	char s1[30];
	char s2[40];
	char s3[100];
	strcpy(s1,"hello");
	strcpy(s2,s1);
	cout << "1) " << s2 << endl;
		strcat(s1,",world");
	cout << "2) " << s1 << endl;
	cout << "3) ";PrintSmall("abc",s2);cout << endl;
	cout << "4) ";PrintSmall("abc","aaa");cout << endl;
	int n = strlen(s2);
	cout << "5) " << n << "," << strlen("abc") << endl;
	strupr(s1);
	cout << "6) " << s1 << endl;
	return 0;
}
