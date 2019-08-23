#include<stdbool.h>
#include <stdlib.h>
typedef int ElementType;
typedef char* NameType;
typedef int AttributeType;
typedef int SymbolTable;
typedef int Index, Cell;

typedef struct HashTbl1 *HashTable1;

#define Deleted -1
#define Empty 0
#define Legitimate 1
#define MinTableSize 10

struct HashTbl1{
	int TableSize;
	Cell *TheCells;
};


SymbolTable InitializeTable(int TableSize);
bool IsIn(SymbolTable Table, NameType Name);
AttributeType Find_1(SymbolTable Table, NameType Name);
SymbolTable Modefy(SymbolTable Table, NameType Name, AttributeType Attr);
SymbolTable Insert_1(SymbolTable Table, NameType Name, AttributeType Attr);
SymbolTable Delete(SymbolTable Table, NameType Name);

Index Hash(const char *Key, int TableSize)
{
	unsigned int h = 0;
	while(*Key != '\0')
		h = (h<<5) + *Key++; //左移5位 == *32
	return h % TableSize;
}

//平方探测
/* 
HashTable InitializeTable_1(int TableSize)
{
	HashTable1 H;
	int i;
	if (TableSize < MinTableSize) {
		return NULL;
	}

	H = (HashTable)malloc(sizeof(struct HashTbl));
	if(H == NULL)
		return NULL;
	H->TableSize = NextPrime(TableSize);
	H->TheCells = (Cell *)malloc(sizeof(Cell)*H->TableSize);
	if(H->TheCells == NULL)
		FatalError("空间溢出");
	for(i=0; i<H->TableSize; i++)
		H->TheCells[i].Info = Empty;
	return H;
}

Position Find(ElementType Key, HashTable H)
{
	Position CurrentPos, NewPos;
	int CNum;
	CNum = 0;
	NewPos = CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[NewPos].Info != Empty &&
		H->TheCells[NewPos].Element != Key) {
		if (++CNum % 2) {
			NewPos = CurrentPos + (CNum+1)/2*(CNum+1)/2;
			while (NewPos >= H->TableSize)
				NewPos -= H->TableSize;
		} else {
			NewPos = CurrentPos - CNum/2*CNum/2;
			while(NewPos < 0)
				NewPos += H->TableSize;
		}
	}
	return NewPos;
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos;
	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate) {
		H->TheCells[Pos].Info = Legitimate;  //Deleted
		H->TheCells[Pos].Element = Key;
	}
}
*/

//分离链接法
typedef struct ListNode *Position, *List;
struct ListNode
{
	ElementType Element;
	Position Next;
};
typedef struct HashTbl *HashTable;
struct HashTbl{
	int TableSize;
	List TheLists;
};

Position Find(ElementType Key, HashTable H)
{
	Position P;
	int Pos;
	Pos = Hash(Key, H->TableSize);
	P = H->TheLists[Pos].Next;
	while(P!=NULL && strcmp(P->Element,Key))
		P = P->Next;
	return P;
}
