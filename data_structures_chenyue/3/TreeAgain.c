#include <stdio.h>
#include <string.h>
#define MAXSIZE 51
typedef char ElementType;
ElementType PreOrder[MAXSIZE], InOrder[MAXSIZE];

int PostOrderByOrders(int preL, int inL, int length, int deepth);

int main()
{
	int length, deepth;
	scanf("%d ", &length);
	scanf("%s ", PreOrder);
	scanf("%s ", InOrder);
	// printf("%s %s", PreOrder, InOrder);
	deepth = PostOrderByOrders(0, 0, length, 1);

	printf("%d", deepth);
	return 0;
}

int PostOrderByOrders(int preL, int inL, int length, int deepth)
{
	if(length == 0) return deepth;
	if(length == 1) {return deepth++;}
	int root =  PreOrder[preL];
	int i, L, R;
	for(i=0; i<length; i++)
		if (InOrder[inL+i] == root) break;
	L = i;
	R = length-i-1;
	//left
	int left, right;
	left =  PostOrderByOrders(preL+1, inL, L, deepth+1);
	//right
	right = PostOrderByOrders(preL+L+1, inL+L+1, R, deepth+1);
	return left > right ? left : right;
}

