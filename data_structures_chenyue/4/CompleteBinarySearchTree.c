#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 1000
int input[MAXSIZE], out[MAXSIZE];
// int input[MAXSIZE]={0,1,2,3,4,5,6,7,8,9}, out[MAXSIZE];
int cnt=0;

int compare ( const void *a , const void *b);
int min(int a, int b);
void solve(int left, int right, int TRoot);
int GetLeftLength(int n);

int main()
{
    int N=10;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &input[i]);

    qsort(input, N, sizeof(int), compare);

    solve(0, N-1, 0);

    for (int i=0; i<N; i++) {
        printf("%d", out[i]);
        if (i != N-1)
            printf(" ");
    }
    return 0;
}

void solve(int left, int right, int TRoot)
{
	int n, L, LeftTRoot, RightTRoot;
	n = right - left + 1;
	if (n==0) return;
	L = GetLeftLength(n);
	out[TRoot] = input[left+L];
	LeftTRoot = TRoot * 2 + 1;
	RightTRoot = LeftTRoot + 1;
	solve(left, left+L-1, LeftTRoot);
	solve(left+L+1, right, RightTRoot);
}

int GetLeftLength(int n)
{
	int H, X, LeftNodes, a, b;
	H = floor(log2(n+1));
	a = pow(2, H-1);
	b = n - pow(2, H) + 1;
	X = min(a, b);
	LeftNodes = 0;
	for(int i=0; i<H-1; i++)
		LeftNodes += pow(2, i);
	LeftNodes = LeftNodes + X;
	return LeftNodes;
}

int compare ( const void *a , const void *b)
{
	return *(int *)a - *(int *)b;
}

int min(int a, int b)
{
	return a-b > 0 ? b : a;
}