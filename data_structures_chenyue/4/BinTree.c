#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    // MinP = FindMin(BST);
    // MaxP = FindMax(BST);
    // scanf("%d", &N);
    // for( i=0; i<N; i++ ) {
    //     scanf("%d", &X);
    //     Tmp = Find(BST, X);
    //     if (Tmp == NULL) printf("%d is not found\n", X);
    //     else {
    //         printf("%d is found\n", Tmp->Data);
    //         if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
    //         if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
    //     }
    // }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */

BinTree Insert( BinTree BST, ElementType X )
{
	BinTree x, y;
	x = y = BST;
	while(x != NULL){
		y = x;
		if(x->Data > X)
			x = x->Left;
		else x = x->Right;
	}
	Position node = malloc(sizeof(struct TNode));
	node->Data = X;
	node->Left = NULL;
	node->Right = NULL;
	if(y == NULL)
		BST = node;
	else if (y->Data > X)
		y->Left = node;
	else y->Right = node;
	return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
	Position Tmp;
	if(!BST) return NULL;
	if (BST->Data > X) {
		BST->Left = Delete(BST->Left, X);
	} else if (BST->Data < X) {
		BST->Right = Delete(BST->Right, X);
	} else {
		if (BST->Left && BST->Right) {
			Tmp = FindMin(BST->Right);
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Right, BST->Data);
		} else {
			Tmp = BST;
			if (!BST->Left)
				BST = BST->Right;
			else if (!BST->Left)
				BST = BST->Left;
			free(Tmp);
		}
	}
	return BST;
}

Position Find( BinTree BST, ElementType X )
{
	Position x = BST;
	while (x != NULL && x->Data != X)
	{
		if(x->Data > X)
			x = x->Left;
		else x = x->Right;
	}
	return x;
}

Position FindMin( BinTree BST )
{
	Position x = BST;
	while (x->Left != NULL)
	{
		x = x->Left;
	}
	return x;
}

Position FindMax( BinTree BST )
{
	Position x = BST;
	while (x->Right != NULL)
	{
		x = x->Right;
	}
	return x;
}

void PreorderTraversal( BinTree BT ) /* 先序遍历，由裁判实现，细节不表 */
{
	if(BT == NULL) return;
	printf("%d ", BT->Data);
	PreorderTraversal(BT->Left);
	PreorderTraversal(BT->Right);
}

void InorderTraversal( BinTree BT )  /* 中序遍历，由裁判实现，细节不表 */
{
	if(BT == NULL) return;
	PreorderTraversal(BT->Left);
	printf("%d ", BT->Data);
	PreorderTraversal(BT->Right);
}