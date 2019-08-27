#include <stdio.h>
#include <stdio.h>

struct user {
	int user_id;
	int * score;
	int 
}
int IsValid(int problem_id, int Score);

int main()
{
	int N, K, M;
	int FullMark[5];
	scanf("%d %d %d", &N, &K, &M);
	int user_id, problem_id, score;
	UserInfo L;
	//初始化分数
	for(int i; i<K; i++)
		scanf("%d", &FullMark[i]);
	
	//初始化学生信息
	for(int i; i<N; i++){
		scanf("%d %d %d", &user_id, &problem_id, &score);
		if(IsValid(problem_id, score)){
			InsertOrUpdate(UserInfo L, user_id, problem_id, score);
		}
	}

	//建立分数表格
	
}

int IsValid(int problem_id, int Score)
{

}