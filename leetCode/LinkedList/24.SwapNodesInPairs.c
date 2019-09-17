#include <stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
	struct ListNode* current, *pre;
	current = head;
	pre = NULL;
	while(current && current->next) {
		current->next = current->next->next;
		current->next->next = current;
		if(pre == NULL) head = current->next;
		else pre->next = current->next;
        pre = current;
		current = current->next;
	}

	return head;
}