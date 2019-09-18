#include <stdlib.h>
#include <stdio.h>

char * removeOuterParentheses(char * S){
	char *r = (char *)malloc(10001);
	char Stack[1000];
	int top=0;
	int i=0, j=0;
	while (S[i] != '\0') {
		if(S[i]=='(') {
			if(top >= 1){
				r[j++] = S[i];
			}
			Stack[top++] = S[i];
		} else {
            if(top > 1) r[j++] = S[i];
			Stack[--top];
		}
		i++;
	}
    r[j] = '\0';
	return r;
}

int main()
{
	char S[12] = "((()))\0";
	char *r = removeOuterParentheses(S);
	printf("%s\n", r);
	return 0;
}