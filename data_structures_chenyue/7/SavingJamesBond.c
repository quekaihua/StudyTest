#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int Vertex;
typedef int position;
typedef struct point *Point;

struct point {
    position x;
    position y;
	int d;
};
double D;
int N;

#define MAXSIZE 101

int Graph[MAXSIZE][MAXSIZE];
Point Points[MAXSIZE];
int dist[MAXSIZE], path[MAXSIZE], Visited[MAXSIZE] = {0};
int count = 0; //calculate points

double Distance(int a, int b);
void PrintPath( int Stack[], int top );
int IsSafe( int v );
int FirstJump( Point dot );
int Jump( int a, int b );
int ShortestPath(int S);
void Save007();

int main()
{
    scanf("%d %lf", &N, &D);
    int x, y;
    for(int i=0; i<N; i++)
    {
        Point p = malloc(sizeof(struct point));
        scanf("%d %d", &x, &y);
        p->x = x;
        p->y = y;
		p->d = x*x + y*y;
       	Points[count++] = p;
    }
    // BuildEdge(D);
    // Points = malloc(sizeof(Point)*MAXSIZE*MAXSIZE);
	//按离原点的距离从小到大排序
	for(int i = 0; i < N - 1; i++){
		int step = 0;
		for(int j = 0; j < N - 1 - i; j++)
			if(Points[j]->d > Points[j + 1]->d){
				Point Tmp = Points[j];
				Points[j] = Points[j + 1];
				Points[j + 1] = Tmp;
				step++;
			}
		if ( step == 0 ) break;
	}
	//007有超能力，能直接跳上岸
	if( D >= 42.5 ) 
		printf("1\n");	
	else 
		Save007();
	return 0;
}

double Distance(int a, int b)
{
	Point X = Points[a];
	Point Y = Points[b];
    return sqrt((Y->x - X->x) * (Y->x - X->x) + (X->y - Y->y) * (X->y - Y->y));
}

int IsSafe( int v )
{
	int x = abs( Points[v]->x );
	int y = abs( Points[v]->y );
	if( x + D >= 50 || y + D >= 50 )
		return 1;
	else return 0;
}

int FirstJump( Point dot )
{
	double temp = dot->x * dot->x + dot->y * dot->y;
	double dis = sqrt( temp );
	double cap = 7.5 + D;	//第一次跳要加上小岛的半径
	if( cap >= dis && dis > 7.5) return 1;	//岸上的鳄鱼不算
	else return 0;
}

int Jump( int a, int b )
{
	double dis = Distance(a, b);
	if( D >= dis) return 1;
	else return 0;
}

int ShortestPath(int S)
{
	for(int i = 0; i < count; i++)
		dist[i] = path[i] = -1;
	int V;
	int rear, front, Queue[MAXSIZE];
	rear = 0;
	front = 0;
	Visited[S] = 1;
	dist[S] = 0;
	if( IsSafe(S) ) return S; //007跳2次就能上岸（经过1条鳄鱼）
	Queue[front++] = S;
	while(rear < front) {
		V = Queue[rear++];
		for(int i = 0; i < N; i++){
			if( !Visited[i] && Jump(V, i) ){
				dist[i] = dist[V] + 1;
				path[i] = V;
				Visited[i] = 1;
				if( IsSafe(i) ) return i;
				Queue[front++] = i;
			}
		}
	}
	return -1;
}

void Save007()
{
	int NumberOfJump = MAXSIZE, LastCro;
	int Stack[MAXSIZE], top=0;

	for(int i = 0; i < N; i++) {
		if ( !Visited[i] && FirstJump(Points[i]) ) {
			LastCro = ShortestPath(i);
			if( LastCro != -1 && NumberOfJump > dist[LastCro] ) { //如果有更短的路径
				NumberOfJump = dist[LastCro];  //更新Jump次数
				//将路径入栈保存（path每做一次单源最短路就要更新一次，因此要记录）
				//错误原因：没记录路径，直接用了path来输出，导致无限循环，内存超限
				while ( top != 0 ) //清空上一次的stack（stack没有clear方法）
					top--;
				
				int v = LastCro;
				while ( v != i ){
					Stack[top++] = v;
					v = path[v];
				}
				Stack[top++] = v;
			}
		}
	}
	if (NumberOfJump == MAXSIZE) printf("0\n"); //没有路径能到岸上
	else {
		printf("%d\n", NumberOfJump + 2); //加上在岛上跳的一次，和最后跳上岸的一次
		PrintPath( Stack, top );
	}
}

void PrintPath( int Stack[], int top )
{
	int temp;
	while( top != 0 ) {
		temp = Stack[--top];
		printf("%d %d\n", Points[temp]->x, Points[temp]->y);
	}
}