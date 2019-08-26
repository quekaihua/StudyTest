#include <stdio.h>
#include <stdlib.h>

typedef struct node *Node;
typedef struct list *List;

struct list {
	Node head;
	int length;
};

struct node {
	int data;
	int address;
	int next;
	Node PreNode, NextNode;
};

#define MAXSIZE 100001
// #define MAXSIZE 10
Node nodes[MAXSIZE];
int list[MAXSIZE];

List BuildList(int begin, Node nodes[], int n, List L);
void ReservingLinkedList(List L, int k);
Node Find(Node head, int n);
void Travel(List L);

int main()
{
	int begin, n, k;
	scanf("%d %d %d", &begin, &n, &k);
	Node ele;
	for(int i=1; i<=n; i++){
		ele = malloc(sizeof(struct node));
		ele->NextNode = NULL;
		ele->PreNode  = NULL;
		scanf("%d %d %d", &ele->address, &ele->data, &ele->next);
		nodes[i] = ele;
	}
	List L = (List)malloc(sizeof(struct list));
	L->length = 0;
	L->head = NULL;

	L = BuildList(begin, nodes, n, L);
	ReservingLinkedList(L, k);
	Travel(L);

	return 0;
}

List BuildList(int begin, Node nodes[], int n, List L)
{
	Node current, next;
	int i, j;
	for (i=1; i<= n; i++) {
		for (j=1; j<=n; j++) {
			current = nodes[i];
			next = nodes[j];
			if(current->next == next->address) {
				current->NextNode = next;
				next->PreNode = current;
				L->length++;
			}
			if(current->address == begin) {
				L->head = current;
			}
		}
	}
	L->length++; //连接两个节点只加了一次，所以这里需要加上1
	return L;
}

void ReservingLinkedList(List L, int k)
{
	Node current, first, last, temp, first_temp, last_temp;
	int size;
	size = L->length;
	int rnum = 1;
	while(size >= k && k > 1) {
		current = Find(L->head, k*rnum-1);
		for(int i=k; i>0; i--) {
			//首部
			if(i==k) {
				first = current;
				first_temp = (Node)malloc(sizeof(struct node));
				first_temp->PreNode  = current->PreNode;
				first_temp->NextNode = current->NextNode;
			} else if(i==1) {  //尾部
				if (L->head == current)
					L->head = first;
				last = current;
				last_temp = (Node)malloc(sizeof(struct node));
				last_temp->PreNode  = current->PreNode;
				last_temp->NextNode = current->NextNode;
			}
			temp = current->NextNode;
			current->NextNode = current->PreNode;
			current->next = current->NextNode ? current->NextNode->address : -1;
			current->PreNode = temp;
			current = current->NextNode;
		}
		
		first->PreNode = last_temp->PreNode;
		last->NextNode = first_temp->NextNode;
		last->next = last->NextNode ? last->NextNode->address : -1;
		if (last_temp->PreNode) {
			last_temp->PreNode->NextNode = first;
			last_temp->PreNode->next     = first ? first->address : -1;
		}
		if (first_temp->NextNode) {
			first_temp->NextNode->PreNode = last;
		}
		free(first_temp);
		free(last_temp);
		size = size - k;
		rnum++;
	}
}

//寻找相对head节点后第n个节点
Node Find(Node head, int n)
{
	Node current = head;
	while(n > 0) {
		current = current->NextNode;
		n--;
	}
	return current;
}

void Travel(List L)
{
	Node current = L->head;
	while(current) {
		printf("%05d %d ", current->address, current->data);
		current->next == -1 ? printf("%d\n", current->next) :
			printf("%05d\n", current->next);
		current = current->NextNode;
	}
}
