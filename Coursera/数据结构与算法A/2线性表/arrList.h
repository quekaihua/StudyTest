#include <iostream>
#include <string>
#include "myList.h"

using namespace std;

template <class T>
class arrList:public List<T>{
	private:
		int maxSize;
		int curlen;
		int position;
		T *aList;
	public:
		arrList(const int size){
			maxSize = size;
			aList = new T[maxSize];
			curlen = position = 0;
		}
		~arrList(){
			delete [] aList;
		}
		void clear(){
			delete [] aList;
			curlen = position = 0;
			aList = new T[maxSize];
		}
		bool append(T value);
		bool insert(int p,T value);
		bool del(int p);
		int getPos(const T value);
		void print();
};

template <class T>
int arrList<T>::getPos(const T value){
	int i;
	for(i=0;i<curlen;i++){
		if(value == aList[i])
		return i;
	}
	return -1;
}

template <class T>
bool arrList<T>::insert(int p,const T value){
	int i;
	if(curlen >= maxSize){
		cout << "The List is overflow\n" << endl;
		return false;
	}
	if(p<0 || p>curlen){
		cout << "Insertion is illegal\n" << endl;
		return false;
	}
	for(i=curlen;i>p;i--){
		aList[i] = aList[i-1];
	}
	aList[p] = value;
	curlen++;
	return true;
}

template <class T>
bool arrList<T>::del(int p){
	int i;
	if(curlen <= 0){
		cout << "No element to delete \n" << endl;
		return false;
	}
	if(p<0 || p>curlen-1){
		cout << "deletetion is illegal\n" << endl;
		return false;
	}
	for(i=p;i<curlen-1;i++){
		aList[i] = aList[i+1];
	}
	curlen--;
	return true;
}

template <class T>
void arrList<T>::print(){
	for(int i=0;i<curlen;i++){
		cout << aList[i];
	}
	cout << endl;
}
