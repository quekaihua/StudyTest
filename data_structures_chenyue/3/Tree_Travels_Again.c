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


void PostOrderByOrders(int *InOrder, int *PreOrder, int length);
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
	PostOrderByOrders(InOrder, PreOrder, length);
	for(int i=0; i<cnt; i++){
		if (i==cnt-1) {
			printf("%d", result[i]);
		} else {
			printf("%d ", result[i]);
		}
	}
	return 0;
}

void PostOrderByOrders(int * InOrder, int * PreOrder, int length)
{
	if(length<1) return;
	int i;
	int * orgIn;
	orgIn = InOrder;
	for(i=0; i<length; i++){
		if (*InOrder == *PreOrder) break;
		InOrder++;
	}
	//left
	PostOrderByOrders(orgIn, PreOrder+1, i);
	//right
	PostOrderByOrders(orgIn+i+1, PreOrder+1+i, length-i-1);
	result[cnt++] = *InOrder;
}

Stack InitialStack()
{
	Stack s = malloc(sizeof(struct stack));
	if(s==NULL)
		exit(1);
	s->size = 0;
	s->top = NULL;
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