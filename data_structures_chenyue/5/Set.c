typedef int ElementType;

typedef struct {
	ElementType Data;
	int Parent;
}SetType;

#define MaxSize 100

int Find(SetType S[], ElementType X)
{
	int i;
	for (i=0; i < MaxSize && S[i].Data != X; i++);
	if (i > MaxSize) return -1;
	for (; S[i].Parent >= 0; i = S[i].Parent);
	return i;
}

//并
void Union(SetType S[ ], ElementType X1, ElementType X2)
{
	int Root1, Root2;
	Root1 = Find(S, X1);
	Root2 = Find(S, X2);
	if(Root1 != Root2) S[Root2].Parent = Root1;
}

//交

//补

//差

//todo
int Size(SetType S[])
{
	int i = 0;

}