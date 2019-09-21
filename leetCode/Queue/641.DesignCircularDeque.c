#include <stdbool.h>

typedef struct {
	int front;
	int rear;
	int size;
	int capital;
	int* data;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* Q = malloc(sizeof(MyCircularDeque));
	Q->front = 0;
	Q->rear = 0;
	Q->size = 0;
	Q->capital = k;
	Q->data = malloc(sizeof(int) * k);
	return Q;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
  return obj->size == 0 ? true : false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
  return obj->size == obj->capital ? true : false;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
	if(myCircularDequeIsFull(obj)) return false;
	obj->front = (obj->front - 1 + obj->capital) % obj->capital;
  	obj->data[obj->front] = value;
  	obj->size++;
  	return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
  if(myCircularDequeIsFull(obj)) return false;
  obj->data[obj->rear] = value;
  obj->rear = (obj->rear+1) % obj->capital;
  obj->size++;
  return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
	if(myCircularDequeIsEmpty(obj)) return false;
  	obj->front = (obj->front+1) % obj->capital;
  	obj->size--;
  	return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
  if(myCircularDequeIsEmpty(obj)) return false;
  obj->rear = (obj->rear - 1 + obj->capital) % obj->capital;
  obj->size--;
  return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
  if(myCircularDequeIsEmpty(obj)) return -1;
  return obj->data[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
  if(myCircularDequeIsEmpty(obj)) return -1;
  return obj->data[(obj->rear - 1 + obj->capital) % obj->capital];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    if(!obj) return;
    free(obj->data);
	free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/