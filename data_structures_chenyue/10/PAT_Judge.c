#include <stdio.h>
#include <stdlib.h>
struct User {
	int id, score, cnt, visited, problem[6];
}user[10005];
int FullScore[5];
int Cmp ( const void *a, const void *b ) {
	int k;
	if ( ((const struct User*)a)->score < ((const struct User*)b)->score ) //按分数递减排序
		k = 1; //返回大于0，a，b位置需交换
	else if ( ((const struct User*)a)->score > ((const struct User*)b)->score )
		k = -1; //返回小于0， a，b位置不变
	else {
		if ( ((const struct User*)a)->cnt < ((const struct User*)b)->cnt ) //按完整解题数量递减排序
			k = 1;
		else if ( ((const struct User*)a)->cnt > ((const struct User*)b)->cnt )
			k = -1;
		else {
			if ( ((const struct User*)a)->id < ((const struct User*)b)->id ) //按id递增排序;
				k = -1;
			else
				k = 1;
		}
	}
	return k;
}
int main () {
	int N, K, M, Uid, Pid, Pscore;
	scanf("%d%d%d", &N, &K, &M);
	for ( int i = 0; i < K; i++ )
		scanf("%d", &FullScore[i]);
	//初始化结构数组
	for ( int i = 0; i < N; i++ ) {
		user[i].id = i + 1; //题中是从1开始
		user[i].cnt = 0;
		user[i].score = 0;
		user[i].visited = 0;
		for ( int j = 0; j < K; j++ )
			user[i].problem[j] = -2; //实际最小-1
	}
	//接收分数并确定是否显示该用户
	for ( int i = 0; i < M; i++ ) {
		scanf("%d %d %d", &Uid, &Pid, &Pscore);
		if ( user[--Uid].problem[--Pid] < Pscore ) { //题中从1开始，这里从0开始
			if ( Pscore > -1 ) //通过1题或以上编译的用户会显示
				user[Uid].visited = 1;
			user[Uid].problem[Pid] = Pscore;
		}
	}
	//计算总分和完整解题数
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < K; j++ ) {
			if ( user[i].problem[j] > 0 ) {
				user[i].score += user[i].problem[j]; //累计总分
				if ( user[i].problem[j] == FullScore[j] ) //记录完整解题数
					user[i].cnt++;
			}
		}
	}
	//排序
	qsort( user, N, sizeof(struct User), Cmp );
	//输出
	int LastScore = user[0].score, LastRank = 1;
	for ( int i = 0; i < N; i++ ) {
		if ( user[i].visited == 1 ) {
			if ( LastScore == user[i].score ) { //如果和上一个分数相同
				printf("%d %05d %d", LastRank, user[i].id, LastScore);
			}
			else { //如果和上一个分数不同
				LastScore = user[i].score; //更新上一个的分数
				LastRank = i + 1; //更新上一个的排名
				printf("%d %05d %d", i + 1, user[i].id, user[i].score);
			}
			for ( int j = 0; j < K; j++ ) {
				if ( user[i].problem[j] == -1 ) //将未通过编译的分数设为0
					user[i].problem[j] = 0; 
				if ( user[i].problem[j] >= 0 )
					printf(" %d", user[i].problem[j]);
				else 
					printf(" -");
			}
			printf("\n");
		}
	}
	return 0;
}