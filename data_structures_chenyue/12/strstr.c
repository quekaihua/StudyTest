#include <stdio.h>
#include <string.h>

#define MAX_STRING  1000001
#define MAX_PATTERN 100001

int main()
{
	char string[MAX_STRING];
	char pattern[MAX_PATTERN];
	int N;
	scanf("%s", string);
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%s", pattern);
		char * ptr = strstr(string, pattern);
		if(ptr) {
			printf("%s\n", ptr);
		} else {
			printf("Not Found\n");
		}
	}
}