#include <stdio.h>
#include <limits.h>

#define MAXSIZE 10000
int Queue[MAXSIZE], Indegree[MAXSIZE], Outdegree[MAXSIZE], Earliest[MAXSIZE], Latest[MAXSIZE];
int Graph[MAXSIZE][MAXSIZE];

void TopSort(int N);
void InitialGraph(int N);
void InitialIndegree(int N);
void InsertEdge(int i, int j, int LastTime);
void UpdateLatest(int N);
int GetEndPoint(int N);
void PrintKeyTask(int N);

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
	UpdateLatest(N);

	// printf("\n");
	// for(int i=1; i<=N; i++) {
	// 	printf("Indegree[%d]=%d ", i, Indegree[i]);
	// }
	// printf("\n");

	// for(int i=1; i<=N; i++) {
	// 	printf("Outdegree[%d]=%d ", i, Outdegree[i]);
	// }
	// printf("\n");
	// for(int i=1; i<=N; i++) {
	// 	printf("Earliest[%d]=%d ", i, Earliest[i]);
	// }
	// printf("\n");
	// for(int i=1; i<=N; i++) {
	// 	printf("Latest[%d]=%d ", i, Latest[i]);
	// }
	// printf("\n");
	//check Indegree
	int flag = 0;
	for(int i=1; i<=N; i++) {
		if(Indegree[i] != 0) {
			printf("0");
			flag = 1;
			break;
		}
	}

	if(!flag) {
		int max;
		for(int i=1; i<=N; i++) {
			if(i==1 || max < Earliest[i])
				max = Earliest[i];
		}
		printf("%d\n", max);
		PrintKeyTask(N);
	}
	return 0;
}

void TopSort(int N)
{
	int front, rear;
	front=0;
	rear=0;
	int V;
	for (int i=1; i<=N; i++)
		if(Indegree[i] == 0) {
			Queue[rear++] = i;
			Earliest[i]  = 0;
		}
	while(front < rear) {
		V = Queue[front++];
		// printf("V=%d ", V);
		for (int j=1; j<=N; j++) {
			if (Graph[V][j] != -1) {
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
	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++){
			Graph[i][j]  = -1;
		}
}

void InitialIndegree(int N)
{
	for(int i=1; i<=N; i++) {
		Indegree[i]  = 0;
		Outdegree[i] = 0;
		Earliest[i]  = 0;
		Latest[i]    = INT_MAX;
	}
}

void InsertEdge(int i, int j, int LastTime)
{
	Graph[i][j] = LastTime;
	Indegree[j]++;
	Outdegree[i]++;
}

void UpdateLatest(int N)
{
	int v, w;
	int front, rear;
	front = rear = 0;
	while (1)
	{
		// printf("Graph[5][7]=%d, Graph[7][5]=%d\n", Graph[5][7], Graph[7][5]);
		v = GetEndPoint(N);
		if (v == -1) break;
		Latest[v] = Earliest[v];
		Queue[rear++] = v;
		while(front < rear) {
			w = Queue[front++];  //处理节点入队， 邻节点入队
			// printf("w=%d\n");
			for(int i=1; i<=N; i++) {
				if(Graph[i][w] != -1) {//i为前节点 
					// printf("i=%d\n", i);
					Queue[rear++] = i;
					if(Latest[i] > Latest[w] - Graph[i][w])   //更新最迟时间
						Latest[i] = Latest[w] - Graph[i][w];
				}
			}
		}
	}
}

/* 获取未记录最迟时间的终点 */
int GetEndPoint(int N)
{
	for(int i=1; i<=N; i++)
		if(Outdegree[i] == 0 && Latest[i] == INT_MAX)
			return i;
	return -1;
}

void PrintKeyTask(int N)
{
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			if( Graph[i][j] != -1 ) {
				if(Latest[j] - Earliest[i] - Graph[i][j] == 0) {
					printf("%d->%d\n", i, j);
				}
			}
		}
	}
}