#include <stdlib.h>
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head){
	struct ListNode* odd, *even, *oddCurrent, *eventCurrent, *current, *oddPrev, *evenPrev;
	if(!head) return head;   //NULL
	if(!head->next) return head; //Only 1 node

	odd  = head;
	even = head->next;
	oddPrev = evenPrev = NULL;
	current = head;
	while (current) {
		oddCurrent = current;
		eventCurrent = current->next;
		if (oddPrev) oddPrev->next = oddCurrent;
		if (evenPrev) evenPrev->next = eventCurrent;

		oddPrev = oddCurrent;
		evenPrev = eventCurrent;
		if(current->next) current = current->next->next;
		else break;
	}

	//join two links
	oddCurrent->next = even;

	return head;
}

struct ListNode* myLinkedListCreate() {
    struct ListNode* obj = NULL;
	return obj;
}

 struct ListNode* myLinkedListAddAtTail(struct ListNode* obj, int val) {
	if(!obj) {
		struct ListNode* node = malloc(sizeof(struct ListNode));
		node->val  = val;
		node->next = NULL;
		obj  = node;
		return obj;
	}
	struct ListNode* current = obj;
	while(current->next) {
		current = current->next;
	}
	struct ListNode* node = malloc(sizeof(struct ListNode));
	node->val  = val;
	node->next = NULL;
	current->next  = node;
	return obj;
}

int main()
{
	struct ListNode* obj = myLinkedListCreate();
	obj = myLinkedListAddAtTail(obj, 1);
	obj = myLinkedListAddAtTail(obj, 2);
	obj = myLinkedListAddAtTail(obj, 3);
	obj = myLinkedListAddAtTail(obj, 4);
	obj = myLinkedListAddAtTail(obj, 5);
	
	oddEvenList(obj);
	return 0;
}
