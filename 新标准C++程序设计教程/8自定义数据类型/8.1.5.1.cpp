#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
const int NUM = 4;
struct Student{
	unsigned ID;
	string name;
	float FGPA;
};
Student MyClass[NUM]{
	{1234,"Tom",3.78},
	{1238,"Jack",3.25},
	{1232,"Mary",4.00},
	{1237,"Jone",2.78},	
};
int CompareID(const void *elem1,const void *elem2){
	Student *ps1 = (Student *) elem1;
	Student *ps2 = (Student *) elem2;
	return ps1->ID - ps2->ID;
}
int CompareName(const void *elem1,const void *elem2){
	Student *ps1 = (Student *) elem1;
	Student *ps2 = (Student *) elem2;
	return strcmp(ps1->name.c_str(),ps2->name.c_str());
}

int main(){
	int i;
	qsort(MyClass,NUM,sizeof(Student),CompareID);
	for(i=0;i<NUM;++i)
		cout << MyClass[i].name << " ";
	cout << endl;
	qsort(MyClass,NUM,sizeof(Student),CompareName);
	for(i=0;i<NUM;++i)
		cout << MyClass[i].name << " ";
	cout << endl;
	return 0;
}

