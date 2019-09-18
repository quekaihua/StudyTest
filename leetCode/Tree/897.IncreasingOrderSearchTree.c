 #include <stdlib.h>
 #include <stdbool.h>

 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* increasingBST(struct TreeNode* root){
	struct TreeNode* Stack[100], *newRoot, *prev, *current;
	newRoot = current = root;
	int top = 0;
	prev = NULL;
	int flag = 0;
	while(current || top > 0){
		while(current) {
			Stack[top++] = current;
			current = current->left;
		}
		if(top > 0) {
			current = Stack[--top];
			current->left = NULL;
			if(prev) {
				prev->right = current;
				prev = current;
			}
			if (!flag) {
				newRoot = current;
				prev = current;
				flag = 1;
			}
			current = current->right;
		}
	}
	return newRoot;
}