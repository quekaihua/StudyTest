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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head, *current;
	head = current = NULL;
    int temp, cf = 0; //进位标志
    
    while(l1 && l2) {
		if(cf == 1) {
			temp = l1->val + l2->val + 1;
            cf = 0;
		} else {
			temp = l1->val + l2->val;
		}
		if(temp >= 10) {
			temp = temp - 10;
			cf = 1;
		}
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = temp;
		node->next = NULL;
		if(head == NULL) {
			head = node;
			current = head;
		} else {
			current->next = node;
			current = current->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1){
		if(cf == 1) {
			temp = l1->val+1;
            cf = 0;
		} else {
			temp = l1->val;
		}
		if(temp >= 10) {
			temp = temp - 10;
			cf = 1;
		}
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val  = temp;
		node->next = NULL;
		if(head == NULL) {
			head = node;
			current = head;
		} else {
			current->next = node;
            current = current->next;
		}
		l1 = l1->next;
	}

	while (l2){
		if(cf == 1) {
			temp = l2->val+1;
            cf = 0;
		} else {
			temp = l2->val;
		}
		if(temp >= 10) {
			temp = temp - 10;
			cf = 1;
		}
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val  = temp;
		node->next = NULL;
		if(head == NULL) {
			head = node;
			current = head;
		} else {
			current->next = node;
            current = current->next;
		}
		l2 = l2->next;
	}

	if (cf == 1) {
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val  = 1;
		node->next = NULL;
		current->next = node;
	}

	return head;
}

int main() 
{
	struct ListNode *l1, *l2, *l3;
	l1 = l2 = NULL;
	l1 = add(l1, 2); l2 = add(l2, 5);
	l1 = add(l1, 4); l2 = add(l2, 6);
	l1 = add(l1, 3); l2 = add(l2, 4);
	l3 = addTwoNumbers(l1, l2);
	while (l3)
	{
		printf("%d ", l3->val);
		l3 = l3->next;
	}
	
}

