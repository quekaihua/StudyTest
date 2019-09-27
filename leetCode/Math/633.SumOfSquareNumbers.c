#include <stdbool.h>
#include <math.h>

bool judgeSquareSum(int c){
    int top, low;
    low = 0;
    top = sqrt(c);
	while(low <= top) {
        if(c - low*low == top*top) return true;
        else if(c - low*low < top*top) top--;
        else low++;
    }
    
	return false;
}

int main()
{
	judgeSquareSum(4);
}