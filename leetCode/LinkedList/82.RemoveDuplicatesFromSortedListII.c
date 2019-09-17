#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
	struct ListNode* current, *prev, *temp;
	current = prev = head;
	int last, now;
	while(current) {
		temp = NULL;
		if(current == head) {
			last  = current->val;
			continue;
		}
		if(current->val == last) {
			temp = current;
			//head nodes
			if (current == head) {
				head = current->next;
				prev = head;
			} else {
				prev->next = current->next;
			}
            current = current->next;
		} else {
            prev = current;
            current = current->next;
        }
		if(!temp) free(temp);
	}

	return head;
}