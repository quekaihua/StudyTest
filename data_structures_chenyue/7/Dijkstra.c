#include <stdio.h>
#include <limits.h>

#define MAXSIZE 5
typedef int Vertex;

int Graph[MAXSIZE][MAXSIZE];
int Graph2[MAXSIZE][MAXSIZE];
int Dist[MAXSIZE],Path[MAXSIZE], Collected[MAXSIZE];
int N, M;

void InitialPath(Vertex S);
void InitialDist(Vertex S);
void InitialCollected(Vertex S);
void InsertEdge(int point1, int point2, int weight, int price);
Vertex GetShortDist();
void Dijkstra(Vertex s);
void InitialGraph(int N);

// int BSF(Vertex v, int N);

int main()
{
	int S, D;
	scanf("%d %d %d %d", &N, &M, &S, &D);
	InitialGraph(N);
	
	int point1, point2, weight, price;
	for (int i=0; i<M; i++)
	{
		scanf("%d %d %d %d", &point1, &point2, &weight, &price);
		InsertEdge(point1, point2, weight, price);
	}

	Dijkstra(0);
	
	for(int i=0; i<N; i++) {
		printf("Dist[%d]=%d ", i, Dist[i]);
	}
	printf("\n");
	for(int i=0; i<N; i++) {
		printf("Path[%d]=%d ", i, Path[i]);
	}
	printf("\n");
	for(int i=0; i<N; i++) {
		printf("Collected[%d]=%d ", i, Collected[i]);
	}
	printf("\n");
	return 0;
}

void InitialGraph(int N)
{
	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++){
			Graph[i][j]  = 0;
			Graph2[i][j] = 0;
		}
}

void InitialPath(Vertex S)
{
    for(int i=0; i<N; i++)
        Path[i] = -1;
}

void InitialDist(Vertex S)
{
	for(int i=0; i<N; i++)
		Dist[i] = i==S ? 0 : INT_MAX;
}

void InitialCollected(Vertex S)
{
	for(int i=0; i<N; i++)
		Collected[i] = i==S ? 1 : 0;
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
	InitialCollected(s);
	InitialDist(s);
	InitialPath(s);

	Collected[s] = 1;
	for(int i=0; i<N; i++) {
		if(Graph[s][i]) {
			Dist[i] = Graph[s][i];
			Path[i] = s;
		}
	}

	Vertex v, w;
	while(1) {
		v = GetShortDist();
		if (v == -1)
			break;
		Collected[v] = 1;
		for(int i=0; i<N; i++) {
			if(Graph[v][i] && Collected[i] == 0) {
				if (Dist[v] + Graph[v][i] < Dist[i]) {
					Dist[i] = Dist[v] + Graph[v][i];
					Path[i] = v;
				}
			}
		}
	}
}

//可以用最小堆优化  todo
Vertex GetShortDist()
{
	int Min = INT_MAX;
	Vertex MinVertex = -1;
	for (int i=0; i<N; i++)
	{
		if (Dist[i] != INT_MAX && !Collected[i]) {
			if(Dist[i]<Min) {
				Min = Dist[i];
				MinVertex = i;
			}
		}
	}

	return MinVertex;
}

