#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 11
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode {
	ElementType data;
	Tree left, right;
}T1[MAXSIZE], T2[MAXSIZE];

Tree build_tree(struct TreeNode tree[]);
bool IsSameTrees(Tree r1, Tree r2);

int main()
{
	Tree R1, R2;
	R1 = build_tree(T1);
	R2 = build_tree(T2);
	bool flag;
	flag = IsSameTrees(R1, R2);
	flag ? printf("YES\n") : printf("NO\n");

	return 0;
}

Tree build_tree(struct TreeNode T[])
{
	int n, i;
	int check[MAXSIZE];
	char cl, cr;
	Tree root = Null;
	scanf("%d", &n);
	if(n){
		for (i = 0; i < n; i++) check[i] = 0;
		for(i=0; i < n; i++){
			fflush(stdin); 
			scanf("%c %c %c", &T[i].data, &cl, &cr);
			if (cl != '-'){
				T[i].left = cl - '0';
				check[T[i].left] = 1;
			} else T[i].left = Null;
			if (cr != '-'){
				T[i].right = cr - '0';
				check[T[i].right] = 1;
			} else T[i].right = Null;
		}
		for(i=0; i < n; i++)
			if(!check[i]) break;
		root = i;
	}
	return root;
}

bool IsSameTrees(Tree r1, Tree r2)
{
	if (r1==Null && r2==Null)
		return true;
	if ((r1==Null && r2!=Null) || (r1!=Null && r2==Null))
		return false;
	if (T1[r1].data != T2[r2].data)
		return false;
	if (T1[r1].left==Null && T2[r2].left==Null)
		return IsSameTrees(T1[r1].right, T2[r2].right);
	if ((T1[r1].left!=Null && T2[r2].left!=Null) &&
		(T1[T1[r1].left].data==T2[T2[r2].left].data))
			return (IsSameTrees(T1[r1].left, T2[r2].left) &&
					IsSameTrees(T1[r1].right, T2[r2].right));
	else
			return (IsSameTrees(T1[r1].left, T2[r2].right) &&
					IsSameTrees(T1[r1].right, T2[r2].left));
}