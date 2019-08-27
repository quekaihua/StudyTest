#include <stdio.h>

#define MAXSIZE 105
int Queue[MAXSIZE], Indegree[MAXSIZE], Earliest[MAXSIZE];
int Graph[MAXSIZE][MAXSIZE];

void TopSort(int N);
void InitialGraph(int N);
void InitialIndegree(int N);
void InsertEdge(int i, int j, int LastTime);
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	InitialIndegree(N);
	InitialGraph(N);

	int point1, point2, LastTime;
	for (int i=0; i<M; i++)
	{
		scanf("%d %d %d", &point1, &point2, &LastTime);
		InsertEdge(point1, point2, LastTime);
	}

// for(int i=0; i<N; i++) {
// 		printf("Indegree[%d]=%d ", i, Indegree[i]);
// 	}
	TopSort(N);

	// printf("\n");
	// for(int i=0; i<N; i++) {
	// 	printf("Indegree[%d]=%d ", i, Indegree[i]);
	// }
	// printf("\n");
	// for(int i=0; i<N; i++) {
	// 	printf("Earliest[%d]=%d ", i, Earliest[i]);
	// }
	// printf("\n");

	//check Indegree
	int flag = 0;
	for(int i=0; i<N; i++) {
		if(Indegree[i] != 0) {
			printf("Impossible\n");
			flag = 1;
			break;
		}
	}

	if(!flag) {
		int max;
		for(int i=0; i<N; i++) {
			if(i==0 || max < Earliest[i])
				max = Earliest[i];
		}
		printf("%d", max);
	}
	return 0;
}

void TopSort(int N)
{
	int front, rear;
	front=0;
	rear=0;
	int V;
	for (int i=0; i<N; i++)
		if(Indegree[i] == 0) {
			Queue[rear++] = i;
			Earliest[i]  = 0;
		}
	while(front < rear) {
		V = Queue[front++];
		// printf("V=%d ", V);
		for (int j=0; j<N; j++) {
			if(Graph[V][j] != -1) {  //只要有边都需要更新Earliest;
				if (Earliest[V] + Graph[V][j] > Earliest[j])
					Earliest[j] = Earliest[V] + Graph[V][j];
				
				if (--Indegree[j] == 0)
					Queue[rear++] = j;
			}
		}
	}
}

void InitialGraph(int N)
{
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++){
			Graph[i][j]  = -1;
		}
}

void InitialIndegree(int N)
{
	for(int i=0; i<N; i++) {
		Indegree[i] = 0;
		Earliest[i]  = 0;
	}
}

void InsertEdge(int i, int j, int LastTime)
{
	Graph[i][j] = LastTime;
	Indegree[j]++;
}