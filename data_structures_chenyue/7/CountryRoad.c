#include <stdio.h>

#define MAXSIZE 101
int Graph[MAXSIZE][MAXSIZE];
int Dist[MAXSIZE][MAXSIZE];

void InitialGraph(int N);
void InsertEdge(int point1, int point2, int weight);

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

void InsertEdge(int point1, int point2, int weight)
{
	Graph[point1][point2] = weight;
	Graph[point2][point1] = weight;
}