#include <stdbool.h>
#include <stdlib.h>

bool backspaceCompare(char * S, char * T){
	char* stack1 = malloc(sizeof(10000));	
	char* stack2 = malloc(sizeof(10000));
	int i=0, k1=0, k2=0;
	while(S[i] != '\0') {
		if(S[i] == '#') {
			if(k1>0) k1--;
		} else stack1[k1++] = S[i];
		i++;
	}
	i = 0;
	while(T[i] != '\0') {
		if(T[i] == '#') {
			if(k2>0) k2--;
		} else stack2[k2++] = T[i];
		i++;
	}

	if(k1 != k2) return false;
	for(int i=0; i<k1; i++) {
		if(stack1[i] != stack2[i])
			return false;
	}
	return true;
}

int main()
{
	char s[] = "xywrrmp";
	char t[] = "xywrrmu#p";
	backspaceCompare(s,t);
}