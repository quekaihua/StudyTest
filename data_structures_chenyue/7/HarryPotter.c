#include <stdio.h>
#include <limits.h>

#define MAXSIZE 101
typedef int Vertex;

int Graph[MAXSIZE][MAXSIZE];
int Dist[MAXSIZE][MAXSIZE];

void InitialGraph(int N);
void InsertEdge(int point1, int point2, int weight);
// int BSF(Vertex v, int N);
void Floyed(int N);
void PrintResult(int N);

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

void Floyed(int N)
{
	for (int i = 1; i<=N; i++)
		for (int j=1; j<=N; j++) {
			if(i != j)
				Dist[i][j] = INT_MAX;
		}
	for (int i = 1; i<=N; i++)
		for (int j=1; j<=N; j++) {
			if(i !=j && Graph[i][j])
				Dist[i][j] = Graph[i][j];
		}
	
	int distance;
	for (int k=1; k<=N; k++)
		for (int i=1; i<=N; i++) 
			for (int j = 1; j<=N; j++) {
				distance = (Dist[i][k] == INT_MAX || Dist[k][j] == INT_MAX) ? INT_MAX : Dist[i][k] + Dist[k][j];
				if(Dist[i][j] > distance) {
					Dist[i][j] = distance;
					Dist[j][i] = distance;
				}
			}
}

void PrintResult(int N)
{
	int max;
	int shortest[MAXSIZE];
	for (int i=1; i<=N; i++) {
		max = -1;
		for(int j=1; j<=N; j++){
			if(max < Dist[i][j]) max = Dist[i][j];
		}
		shortest[i] = max;
	}

	int min, index;
	for (int i=1; i<=N; i++) {
		if (i==1 || min > shortest[i]) {
			min   = shortest[i];
			index = i;
		}
	}
	
	min == INT_MAX ? printf("%d", 0) : printf("%d %d", index, min);
}