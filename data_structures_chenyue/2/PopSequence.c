#include <stdio.h>

int capacity;
#define MAXSIZE 10
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
	int top = 0;

	int data,next_data, value, max=0, check=0;
	for (int i=0; i<n; i++) {
		data = input[i];
		if (data>max) {
			if(top && Stack[top] < data){
				//pop
				value = Stack[--top];
				if(value != input[check++]) return 0;
			}
			for(int j=max+1; j<=data; j++) {
				//push
				if(top+1 > capacity) return 0;
				Stack[top++] = j;
			}
			max = data;
		}
	}
	return 1;
}