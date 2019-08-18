#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElementType;
typedef int Vertex;
typedef struct graph *Graph;
typedef struct edge *Edge;

#define MAXSIZE 1001

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
        scanf("%d %d", &e->a, &e->b);
        InsertEdge(g, e);
    }

    InitialVisited(g);
    ListComponentsDFS(g);

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