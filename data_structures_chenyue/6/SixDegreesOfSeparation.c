#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElementType;
typedef int Vertex;
typedef struct graph *Graph;
typedef struct edge *Edge;

#define MAXSIZE 10001

bool visited[MAXSIZE];

struct graph {
    int v[MAXSIZE][MAXSIZE];
    int n;
    int e;
    int size;
};

struct edge {
    Vertex a;
    Vertex b;
};

Graph Create();
Graph InsertEdge(Graph G, Edge E);
int DFS(Graph G, Vertex V, int degree);
void ListComponentsDFS(Graph G);

int BFS(Graph G, Vertex V);
void ListComponentsBFS(Graph G);

/* local function */
Vertex CreateNode(ElementType number);
void InitialVisited(Graph G);

/* Queue */
struct queue {
	Vertex data[MAXSIZE];
	int front, rear, size;
};

typedef struct queue* Queue;

Queue InitializeQueue();
Vertex dequeue_q(Queue q);
bool enqueue_q(Queue q, Vertex element);
bool IsFull(const Queue q);
bool IsEmpty(const Queue q);

int main()
{

    //Create Graph
    Graph g = Create();
    int a, b;
    Edge e = malloc(sizeof(struct edge));

    for (int i=0; i<g->e; i++) {
        scanf("%d %d", &e->a, &e->b);
        InsertEdge(g, e);
    }

    InitialVisited(g);
    ListComponentsBFS(g);

    return 0;
}

Graph Create()
{
    int N, E;
    scanf("%d %d", &N, &E);
    Graph g = malloc(sizeof(struct graph));
    g->n = N;
    g->e = E;
    g->size = N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++)
            g->v[i][j] = 0;
    }
    return g;
}

Graph InsertEdge(Graph G, Edge E)
{
    G->v[E->a][E->b] = 1;
    G->v[E->b][E->a] = 1;
    return G;
}

int DFS(Graph G, Vertex V, int degree)
{
    int count = 0;
    if(degree>7) return count;
    visited[V] = true;
    count++;
    degree++;
    for(int i=1; i<=G->size; i++){
        if (G->v[V][i] && !visited[i] && degree<7)
            count = count+DFS(G, i, degree);
    }
    return count;
}

/* local funciton */

void InitialVisited(Graph G)
{
    for (int i=1; i<=G->size; i++)
        visited[i] = false;
}

void ListComponentsDFS(Graph G)
{
    for (int i=1; i<=G->size; i++) 
    {
        InitialVisited(G);
        if (!visited[i]){
            int count = 0; 
            count= DFS(G, i, 0);
            if(count==1) count = 0;
            printf("%d: %.2lf%%\n", i, count*100.0/G->size);
        }
    }
}

int BFS(Graph G, Vertex V)
{
    int level, last, tail, count;
    visited[V] = true;
    count = 1;//这个节点有多少人 
    level = 0;//层数
    last = V;//这一层访问的最后一个节点 
    Queue Q = InitializeQueue();
    enqueue_q(Q, V);
    while (!IsEmpty(Q)) 
    {
        Vertex T = dequeue_q(Q);
        // printf("%d ", T);
        for(int i=1; i<=G->size; i++){
            if (G->v[T][i] && !visited[i])
            {
                visited[i] = true;
                enqueue_q(Q, i);
                count++;
                tail = i;
            }
        }
        if (T == last) {
            level++;
            last = tail;
        }
        if(level == 6)  break;
    }
    return count;
}

void ListComponentsBFS(Graph G)
{
    for (int i=1; i<=G->size; i++) 
    {
        InitialVisited(G);
        if (!visited[i]){
            int count = 0; 
            count= BFS(G, i);
            if(count==1) count = 0;
            printf("%d: %.2lf%%\n", i, count*100.0/G->size);
        }
    }
}

/* Queue functions */
Vertex dequeue_q(Queue q)
{
	if(IsEmpty(q)){
		exit(1);
	}
	Vertex temp;
	temp = q->data[q->front];
	q->front = q->front+1==MAXSIZE ? 0 : q->front+1;
	q->size--;
	return temp;
}

Queue InitializeQueue()
{
    Queue q = malloc(sizeof(struct queue));
	q->front = q->rear = q->size = 0;
    return q;
}

bool enqueue_q(Queue q, Vertex element)
{
	if(IsFull(q)){
		return false;
	}
	q->data[q->rear] = element;
	q->rear = q->rear+1==MAXSIZE ? 0 : q->rear+1;
	q->size++;
	return true;
}

bool IsEmpty(const Queue q)
{
	return q->size == 0;
}

bool IsFull(const Queue q)
{
	return q->size == MAXSIZE;
}