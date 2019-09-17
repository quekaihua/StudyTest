#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k){
	int total=0;
	struct ListNode* current, *new, *prev;

	//count total nodes
	current = head;
	prev = NULL;
	while(current){
		total++;
		prev = current;
		current = current->next;
	}

	if(total <= 1) return head;
	
	if(prev) prev->next = head; //linked the end node to begin node.
	
	//find right k node.
	k = total - k % total;
	total = 0;
	current = head;
	while(total <= k) {
		if(total == k) {
			new = current;
			prev->next = NULL;
			break;
		}
		total++;
        prev = current;
		current = current->next;
	}

	return new;
}
