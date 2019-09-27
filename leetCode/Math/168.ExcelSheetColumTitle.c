

char * convertToTitle(int n){
	char tem[10];
    char * res = malloc(10);
	int len = 0, cur;
	while(n > 0) {
		cur = --n % 26;
		tem[len++] = 'A' + cur;
		n = n / 26;
	}
	for(int i=0; i<=len-1; i++) {
		res[i] = tem[len-1-i];
	}

	res[len] = '\0';
	return res;
}

int main()
{
	convertToTitle(1);
}