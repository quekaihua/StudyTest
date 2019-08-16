#include <stdio.h>
#include <stdlib.h>

typedef struct monkey * Monkey;
struct monkey {
	int number;
	Monkey next;
};

Monkey init_circle(int n);
void delete_next(Monkey monkey);
int find_king(Monkey monkey, int n);

int main()
{
    int n;
	scanf("%d", &n);
	Monkey circle;
	circle = init_circle(n);
	int king;
	king = find_king(circle, n);
	printf("%d", king);
    return 0;
}

Monkey init_circle(int n)
{
	Monkey head,temp;
	for(int i=1; i<=n; i++){
		Monkey new_monkey;
		new_monkey = malloc(sizeof(struct monkey));
		new_monkey->number = i;
		new_monkey->next = NULL;
		if (i==1) {
			head = temp = new_monkey;
		} else {
			temp->next = new_monkey;
			temp = new_monkey;
		}
		if (i == n && i !=1 ) {
			new_monkey->next = head;
		}
	}
	return head;
}

void delete_next(Monkey monkey)
{
	Monkey temp = monkey->next;
	if (temp != NULL){
		if(temp->next == monkey){
			monkey->next = NULL;
		} else {
			monkey->next = temp->next;
		}
		free(temp);
	}
}

int find_king(Monkey monkey, int n)
{
	int count = 1;
	Monkey current;
	current = monkey;
	while(current->next != NULL) {
		if( 2 == count++) {
			delete_next(current);
			count = 1;
		}
		if(current->next == NULL) break;
		current = current->next;
	}
	return current->number;
}