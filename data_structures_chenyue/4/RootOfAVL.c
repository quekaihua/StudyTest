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

BinTree Insert( BinTree BST, ElementType X );
BinTree RR(BinTree BST);  //发现者的右子树的右子树
BinTree LL(BinTree BST);  //发现者的左子树的左子树
BinTree LR(BinTree BST);  //发现者的左子树的右子树
BinTree RL(BinTree BST);  //发现者的右子树的左子树

int main() {
    BinTree BST = NULL;
    int X, N;
    scanf("%d", &N);
    for (int i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
}

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

BinTree RR(BinTree BST)  //发现者的右子树的右子树
{
	BinTree Source = BST;
    BST = BST->Left;
	Source->Right = BST->Left;
	BST->Left = Source;
	return BST;
}

BinTree LL(BinTree BST)  //发现者的左子树的左子树
{
	BinTree Source = BST;
	BST = BST->Left;
	Source->Left = BST->Right;
	BST->Right = Source;
	return BST;
}

BinTree LR(BinTree BST)  //发现者的左子树的右子树
{
	BinTree Root, Tmp, Source = BST;
	Root = BST->Left->Right;
	Tmp = Root;
	Root->Right = Source;
	Root->Left = Source->Left;
	Source->Left = NULL;
	Root->Left->Right = Tmp->Right ? Tmp->Right : Root->Left;
	return Root;
}

BinTree RL(BinTree BST)  //发现者的右子树的左子树
{
	BinTree Root, Tmp, Source = BST;
	Root = BST->Right->Left;
	Tmp = Root;
	Root->Left = Source;
	Root->Right = Source->Right;
	Source->Right = NULL;
	Root->Right->Left = Tmp->Right ? Tmp->Right : Root->Left;
	return Root;
}
