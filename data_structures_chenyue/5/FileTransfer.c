#include <stdio.h>

#define MAXSIZE 10001

int network[MAXSIZE];

void check(int network[], int c1, int c2);
void UnionSet(int network[], int c1, int c2);
int find(int network[], int k);

int main()
{
	char signal;
	int c1, c2, N;
	scanf("%d", &N);
	//initial network
	for(int i=1; i<=N; i++)
		network[i] = -1;
	scanf("%c", &signal);
	while(signal != 'S'){
		if (signal == 'I') {
			scanf("%d %d", &c1, &c2);
			UnionSet(network, c1, c2);
		} else if(signal == 'C') {
			scanf("%d %d", &c1, &c2);
			check(network, c1, c2);
		}
		scanf("%c", &signal);
	}

	//check if it is a network
	int count=0;
	for(int i=1; i<=N; i++){
		if(network[i] < 0) count++;
	}
	count > 1 ? printf("There are %d components.", count)
		: printf("The network is connected.");
}

void check(int network[], int c1, int c2)
{
	int parent1, parent2, flag;
	parent1 = find(network, c1);
	parent2 = find(network, c2);
	parent1==parent2 && parent1 > 0 ? printf("yes\n") : printf("no\n");
}

void UnionSet(int network[], int c1, int c2)
{
	int parent1, parent2;
	parent1 = find(network, c1);
	parent2 = find(network, c2);

	if (network[parent1] < network[parent2]) {
		network[parent1] = network[parent1] + network[parent2];
		network[parent2] = parent1;
	} else {
		network[parent2] = network[parent1] + network[parent2];
		network[parent1] = parent2;
	}
}

int find(int network[], int k)
{
	int parent = k;
	while (network[parent] > 0)
	{
		parent = network[parent];
	}
	
	return parent;
}