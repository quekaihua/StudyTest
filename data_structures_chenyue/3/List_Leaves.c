#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 11
#define ElementType int
#define Tree int
#define Null -1

struct TreeNode {
	ElementType data;
	Tree left, right;
}T[MAXSIZE];

Tree build_tree(struct TreeNode tree[]);
bool is_leaves(struct TreeNode node);
void list_leaves(Tree t);

struct queue {
	int data[MAXSIZE];
	int front, rear, size;
};

typedef struct queue* Queue;

void InitializeQueue(Queue q);
ElementType dequeue(Queue q);
bool enqueue(Queue q, ElementType element);
bool QueueIsFull(const Queue q);
bool QueueIsEmpty(const Queue q);

int main()
{
	Tree r;
	r = build_tree(T);
	list_leaves(r);
	return 0;
}

Tree build_tree(struct TreeNode tree[])
{
	int n, i, check[MAXSIZE];
	char lc, rc;
	scanf("%d\n", &n);
	Tree r;
	if(n){
		for(i=0; i<n; i++) check[i] = 0;
		for(i=0; i<n; i++) {
			scanf("%c %c\n", &lc, &rc);
			T[i].data = i;
			if (lc != '-') {
				T[i].left = lc - '0';
				check[T[i].left] = 1;
			} else T[i].left = Null;
			if (rc != '-') {
				T[i].right = rc - '0';
				check[T[i].right] = 1;
			} else T[i].right = Null;
		}
	}
	for(i=0; i<n; i++)
		if(!check[i]) break;
	r = i;
	return r;
}

void list_leaves(Tree t)
{
	Queue q, p;
	q = (Queue)malloc(sizeof(struct queue));
    p = (Queue)malloc(sizeof(struct queue));
	InitializeQueue(q);
    InitializeQueue(p);
	enqueue(q, t);
    int cnt = 0;
	while(!QueueIsEmpty(q))
	{
		Tree node;
		node = dequeue(q);
		if (is_leaves(T[node])) {
			enqueue(p, T[node].data);
			cnt++;
		}
		if(T[node].left != Null)
			enqueue(q, T[node].left);
		if(T[node].right != Null)
			enqueue(q, T[node].right);
	}
	for(int i=0; i<cnt; i++){
		if (i==cnt-1)
			printf("%d",dequeue(p));
		else printf("%d ", dequeue(p));
	}
}

bool is_leaves(struct TreeNode node)
{
	return node.left == Null && node.right == Null;
}

ElementType dequeue(Queue q)
{
	if(QueueIsEmpty(q)){
		exit(1);
	}
	ElementType temp;
	temp = q->data[q->front];
	q->front = q->front+1==MAXSIZE ? 0 : q->front+1;
	q->size--;
	return temp;
}

void InitializeQueue(Queue q)
{
	q->front = q->rear = q->size = 0;
}

bool enqueue(Queue q, ElementType element)
{
	if(QueueIsFull(q)){
		return false;
	}
	q->data[q->rear] = element;
	q->rear = q->rear+1==MAXSIZE ? 0 : q->rear+1;
	q->size++;
	return true;
}

bool QueueIsEmpty(const Queue q)
{
	return q->size == 0;
}

bool QueueIsFull(const Queue q)
{
	return q->size == MAXSIZE;
}
