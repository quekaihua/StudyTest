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
lnkList<T>::lnkList(){
	head = tail = new Link<T>(9999,NULL);
}

template <class T>
lnkList<T>::~lnkList(){
	Link<T> * tmp;
	head = head->next;
	while(head != NULL){
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <class T>
Link<T>* lnkList<T>::setPos(int i){
	Link<T> *p;
	int count = 0;
	if(i == -1)
		return head;
	p = new Link<T>(head->next);
	while(p != NULL && count < i){
		p = p->next;
		count++;
	}
	return p;
}

template <class T>
bool lnkList<T>::insert(int i,T value){
	Link<T> *p,*q;
	if((p = setPos(i-1)) == NULL){
		cout << "the insertion point is illegal" << endl;
		return false;
	}
	q = new Link<T>(value,p->next);
	p->next = q;
	if(p == tail)
		tail = q;
	return true;
}

template <class T>
bool lnkList<T>::del(int i){
	Link<T> *p,*q;
	if((p = setPos(i-1)) == NULL){
		cout << "the deletion point is illegal" << endl;
		return false;
	}
	q = p->next;
	if(q == tail){
		tail = p;
		delete q;
	}
	if(q != NULL){
		p->next = q->next;
		delete q;
	}
	return true;
}

template <class T>
void lnkList<T>::print(){
	Link<T> *tmp = head;
	cout << "begin" << endl;
	while(tmp != NULL){
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
	cout << "end" << endl; 
}
