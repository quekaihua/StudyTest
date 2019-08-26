#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 30
typedef int ElementType;
// int InOrder[MAXSIZE], PreOrder[MAXSIZE];
int PreOrder[MAXSIZE], InOrder[MAXSIZE], result[MAXSIZE];
int cnt=0;
typedef struct node * Node;
struct node {
	ElementType data;
	Node next;
};

struct stack {
	int size;
	Node top;
};

typedef struct stack* Stack;
Stack InitialStack();
void push(Stack s, ElementType data);
ElementType pop(Stack s);


void PostOrderByOrders(int preL, int inL, int PostRoot, int length);

int main()
{
	int length;
	scanf("%d", &length);
	Stack S = InitialStack();
	int j =0, k = 0;
	for(int i=0; i<length*2; i++)
	{
		char command[10];
		scanf("%s", command);
		char *ptr = "Push";
		if(strcmp(command, ptr) == 0){
			int number;
			scanf("%d", &number);
			push(S, number);
			PreOrder[k++] = number;
		} else {
			InOrder[j++] = pop(S);
		}
	}
	PostOrderByOrders(0, 0, 0, length);

	for(int i=0; i<length; i++){
		if (i==length-1) {
			printf("%d", result[i]);
		} else {
			printf("%d ", result[i]);
		}
	}
	return 0;
}

void PostOrderByOrders(int preL, int inL, int PostL, int length)
{
	if(length == 0) return;
	if(length == 1) {result[PostL] = PreOrder[preL]; return;}
	int root = PreOrder[preL];
	result[PostL+length-1] = root;
	int i, L, R;
	for(i=0; i<length; i++)
		if (InOrder[inL+i] == root) break;
	L = i;
	R = length-i-1;
	//left
	PostOrderByOrders(preL+1, inL, PostL, L);
	//right
	PostOrderByOrders(preL+L+1, inL+L+1, PostL+L, R);
}

Stack InitialStack()
{
	Stack s = malloc(sizeof(struct stack));
	if(s==NULL)
		exit(1);
	s->size = 0;
	s->top = NULL;
	return s;
}

void push(Stack s, ElementType data)
{
	Node n;
	n = malloc(sizeof(struct node));
	if(n==NULL)
		exit(1);
	n->data = data;
	n->next = s->top;

	s->top = n;
	s->size++;
}

ElementType pop(Stack s)
{
	if(s->size == 0)
		exit(1);
	Node n = s->top;
	ElementType data = n->data;
	s->top = s->top->next;
	free(n);
	return data;
}