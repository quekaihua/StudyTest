#include <stdlib.h>
#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head, *current, *temp;
	head = current = NULL;
    
    while(l1 && l2) {
		if (l1->val < l2->val) {
			temp = l1;
			l1 = l1->next;
		} else {
			temp = l2;
			l2 = l2->next;
		}
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = temp->val;
		node->next = NULL;
		if(head == NULL) {
			head = node;
			current = head;
		} else {
			current->next = node;
			current = current->next;
		}
	}

	if (l1) { if(current == NULL) head = l1; else current->next = l1;}
	if (l2) { if(current == NULL) head = l2; else current->next = l2;}
	return head;
}

int main() 
{
	struct ListNode *l1, *l2, *l3;
	l1 = l2 = NULL;
	l1 = add(l1, 2); l2 = add(l2, 5);
	l1 = add(l1, 4); l2 = add(l2, 6);
	l1 = add(l1, 3); l2 = add(l2, 4);
	l3 = mergeTwoLists(l1, l2);
	while (l3)
	{
		printf("%d ", l3->val);
		l3 = l3->next;
	}
	
}

