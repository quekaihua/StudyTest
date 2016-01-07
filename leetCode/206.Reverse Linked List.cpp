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
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL){
        	ListNode* tempNode;
        	tempNode = curr->next;
        	curr->next = prev;
        	prev = curr;
        	
        	curr = tempNode;
		}
		
		return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* prev = NULL;
		ListNode* curr = head;
    	int count = 0;
    	
    	//找出正序第几 
    	while(curr != NULL){
    		curr = curr->next;
    		count++;
		}
		
		int nth = count - n;
		//找到正序的指针 
		count = 0;
		curr = head;
		while(curr != NULL && count < nth){
			prev = curr;
			curr = curr->next;
			count++;
		}
		if(prev == NULL){
			head = curr->next;
		}else{
		//改变指针并删除节点
		prev->next = curr->next;	
		delete curr;
		}
		return head;
    }
    ListNode* removeElements(ListNode* head, int val) {
    	while(head->next != NULL && head->val == val){
    		head = head->next;
		}
        ListNode* prev = NULL;
        ListNode* curr = head;
		while(curr != NULL){
			cout << "curr: " << curr->val << endl;
        	if(curr->val == val){
				prev->next = curr->next;	
			}
			prev = curr;
			curr = curr->next;
		}
		
		return head;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = curr;
		while(curr != NULL){
       		bool flag = true;
       	
			if(prev && curr){
				if(curr->val == prev->val)
	        		prev->next = curr->next;
				else
					flag = false;
				
			}
			if(!flag)prev = curr;
			curr = curr->next;
		}
		
		return head;
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
	ListNode first = ListNode(1);
	ListNode second = ListNode(2);
	ListNode second2 = ListNode(1);
	ListNode third = ListNode(2);
	ListNode forth = ListNode(3);
	ListNode fifth = ListNode(3);
	first.next = &second; 
	second2.next = &third; second.next = &second2;
	third.next=&forth; forth.next = &fifth;second.next = &second2;
	Solution a;
	a.printList(&first);
//	a.reverseList(&first);
//	a.printList(&third);	
//	a.removeNthFromEnd(&first,2);
//	a.printList(a.removeNthFromEnd(&first,2));
	a.printList(a.removeElements(&first,3));
//	a.printList(a.deleteDuplicates(&first));
}
