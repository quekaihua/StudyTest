#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput() /* 裁判实现，细节不表。元素从下标1开始存储 */
{
	int n;
	scanf("%d", &n);
	List L = malloc(sizeof(struct LNode));
	// L->Data = malloc(sizeof(ElementType) * MAXSIZE);
	L->Last = n;
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &L->Data[i]);
	}
	return L;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X )
{
	Position left, right, mid;
	int length;
	left = 1;
	right = L->Last;
	for (int mid=(right - left + 1) / 2 + left; left <= right; mid = (right - left + 1) / 2 + left) {
		if(L->Data[mid] < X)
			left = mid + 1;
		else if (L->Data[mid] > X) {
			right = mid - 1;
		} else return mid;
	}
	return NotFound;
}