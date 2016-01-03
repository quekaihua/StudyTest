#include <cstdlib>
#include <iostream>
#include "myList.h"

using namespace std;

template <class T> 
class Link{
	public:
		T data;
		Link *next;
		Link(const T info,Link* nextValue = NULL){
			data = info;
			next = nextValue;
		}
		Link(Link* nextValue = NULL){
			next = nextValue;
		}
};

//单链表类型定义
template <class T>
class lnkList:public List<T>{
	protected:
		Link<T>* head,tail;
	public:
		lnkList();
		~lnkList();
		bool isEmpty();
		void clear();
		int length();
		bool append(T value);
		bool insert(int p,T value);
		bool delete(int p);
		int getPos(const T value);
		Link<T> setPos(int p);
}; 

template <class T>
class lnkList::lnkList(){
	head = tail = new Link<T>;
}

template <class T>
class lnkList::~lnkList(){
	
}
