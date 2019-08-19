#include <stdio.h>
#include <stdlib.h>

typedef struct node *Node;

struct node {
	int data;
	int address;
	int next;
};

#define MAXSIZE 100001
Node nodes[MAXSIZE];
int list[MAXSIZE];

void BuildList(int begin, Node nodes[], int n);
void ReservingLinkedList(int list[], int n, int k);

int main()
{
	int begin, n, k;
	scanf("%d %d %d", &begin, &n, &k);
	Node ele;
	for(int i=1; i<=n; i++){
		ele = malloc(sizeof(struct node));
		scanf("%d %d %d", &ele->address, &ele->data, &ele->next);
		nodes[i] = ele;
	}
	BuildList(begin, nodes, n);
	ReservingLinkedList(list, n, k);

	int data, j;
	Node p;
	for (int i=1; i<=n; i++){
		data = list[i];
		//find the node
		for (j=1; j<= n; j++) {
			p = nodes[j];
			if(p->data == data) break;
		}
		printf("%05d %d ", p->address, p->data);
		p->next == -1 ? printf("%d\n", p->next) :
			printf("%05d\n", p->next);
	}

	return 0;
}

void BuildList(int begin, Node nodes[], int n)
{
	Node p;
	int i, j;
	for (i=1; i<= n; i++) {
		p = nodes[i];
		if(p->address == begin) break;
	}
	list[i] = p->data;
	for (i=1; i<=n; i++){
		for (j=1; j<= n; j++) {
			p = nodes[j];
			if(p->address == begin) break;
		}
		list[i] = p->data;
		begin = p->next;
	}
}

void ReservingLinkedList(int list[], int n, int k)
{
	int temp, j, l;
	// for (int v = 1; v<=n; v++) printf("%d", list[v]);
	for (int i=1; i<=n; i=i+k) {
		if(i+k-1 > n) break;
		for(j = i, l=i+k-1; j<l; j++, l--){
			temp = list[j];
			list[j] = list[l];
			list[l] = temp;
		}
	}
	// for (int v = 1; v<=n; v++) printf("%d", list[v]);

	int data;
	Node current, next, p;
	for (int i=1; i<=n; i++) {
		data = list[i];
		//find the node
		for (j=1; j<= n; j++) {
			p = nodes[j];
			if(p->data == data) break;
		}
		current = p;
		if (i == n) {
			current->next = -1;
		} else {
			//find next node
			data = list[i+1];
			for (j=1; j<= n; j++) {
				p = nodes[j];
				if(p->data == data) break;
			}
			next = p;
			current->next = next->address;
		}
	}
}
