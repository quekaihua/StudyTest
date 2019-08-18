#include <stdio.h>
#include <stdbool.h>

int main()
{
	int n, i, sum = 0, max_sum=0, start, end;
	scanf("%d", &n);
    int v[n];
    start = 0;
    end = n-1;
	for(i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
    bool flag = false;
    for (i=0; i<n; i++) {
        if(v[i] < 0) continue;
        sum = 0;
        for (int j=i; j<n; j++) {
            sum += v[j];
            if(!flag && sum==0 && max_sum==0){
                max_sum = sum;
                start = i;
                end = j;
                flag = true;
            } else if (max_sum < sum) {
                max_sum = sum;
                start = i;
                end = j;
            }
        }
    }
	printf("%d %d %d\n", max_sum, v[start], v[end]);
	return 0;
}