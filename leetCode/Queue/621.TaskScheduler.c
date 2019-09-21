
/**
 * 1.队列空时，把当前任务入队
 * 2.从当前未处理的队列开始，往后循环找未处理任务,直到
 * 
 */
int leastInterval(char* tasks, int tasksSize, int n){
	int front=0;
	char* res=malloc(100000);
	char idle = '-';
	//initial visited
	int visited[tasksSize];
	char* Queue=malloc(n);
	for(int i=0; i<tasksSize; i++) visited[i] = 0;
	int i = 0, flag=0;
	while(tasksSize) {
		if(visited[i]) continue;
		visited[i] = 1;
		if(front=0) {
			//If Queue is Empty, enQueue
			Queue[front++] = tasks[i];
		} else {
			for(int k=i+1; k<tasksSize; k++) {
				if (front < n-1) {
					//If Queue has the task, continue
					for(int j=0; j<front; j++) {
						if(Queue[j] != tasks[i]) {
						flag=1;
						break;
					}
				}
			}
		}

		if(front==n) 
		Queue[front++] = tasks[i];

		
		i++;
		tasksSize--;
	}
}