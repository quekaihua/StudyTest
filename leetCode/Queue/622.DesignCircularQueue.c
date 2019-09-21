#include <stdbool.h>


typedef struct {
    int front;
	int rear;
	int size;
	int capital;
	int* data;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* Q = malloc(sizeof(MyCircularQueue));
	Q->front = 0;
	Q->rear = 0;
	Q->size = 0;
	Q->capital = k;
	Q->data = malloc(sizeof(int) * k);
	return Q;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return obj->size == 0 ? true : false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return obj->size == obj->capital ? true : false;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  if(myCircularQueueIsFull(obj)) return false;
  obj->data[obj->rear] = value;
  obj->rear = (obj->rear+1) % obj->capital;
  obj->size++;
  return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj)) return false;
  obj->front = (obj->front+1) % obj->capital;
  obj->size--;
  return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj)) return -1;
  return obj->data[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj)) return -1;
  return obj->data[(obj->rear - 1 + obj->capital) % obj->capital];
}

void myCircularQueueFree(MyCircularQueue* obj) {
	if(!obj) return;
    free(obj->data);
	free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/