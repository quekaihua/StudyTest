#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Vertex;
typedef int position;
typedef struct point *Point;

struct point {
    position x;
    position y;
};

#define MAXSIZE 100

int Graph[MAXSIZE*MAXSIZE][MAXSIZE*MAXSIZE];
Point Points[MAXSIZE*MAXSIZE];
bool visited[MAXSIZE*MAXSIZE];
int count = 0; //calculate points

void InitialVisited();
void InitialGraph();
void BuildEdge(double D);
void InsertVertex(Point x);
void InsertEdge(Point x, Point y, double D, int i, int j);
void DFS(int V);
int Distance(Point X, Point Y);

int main()
{

    Point p = malloc(sizeof(struct point));
    p->x = 50;
    p->y = 50;
    Points[count++] = p;
    
    return 0;
}

void InitialGraph()
{
    for (int i=0; i<MAXSIZE*MAXSIZE; i++) {
        for (int j=0; j<MAXSIZE*MAXSIZE; j++) {
            if (i==0 || j==0 || i==99 || j==99) {  //edge
                Point p = malloc(sizeof(struct point));
                p->x = i;
                p->y = j;
                Points[count++] = p;
            }
            Graph[i][j] = 0;
        }
    }
    Point a = malloc(sizeof(struct point));
    a->x = a->y = 50;
    Points[count++] = a;
}

void InitialVisited()
{
    for(int i=0; i<count; i++)
        visited[i] = false;
}

void BuildEdge(double D)
{
    for(int i=0; i<count; i++){
        for(int j=0; j<count;j++){
            if(i != j){
                Point q = Points[i];
                Point p = Points[j];
                InsertEdge(p, q, D, i, j);
            }
        }
    }
}

void InsertVertex(Point p)
{
    Points[count++] = p;
}

void InsertEdge(Point X, Point Y, double D, int i, int j)
{
    int distance = Distance(X, Y);
    if((X->x==50 && X->y==50) || (Y->x==50 && Y->y==50)){
        if(distance < (D+7.5)*(D+7.5)){
            Graph[i][j] = 1;
            Graph[j][i] = 1;
        }
    }
    if(distance < D*D){
        Graph[i][j] = 1;
        Graph[j][i] = 1;
    }
}

int Distance(Point X, Point Y)
{
    return (Y->x - X->x) * (Y->x - X->x) + (X->y - Y->y) * (X->y - Y->y);
}

void DFS(int V)
{
    visited[V] = true;
    Point ptr = Points[V];
    printf("%d %d\n", ptr->x, ptr->y);
    for(int i=0; i<count; i++){
        if (Graph[V][i] && !visited[i])
            DFS(i);
    }
}
