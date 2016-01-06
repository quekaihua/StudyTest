#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev;
        ListNode* curr;
        prev = NULL;
        curr = head;
        while(curr != NULL){
        	ListNode* tempNode;
        	tempNode = curr->next;
        	curr->next = prev;
        	prev = curr;
        	
        	curr = tempNode;
		}
		
		return prev;
    }
    void printList(ListNode* head){
    	ListNode* curr = head;
		while(curr != NULL){
			cout << curr->val << "->";
			curr = curr->next;
		}
		cout << endl;
	}
};

int main(){
	ListNode* head = NULL;
	ListNode* first;ListNode* second;ListNode* third;
	first->val = 1;
	second->val = 2;
	third->val = 3;
	head = first;
	head->next = second;
	second->next = third; 
	third->next = NULL;
	Solution a;
	a.printList(head);
	
}
