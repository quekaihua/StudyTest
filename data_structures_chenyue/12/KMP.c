#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int Position;

#define MAX_STRING  1000001
#define MAX_PATTERN 100001
#define NotFound -1

Position KMP(char *string, char *pattern);
void BuildMatch(char *pattern, int *match);

int main()
{
	char string[MAX_STRING];
	char pattern[MAX_PATTERN];
	int N;
	scanf("%s", string);
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%s", pattern);
		Position ptr = KMP(string, pattern);
		if(ptr != NotFound) {
			printf("%s\n", string+ptr);
		} else {
			printf("Not Found\n");
		}
	}
}

Position KMP(char *string, char *pattern)
{
	int n = strlen(string);
	int m = strlen(pattern);
	int s, p, *match;
	if (n < m) return NotFound;
	match = (int *)malloc(sizeof(int) * m);
	BuildMatch(pattern, match);
	s = p = 0;
	while (s<n && p<m) {
		if (string[s] == pattern[p]) {s++; p++;}
		else if (p>0) p = match[p-1] + 1;
		else s++;
	}
	return (p==m) ? (s-m) : NotFound;
}

void BuildMatch(char *pattern, int *match)
{
	int i, j;
	int m = strlen(pattern);
	match[0] = -1;
	for (j=1; j<m; j++) {
		i = match[j-1];
		while ((i>=0) && (pattern[i+1] != pattern[j]))
			i = match[i];
		if (pattern[i+1] == pattern[j])
			match[j] = i+1;
		else match[j] = -1;
	}
}