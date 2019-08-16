#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElementType int

typedef struct node * Tree;
struct node {
	ElementType data;
	Tree left, right;
};

Tree tree_insert(Tree t, Tree z);
bool tree_travel_compare(Tree t1, Tree t2);
Tree node_create(ElementType element);
void free_tree(Tree t);

int main()
{
	int n, group;
	int value;
	while(scanf("%d", &n)){
		if(n == 0) break;
		scanf("%d", &group);
		Tree t1 = NULL;
		for(int j=0; j<n; j++){
			scanf("%d", &value);
			Tree node = node_create(value);
			t1= tree_insert(t1, node);
		}
		for(int i=0; i<group; i++){
			Tree t2 = NULL;
			for(int j=0; j<n; j++){
				scanf("%d", &value);
				Tree node = node_create(value);
				t2 = tree_insert(t2, node);
			}
			bool flag = tree_travel_compare(t1, t2);
			free_tree(t2);
			flag ? printf("YES\n") : printf("No\n");
		}
		free_tree(t1);
	}
	return 0;
}

Tree tree_insert(Tree t, Tree z)
{
	Tree y, x;
	x = y = t;
	while (x != NULL){
		y = x;
		if (z->data < x->data)
			x = x->left;
		else x = x->right;
	}
	if (y == NULL)
		t = z;
	else if (z->data < y->data)
		y->left = z;
	else y->right = z;
	return t;
}

bool tree_travel_compare(Tree t1, Tree t2)
{
	if (t1 == NULL && t2 == NULL) return true;
	if ((t1 == NULL && t2 != NULL) ||
		(t1 != NULL && t2 == NULL)) return false;
	if (t1->data != t2->data) return false;
	return (tree_travel_compare(t1->left, t2->left) &&
	tree_travel_compare(t1->right, t2->right));
}

Tree node_create(ElementType element)
{
	Tree node = malloc(sizeof(struct node));
	node->data = element;
	node->left = node->right = NULL;
	return node;
}

void free_tree(Tree t)
{
	if(t != NULL){
		free_tree(t->left);
		free_tree(t->right);
	}
	free(t);
}