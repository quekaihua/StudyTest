#include <stdio.h>
#define SIZE 10

int sum(int * start, int * end);

int main(void)
{
    int days[SIZE] = {31,28,31,30,31,30,31,30,31,30};
    long answer;

    answer = sum(days, days+SIZE);
    printf("The total number of days is %ld.\n", answer);

    return 0;
}

int sum(int * start, int * end)
{
    int total = 0;
    while(start < end){
        total += *(start++);
        // start++;
    }
    return total;
}