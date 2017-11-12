#include <stdio.h>
#define SIZE 10

int sum(int ar[], int n);

int main(void)
{
    int days[SIZE] = {31,28,31,30,31,30,31,30,31,30};
    long answer;

    answer = sum(days, SIZE);
    printf("The total number of days is %ld.\n", answer);
    printf("The size of days is %zd bytes.\n", sizeof(days));

    
    return 0;
}

int sum(int ar[], int n)
{
    int i, total;
    for(i = 0, total = 0; i < n; i++)
        total += ar[i];
    printf("The size of ar is %zd bytes.\n", sizeof(ar));
    return total;
}