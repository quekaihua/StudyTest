#include <stdio.h>

int capacity;
#define MAXSIZE 1005
int input[MAXSIZE];
int Stack[MAXSIZE];

int IsPopSequence(int input[], int n);
int main()
{
	int n, group, flag;
	scanf("%d %d %d", &capacity, &n, &group);
	for (int i=0; i<group; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", &input[j]);
		}
		flag = IsPopSequence(input, n);
		flag > 0 ? printf("YES\n") : printf("NO\n");
	}
}

int IsPopSequence(int input[], int n)
{
	//initial stack
	Stack[capacity];
	int top = 1;
	Stack[0] = 0;

	int max=1;
	for (int i=0; i<n; i++) {
		while(Stack[top-1] < input[i] && top <= capacity) {
			Stack[top++] = max++;
		}
		// printf("Stack[%d]=%d, input[%d]=%d\n", top-1, Stack[top-1], i, input[i]);
		if (Stack[top-1] == input[i])
			--top;
		else return 0;
	}
	return 1;
}