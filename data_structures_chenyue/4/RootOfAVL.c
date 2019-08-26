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
int Height(BinTree BST);  //获取树的高度
BinTree FixTree(BinTree BST);

int main() {
    BinTree BST = NULL;
    int X, N;
    scanf("%d", &N);
    for (int i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
	if(BST) printf("%d", BST->Data);
}

BinTree Insert( BinTree BST, ElementType X )
{
	if(BST == NULL) {
		Position node = malloc(sizeof(struct TNode));
		node->Data = X;
		node->Left = NULL;
		node->Right = NULL;
		return node;
	} else {
		if(X > BST->Data) {
			BST->Right = Insert(BST->Right, X);
			int HL, HR;
			HL = Height(BST->Left);
			HR = Height(BST->Right);
			if(HL-HR > 1 || HR-HL > 1) {
				if(X > BST->Right->Data) {
					return RR(BST);
				} else {
					return RL(BST);
				}
			}
		}else {
			BST->Left = Insert(BST->Left, X);
			int HL, HR;
			HL = Height(BST->Left);
			HR = Height(BST->Right);
			if(HL-HR > 1 || HR-HL > 1) {
				if(X > BST->Left->Data) {
					return LR(BST);
				} else {
					return LL(BST);
				}
			}
		}
		return BST;
	}
}

BinTree RR(BinTree BST)  //发现者的右子树的右子树
{
	BinTree Source = BST;

	BST = BST->Right;
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
	BST->Left = RR(BST->Left);
	return LL(BST);
}

BinTree RL(BinTree BST)  //发现者的右子树的左子树
{
	BST->Right = LL(BST->Right);
	return RR(BST);
}

int Height(BinTree BST)
{
	if (BST) {
		int HL, HR, max;
		HL = Height(BST->Left);
		HR = Height(BST->Right);
		max = HL > HR ? HL : HR;
		return max + 1;
	} else {
		return 0;
	}
}