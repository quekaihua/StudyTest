#include <stdio.h>
#include <math.h>

#define MAXSIZE 1000
// int Table[MAXSIZE];
int Table[11] = {33, 1, 13, 12, 34, 38, 27, 22, 32, -1, 21};
int Table_2[MAXSIZE];
int Visited[MAXSIZE];
int result[MAXSIZE];

typedef int Position, ElementType;
int N;

Position Find(ElementType Key, int TableSize);
void InsertTable(int TableSize);
void InitialTable(int TableSize);
void InitialVisited(int TableSize);
int CheckFull(int TableSize);
Position Find_Index(ElementType Key, int TableSize);

int main()
{
	// scanf("%d", &N);
	N = 11;
	InitialVisited(N);
	InitialTable(N);
	// for (int i=0; i<N; i++) {
	// 	scanf("%d", Table[i]);
	// }
	InsertTable(N);
	return 0;
}

void InitialVisited(int N)
{
	for (int i=0; i<N; i++) {
		Visited[i] = 0;
	}
}

void InitialTable(int N)
{
	for (int i=0; i<N; i++) {
		Table_2[i] = 0;
	}
}

void InsertTable(int TableSize)
{	
	int Key, cnt;
	while(!CheckFull(TableSize)){
		cnt = 0;
		for (int i=0; i<N; i++) {
			Key = Table[i];
			if(Key == -1){
				Visited[i] = 1;
				continue;
			}
			Position pos1;
			Position pos = Find(Key, TableSize);
			pos1 =  Find_Index(Key, TableSize);
			if (pos == pos1) {
				result[cnt++] = Key;
				Visited[pos]  = 1;
			} else {
				continue;
			}
		}
		for (int i=0; i<cnt; i++) {
			Key = result[i];
			Position pos = Find(Key, TableSize);
			Table_2[pos] = Key;
			printf("%d", result[i]);
			if (i!=cnt-1) printf(" ");
		}
		printf("\n");
	}
}

int CheckFull(int TableSize)
{
	for (int i=0; i<TableSize; i++) {
		if (!Visited[i]) return 0;
	}
	return 1;
}

Position Find(ElementType Key, int TableSize)
{
	Position pos = Key % TableSize;
	int cnum = 1;  //冲突次数
	while ( cnum < TableSize ) {  //k>=size后，平方探测将进入一个死循环
		if ( Table_2[pos] == 0 ) { //如果该位置没有元素
			return pos;
		}
		else { //该位置有元素，使用平方探测法解决冲突
			pos = ( pos + 1) % TableSize;
			cnum++;
		}
	}
	return -1;
}

Position Find_Index(ElementType Key, int TableSize)
{
	for (int i=0; i<TableSize; i++) {
		if(Table[i] == -1) continue;
		if(Table[i] == Key) return i;
	}
	return -1;
}



