/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * S, int* returnSize){
	int N=0, k=0, l=0;
	int *res = malloc(sizeof(int)*10001);
	while(S[N] != '\0'){N++;}
	for (int i=0; S[i] != '\0'; i++) {
		if (S[i] == 'I') {
			res[k++] = l++;
		} else {
			res[k++] = N--;
		}
	}
	res[k++] = l; 
	*returnSize = k;
	return res;
}

int main()
{
	char S[] = "IDID";
	int re;
	diStringMatch(S, &re);
}