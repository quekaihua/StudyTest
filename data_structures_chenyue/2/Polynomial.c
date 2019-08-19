#include <stdio.h>
#include <stdlib.h>

typedef struct node *Polynimial;

struct node {
	int modulus, exponent;
	Polynimial next;
};

Polynimial CreatePolynomial();
Polynimial Insert(Polynimial head, int modulus, int exponent);
Polynimial AddPolynomial(Polynimial p1, Polynimial p2);
Polynimial MultifyPolynomial(Polynimial p1, Polynimial p2);
void TravelPolynomial(Polynimial p);

int main()
{
	Polynimial p1, p2, p3, p4;
	p1 = CreatePolynomial();
	p2 = CreatePolynomial();
	
	p4 = AddPolynomial(p1, p2);
	p3 = MultifyPolynomial(p1, p2);
	TravelPolynomial(p3);
	TravelPolynomial(p4);
}

Polynimial CreatePolynomial()
{
	int n;
	scanf("%d", &n);
	Polynimial head = NULL;
	int modulus, exponent;
	for(int i=0; i<n; i++){
		scanf("%d %d", &modulus, &exponent);
		head = Insert(head, modulus, exponent);
	}
	return head;
}

Polynimial Insert(Polynimial head, int modulus, int exponent)
{
	Polynimial x = malloc(sizeof(struct node));
	x->next		 = NULL;
	x->modulus	 = modulus;
	x->exponent  = exponent;
	if (!head) head = x;
	else {
		Polynimial end = head;
		while(end->next) end = end->next;
		end->next = x;
	}
	return head;
}

Polynimial AddPolynomial(Polynimial p1, Polynimial p2)
{
	Polynimial result = NULL;
	while(p1 && p2) {
		if(p1->exponent == p2->exponent && p1->modulus+p2->modulus == 0) {
			p1 = p1->next;
			p2 = p2->next;
		} else if(p1->exponent == p2->exponent) {
			result = Insert(result, p1->modulus+p2->modulus, p1->exponent);
			p1 = p1->next;
			p2 = p2->next;
		} else if(p1->exponent > p2->exponent) {
			result = Insert(result, p1->modulus, p1->exponent);
			p1 = p1->next;
		} else {
			result = Insert(result, p2->modulus, p2->exponent);
			p2 = p2->next;
		}
	}

	while(p1) {
		result = Insert(result, p1->modulus, p1->exponent);
		p1 = p1->next;
	}
	while(p2){
		result = Insert(result, p2->modulus, p2->exponent);
		p2 = p2->next;
	}
	return result;
}

Polynimial MultifyPolynomial(Polynimial p1, Polynimial p2)
{
	Polynimial result = NULL, temp, current;
	while(p1 && p2){
		current = p1;
		temp=NULL;
		while(current){
			temp = Insert(temp, current->modulus*p2->modulus, current->exponent+p2->exponent);
			current = current->next;
		}
		result = AddPolynomial(result, temp);
		p2 = p2->next;
	}
	return result;
}

void TravelPolynomial(Polynimial p)
{
	if(!p) {
		printf("%d %d\n", 0, 0);
	}
	while(p){
		if(p->next)
			printf("%d %d ", p->modulus, p->exponent);
		else
			printf("%d %d\n", p->modulus, p->exponent);
		p = p->next;
	}
}