#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int val;
	struct node* next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
	obj->next = NULL;
	return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
  if(index < 0) return -1;
  int cnt = 0;
  MyLinkedList* current;
  current = obj->next;
  while (current && cnt <= index)
  {
	  if(cnt == index) return current->val;
	  current = current->next;
	  cnt++;
  }
  return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  MyLinkedList* node = malloc(sizeof(MyLinkedList));
  node->val  = val;
  node->next = obj->next;
  obj->next  = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
  while(obj->next) {
	  obj = obj->next;
  }
  MyLinkedList* node = malloc(sizeof(MyLinkedList));
  node->val  = val;
  node->next = NULL;
  obj->next  = node;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  if(index < 0) myLinkedListAddAtHead(obj, val);
  int cnt = 0;
  MyLinkedList* current, *prev;
  prev = obj;
  current = obj->next;
  while (prev && cnt <= index)
  {
	  if(cnt == index) {
		MyLinkedList* node = malloc(sizeof(MyLinkedList));
  	    node->val  = val;
        node->next = current;
        prev->next  = node;
		break;
	  }
	  prev    = current;
	  if(!current) break;
	  current = current->next;
	  cnt++;
  }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  if(index < 0) return;
  int cnt = 0;
  MyLinkedList* current, *prev, *temp;
  temp = NULL;
  prev = obj;
  current = obj->next;
  while (current && cnt <= index)
  {
	  if(cnt == index) {
		temp = current;
		prev->next = current->next;
		break;
	  }
	  prev = current;
	  current = current->next;
	  cnt++;
  }
  if(temp)
	free(temp);
}

void myLinkedListFree(MyLinkedList* obj) {
    if(obj != NULL)
		myLinkedListFree(obj->next);
	free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

int main()
{
	MyLinkedList *obj = myLinkedListCreate();
	myLinkedListAddAtHead(obj, 1);
	myLinkedListAddAtIndex(obj, 1, 2);
	myLinkedListAddAtTail(obj, 3);
	myLinkedListDeleteAtIndex(obj, 1);
	int val;
	val = myLinkedListGet(obj,0);
	myLinkedListFree(obj);
	printf("%d\n", val);
	return 0;
}