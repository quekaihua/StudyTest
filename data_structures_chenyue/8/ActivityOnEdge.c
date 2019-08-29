#include <stdio.h>
#include <limits.h>

#define MAXSIZE 105
int Indegree[MAXSIZE], Outdegree[MAXSIZE], Earliest[MAXSIZE], Latest[MAXSIZE];
int Graph[MAXSIZE][MAXSIZE];
int idx;

int TopSort(int N);
void InitialGraph(int N);
void InitialIndegree(int N);
void InsertEdge(int i, int j, int LastTime);
void UpdateLatest(int N);
int GetEndPoint(int N);
void PrintKeyTask(int N);
int getMax( int arr[], int N);

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

	// printf("\n");
	// for(int i=1; i<=N; i++) {
	// 	printf("Indegree[%d]=%d ", i, Indegree[i]);
	// }
	// printf("\n");

	// for(int i=1; i<=N; i++) {
	// 	printf("Outdegree[%d]=%d ", i, Outdegree[i]);
	// }
	// printf("\n");
	//check Indegree

	if( !TopSort(N) )
		printf("0\n");
	else {
		int max;
		for(int i=1; i<=N; i++) {
			if(i==1 || max < Earliest[i])
				max = Earliest[i];
		}
		printf("%d\n", max);
		UpdateLatest(N);

		PrintKeyTask(N);
	}
	
	return 0;
}

int TopSort(int N)
{
	int Queue[MAXSIZE] = {0}, front=0, rear=0;
	int V, cnt=0;
	for (int i=1; i<=N; i++)
		if(Indegree[i] == 0) {   //入度为0入队
			Queue[rear++] = i;
			Earliest[i]  = 0;
		}

	while(front < rear) {
		V = Queue[front++];
		cnt++;
		// printf("V=%d ", V);
		for (int j=1; j<=N; j++) {
			if (Graph[V][j] != -1) {
				if (Earliest[V] + Graph[V][j] > Earliest[j])  //时间比较大则更新
					Earliest[j] = Earliest[V] + Graph[V][j];
				if (--Indegree[j] == 0)
					Queue[rear++] = j;
			}
		}
	}

	if( cnt != N ) return 0;	//如果没有取出所有元素，说明图中有回路
	else return 1;
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
	int Queue[MAXSIZE] = {0};
	front = rear = 0;

	for (int i=1; i<=N; i++) {
		if(Outdegree[i] == 0) {   //入度为0入队
			Queue[rear++] = i;
		}
	}

	for( int i = 1; i <= N; i++ )
		Latest[i] = INT_MAX;
	// printf("ids=%d max=%d", idx, getMax(Earliest, N));
	int max = getMax(Earliest, N);
	Latest[idx] = max;
	while(front < rear) {
		w = Queue[front++];  //处理节点入队， 邻节点入队
		// printf("w=%d\n");
		for(int i=1; i<=N; i++) {
			if(Graph[i][w] != -1) {//i为前节点 
				// printf("i=%d\n", i);
				if(Latest[i] >= Latest[w] - Graph[i][w])   //更新最迟时间
					Latest[i] = Latest[w] - Graph[i][w];
				if (--Outdegree[i] == 0)
					Queue[rear++] = i;
			}
		}
	}
}

int getMax( int arr[], int N)
{
	int max = 0;
	for(int i = 1; i <= N; i++)
		if( max < arr[i] ){
			max = arr[i];
			idx = i;
		}
	return max;
}

void PrintKeyTask(int N)
{
	for (int i=1; i<=N; i++) {
		for (int j=N; j>=1; j--) {
			if( Graph[i][j] != -1 ) {
				if(Latest[j] - Earliest[i] - Graph[i][j] == 0) {
					printf("%d->%d\n", i, j);
				}
			}
		}
	}
}