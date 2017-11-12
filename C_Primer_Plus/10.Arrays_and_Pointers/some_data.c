#include <stdio.h>
#define SIZE 4

int main(void)
{
    int no_data[SIZE] = {31, 23};
    int index;

    for(index = 0; index < SIZE; index++){
        printf("Month %d has %2d days.\n", index+1, no_data[index]);
    }

    return 0;
}