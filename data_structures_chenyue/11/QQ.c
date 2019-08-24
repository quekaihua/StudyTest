#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NEW_OK "New: OK"
#define EXIST "ERROR: Exist"
#define NOT_EXIST "ERROR: Not Exist"
#define LOGIN_OK "Login: OK"
#define WRONG_PW "ERROR: Wrong PW"

#define PW_LENGTH 17
#define MAXSIZE 100000

typedef struct node* User;
typedef struct table *UserTable;
typedef long long ElementType;

UserTable CreateHashTbl(int N);
void Login(long long name, const char psw[], UserTable H);
void RegisterNewUser(long long name, const char psw[], UserTable H);
int Hash(ElementType Key, int TableSize);
User Find(ElementType Key, UserTable H);
void Insert(ElementType Key, const char psw[], UserTable H);
int NextPrime( int N );

struct node {
    long long name;
    char pws[PW_LENGTH];
    User next;
};

struct table {
    int TableSize;
    User UserLists;
};

int main()
{
    int N;
    scanf("%d", &N);

    char command[2], psw[30];
    long long name;

    UserTable H = CreateHashTbl(N);
    for (int i=0; i<N; i++) {
        scanf("%s", command);
        scanf("%lld %s", &name, psw);
        if (command[0] == 'L') {
            Login(name, psw, H);
        } else if (command[0] == 'N') {
            RegisterNewUser(name, psw, H);
        }
    }

    return 0;
}

UserTable CreateHashTbl(int N)
{
	UserTable H = (UserTable) malloc(sizeof(struct table));
	if (H == NULL) {
		fprintf(stderr, "alloc HashTable fail.\n");
		exit(1);
	}
	H->TableSize = NextPrime(N);
	H->UserLists = (User) malloc(H->TableSize * sizeof(struct node));
	if (H->UserLists == NULL) {
		fprintf(stderr, "alloc Table List fail.\n");
		exit(1);
	}
	for (int i=0; i<H->TableSize; i++)
		H->UserLists[i].next = NULL;
	return H;
}

void Login(long long name, const char psw[], UserTable H)
{
    User P = Find(name, H);
    if(!P) {
        printf("%s\n", NOT_EXIST);
    } else {
        if (strcmp(P->pws, psw) != 0)
            printf("%s\n", WRONG_PW);
        else
            printf("%s\n", LOGIN_OK);
    }
}

void RegisterNewUser(long long name, const char psw[], UserTable H)
{
    User P = Find(name, H);
    if(P) {
        printf("%s\n", EXIST);
    } else {
        Insert(name, psw, H);
    }
}

int Hash(ElementType Key, int TableSize)
{
    return Key % TableSize;
}

User Find(ElementType Key, UserTable H)
{
    int pos = Hash(Key, H->TableSize);
    User P = H->UserLists[pos].next;
    while (P != NULL && P->name != Key) {
        P = P->next;
    }
    return P;
}

void Insert(ElementType Key, const char psw[], UserTable H)
{
    User P = Find(Key, H);
    if (P) {
        printf("%s\n", EXIST);
    } else {
        User node = (User)malloc(sizeof(struct node));
        node->name = Key;
        strncpy(node->pws, psw, PW_LENGTH);
        int pos = Hash(Key, H->TableSize);
        node->next = H->UserLists[pos].next;
        H->UserLists[pos].next = node;
        printf("%s\n", NEW_OK);
    }
}

int NextPrime( int N )
{ /*  返回大于N 且不超过MAXTABLESIZE数 的最小素数 */
	int i, p = (N%2)? N+2 : N+1; /* 从大于N始 的下一个奇数开始 */
	while( p <= MAXSIZE ) {
		for( i=(int)sqrt(p); i>2; i-- )
			if ( !(p%i) ) break; /* p数 不是素数 */
			if ( i==2 ) break; /* for 正常结束，说明p数 是素数 */
			else p += 2; /* 数 否则试探下一个奇数 */
	}
	return p;
}