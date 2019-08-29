#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
#define MAX 1000
#define INFINITY 0
int A[MAX][MAX];
 
void BuildGraph ( int Hash[], int N ) {
    int i, j, tmp;
    for ( i = 0; i < N; i++ ) {
        if ( Hash[i] >= 0 ) {
            tmp = Hash[i] % N; //求余数
            if ( Hash[tmp] != Hash[i]) { //如果这个位置已被占有
                for ( j = tmp; j != i; j = ( j + 1 ) % N )
                    A[j][i] = 1; //位置j到i的元素都在i之前进入哈希表
            }
        }
    }
}
 
int TopSort( int Hash[], int HashMap[], int N , int num){
    int V, W, cnt = 0, Indegree[MAX] = {0};
    set<int> s;
    //计算各结点的入度
    for( V = 0; V < N; V++ )
        for( W = 0; W < N; W++ )
            if( A[V][W] != INFINITY )
                Indegree[W]++;    //对于有向边<V,W>累计终点W的入度
    //入度为0的入队
    for( int i = 0; i < N; i++ )
        if( Indegree[i] == 0 && Hash[i] > 0 )
            s.insert( Hash[i] );  //将大于0且入度为0的顶点放入集合，自动排序
    while( !s.empty() ) {
        V = HashMap[ *s.begin() ]; //获取最小的元素的下标
        s.erase( s.begin() );
        cnt++;
        printf("%d", Hash[V]);
        if ( cnt != num )
            printf(" ");
        for( W = 0; W < N; W++ )
            if( A[V][W] != INFINITY ) {  //<V, W>有有向边
                if( --Indegree[W] == 0 )  //去掉V后，如果W的入度为0
                    s.insert( Hash[W] );
            }
    }
    if( cnt != num ) return 0;    //如果没有取出所有元素，说明图中有回路
    else return 1;
}
 
int main () {
    int N, Hash[1005],HashMap[100000], num = 0;
    scanf("%d", &N);
    for ( int i = 0 ;i < N; i++ ) {
        scanf("%d", &Hash[i]);
        HashMap[ Hash[i] ] = i;    //记录下标
        if ( Hash[i] > 0 ) num++; //记录哈希表中的元素个数
    }
    BuildGraph( Hash, N );
    TopSort( Hash, HashMap, N ,num );
    return 0;
}