#include <stdlib.h>
#include <stdio.h>

char * removeDuplicates(char * S){
	char *r = (char *)malloc(10);
	int top=0;
	r[0] = S[0];
	int i=0;
	while (S[i] != '\0') {
		if(top > 0){
			if(r[top-1] != S[i]){
				r[top++] = S[i];
			} else {
				while(top > 0 && r[top-1] == S[i]){
					top--;
				}
			}
		} else {
			r[top++] = S[i];
		}
		i++;
	}
    r[top] = '\0';
	return r;
}

int main()
{
	char S[] = "abbaca";
	removeDuplicates(S);
}