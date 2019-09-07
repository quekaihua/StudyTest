#include <stdio.h>
#include <stdlib.h>

#define USER_MAXSIZE 10005
#define PROBLEM_MAXSIZE 5
#define EMPTY -2
typedef struct user * UserInfo;

struct user {
	int user_id;
	int score[PROBLEM_MAXSIZE+1];	//score
	int total_score; 
	int total_full;  //total number of fullmark
	int submit;
};

int FullMark[PROBLEM_MAXSIZE+1];
struct user DB[USER_MAXSIZE];
int N, K, M, cnt=0;

int IsValid(int problem_id, int score);
void InsertOrUpdate(int user_id, int problem_id, int score);
struct user CreateUser();
int FindUser(int user_id);
int compare(const void * a, const void * b);
void PrintPAT();
void InitialDB();
int main()
{
	scanf("%d %d %d", &N, &K, &M);
	int user_id, problem_id, score;
	//初始化分数
	for(int i=1; i<=K; i++)
		scanf("%d", &FullMark[i]);
	InitialDB();
	//提交分数
	for(int i=0; i<M; i++){
		scanf("%d %d %d", &user_id, &problem_id, &score);
		if(IsValid(problem_id, score))
			InsertOrUpdate(user_id, problem_id, score);
	}

	qsort(DB, N, sizeof(struct user), compare);

	PrintPAT();

	return 0;
	
}

int IsValid(int problem_id, int score)
{
	if((score > EMPTY) && (score <= FullMark[problem_id]))
		return 1;
	else return 0;
}

void InsertOrUpdate(int user_id, int problem_id, int score)
{
	if(score > DB[user_id-1].score[problem_id]) {  //高于原分数才更新
		if(score > 0) {
			int s_score = DB[user_id-1].score[problem_id] >= 0 ? DB[user_id-1].score[problem_id] : 0;
			DB[user_id-1].total_score = DB[user_id-1].total_score + (score - s_score);
		}
		if(score == FullMark[problem_id])
			DB[user_id-1].total_full++;
		DB[user_id-1].score[problem_id] = score;
		if(score > -1) DB[user_id-1].submit = 1;
	}
	// int index = FindUser(user_id);
	// if (index != -1) {
	// 	if(score > DB[index].score[problem_id]) {  //高于原分数才更新
	// 		if(score > 0) {
	// 			int s_score = DB[index].score[problem_id] >= 0 ? DB[index].score[problem_id] : 0;
	// 			DB[index].total_score = DB[index].total_score + (score - s_score);
	// 		}
	// 		if(score == FullMark[problem_id])
	// 			DB[index].total_full++;
	// 		DB[index].score[problem_id] = score;
	// 	}
	// } else {
	// 	struct user u  			= CreateUser();
	// 	u.user_id  			= user_id;
	// 	u.score[problem_id]	= score;
	// 	u.total_score 		= score <= 0 ? 0 : score;
	// 	if(score == FullMark[problem_id])
	// 		u.total_full = 1;
		
	// 	DB[cnt++] = u;
	// }
}

struct user CreateUser()
{
	struct user * u = (UserInfo)malloc(sizeof(struct user));
	u->total_score = 0;
	u->total_full  = 0;
	for (int i=1; i<=K; i++)
		u->score[i] = EMPTY;
	return *u;
}


void InitialDB()
{
	for (int i=0; i<N; i++) {
		DB[i].user_id = i+1;
		DB[i].total_score = 0;
		DB[i].total_full = 0;
		DB[i].submit = 0;
		for (int j=1; j<=K; j++) {
			DB[i].score[j] = EMPTY;
		}
	}
}

int FindUser(int user_id)
{
	int index = -1;
	for (int i=0; i<cnt; i++)
		if(DB[i].user_id == user_id)
			return i;
	return index;
}

int compare(const void *a, const void *b)
{
	struct user A = *(struct user *)a;
	struct user B = *(struct user *)b;
	if (A.total_score < B.total_score){       //1.比较总分
		return 1;
	}
	else if (A.total_score > B.total_score)
		return -1;
	else {
		if (A.total_full < B.total_full)     //比较满分数
			return 1;
		else if (A.total_full > B.total_full)
			return -1;
		else {
			if (A.user_id < B.user_id) {     //比较user_id
				return -1;
			} else {
				return 1;
			}
		}
	}
	
}

void PrintPAT()
{
	int Rank, LastRank, LastScore=0, flag;
	Rank = LastRank = 1;
	for (int i=0; i<N; i++) {
		struct user u = DB[i];

		if(u.submit) {
			if (u.total_score == LastScore) {
				LastRank = LastRank;
			} else {
				LastRank = Rank;
			}
			printf("%d %05d %d ",LastRank, u.user_id, u.total_score);
			LastScore = u.total_score;
			for(int j=1; j<=K; j++){
				if(u.score[j] == EMPTY) 	printf("-");
				else if (u.score[j] == -1) 	printf("0");
				else						printf("%d", u.score[j]);
				if (j != K) printf(" ");
			}
			printf("\n");
			Rank++;
		}
	}
}