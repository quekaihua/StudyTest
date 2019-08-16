#include <stdio.h>
typedef struct TreeNode *Tree;
struct TreeNode{
	int v;
	Tree Left, Right;
	int flag;
};

Tree MakeTree(int N);
int Judge()
int main()
{
	int N, L, i;
	Tree T;
	scanf("%d", &N);
	while(N){
		scanf("%d", &L);
		T = MakeTree(N);
		for(i=0; i<L;i++){
			if(Judge(T,N)) printf("Yes\n");
			else printf("No\n");
			ResetT(T);
		}
		FreeTree(T);
		scanf("%d", &N);
	}

	return 0;
}
