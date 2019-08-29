#include <stdio.h>
#include <stdlib.h>

#define USER_MAXSIZE 10
#define PROBLEM_MAXSIZE 5
#define EMPTY -1
typedef struct user * UserInfo;

struct user {
	int user_id;
	int score[PROBLEM_MAXSIZE+1];	//score
	int total_score; 
	int total_full;  //total number of fullmark
};

int FullMark[PROBLEM_MAXSIZE+1];
UserInfo DB[USER_MAXSIZE];
int N, K, M, cnt=0;

int IsValid(int problem_id, int score);
void InsertOrUpdate(int user_id, int problem_id, int score);
UserInfo CreateUser();
int FindUser(int user_id);

int main()
{
	scanf("%d %d %d", &N, &K, &M);
	int user_id, problem_id, score;
	UserInfo L;
	//初始化分数
	for(int i=1; i<=K; i++)
		scanf("%d", &FullMark[i]);
	
	//提交分数
	for(int i=0; i<M; i++){
		scanf("%d %d %d", &user_id, &problem_id, &score);
		if(IsValid(problem_id, score))
			InsertOrUpdate(user_id, problem_id, score);
	}

	for (int i=0; i<cnt; i++) {
		UserInfo u = DB[i];
		printf("user_id=%d total_score=%d total_full=%d\n",
			u->user_id, u->total_score, u->total_full);
		for(int j=1; j<=K; j++){
			printf("%d ", u->score[j]);
		}
		printf("\n");
	}
	//关键字排序

	return 0;
	
}

int IsValid(int problem_id, int score)
{
	if((score > -1) && (score <= FullMark[problem_id]))
		return 1;
	else return 0;
}

void InsertOrUpdate(int user_id, int problem_id, int score)
{
	int index = FindUser(user_id);
	if (index != -1) {
		UserInfo u = DB[index];
		if(score > u->score[problem_id]) {  //高于原分数才更新
			if(u->score[problem_id] == EMPTY) {
				u->total_score = u->total_score + score;
			} else {
				u->total_score = u->total_score + (score - u->score[problem_id]);
			}
			if(score == FullMark[problem_id])
				u->total_full++;
			u->score[problem_id] = score;
		}
	} else {
		UserInfo u  			= CreateUser();
		u->user_id  			= user_id;
		u->score[problem_id]	= score;
		u->total_score 			= score;
		if(score == FullMark[problem_id])
			u->total_full = 1;
		
		DB[cnt++] = u;
	}
}

UserInfo CreateUser()
{
	UserInfo u = malloc(sizeof(struct user));
	u->total_score = 0;
	u->total_full  = 0;
	for (int i=1; i<=K; i++)
		u->score[i] = EMPTY;
	return u;
}

int FindUser(int user_id)
{
	int index = -1;
	for (int i=0; i<N; i++)
		if(DB[i] && DB[i]->user_id == user_id)
			return i;
	return index;
}