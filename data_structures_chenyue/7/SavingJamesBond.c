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
int dist[MAXSIZE], path[MAXSIZE];
int count = 0; //calculate points

void InitialPath(int S);
void InitialDist(int S);
void InitialGraph();
void BuildEdge();
void InsertVertex(Point x);
void InsertEdge(Point x, Point y, int i, int j);

int Distance(Point X, Point Y);
bool IsSave(Point X);
void Unweighted (Vertex S);
void PrintPath();

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
    Unweighted(0);
	PrintPath();

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

void InitialPath(int S)
{
    for(int i=0; i<count; i++)
        path[i] = i==S ? -1 : 0;
}

void InitialDist(int S)
{
	for(int i=0; i<count; i++)
		dist[i] = i==S ? 0 : -1;
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

void Unweighted (Vertex S)
{
	InitialPath(S);
	InitialDist(S);

	int rear, front, Queue[MAXSIZE];
	rear = 0;
	front = 0;
	Queue[front++] = S;

	Vertex V, i;
	while(rear < front) {
		V = Queue[rear++];
		for(i=0; i<count; i++){
			if(Graph[V][i] && dist[i] == -1) {
				dist[i] = dist[V] + 1;
				path[i] = V;
				Queue[front++] = i;
			}
		}
	}
}

void PrintPath()
{
	int j = 0, save[MAXSIZE];
	for(int i=0; i<count; i++) {
		Point ptr = Points[i];
		if(IsSave(ptr)) {
			save[j++] = i;
		}
	}

	int k = 0;
	int min=0, minPath[MAXSIZE];
	for(int i=0; i<j; i++)
	{
		if((dist[save[i]] > 0 && dist[save[i]] < min) || 
		i==0) {
			min = dist[save[i]];
		}
	}
	if(min==0) {
		printf("%d", min);
		return;
	}

	for(int i=0; i<j; i++){
		if(min == dist[save[i]]){
			minPath[k++] = save[i];
		}
	}
	int minPath_a, minPath_b, temp_a, temp_b, result;
	for (int i=0; i<k; i++) {
		for (int m=0; m<k; m++) {
			// if(i==m) continue;
			minPath_a = temp_a = minPath[i];
			minPath_b = temp_b = minPath[m];
			while(path[minPath_a] != 0) {
				minPath_a = path[minPath_a];
				minPath_b = path[minPath_b];
			}
			if(Distance(Points[minPath_a], Points[0]) < Distance(Points[minPath_b], Points[0])) {
				result = temp_a;
			} else {
				result = temp_b;
			}
		}
	}

	int Stack[MAXSIZE], top=0, step=1;
	while(path[result] != -1) {
		Stack[top++] = result;
		result = path[result];
		step++;
	}
	printf("%d\n", step);
	for(int i=top-1; i>=0; i--) {
		Point p = Points[Stack[i]];
		printf("%d %d\n", p->x-50, p->y-50);
	}
}