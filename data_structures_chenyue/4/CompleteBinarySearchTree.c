#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 10
int input[MAXSIZE], out[MAXSIZE];

int compare(int a, int b);
void solve(int N);

int main()
{
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &input[i]);

    qsort(input, N, sizeof(int), compare);

    solve(N);
    for (int i=0; i<N; i++) {
        printf("%d ", out[i]);
        if (i != N-1)
            printf(" ");
    }
    return 0;
}

int compare(int a, int b)
{
    return a - b;
}

void solve(int N)
{
    int H, X;
    H = floor((log2)(N-1));
    X = min(pow(2,H-1), pow(2, H));
    for(int i=1; i<H; i++) {


    }

}