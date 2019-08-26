#include <stdio.h>
#include <limits.h>

#define MAXSIZE 101
typedef int Vertex;

int Graph[MAXSIZE][MAXSIZE];
int Graph2[MAXSIZE][MAXSIZE];
int Dist[MAXSIZE][MAXSIZE];

void InitialGraph(int N);
void InsertEdge(int point1, int point2, int weight, int price);
// int BSF(Vertex v, int N);

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	InitialGraph(N);
	
	int point1, point2, weight, price;
	for (int i=0; i<M; i++)
	{
		scanf("%d %d %d %d", &point1, &point2, &weight, &price);
		InsertEdge(point1, point2, weight, price);
	}

	Floyed(N);
	PrintResult(N);

	return 0;
}

void InitialGraph(int N)
{
	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++)
			Graph[i][j] = 0;
}

void InsertEdge(int point1, int point2, int weight, int price)
{
	Graph[point1][point2] = weight;
	Graph[point2][point1] = weight;
	Graph2[point1][point2] = price;
	Graph2[point2][point1] = price;
}

void Dijkstra(Vertex s)
{
	InitialPath(S);
	InitialDist(S);

	int rear, front, Queue[MAXSIZE];
	rear = 0;
	front = 0;
	Queue[front++] = S;

	Vertex V, i;
	while(rear < front) {
		V = Queue[rear++];
		for(i=0; i<count; i++){
			if(Graph[V][i] && dist[i] == -1) {
				dist[i] = dist[V] + 1;
				path[i] = V;
				Queue[front++] = i;
			}
		}
	}
}