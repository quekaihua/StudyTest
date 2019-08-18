#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct node *Vertex;
typedef struct graph *Graph;
typedef struct edge *Edge;

#define MAXSIZE 10

bool visited[MAXSIZE];

struct graph {
    Vertex v[MAXSIZE];
    int n;
    int e;
    int size;
};

struct node {
    ElementType number;
    Vertex Next;
};

struct edge {
    Vertex a;
    Vertex b;
};

Graph Create();
Graph InsertVertex(Graph G, Vertex V);
Graph InsertEdge(Graph G, Edge E);
void DFS(Graph G, Vertex V);
void BFS(Graph G, Vertex V);
void ListComponentsDFS(Graph G);
void ListComponentsBFS(Graph G);

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

/* local function */
Vertex CreateNode(ElementType number);
void InitialVisited(Graph G);

int main()
{

    //Create Graph
    Graph g = Create();
    int a, b;
    Edge e = malloc(sizeof(struct edge));

    for (int i=0; i<g->e; i++) {
        scanf("%d %d", &a, &b);
        e->a = g->v[a];
        e->b = g->v[b];
        InsertEdge(g, e);
    }

    InitialVisited(g);
    ListComponentsDFS(g);

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
    g->size = 0;
    for(int i=0; i<N; i++) {
        Vertex v = CreateNode(i);
        g = InsertVertex(g, v);
    }
    return g;
}

Graph InsertVertex(Graph G, Vertex V)
{
    if(G->size+1 > G->n)
        exit(1);
    G->v[G->size++] = V;
    return G;
}

Graph InsertEdge(Graph G, Edge E)
{
    //find a end.
    Vertex a = G->v[E->a->number];
    while(a->Next != NULL)
        a = a->Next;
    Vertex r;
    r = CreateNode(E->b->number);
    a->Next = r;

    //find b end.
    Vertex b = G->v[E->b->number];
    while(b->Next != NULL)
        b = b->Next;
    r = CreateNode(E->a->number);
    b->Next = r;
    return G;
}

void DFS(Graph G, Vertex V)
{
    visited[V->number] = true;
    printf("%d ", V->number);
    Vertex W = V->Next;
    while (W != NULL)
    {
        if (!visited[W->number])
        {
            DFS(G, G->v[W->number]);
        }
        W = W->Next;
    }
}

void BFS(Graph G, Vertex V)
{
    visited[V->number] = true;
    printf("%d ", V->number);
    Queue Q = InitializeQueue();
    enqueue_q(Q, V);
    while (!IsEmpty(Q)) 
    {
        Vertex T = dequeue_q(Q);
        Vertex W = T->Next;
        while (W != NULL)
        {
            if (!visited[W->number])
            {
                visited[W->number] = true;
                printf("%d ", W->number);
                enqueue_q(Q, G->v[W->number]);
            }
            W = W->Next;
        }
    }
}


/* local funciton */
Vertex CreateNode(ElementType number)
{
    Vertex v  = malloc(sizeof(struct node));
    v->number = number;
    v->Next   = NULL;
    return v;
}

void InitialVisited(Graph G)
{
    for (int i=0; i<G->size; i++)
        visited[i] = false;
}

void ListComponentsDFS(Graph G)
{
    for (int i=0; i<G->size; i++) 
    {
        if (!visited[G->v[i]->number]){
            printf("{ ");
            DFS(G, G->v[i]);
            printf("}\n");
        }
    }
}

void ListComponentsBFS(Graph G)
{
    for (int i=0; i<G->size; i++) 
    {
        if (!visited[G->v[i]->number]){
            printf("{ ");
            BFS(G, G->v[i]);
            printf("}\n");
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