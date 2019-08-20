#include <stdio.h>

#define MAXSIZE 101

typedef int Vertex;

int Graph[MAXSIZE][MAXSIZE];

void InitialGraph(int N);
void InsertEdge(int point1, int point2, int weight);
int BSF(Vertex v, int N);
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

	int shortest[MAXSIZE];
	for(int i=1; i<=N; i++) {
		shortest[i] = BSF(i, N);
	}

	int min;
	int index = 0;
	for (int i=1; i<=N; i++) {
		if (i==1 || min > shortest[i]) {
			min = shortest[i];
			index = i;
		}
	}
	
	min == 0 ? printf("%d", min) : printf("%d %d", index, min);
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

int BSF(Vertex v, int N)
{
	int Q[MAXSIZE];
	int front=0, rear=0;
	Vertex s = v;
	Q[rear++] = v;
	int Dist[MAXSIZE];
	for (int i=1; i<=N; i++) {
		Dist[i] = -1;
	}
	while(front < rear) {
		Vertex w  = Q[front++];
		for(int i=1; i<=N; i++){
			if (Graph[w][i] && Dist[i] == -1 && i != s) {
				Dist[i] = Dist[w] + Graph[w][i];
				Q[rear++] = i;
			}
		}
	}
	for (int i=1; i<=N; i++) {
		if(Dist[i] == -1 && i != s)
			return 0;
	}

	int max = -1;
	for (int i=1; i<=N; i++) {
		if(max < Dist[i]) max = Dist[i];
	}
	return max+1;
}