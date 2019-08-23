#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef char ElementType[12];
#define MAXSIZE 1000000
#define MINTABLESIZE 11

//分离链接法
typedef struct ListNode *Position, *List;
struct ListNode
{
	ElementType Element;
	int Count;
	Position Next;
};

typedef struct HashTbl *HashTable;
struct HashTbl{
	int TableSize;
	List TheLists;
};

HashTable CreateHashTbl(int N);
Position Find(ElementType Key, HashTable H);
int Hash(ElementType Key, int TableSize);
void InsertAndCount(ElementType Key, HashTable H);
void Show(HashTable H);
int NextPrime( int N );

int main()
{
	int N;
	char Phone[12];
	scanf("%d", &N);
	HashTable H = CreateHashTbl(N);
	for (int i=0; i<2*N; i++) {
		scanf("%s", Phone);
		InsertAndCount(Phone, H);
	}
	Show(H);
	return 0;
}

HashTable CreateHashTbl(int N)
{
	HashTable H = (HashTable) malloc(sizeof(struct HashTbl));
	if (H == NULL) {
		fprintf(stderr, "alloc HashTable fail.\n");
		exit(1);
	}
	H->TableSize = NextPrime(N);
	H->TheLists = (List) malloc(H->TableSize * sizeof(struct ListNode));
	if (H->TheLists == NULL) {
		fprintf(stderr, "alloc Table List fail.\n");
		exit(1);
	}
	for (int i=0; i<H->TableSize; i++)
		H->TheLists[i].Next = NULL;
	return H;
}

Position Find(ElementType Key, HashTable H)
{
	Position P;
	int Pos;
	Pos = Hash(Key, H->TableSize);
	P = H->TheLists[Pos].Next;
	while(P && strcmp(P->Element, Key))
		P = P->Next;
	return P;
}

int Hash(ElementType Key, int TableSize)
{
	char sub_phone[6];
	strncpy(sub_phone, Key+6, 5);
	int temp = atoi(sub_phone);
	return temp % TableSize;
}

void InsertAndCount(ElementType Key, HashTable H)
{
	Position P;
	P = Find(Key, H);
	if (P){
		P->Count++;
	} else {
		List node = (List)malloc(sizeof(struct ListNode));
		if (!node) {
			fprintf(stderr, "alloc memory fail.\n");
		}
		strcpy(node->Element, Key);
		node->Count   = 1;
		int pos = Hash(Key, H->TableSize);
		node->Next = H->TheLists[pos].Next;
		H->TheLists[pos].Next = node;
	}
}

void Show(HashTable H)
{
	Position P, Current;
	P = (Position)malloc(sizeof(struct ListNode));
	P->Count = 0;
	P->Element[0] = '\0';
	P->Next = NULL;

	int Total[MAXSIZE]; //并列人数
	for (int i=0; i<H->TableSize; i++) {
		Current = H->TheLists[i].Next;
		while(Current!=NULL) {
			if (Current->Count > P->Count) {
				P = Current;
				Total[Current->Count] = 1;
			} else if (Current->Count == P->Count) {
				Total[Current->Count]++;
				if(strcmp(Current->Element, P->Element) < 0) {
					P = Current;
				}
			}
			Current = Current->Next;
		}
	}

	if(P->Count > 0) {
		printf("%s %d", P->Element, P->Count);
		if(Total[P->Count] > 1)
			printf(" %d", Total[P->Count]);
	}
}

int NextPrime( int N )
{ /*  返回大于N 且不超过MAXTABLESIZE数 的最小素数 */
	int i, p = (N%2)? N+2 : N+1; /* 从大于N始 的下一个奇数开始 */
	while( p <= MAXSIZE ) {
		for( i=(int)sqrt(p); i>2; i-- )
			if ( !(p%i) ) break; /* p数 不是素数 */
			if ( i==2 ) break; /* for 正常结束，说明p数 是素数 */
			else p += 2; /* 数 否则试探下一个奇数 */
	}
	return p;
}