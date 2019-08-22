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
double D;

#define MAXSIZE 101

int Graph[MAXSIZE][MAXSIZE];
Point Points[MAXSIZE];
bool visited[MAXSIZE];
int count = 0; //calculate points

void InitialVisited();
void InitialGraph();
void BuildEdge();
void InsertVertex(Point x);
void InsertEdge(Point x, Point y, int i, int j);

bool DFS(int V);
int Distance(Point X, Point Y);
bool IsSave(Point X);

int main()
{
    InitialGraph();
    int N;
    scanf("%d %lf", &N, &D);
    int x, y;
    for(int i=0; i<N; i++)
    {
        Point p = malloc(sizeof(struct point));
        scanf("%d %d", &x, &y);
        p->x = x + 50;
        p->y = y + 50;
        InsertVertex(p);
    }
    BuildEdge(D);

    // Points = malloc(sizeof(Point)*MAXSIZE*MAXSIZE);
    InitialVisited();
    Point begin;
    bool flag = false;
    for (int i=0; i<count; i++){
        begin = Points[i];
        if(begin->x == begin->y && begin->x ==50){
            flag = DFS(i);
            break;
        }
    }
    flag ? printf("Yes\n") : printf("No\n");
    return 0;
}

void InitialGraph()
{
    for (int i=0; i<MAXSIZE; i++) {
        for (int j=0; j<MAXSIZE; j++)
            Graph[i][j] = 0;
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

void BuildEdge()
{
    for(int i=0; i<count; i++){
        for(int j=count-1; j>i;j--){
            Point q = Points[i];
            Point p = Points[j];
            InsertEdge(p, q, i, j);
        }
    }
}

void InsertVertex(Point p)
{
    Points[count++] = p;
}

void InsertEdge(Point X, Point Y, int i, int j)
{
    int distance = Distance(X, Y);
    if((X->x==50 && X->y==50) || (Y->x==50 && Y->y==50)){
        if(distance <= (D+7.5)*(D+7.5)){
            Graph[i][j] = 1;
            Graph[j][i] = 1;
        }
    } else if (distance <= D*D){
        Graph[i][j] = 1;
        Graph[j][i] = 1;
    }
}

int Distance(Point X, Point Y)
{
    return (Y->x - X->x) * (Y->x - X->x) + (X->y - Y->y) * (X->y - Y->y);
}

bool DFS(int V)
{
    visited[V] = true;
    Point ptr = Points[V];
    bool flag;
    // printf("%d %d\n", ptr->x, ptr->y);
    // IsSave(ptr) ? printf("yes\n") : printf("no\n");
    if(IsSave(ptr)) return true;
    for(int i=0; i<count; i++){
        if (Graph[V][i] && !visited[i]){
            flag = DFS(i);
            if(flag == true)
                return true;
        }
    }
    return false;
}

bool IsSave(Point X){
    Point Y = malloc(sizeof(struct point));
    Y->x = X->x;
    Y->y = 0;
    if(Distance(X, Y) <= D*D){
        free(Y);
        return true;
    }

    Y->x = 0;
    Y->y = X->y;
    if(Distance(X, Y) <= D*D){
        free(Y);
        return true;
    }

    Y->x = 99;
    Y->y = X->y;
    if(Distance(X, Y) <= D*D){
        free(Y);
        return true;
    }

    Y->x = X->x;
    Y->y = 99;
    if(Distance(X, Y) <= D*D){
        free(Y);
        return true;
    }

    return false;
}
