#include <stdio.h>

void changeInt(int **i);
int main()
{
	int z = 10;
	int *a;
	a = &z;
	int **b;
	b = &a;
	changeInt(b);
	printf("z=%d\n", z);
	printf("a=%p\n", a);
	printf("b=%p\n", b);
	return 0;
}

void changeInt(int **i)
{
	**i = 5;
	printf("i=%p\n", i);
}