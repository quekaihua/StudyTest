#include <stdio.h>
#include <math.h>

#define MAXSIZE 100000

int Table[MAXSIZE];
typedef int Position, ElementType;
int N, M;

Position Hash(ElementType Key, int TableSize);
Position Find(ElementType Key, int TableSize);
void InsertTable(int TableSize);
void InitialTable(int TableSize);

int IsPrime ( int n );
int NextPrime(int M);

int main()
{
	scanf("%d %d", &M, &N);
	int TableSize;
	if(IsPrime(M)) TableSize = M;
	else
		TableSize = NextPrime(M);
	// printf("%d", TableSize);
	InitialTable(TableSize);
	InsertTable(TableSize);
	return 0;
}

void InitialTable(int N)
{
	for (int i=0; i<N; i++) 
		Table[N] = 0;
}

void InsertTable(int TableSize)
{	
	int Key;
	for (int i=0; i<N; i++) {
		scanf("%d", &Key);
		Position pos = Find(Key, TableSize);
		if(pos == -1)
			printf("-");
		else {
			printf("%d", pos);
			Table[pos] = Key;
		}

		if(i != N-1)
			printf(" ");
	}
}

Position Hash(ElementType Key, int TableSize)
{
	return Key % TableSize;
}

Position Find(ElementType Key, int TableSize)
{
	// Position NewPos,CurrentPos;
	// int CNum = 0;  // 记录冲突次数 
	// CurrentPos = NewPos = Hash(Key, TableSize);
	// printf("newpos=%d\n", NewPos);
	// // 如果当前状态不为空，且一直不等，一直做 
	// while(Table[NewPos] && Table[NewPos] != Key){
	// 	printf("newpos=%d\n", NewPos);
	// 	CNum++;
	// 	NewPos = (CurrentPos + CNum*CNum) % TableSize;
	// 	if(CNum == TableSize/2) // 没找到
	// 		return -1;
	// }
	// return NewPos;

	Position pos = Hash(Key, TableSize);
	Position current = pos;
	int cnum = 1;  //冲突次数
	// while(Table[pos] != 0){
	// 	pos = Hash(pos + cnum*cnum, TableSize);
	// 	if (cnum > TableSize){
	// 		return -1;
	// 	}
	// 	cnum++;
	// }
	while ( cnum < TableSize ) {  //k>=size后，平方探测将进入一个死循环
			if ( Table[pos] == 0 ) { //如果该位置没有元素
				return pos;
			}
			else { //该位置有元素，使用平方探测法解决冲突
				pos = ( current + cnum*cnum ) % TableSize;
				cnum++;
			}
	}
	return -1;
	// if(cnum == TableSize) 
	// 	printf("-");
	// return 0;
}

int NextPrime ( int N )
{
	if ( N == 1 ) //1既不是素数，也不是合数； 2是素数
		return 2;
	int i, p = ( N % 2 ) ? N + 2 : N + 1;
	while (1) {
		double q = p;
		for ( i = sqrt(q); i > 2; i-- )
			if ( !( p % i ) ) break;
		if ( i == 2 ) return p;
		else p += 2;
	}
}

int IsPrime ( int n )
{
	if ( n == 1 ) 
		return 0;
	else if ( n == 2 )
		return 1;
	else {
		int k = sqrt(n);
		for ( int i = 2; i <= k; i++ )
			if ( n % i == 0 )
				return 0;
		return 1;
	}
}