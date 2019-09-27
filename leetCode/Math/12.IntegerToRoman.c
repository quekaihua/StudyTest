#include <stdio.h>
#include <stdlib.h>

int len=0;

int solveThousand(char *ans, int num)
{
	int count = num / 1000;
	num = num - count*1000;
	for(int i=0; i<count; i++) ans[len++] = 'M';
	return num;
}

int solveHundred(char *ans, int num)
{
	int count = num / 100;
	num = num - count*100;
	if (count == 4) {
		ans[len++] = 'C';
		ans[len++] = 'D';
	} else if (count==9) {
		ans[len++] = 'C';
		ans[len++] = 'M';
	}else {
		if(count >= 5) {
			ans[len++] = 'D';
			count = count - 5;
		}
		for(int i=0; i<count; i++) ans[len++] = 'C';
	}
	
	return num;
}

int solveTen(char *ans, int num)
{
	int count = num / 10;
	num = num - count*10;
	if (count == 4) {
		ans[len++] = 'X';
		ans[len++] = 'L';
	} else if (count==9) {
		ans[len++] = 'X';
		ans[len++] = 'C';
	}else {
		if(count >= 5) {
			ans[len++] = 'L';
			count = count - 5;
		}
		for(int i=0; i<count; i++) ans[len++] = 'X';
	}
	
	return num;
}

int solveUnit(char *ans, int num)
{
	int count = num;
	if (count == 4) {
		ans[len++] = 'I';
		ans[len++] = 'V';
	} else if (count==9) {
		ans[len++] = 'I';
		ans[len++] = 'X';
	}else {
		if(count >= 5) {
			ans[len++] = 'V';
			count = count - 5;
		}
		for(int i=0; i<count; i++) ans[len++] = 'I';
	}
	
	return num;
}

char * intToRoman(int num)
{
	char * ans = malloc(20);
	if(num >= 1000) {
		num = solveThousand(ans, num);
	}
	if(num >= 100) {
		num = solveHundred(ans, num);
	}
	if(num >= 10) {
		num = solveTen(ans, num);
	}
	if(num > 0) {
		num = solveUnit(ans, num);
	}
	ans[len] = '\0';
	return ans;
}

int main()
{
	int input;
	scanf("%d", &input);
	char* ans = intToRoman(input);
	printf("%s\n", ans);
}