int calPoints(char ** ops, int opsSize){
	char * cur;
	int sum=0, temp, top=0, stack[1000];
	for(int i=0; i<opsSize; i++) {
		cur = ops[i];
		if(cur[0] == 'C') {
            if(top>0){
			    temp = stack[--top];
			    sum -= temp;
            }
		} else if (cur[0] == 'D') {
            if(top>0){
			    temp = 2 * stack[top-1];
                stack[top++] = temp;
			    sum += temp;
            }
		} else if (cur[0] == '+') {
            if(top > 1){
                temp = (stack[top-1] + stack[top-2]);
                stack[top++] = temp;
                sum += temp;
            }
		} else {
			temp = atoi(cur);
			stack[top++] = temp;
			sum += temp;
		}
	}

	return sum;
}