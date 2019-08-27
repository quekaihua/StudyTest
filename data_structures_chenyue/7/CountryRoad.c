#include <stdio.h>
#include <limits.h>

#define MAXSIZE 1001
typedef int Vertex;
int Graph[MAXSIZE][MAXSIZE];
int Dist[MAXSIZE], Path[MAXSIZE], Cost[MAXSIZE];

void InitialGraph(int N);
void InitialDist(int N, Vertex S);
void InitialPath(int N, Vertex S);
void InsertEdge(int point1, int point2, int weight);
int Prim(int N, Vertex S);
int CountMST(int N);
Vertex GetShortDist(int N);

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	InitialGraph(N);
	
	int point1, point2, weight;
	for (int i=0; i<M; i++) 
	{
		scanf("%d %d %d", &point1, &point2, &weight);
		InsertEdge(point1, point2, weight);
	}

	int flag = Prim(N, 1);
	if (flag) {
		int charge = 0;
		for(int i=1; i<=N; i++){
			charge += Cost[i];
		}
		printf("%d", charge);
	} else {
		printf("-1");
	}
	return 0;
}

void InitialGraph(int N)
{
	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++)
			Graph[i][j] = 0;
}

void InsertEdge(int point1, int point2, int weight)
{
	Graph[point1][point2] = weight;
	Graph[point2][point1] = weight;
}

void InitialDist(int N, Vertex S)
{
	for(int i=1; i<=N; i++) {
		Dist[i] = i==S ? 0 : INT_MAX;
	}

	for(int i=1; i<=N; i++) {
		if(Graph[S][i]) {
			Dist[i] = Graph[S][i];
			Path[i] = S;
			Cost[i] = Graph[S][i];
		}
	}
}

void InitialPath(int N, Vertex S)
{
    for(int i=0; i<N; i++) {
        Path[i] = -1;
		Cost[i] = 0;
	}
}

int Prim(int N, Vertex S)
{
	InitialPath(N, S);
	InitialDist(N, S);
	Vertex v;
	while (1) {
		v = GetShortDist(N);
		if(v == -1) break;
		Dist[v] = 0;
		for(int i=1; i<=N; i++) {
			if(Graph[v][i] && Dist[i] != 0) {
				if (Graph[v][i] < Dist[i]) {
					Dist[i] = Graph[v][i];
					Path[i] = v;
					Cost[i] = Graph[v][i];
				}
			}
		}
	}
	if (CountMST(N) < N)
		return 0;  //未全部收录
	else
		return 1;
}

Vertex GetShortDist(int N)
{
	int Min = INT_MAX;
	Vertex MinVertex = -1;
	for (int i=1; i<=N; i++)
	{
		if (Dist[i] != INT_MAX && Dist[i]!=0 ) {
			if(Dist[i]<Min) {
				Min = Dist[i];
				MinVertex = i;
			}
		}
	}

	return MinVertex;
}

int CountMST(int N)
{
	int count = 0;
	for (int i=1; i<=N; i++)
		if (Dist[i] == 0) count++;
	return count;
}