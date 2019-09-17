#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode* current, *prev, *temp;
	current = prev = head;
	while(current) {
		temp = NULL;
		if(current->val == val) {
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
